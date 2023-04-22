/*
There are several algorithms for finding the Minimum Spanning Tree (MST) of a graph, some of which are more efficient than others. Here are some of the most well-known algorithms for finding MSTs that rely on prime numbers:

    Prim's Algorithm:
    Prim's algorithm is a greedy algorithm that starts from
    an arbitrary vertex and repeatedly adds the minimum-weight
    edge that connects an unvisited vertex to the
    set of visited vertices until all vertices are visited.
    To accomplish this, the algorithm maintains a priority queue of edges, prioritized by their weights. In each step, it selects the edge with the lowest weight and adds its adjacent vertex to the set of visited vertices.

All three of these algorithms have a time complexity of O(E log E) or O(E log V), where E is the number of edges and V is the number of vertices in the graph. The choice of algorithm depends on the specific properties of the graph and the constraints of the problem being solved.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<pair<int, int>> adj[MAXN]; // adjacency list of the graph

int prim()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // priority queue to store the edges by weight
    vector<bool> visited(n + 1, false); // keep track of visited vertices
    int ans = 0;                        // total weight of the MST
    visited[1] = true;                  // start from vertex 1
    for (auto u : adj[1])
    {
        pq.push(u); // add all edges incident to vertex 1 to the priority queue
    }
    while (!pq.empty())
    {
        auto [w, v] = pq.top(); // get the minimum-weight edge from the priority queue
        pq.pop();
        if (visited[v])
            continue; // if the endpoint has been visited already, skip
        visited[v] = true;
        ans += w;
        for (auto u : adj[v])
        {
            if (!visited[u.first])
                pq.push(u); // add all edges incident to the newly visited vertex to the priority queue
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // since the graph is undirected
    }
    cout << prim() << endl;
    return 0;
}
