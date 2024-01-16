disc_function = [2, 1, 2, -2, 1, -1, 1]

def sum_of_interval(disc_function, i0, i1):
    if(i1 == i0):
        return disc_function[i0]
    else:
        return disc_function[i0] + sum_of_interval(disc_function, i0+1, i1) 

def largest_total(disc_function):
    return largest_total_helper(disc_function, 0, 0)

def largest_total_helper(disc_function, x, y):
    if(x == y):
        return largest_total_helper(disc_function, 0, y + 1)

    elif y == len(disc_function):
        return float('-inf'), 0, 0

    current_largest = sum_of_interval(disc_function, x, y)

    next_largest, nx, ny = largest_total_helper(disc_function, x+1, y)

    if(next_largest > current_largest):
        return next_largest, nx, ny
    else:
        return current_largest, x, y

largest, x, y = largest_total(disc_function)

print(f"The maximum total area is [{x},{y}] = {largest}")

