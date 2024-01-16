def print_m(m):
    for row in m:
        print(row)

def init_dynamic_array(M):
    i = len(M)
    j = len(M[0])
    to_return = [[0 for _ in range(j)] for _ in range(i)]
    for i in range(len(M)):
        to_return[i][0] = M[i][0]

    for i in range(len(M[0])):
        to_return[0][i] = M[0][i]

    return to_return

def fill_dynamic_array(M, d_arr):
    for i in range(len(M)):
        if i == 0:
            continue
        for j in range(len(M[0])):
            if j == 0 :
                continue
            if M[i][j] == 1:
                d_arr[i][j] = min(d_arr[i][j-1], d_arr[i-1][j], d_arr[i-1][j-1]) + 1

    return d_arr


M = [[0, 1, 1, 0, 1],
     [1, 1, 0, 1, 0],
     [0, 1, 1, 1, 0],
     [1, 1, 1, 1, 0],
     [1, 1, 1, 1, 1],
     [0, 0, 0, 0, 0]]
 

d_arr = init_dynamic_array(M)

print_m(M)
print()
print_m(fill_dynamic_array(M, d_arr))

