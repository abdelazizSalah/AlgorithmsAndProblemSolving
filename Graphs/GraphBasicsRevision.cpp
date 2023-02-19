#include <bits/stdc++.h>
using namespace std;

/// implementing dfs using recursion
void dfs(const vector<vector<int>> &Graph, vector<bool> &visited, int src)
{
    // setting the base case
    if (visited[src])
        return;

    // mark the node as visited
    visited[src] = true;

    // iterating over all nodes and calling dfs on them
    for (auto node : Graph[src])
        if (!visited[node])
            dfs(Graph, visited, node);
}

/// implementing bfs using queue
void bfs(const vector<vector<int>> &Graph, vector<bool> &visited, int src)
{
    // setting the base case
    if (visited[src])
        return;

    // creating a queue to store the nodes
    queue<int> q;

    // pushing the source node into the queue
    q.push(src);

    // iterating over the queue
    while (!q.empty())
    {
        // getting the front node
        int node = q.front();

        // popping the front node
        q.pop();

        // checking if the node is visited or not
        if (visited[node])
            continue;

        // marking the node as visited
        visited[node] = true;

        // iterating over all neighbours and pushing them into the queue
        for (auto it : Graph[node])
            if (!visited[it])
                q.push(it);
    }
}

void bfsRec(const vector<vector<int>> &Graph, queue<int> &Q, vector<bool> &vis, int src)
{
    // setting the base case
    if (vis[src])
        return;

    // iterating over all nodes and calling dfs on them
    for (auto node : Graph[src])
        if (!vis[node])
            Q.push(node);

    // marking the node as visited
    vis[src] = true;

    // iterating all in the queue
    while (Q.size())
    {
        // getting the front node
        int node = Q.front();

        // poping it from the queue
        Q.pop();

        // calling the function recursively
        bfsRec(Graph, Q, vis, node);
    }
}

// representing the graph as a matrix
vector<vector<int>> representingAsMatrix(int N)
{
    // creating a matrix to represent the graph
    vector<vector<int>> Graph(N, vector<int>(N, 0));

    // taking the edges as input
    int edges;
    cin >> edges;

    // taking the edges as input
    while (edges--)
    {
        // taking the source and destination
        int src, dest;
        cin >> src >> dest;

        // setting the edge
        Graph[src][dest] = Graph[dest][src] = 1;
    }

    // returning the graph
    return Graph;
}

// representing the graph as a list
vector<vector<int>> representingAsList(int N)
{
    // creating a list to represent the graph
    vector<vector<int>> Graph(N);

    // taking the edges as input
    int edges;
    cin >> edges;

    // taking the edges as input
    while (edges--)
    {
        // taking the source and destination
        int src, dest;
        cin >> src >> dest;

        // setting the edge
        Graph[src].push_back(dest);
        Graph[dest].push_back(src);
    }

    // returning the graph
    return Graph;
}

int main()
{
}