#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

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
        if (node != parent)
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

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int noOfEdges = edges.size();
    vector<vector<int>> Graph(noOfEdges);
    for (auto &edge : edges)
        edge[0]--, edge[1]--;
    for (int i = 0; i < noOfEdges; i++)
    {
        Graph[edges[i][0]].push_back(edges[i][1]);
        Graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> visited(noOfEdges);
    auto res = cycleExists(Graph, edges, visited);
    return res;
}
