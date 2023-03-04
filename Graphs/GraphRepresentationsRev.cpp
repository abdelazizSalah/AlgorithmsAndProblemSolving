#include <bits/stdc++.h>
using namespace std;

void addingNewEdgeForMatrixRepresentationOfDirectedGraphs(vector<vector<int>> &Graph, int src, int dest, int weight)
{
    src--;
    dest--;
    Graph[src][dest] = weight;
}
void addingNewEdgeForMatrixRepresentationOfUndirectedGraphs(vector<vector<int>> &Graph, int src, int dest, int weight)
{
    src--;
    dest--;
    Graph[src][dest] = Graph[dest][src] = weight;
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

void generatingTheGraphInMatrixForDirected()
{
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    vector<vector<int>> Graph(noOfNodes, vector<int>(noOfNodes, 0));
    for (int i = 0; i < noOfEdges; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        addingNewEdgeForMatrixRepresentationOfDirectedGraphs(Graph, src, dest, weight);
    }
    printingGraphInMatrixForm(Graph);
}
void generatingTheGraphInMatrixForUndirected()
{
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    vector<vector<int>> Graph(noOfNodes, vector<int>(noOfNodes, 0));
    for (int i = 0; i < noOfEdges; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        addingNewEdgeForMatrixRepresentationOfUndirectedGraphs(Graph, src, dest, weight);
    }
    printingGraphInMatrixForm(Graph);
}

/// representing the graph in the adjacency form
void addingNewEdgeForAdjacencyListRepresentationOfDirectedGraphs(vector<vector<pair<int, int>>> &Graph, int src, int dest, int weight)
{
    src--;
    dest--;
    Graph[src].push_back({dest, weight});
}
void addingNewEdgeForAdjacencyListRepresentationOfUndirectedGraphs(vector<vector<pair<int, int>>> &Graph, int src, int dest, int weight)
{
    src--;
    dest--;
    Graph[src].push_back({dest, weight});
    Graph[dest].push_back({src, weight});
}

void printingGraphInAdjacencyListForm(const vector<vector<pair<int, int>>> &Graph)
{
    for (int i = 0; i < Graph.size(); i++)
    {
        cout << i + 1 << ": ";
        for (auto it : Graph[i])
            cout << "(" << it.first + 1 << ", " << it.second << "), ";
        cout << '\n';
    }
}

void generatingTheGraphInAdjacencyListForDirected()
{
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    vector<vector<pair<int, int>>> Graph(noOfNodes);
    for (int i = 0; i < noOfEdges; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        addingNewEdgeForAdjacencyListRepresentationOfDirectedGraphs(Graph, src, dest, weight);
    }
    printingGraphInAdjacencyListForm(Graph);
}
void generatingTheGraphInAdjacencyListForUndirected()
{
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    vector<vector<pair<int, int>>> Graph(noOfNodes);
    for (int i = 0; i < noOfEdges; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        addingNewEdgeForAdjacencyListRepresentationOfUndirectedGraphs(Graph, src, dest, weight);
    }
    printingGraphInAdjacencyListForm(Graph);
}

int main()
{
    generatingTheGraphInAdjacencyListForDirected();
}