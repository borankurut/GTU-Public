def dynamic_programming_discount(set_of_stores, calc_discount):
    n = len(set_of_stores)
    
    dp_table = [0] * (n + 1)

    for i in range(1, n + 1):
        with_current_store = calc_discount(set_of_stores[i - 1]) + dp_table[i - 1]
        without_current_store = dp_table[i - 1]
        dp_table[i] = max(with_current_store, without_current_store)

    max_discount = dp_table[n]
    selected_stores = set()
    i = n

    while i > 0:
        if dp_table[i] != dp_table[i - 1]:
            selected_stores.add(set_of_stores[i - 1])
            i -= 2
        else:
            i -= 1

    return max_discount, selected_stores

