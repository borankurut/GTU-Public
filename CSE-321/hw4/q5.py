def find_min_max(resources):
    if len(resources) == 1:
        return resources[0], resources[0]

    mid = len(resources) // 2
    l_resources = resources[:mid]
    r_resources = resources[mid:]

    l_max, l_min = find_min_max(l_resources)
    r_max, r_min = find_min_max(r_resources)

    max_resource = max(l_max, r_max)
    min_resource = min(l_min, r_min)

    return max_resource, min_resource


needed_resources_of_tasks = [10, 100, 8, 3, 99, 2, 1]

max_resource, min_resource = find_min_max(needed_resources_of_tasks)

print(f"Task with maximum resources: {max_resource}")
print(f"Task with minimum resources: {min_resource}")

