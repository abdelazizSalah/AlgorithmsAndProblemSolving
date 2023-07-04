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

void Initialize_single_source(vector<Node> &G, int source)
{
    /*
        @describtion: this is a common subroutine used to initialize all the nodes
                        distance to inf, and the parent to null
                        and the distance of the source should be = 0
    */

    // iterate over all the nodes and initialize them as mentioned before.
    int id = 0;
    for (auto &node : G)
    {
        node.distance = INT_MAX;
        node.parent = NULL;
        node.ID = id++;
    }

    // mark the distance of the source to zero
    G[source].distance = 0;
}

void Relax(vector<Node> &G, int source, int destnation, int weight)
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
    }
}

vector<Node> Dijekstra(vector<pair<int, int>> &G, int source)
{
    // define a vector of nodes, depending on no of verticies in the graph.
    int size = G.size();
    vector<Node> Graph(size);

    // initialize the graph
    Initialize_single_source(Graph, source);

    // create an empty set to mark the finshed nodes
    vector<bool> finshedNodes(size);

    // create a priority queue to set the node with the minimum value at the front
    priority_queue<Node, vector<Node>, greater<>> pq;

    // iterate over all the verticies
    while (pq.size())
    {
        // extract the node with the minimum distance from the source
        Node node = pq.top();
        pq.pop();

        // iterate over all its neighbours and mark them as finshed
        for (auto nei : G[node.ID])
            Relax(Graph, node.ID, nei, G[node.ID][nei]);

        // mark this node as finshed
        finshedNodes[node.ID] = true;
    }

    return Graph;
}

int main()
{
    DPsolver;
    // build the graph
    vector<vector<int>> graph = buildTheGraph();
    // call dijekstra

    return 0;
}
