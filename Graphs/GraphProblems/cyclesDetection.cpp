#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// Accepted Solution ;D
pair<vector<pair<int, int>>, pair<int, bool>> dfs(const vector<vector<int>> &G, vector<bool> &vis, int src, int parent)
{
    if (vis[src])
    {
        // cycle is detected
        vector<pair<int, int>> res;
        res.push_back({src, parent});
        return {res, {src, false}};
    }

    vis[src] = true;
    pair<vector<pair<int, int>>, pair<int, bool>> finalRes;
    for (auto node : G[src])
        // skip parent visiting.
        if (finalRes.second.second)
            return finalRes;
        else if (node != parent)
        {
            finalRes = dfs(G, vis, node, src);
            if (finalRes.first.size() && !finalRes.second.second)
            {
                if (finalRes.second.first == src)
                    finalRes.second.second = true; // we reached the root of the cycle.
                // push current edge
                finalRes.first.push_back({node, src});
                // return the cycle
                return finalRes;
            }
            else if (finalRes.second.second)
                return finalRes;
        }
    // no cycles are detected, return empty list.
    return finalRes;
}

vector<int> cycleExists(const vector<vector<int>> &G, const vector<vector<int>> &edges, vector<bool> &vis)
{
    // list representation
    int sz = G.size();
    pair<vector<pair<int, int>>, pair<int, bool>> cycles = dfs(G, vis, 0, -1);
    int edgesSize = edges.size();
    for (int i = edgesSize - 1; i >= 0; i--)
        for (auto edge : cycles.first)
            if ((edge.first == edges[i][0] && edge.second == edges[i][1]) || (edge.second == edges[i][0] && edge.first == edges[i][1]))
            {
                vector<int> res;
                res.push_back(edges[i][0] + 1);
                res.push_back(edges[i][1] + 1);
                return res;
            }

    return vector<int>();
}

void printGraph(const vector<vector<int>> &G)
{
    int sz = G.size();
    for (int i = 0; i < sz; i++)
    {
        cout << i << " --> ";
        for (int neighbour : G[i])
            cout << neighbour << " , ";
        cout << endl;
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int noOfEdges = edges.size();
    vector<vector<int>> Graph(noOfEdges);
    for (int i = 0; i < noOfEdges; i++)
    {
        Graph[edges[i][0]].push_back(edges[i][1]);
        Graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> visited(noOfEdges);
    return cycleExists(Graph, edges, visited);
}

int main()
{
    DPSolver;
    // read the graph, and store it as list.
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    // vector<vector<int>> Graph(noOfNodes);
    // vector<bool> visited(noOfNodes);
    // for (int loopCounter = 0; loopCounter < noOfEdges; loopCounter++)
    // {
    //     // read the edges
    //     int src, dest;
    //     cin >> src >> dest;
    //     // undirected so we have to place in both -> zeroBased
    //     Graph[src].push_back(dest);
    //     Graph[dest].push_back(src);
    // }

    // cout << boolalpha << cycleExists(Graph, visited);

    vector<vector<int>> edges(noOfEdges);
    for (int i = 0; i < noOfEdges; i++)
    {
        int src, dest;
        cin >> src >> dest;
        src--, dest--;
        edges[i].push_back(src);
        edges[i].push_back(dest);
    }
    auto res = findRedundantConnection(edges);
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}

// Faster Solution ;)
vector<int> parent;

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        int parent_u = find(u), parent_v = find(v);
        if (parent_u == parent_v)
            return edge;
        parent[parent_u] = parent_v;
    }

    return {};
}