def calc_discount(subset): # I assume this function is implemented
    return 0

def recursive_exhaustive(shops, subset, index):
    # index is out of bounds, we reached the end of the list
    if index == len(shops):
        return subset, calc_discount(subset)

    #include the current index and recursively compute the discount.
    subset.append(shops[index])
    included_subset, discount_include = recursive_exhaustive(shops, subset, index + 1)

    # remove the current shop from the subset and compute the discount recursively.
    subset.pop()
    excluded_subset, discount_exclude = recursive_exhaustive(shops, subset, index + 1)

    # compare the discounts and return the the higher discount
    if discount_include > discount_exclude:
        return included_subset, discount_include
    else:
        return excluded_subset, discount_exclude

