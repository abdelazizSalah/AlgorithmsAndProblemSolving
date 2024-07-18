def valid_idx(rows, cols, i, j):
    return 0 <= i < rows and 0 <= j < cols

def dfs(graph, vis_nodes, num_rows, num_cols, i, j):
    # check if we are within valid range and this is a hole
    if not valid_idx(num_rows, num_cols, i, j) or graph[i][j] == '1':
        return False

    # check if we have already visited this node
    if vis_nodes.get((i, j), False):
        return False

    # mark this node as visited
    vis_nodes[(i, j)] = True

    # recursively visit all the neighbors
    dfs(graph, vis_nodes, num_rows, num_cols, i - 1, j)  # up
    dfs(graph, vis_nodes, num_rows, num_cols, i + 1, j)  # down
    dfs(graph, vis_nodes, num_rows, num_cols, i, j - 1)  # left
    dfs(graph, vis_nodes, num_rows, num_cols, i, j + 1)  # right

    return True

if __name__ == "__main__":
    graph = []
    num_rows = int(input())
    for _ in range(num_rows):
        s = input()
        graph.append(s)

    num_cols = len(graph[0])
    vis_nodes = {}
    num_of_components = 0
    for i in range(num_rows):
        for j in range(num_cols):
            if dfs(graph, vis_nodes, num_rows, num_cols, i, j):
                num_of_components += 1

    print(num_of_components)
