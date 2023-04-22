/*
Boruvka's Algorithm:
    Boruvka's algorithm is a parallel algorithm that works by repeatedly
    selecting the minimum-weight edge from each connected component
    of the graph and merging them into a single component.
    This process continues until there is only one connected component left
    ,which corresponds to the MST. To accomplish this, the algorithm maintains
    a list of edges for each connected component and selects the minimum-weight edge
    from each list.

All three of these algorithms have a time complexity of O(E log E) or O(E log V), where E is the number of edges and V is the number of vertices in the graph. The choice of algorithm depends on the specific properties of the graph and the constraints of the problem being solved.
.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<pair<int, int>> adj[MAXN]; // adjacency list of the graph
int parent[MAXN], cheapest[MAXN]; // parent of each vertex in the MST, cheapest edge to each component in the current forest

int find(int u)
{
    if (parent[u] == u)
        return u;                       // if u is the root of its tree, return u
    return parent[u] = find(parent[u]); // otherwise, recursively find the root of u's tree and update u's parent to the root
}

void merge(int u, int v, int w)
{
    u = find(u); // find the root of u's tree
    v = find(v); // find the root of v's tree
    if (u != v)
    { // if u and v are in different trees
        if (cheapest[u] == -1 || w < adj[u][cheapest[u]].second)
            cheapest[u] = adj[u].size(); // update cheapest edge to u if necessary
        if (cheapest[v] == -1 || w < adj[v][cheapest[v]].second)
            cheapest[v] = adj[v].size(); // update cheapest edge to v if necessary
        adj[u].push_back({v, w});        // add edge (u, v) to the graph
        adj[v].push_back({u, w});        // add edge (v, u) to the graph
        parent[u] = v;                   // make v the parent of u
    }
}

int boruvka()
{
    int ans = 0; // total weight of the MST
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;    // initialize the parent of each vertex to itself
        cheapest[i] = -1; // initialize cheapest edge to each component to -1 (i.e. no edge)
    }
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 1; i <= n; i++)
        {
            if (find(i) != find(1))
            {                                                                             // if vertex i is not already in the same component as vertex 1
                int u = i, v = adj[i][cheapest[i]].first, w = adj[i][cheapest[i]].second; // get the cheapest edge from vertex i to another component
                merge(u, v, w);                                                           // merge the two components
                ans += w;                                                                 // add the weight of the edge to the MST
                changed = true;                                                           // indicate that a change has been made
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << boruvka() << endl;
    return 0;
}
