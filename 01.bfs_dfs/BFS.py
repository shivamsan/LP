graph = {
  '1' : ['2','3'],
  '2' : ['1', '4'],
  '3' : ['1', '4','7'],
  '4' : ['2','5','3','6'],
  '5' : ['4'],
  '6' : ['4'],
  '7' : ['3']
}

visited = [] # List for visited nodes.
queue = []     #Initialize a queue

def bfs(visited, graph, node): #function for BFS
  visited.append(node)
  queue.append(node)

  while queue:          # Creating loop to visit each node
    m = queue.pop(0) 
    print (m, end = " ") 

    for neighbour in graph[m]:
      if neighbour not in visited:
        visited.append(neighbour)
        queue.append(neighbour)

# Driver Code
print("Following is the Breadth-First Search")
bfs(visited, graph, '1')    # function calling