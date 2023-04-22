#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixRepresentation(int numberOfNodes, int numberOfEdges, bool directed = false, bool zeroBased = false, bool weighted = false)
{
    vector<vector<int>> graph(numberOfNodes, vector<int>(numberOfNodes));
    for (int i = 0; i < numberOfEdges; i++)
    {
        int src, dest;
        cin >> src >> dest;
        if (!zeroBased)
        {
            src--;
            dest--;
        }
        if (weighted)
        {
            int weight;
            cin >> weight;
            if (directed)
                graph[src][dest] = weight;
            else
            {
                graph[src][dest] = weight;
                graph[dest][src] = weight;
            }
        }
        else
        {
            if (directed)
                graph[src][dest] = 1;
            else
            {
                graph[src][dest] = 1;
                graph[dest][src] = 1;
            }
        }
    }
    return graph;
}
vector<vector<pair<int, int>>> listRepresentation(int numberOfNodes, int numberOfEdges, bool directed = false, bool zeroBased = false, bool weighted = false)
{
    vector<vector<pair<int, int>>> graph(numberOfNodes); // we push {dest, weight}

    for (int i = 0; i < numberOfEdges; i++)
    {
        int src, dest;
        cin >> src >> dest;
        if (!zeroBased)
        {
            src--;
            dest--;
        }
        if (weighted)
        {
            int weight;
            cin >> weight;
            if (directed)
                graph[src].push_back({dest, weight});
            else
            {
                graph[src].push_back({dest, weight});
                graph[dest].push_back({src, weight});
            }
        }
        else
        {
            if (directed)
                graph[src].push_back({dest, 1});
            else
            {
                graph[src].push_back({dest, 1});
                graph[dest].push_back({src, 1});
            }
        }
    }
    return graph;
}

void printMatrixRepresentation(const vector<vector<int>> &graph)
{
    for (auto row : graph)
    {
        for (auto col : row)
            cout << col << " ";
        cout << endl;
    }
}

void printListRep(const vector<vector<pair<int, int>>> &graph)
{
    int sz = graph.size();
    for (int i = 0; i < sz; i++)
    {
        cout << "Neighbours of node " << i + 1 << " are: ";
        for (auto pair : graph[i])
            cout << "(" << pair.first + 1 << ", " << pair.second << ") ";
        cout << endl;
    }
}

void dfsMatrix(const vector<vector<int>> &graph, vector<bool> &visited, int nodeToVisit)
{
    visited[nodeToVisit] = true;
    int sz = graph.size();
    cout << nodeToVisit + 1 << ' ';
    for (int i = 0; i < sz; i++)
    {
        if (!visited[i] && graph[nodeToVisit][i] > 0)
        {
            // this is a valid neighbour.
            // lets visit him :)
            dfsMatrix(graph, visited, i);
        }
    }
}
void dfsList(const vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int nodeToVisit)
{
    visited[nodeToVisit] = true;
    int sz = graph.size();
    cout << nodeToVisit + 1 << ' ';
    for (pair<int, int> pair : graph[nodeToVisit])
    {
        if (!visited[pair.first])
        {
            // lets visit our neighbours :)
            dfsList(graph, visited, pair.first);
        }
    }
}

int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    auto mat = listRepresentation(numberOfNodes, numberOfEdges, false, false, true);
    vector<bool> visited(numberOfNodes);
    dfsList(mat, visited, 0);
    return 0;
}