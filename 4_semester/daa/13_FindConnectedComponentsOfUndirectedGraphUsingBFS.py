from collections import deque, defaultdict

def bfs_connected_components(graph):
    def bfs(start_node):
        queue = deque([start_node])
        visited.add(start_node)
        component = []
        
        while queue:
            node = queue.popleft()
            component.append(node)
            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        return component

    visited = set()
    components = []
    
    for node in graph:
        if node not in visited:
            component = bfs(node)
            components.append(component)
    
    return components

graph = {
    0: [1, 2],
    1: [0, 3],
    2: [0],
    3: [1],
    4: [5],
    5: [4]
}

components = bfs_connected_components(graph)
print(components)

# Time Complexity: O(V+E)
# Auxiliary space: O(V)