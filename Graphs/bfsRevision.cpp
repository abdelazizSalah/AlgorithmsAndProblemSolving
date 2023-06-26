#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

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
