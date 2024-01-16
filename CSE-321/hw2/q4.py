M = 6
N = 6

bipartiteGraph = [
    [0, 1, 1, 0, 0, 0],
    [1, 0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0, 0],
    [0, 0, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 1]
]

def bipartite_match(u, visited, assign):
    for v in range(N):
        if bipartiteGraph[u][v] and not visited[v]:
            visited[v] = True
            if assign[v] < 0 or bipartite_match(assign[v], visited, assign):
                assign[v] = u
                return True
    return False

def max_match():
    assign = [-1] * N
    count = 0

    for u in range(M):
        visited = [False] * N
        if bipartite_match(u, visited, assign):
            count += 1

    return count

print(max_match())

