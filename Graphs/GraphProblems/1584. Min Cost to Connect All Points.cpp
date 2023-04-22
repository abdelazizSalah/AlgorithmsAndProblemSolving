#include <bits/stdc++.h>
using namespace std;
vector<int> parents;

int findSet(int n)
{
    /*
        recursive function which returns the parent of certain node.
    */

    // base case is that the node has no parent, so it should return itself.
    if (parents[n] == n)
        return n;

    // recursive case, we store the parent of n as the returned from the recursive function
    return parents[n] = findSet(parents[n]);
}

void unionSets(int u, int v)
{
    int parentOfN = findSet(u);
    int parentOfV = findSet(v);
    // if they are not equal, we can set the parent of any of them as the other
    if (parentOfN != parentOfV)
    {
        // then they are not in the same set
        parents[parentOfN] = parentOfV;
    }
}

int kruskal(vector<pair<int, pair<int, int>>> &edges)
{
    // 1- define each node as a set
    int sz = edges.size();
    parents = vector<int>(sz + 1);
    for (int i = 0; i <= edges.size(); i++)
    {
        parents[i] = i;
    }
    // 2- sort edges ascendingly
    sort(edges.begin(), edges.end());

    // 3- iterating over all edges
    int ans = 0;
    for (pair<int, pair<int, int>> edge : edges)
    {
        // getting the nodes
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;
        // check if they are not in the same set
        if (findSet(u) != findSet(v))
        {
            // add the weight of that edge
            ans += w;

            // union the two sets
            unionSets(u, v);
        }
    }

    // return result
    return ans;
}
int manhattanDistance(pair<int, int> src, pair<int, int> des)
{
    return abs(src.first - des.first) + abs(src.second - des.second);
}

int minCostConnectPoints(vector<vector<int>> points)
{
    // preparing the edges to be evaluated
    // manhaten distance = |xi - xj| + |yi - yj|
    vector<pair<int, pair<int, int>>> edges;
    int sz = points.size();
    for (int i = 0; i < sz; i++)
        for (int j = i + 1; j < sz; j++)
            edges.push_back({manhattanDistance({points[i][0], points[i][1]}, {points[j][0], points[j][1]}), {i, j}});

    cout << kruskal(edges);
}

int main()
{
    vector<vector<int>> points = {{-1000000, -1000000}, {1000000, 1000000}};
    minCostConnectPoints(points);
}