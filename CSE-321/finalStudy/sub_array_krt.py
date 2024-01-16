array = [-2, -3, 4, -1, -2, 1, 5, -3]

def solve(array):
    dynamic = []
    dynamic.append(array[0])
    for i in range(len(array)):
        if i == 0 :
            continue
        dynamic.append(max(array[i], dynamic[i-1] + array[i]))

    return dynamic


print(solve(array))

