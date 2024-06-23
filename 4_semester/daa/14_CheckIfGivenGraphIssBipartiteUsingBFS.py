from collections import deque, defaultdict

def is_bipartite(graph):
    color = {}
    
    def bfs(start_node):
        queue = deque([start_node])
        color[start_node] = 0  
        
        while queue:
            node = queue.popleft()
            current_color = color[node]
            next_color = 1 - current_color  
            
            for neighbor in graph[node]:
                if neighbor not in color:
                    color[neighbor] = next_color
                    queue.append(neighbor)
                elif color[neighbor] == current_color:
                    return False  

        return True
    
    for node in graph:
        if node not in color:
            if not bfs(node):
                return False  
    
    return True

graph = {
    0: [1, 3],
    1: [0, 2],
    2: [1, 3],
    3: [0, 2],
    4: [5],
    5: [4]
}

result = is_bipartite(graph)
print(result)

# Time Complexity: O(V+E)
# Auxiliary space: O(V)