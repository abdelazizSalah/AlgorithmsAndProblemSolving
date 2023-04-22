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

void printMatrixRepresentation(const vector<vector<int>> &graph)
{
    for (auto row : graph)
    {
        for (auto col : row)
            cout << col << " ";
        cout << endl;
    }
}
int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    vector<vector<int>> graph = matrixRepresentation(numberOfNodes, numberOfEdges, false, false, true);
    printMatrixRepresentation(graph);
    return 0;
}