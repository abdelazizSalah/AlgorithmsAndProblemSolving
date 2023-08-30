/*
    @author: Abdelaziz Salah
    @date: 4/7/2023
    @describtion: this file contains the algorithms of dijekstra for finding
                        the shortest pathes from certain single source
    @algorithm:
    Dijekstra(G, W, s)
    1. Initialize_single_source(g, s)
    2. s= phi -> empty set contains the finshed nodes.
    3. Q = S.v -> heap which contains the verticies of the graph, but with sorting them ascendingly
    4. while Q.size
        1. u = extractMin(Q)
        2. s = s union {u} // mark the node as finshed.
        3. for each neighbour (nei) to that u vertex
            1. relax (u, nei, w)
*/
#include <bits/stdc++.h>
#define DPsolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct Node
{
    int distance;
    int parent;
    int ID;
};

// O(V) -> V is # of Nodes
void Initialize_single_source(vector<Node> &G, int source)
{
    /*
        @describtion: this is a common subroutine used to initialize all the nodes
                        distance to inf, and the parent to -1
                        and the distance of the source should be = 0
    */

    // iterate over all the nodes and initialize them as mentioned before.
    int id = 0;
    for (auto &node : G)
    {
        node.distance = INT_MAX;
        node.parent = -1;
        node.ID = id++;
    }

    // mark the distance of the source to zero
    G[source].distance = 0;
}

// O(1)
bool Relax(vector<Node> &G, int source, int destnation, int weight)
{
    /*
        @describtion: this is a common subrouting used to relax the edges under a condition:
                        if the weight from the source and the distance of the source was
                        less than the distance of the destination then we should
                        apply the relaxation operation
        @algorithm:
                make the parent of the destination as the source
                make the distance of the destination as the sum of the source distance and the weight
    */
    if (G[source].distance + weight < G[destnation].distance)
    {
        G[destnation].distance = G[source].distance + weight;
        G[destnation].parent = source;
        return true;
    }

    return false;
}

// O(V^2)
void printGraph(const vector<vector<pair<int, int>>> &G)
{
    int sz = G.size();
    for (int i = 0; i < sz; i++)
    {
        cout << "node# " << i + 1 << " neighbours: \n";
        for (auto &nei : G[i])
            cout << "neighbour ID: " << nei.first + 1 << " --- distance: " << nei.second << endl;
    }
}

// O(E + V)
void buildTheGraph(vector<vector<pair<int, int>>> &G)
{
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    // matrix representation -> undirected
    G = vector<vector<pair<int, int>>>(noOfNodes);

    // reading the weights
    for (int i = 0; i < noOfEdges; i++)
    {
        int src, dest, w;
        cin >> src >> dest >> w;
        G[--src].push_back({--dest, w});
        G[dest].push_back({src, w});
    }

    // printGraph(G);
    // return G;
}

void Dijekstra(const vector<vector<pair<int, int>>> &G, int source, vector<Node> &Graph)
{
    // define a vector of nodes, depending on no of verticies in the graph.
    int size = G.size();
    // vector<Node> Graph(size);

    // initialize the graph
    Initialize_single_source(Graph, source); // O(V)

    // create an empty set to mark the finshed nodes
    vector<bool> finshedNodes(size);

    // create a priority queue to set the node with the minimum value at the front
    auto compareNode = [](const Node &a, const Node &b)
    {
        return a.distance > b.distance;
    };
    priority_queue<Node, vector<Node>, decltype(compareNode)> pq(compareNode);

    // insert the sorce with distance = 0
    pq.push(Graph[source]);

    // iterate over all the verticies
    while (pq.size()) // O(V + E) -> bfs
    {
        // extract the node with the minimum distance from the source
        Node node = pq.top();
        pq.pop();
        if (finshedNodes[node.ID])
            continue;
        // iterate over all its neighbours and mark them as finshed
        for (auto &nei : G[node.ID])
            if (Relax(Graph, node.ID, nei.first, nei.second))
                // this mean that we have applied the relaxation operation
                pq.push(Graph[nei.first]);

        // mark this node as finshed
        finshedNodes[node.ID] = true;
    }

    // return Graph;
}

// O(V)
void pathToNodeN(const vector<Node> &G, Node n)
{
    // base case
    if (n.parent == -1)
    {
        cout << n.ID + 1 << ' ';
        return;
    }

    // recursive condition
    pathToNodeN(G, G[n.parent]);
    cout << n.ID + 1 << ' ';
}

void pathToNodeNIterative(const vector<Node> &G, Node n)
{
    vector<int> path; // Store the path nodes

    // Traverse the path from node n to the root iteratively
    while (n.parent != -1)
    {
        path.push_back(n.ID + 1); // Add current node ID to the path
        n = G[n.parent];          // Move to the parent node
    }

    // Add the root node to the path
    path.push_back(n.ID + 1);

    // Print the path in reverse order
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << ' ';
    }
}

// O(V)
void CDijekstraProblemCodeForces(const vector<Node> &resGraph)
{
    /*
        @problemDescribtion:
        You are given a weighted undirected graph. The vertices are enumerated from 1 to n. Your task is to find the shortest path between the vertex 1 and the vertex n.
        Input

        The first line contains two integers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), where n is the number of vertices and m is the number of edges. Following m lines contain one edge each in form ai, bi and wi (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106), where ai, bi are edge endpoints and wi is the length of the edge.

        It is possible that the graph has loops and multiple edges between pair of vertices.
        Output

        Write the only integer -1 in case of no path. Write the shortest path in opposite case. If there are many solutions, print any of them.

    */
    if (resGraph[resGraph.size() - 1].distance != INT_MAX)
        pathToNodeNIterative(resGraph, resGraph[resGraph.size() - 1]);
    else
        cout << -1;
}

// Time Complexity = O(V + E)
int main()
{
    DPsolver;
    // build the graph
    vector<vector<pair<int, int>>> graph;
    buildTheGraph(graph);
    // call dijekstra
    vector<Node> resGraph(graph.size());
    Dijekstra(graph, 0, resGraph);
    // solve the problem
    CDijekstraProblemCodeForces(resGraph);
    return 0;
}