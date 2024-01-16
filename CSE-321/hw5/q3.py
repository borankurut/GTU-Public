def align_sequences(sequence1, sequence2, insertion_deletion_cost=1, substitution_cost=3):
    m = len(sequence1) + 1  
    n = len(sequence2) + 1 

    dp_matrix = [[0] * n for _ in range(m)]

    for i in range(1, m):
        dp_matrix[i][0] = i * insertion_deletion_cost

    for j in range(1, n):
        dp_matrix[0][j] = j * insertion_deletion_cost

    for i in range(1, m):
        for j in range(1, n):
            insertion_deletion = dp_matrix[i-1][j-1] + substitution_cost if sequence1[i-1] != sequence2[j-1] else dp_matrix[i-1][j-1]
            
            insertion = dp_matrix[i-1][j] + insertion_deletion_cost
            
            deletion = dp_matrix[i][j-1] + insertion_deletion_cost
            
            dp_matrix[i][j] = min(insertion_deletion, insertion, deletion)

    i, j = m - 1, n - 1
    operations_sequence = []

    while i > 0 or j > 0:
        if i > 0 and j > 0 and dp_matrix[i][j] == dp_matrix[i-1][j-1] and sequence1[i-1] == sequence2[j-1]:
            operations_sequence.append("Match")
            i -= 1
            j -= 1
        elif i > 0 and dp_matrix[i][j] == dp_matrix[i-1][j] + insertion_deletion_cost:
            operations_sequence.append("Insert")
            i -= 1
        else:
            operations_sequence.append("Delete")
            j -= 1

    operations_sequence.reverse()

    return dp_matrix[m-1][n-1], operations_sequence

sequence1 = "ACGT"
sequence2 = "AGT"
insertion_deletion_cost = 1
substitution_cost = 3

min_cost, operations_sequence = align_sequences(sequence1, sequence2, insertion_deletion_cost, substitution_cost)
print("Minimum Cost:", min_cost)
print("Operations Sequence:", operations_sequence)


