fuses = [1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0];

def find_malfunctioning(arr):
    return return_mal(arr, 0)

def return_mal(arr, i):
    if(i == len(arr)):
        return -1

    if(arr[i] == 0):
        return i

    else: 
        return return_mal(arr, i + 1)

print(find_malfunctioning(fuses))


