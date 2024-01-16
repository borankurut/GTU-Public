def exhaustive_search(assembly_sequence, current_position, energy_matrix, visited, total_energy):
    n = len(assembly_sequence)
    
    # all parts are assembled, return
    if len(visited) == n:
        return assembly_sequence, total_energy
    
    #initialize
    optimal_sequence = None
    min_total_energy = float('inf')
    
    # iterate all possible next parts
    for i in range(n):
        if i not in visited:
            # calculate energy cost for next part
            energy_cost = energy_matrix[current_position][assembly_sequence[i]]
            
            # recursively compute the next part
            new_sequence, new_energy = exhaustive_search(assembly_sequence, i, energy_matrix, visited + [i], total_energy + energy_cost)
            
            # update optimum sequence and minimum total energy if the current sequence is more efficient
            if new_energy < min_total_energy:
                optimal_sequence = new_sequence
                min_total_energy = new_energy
    
    return optimal_sequence, min_total_energy


optimal_sequence, min_total_energy = exhaustive_search(assembly_sequence, 0, energy_matrix, [], 0)

