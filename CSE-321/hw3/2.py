def calculate_cost(assignment): # I assume this is implemented
    return 0

def permutations(users, processes, processors):
    per = []
    for user in users:
        for process in processes:
            for processor in processors:
                per.append([user, process, processor])

    return per;

def exhaustive_search(users, processes, processors):
    best_assignment = None
    min_cost = float('inf')

    # generate all possible combinations of job assignments
    for assignment in generate_all_assignments(users, processes, processors):
        # calculate the cost of the current assignment
        current_cost = calculate_cost(assignment)

        # update the optimum solution if current assignment is better
        if current_cost < min_cost:
            best_assignment = assignment
            min_cost = current_cost

    return best_assignment


def generate_all_assignments(users, processes, processors):
    return permutations(users, processes, processors)

