import numpy as np
# 1. Read the Input
directions = input('insert the directions: ').split('  ')
size = len(directions)

# 2. Create a boolean list with shape = len of node, to mark the safe nodes.
safeNodes = np.zeros(size)

# 3. Build the directed unweighted graph
graph = {}
for i in range(size):
    g = directions[i].split(',')
    # if len(g) == 0:
    if g[0] == '.':
        graph.update({i: []})
        continue
    for neibour in g:
        if(i not in graph):
            graph.update({i: [int(neibour)]})
        else:
            graph[i].append(int(neibour))


'''
    4. the solution algorithm:
        1. remove all the nodes which has zero outgoings, and store the node value
            in solution list. 
        2. remove that edge from all other nodes. 
        3. repeat till no more nodes can be removed. 
        4. sort the solution list and output it. 
'''
Change = True
while Change:  # O(k) -> k # of iterations.
    Change = False
    for key in graph:  # O(n) -> n # of nodes
        if len(graph[key]) == 0:
            Change = True
            safeNodes[key] = 1
            for node in graph:  # O(m) -> m # of neighbours
                try:
                    graph[node].remove(key)
                except:
                    continue
            graph.pop(key)
            graph = graph
outputList = []
for i in range(size):
    if(safeNodes[i]):
        outputList.append(i)

print(outputList)  # overall Complexity = O (m * n * k)

''' 
    4. Iterate over all nodes:
        1. Iterate over all neighbours 
            1. if all safe
                mark this node as safe
# '''
# for i in range(size):
#     safe = True
#     for neighbour in graph[i]:
#         if (safeNodes[neighbour] != 1):
#             safe = False
#             break
#     if safe:
#         safeNodes[i] = True

# print(safeNodes == 1)
