pixels =[
        [200, 200, 200, 200, 200],
        [200, 200, 200, 200, 200],
        [200, 200, 200, 200, 200],
        [200, 200, 240, 200, 200],

]

def find_bright(pixels): 
    return find_bright_helper(0, 0, pixels)

def find_bright_helper(x, y, pixels):
    if(is_brightest(x,y,pixels)):
        return x, y
    if(x >= len(pixels[0])):
        if(y >= len(pixels)):
            return -1, -1
        else:
            return find_bright_helper(0, y+1, pixels)
    else:
        return find_bright_helper(x+1, y, pixels)

def is_brightest(x, y, pixels):
    if(x + 1 >= len(pixels[0]) or x - 1 < 0 or y + 1 >= len(pixels) or y - 1 < 0):
        return False

    else:
        return (pixels[y][x] > pixels[y-1][x] and 
                pixels[y][x] > pixels[y+1][x] and 
                pixels[y][x] > pixels[y][x-1] and 
                pixels[y][x] > pixels[y][x+1])

print(find_bright(pixels))

# O(i * j)
