class Graph:
    def __init__(self):
        self.graph = {}
        self.min_latency = float('inf')
        self.min_route = ""

    def add_edge(self, src, dest, latency):
        if src not in self.graph:
            self.graph[src] = []
        self.graph[src].append((dest, latency))

    def exhaustive_search_all_routes(self, src, dest, current_path, visited, all_routes):
        visited[src] = True

        if src == dest:
            route_str = ''.join(node for node, _ in current_path)
            total_latency = sum(lat for _, lat in current_path)
            all_routes.append((route_str, total_latency))
        else:
            if src in self.graph:
                for neighbor, latency in self.graph[src]:
                    if not visited.get(neighbor, False):
                        self.exhaustive_search_all_routes(neighbor, dest, current_path + [(neighbor, latency)], visited, all_routes)

        visited[src] = False

    def find_all_routes(self, src, dest):
        visited = {node: False for node in self.graph}
        all_routes = []
        self.exhaustive_search_all_routes(src, dest, [(src, 0)], visited, all_routes)

        for route, latency in all_routes:
            print(f"{route}: {latency}")
            if(latency < self.min_latency):
                self.min_latency = latency
                self.min_route = f"{route}: {latency}"

network = Graph()
network.add_edge('A', 'B', 2)
network.add_edge('A', 'C', 5)
network.add_edge('B', 'D', 1)
network.add_edge('C', 'D', 3)
network.add_edge('D', 'E', 4)

source = 'A'
destination = 'E'

network.find_all_routes(source, destination)

print(f"min_route: ({network.min_route})")

