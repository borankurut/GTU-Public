def find_peak_ix(arr):
    if len(arr) == 1 or arr[0] >= arr[1]:
        return 0
    elif arr[len(arr) - 1] >= arr[len(arr) - 2]:
        return len(arr) - 1

    min = 0
    max = len(arr) - 1
    return find_peak_helper(arr, min, max)


def find_peak_helper(arr, min, max):
    mid = (min + max) // 2
    
    if arr[mid] >= arr[mid + 1] and arr[mid] >= arr[mid - 1]:
        return mid
    elif arr[mid] < arr[mid + 1]:
        return find_peak_helper(arr, mid + 1, max)
    else:
        return find_peak_helper(arr, min, mid - 1)

arr = [1, 2, 3, 3, 2, 1]
print(f"A peak point is: {arr[find_peak_ix(arr)]}")

