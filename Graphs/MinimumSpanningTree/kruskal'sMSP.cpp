/*
 Kruskal's Algorithm:
    Kruskal's algorithm is also a greedy algorithm that sorts all
    the edges in the graph by weight and then
    adds the edges to the MST one by
    one, starting from the lowest-weight edge and
    adding edges that do not form a cycle. To accomplish this, the algorithm uses a disjoint-set data structure to keep track of the connected components of the graph.


All three of these algorithms have a time complexity of O(E log E) or O(E log V),
where E is the number of edges and V is the number of vertices in the graph.
The choice of algorithm depends on the specific properties of the graph and the constraints of the problem being solved.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<pair<int, pair<int, int>>> edges; // list of edges in the graph
int parent[MAXN];                        // parent of each vertex in the disjoint-set data structure

int find(int u)
{
    if (parent[u] == u)
        return u;                       // if u is the root of its tree, return u
    return parent[u] = find(parent[u]); // otherwise, recursively find the root of u's tree and update u's parent to the root
}

void unite(int u, int v)
{
    u = find(u); // find the root of u's tree
    v = find(v); // find the root of v's tree
    if (u != v)
        parent[u] = v; // if u and v are in different trees, make v the parent of u
}

int kruskal()
{
    int ans = 0; // total weight of the MST
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i; // initialize the parent of each vertex to itself
    }
    sort(edges.begin(), edges.end()); // sort the edges by weight
    for (auto [w, e] : edges)
    {
        int u = e.first, v = e.second;
        if (find(u) != find(v))
        {                // if u and v are not already in the same tree
            ans += w;    // add the weight of the edge to the MST
            unite(u, v); // unite the trees of u and v
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
        edges.push_back({w, {u, v}});
    }
    cout << kruskal() << endl;
    return 0;
}
