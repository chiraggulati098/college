graph = {
    '5' : ['3','7'],
    '3' : ['2', '4'],
    '7' : ['8'],
    '2' : [],
    '4' : ['8'],
    '8' : []
}

visited = set()
queue = []

def bfs(visited, graph, node):
    visited.add(node)
    queue.append(node)

    while queue:         
        cur = queue.pop(0) 
        print (cur, end = " ") 

        for nei in graph[cur]:
            if nei not in visited:
                visited.add(nei)
                queue.append(nei)


bfs(visited, graph, '5')