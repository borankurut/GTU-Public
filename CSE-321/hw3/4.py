coins = [1, 5, 10, 50, 100]

change = 344


def exhaustive_search(coins, change):
    toReturn = []
    coins.sort(reverse = True)
    sum = 0
    while sum < change:
        for i in range (len(coins)):
            if coins[i] <= change - sum:
                sum += coins[i]
                toReturn.append(coins[i])
                break

    return toReturn

print(exhaustive_search(coins, change))


