def find_first_even(arr):
    for num in arr:
        if num % 2 == 0:
            return num
    return None  # Return None if no even element is found

my_array = [1, 3, 5, 7, 2]
result = find_first_even(my_array)

print(result)

