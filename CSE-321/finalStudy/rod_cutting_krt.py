def init_opt(length):
    opt_arr = []
    for _ in range(length):
        opt_arr.append(0)
    return opt_arr

def init_price_new(price_arr):
    price_new = []
    price_new.append(0)
    for price in price_arr:
       price_new.append(price) 
    return price_new 

#returns optimum value for index i
def find_opt(price_arr, i, opt_arr):
    opt_val = 0
    for j in range(i):
        opt_val = max(opt_val, opt_arr[j] + price_arr[i - j])
    return opt_val

def road_cut(price_arr, n):
    price_new = init_price_new(price_arr)
    opt_arr = init_opt(len(price_new))
    for i in range(n + 1):
        opt_arr[i] = find_opt(price_new, i, opt_arr) 
        print(opt_arr)

    return opt_arr[n]

price_arr = [3, 5, 8, 9, 10, 17, 22, 20]
print(f"pricearray: {price_arr}")

print(road_cut(price_arr, 8))

