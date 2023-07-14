#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool checkIfValid(const vector<bool> &vis)
{
    int sz = vis.size();
    for (int i = 0; i < sz; i++)
        if (!vis[i])
            return false;

    return true;
}

void dfs(const vector<vector<int>> &G, vector<bool> &vis, int src)
{
    if (vis[src])
        return;

    vis[src] = true;

    for (auto nei : G[src])
        dfs(G, vis, nei);
}

int main()
{
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    // using list representation
    vector<vector<int>> Graph(noOfNodes);

    // reading the edges and building the graph
    for (int i = 0; i < noOfEdges; i++)
    {
        int room, keyNum;
        cin >> room >> keyNum;
        Graph[room].push_back(keyNum);
    }

    // creating a visited vector
    vector<bool> vis(noOfNodes);

    // applying dfs and check if we can visit all nodes.
    dfs(Graph, vis, 0);

    // check if valid
    cout << boolalpha << checkIfValid(vis);

    return 0;
}