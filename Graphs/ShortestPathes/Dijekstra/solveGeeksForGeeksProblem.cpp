/*
    @author: Abdelaziz Salah
    @date: 4/7/2023
    @describtion: this file contains the algorithms of dijekstra for finding
                        the shortest pathes from certain single source
    @algorithm:
    Dijekstra(G, s)
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
int Relax(vector<Node> &G, int source, int destnation, int weight)
{
    /*
        @describtion: this is a common subrouting used to relax the edges under a condition:
                        if the weight from the source and the distance of the source was
                        less than or equal to the distance of the destination then we should
                        apply the relaxation operation
        @algorithm:
                make the parent of the destination as the source
                make the distance of the destination as the sum of the source distance and the weight
    */
    if (G[source].distance + weight <= G[destnation].distance)
    {
        G[destnation].distance = G[source].distance + weight;
        G[destnation].parent = source;
        return G[source].distance + weight;
    }

    return 0;
}

vector<Node> Dijekstra(vector<vector<pair<int, int>>> &G, int source)
{
    // define a vector of nodes, depending on no of verticies in the graph.
    int size = G.size();
    vector<Node> Graph(size);

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

        // iterate over all its neighbours and mark them as finshed
        for (auto &nei : G[node.ID])
            if (nei.second != 0)
            { // this means it is a neighbour
                int res = Relax(Graph, node.ID, nei.first, nei.second);
                if (res != 0)
                    // this mean that we have applied the relaxation operation
                    pq.push(Graph[nei.first]);
            }

        // mark this node as finshed
        finshedNodes[node.ID] = true;
    }

    return Graph;
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
vector<vector<pair<int, int>>> buildTheGraph(int noOfNodes, vector<vector<int>> adj[])
{
    int noOfEdges = adj->size();
    // list representation -> undirected
    vector<vector<pair<int, int>>> G(noOfNodes);

    // reading the weights
    for (int i = 0; i < noOfNodes; i++)
        for (auto node : adj[i])
            G[i].push_back({node[0], node[1]});

    printGraph(G);
    return G;
}

// Time Complexity = O(V + E)
int main()
{
    DPsolver;
    // build the graph
    vector<vector<int>> arr[] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    vector<vector<pair<int, int>>> graph = buildTheGraph(3, arr);
    // call dijekstra
    auto resGraph = Dijekstra(graph, 2);
    for (auto res : resGraph)
        cout << "Node# " << res.ID << " --- distance From src = " << res.distance << endl;

    return 0;
}
