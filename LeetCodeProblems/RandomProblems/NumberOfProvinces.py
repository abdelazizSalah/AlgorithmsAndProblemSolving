import numpy as np

'''
    Lets write the algorithm here: 
    1. read the input
    2. construct the graph in terms of list
    3. build a visit array
    4. iterate over all nodes. 
        4.1 if the node is not visited
            4.1.1 apply dfs.
            4.1.2 increment the number of components. 
    5. return the number of components. 
'''


def dfs(graph, vis, src):
    if vis[src]:
        return

    vis[src] = True

    for neighbour in graph[src]:
        if vis[neighbour] == False:
            dfs(graph=graph, vis=vis, src=neighbour)


# 1. read the input.
graph = input('insert the graph: ').split('  ')
newGraph = []
for g in graph:
    g = g.split(',')
    newGraph.append(g)

# 2. construct the graph
n = len(newGraph)
graph = [[] for i in range(n)]
for i in range(n):
    for j in range(n):
        newGraph[i][j] = int(newGraph[i][j])
        if newGraph[i][j] == 1 and i != j:
            graph[i].append(j)


# 3. Build a visited array
visited = np.zeros(n)

# 4. iterate over all nodes and apply the algo
numberOfComponents = 0
for i in range(n):
    if (visited[i] == 0):
        numberOfComponents += 1
        dfs(graph=graph, vis=visited, src=i)

print(numberOfComponents)
