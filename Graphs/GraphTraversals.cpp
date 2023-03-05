#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> GraphList;
vector<vector<int>> GraphMatrix;
vector<bool> visited;
void DFSMatrix(int node)
{
    if (visited[node])
        return;

    visited[node] = true;
    int sz = GraphMatrix[node].size();
    for (int i = 0; i < sz; i++)
        if (GraphMatrix[node][i] != 0)
            DFSMatrix(i);

    cout << node + 1 << " ";
}

void DFSForAdjacentList(int node)
{
    if (visited[node])
        return;

    visited[node] = true;
    for (pair<int, int> neighbour : GraphList[node])
        DFSForAdjacentList(neighbour.first);

    cout << node + 1 << " ";
}

void printingGraphInMatrixForm(const vector<vector<int>> &Graph)
{
    for (int i = 0; i < Graph.size(); i++)
    {
        for (int j = 0; j < Graph.size(); j++)
            cout << Graph[i][j] << " ";
        cout << '\n';
    }
}

void printingGraphInAdjacencyListForm(const vector<vector<pair<int, int>>> &Graph)
{
    for (int i = 0; i < Graph.size(); i++)
    {
        cout << i + 1 << " -> ";
        for (int j = 0; j < Graph[i].size(); j++)
            cout << Graph[i][j].first + 1 << " " << Graph[i][j].second << " | ";
        cout << '\n';
    }
}
int NumberOfConnectedComponentsusingList(vector<vector<int>> &graph, int N, vector<bool> &vis)
{
    int cntr = 0;
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            cntr++;
            DFSForAdjacentList(i);
        }
    return cntr;
}

/// bfs
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr + 1 << " ";
        for (pair<int, int> neighbour : GraphList[curr])
            if (!visited[neighbour.first])
            {
                visited[neighbour.first] = true;
                q.push(neighbour.first);
            }
    }
}

int main()
{
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    GraphList.resize(noOfNodes);
    visited.resize(noOfNodes, false);
    for (int i = 0; i < noOfEdges; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        GraphList[--src].push_back({--dest, weight});
    }

    printingGraphInAdjacencyListForm(GraphList);
    bfs(0);
    return 0;
}