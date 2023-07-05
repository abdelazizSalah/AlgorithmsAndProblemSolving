#include <bits/stdc++.h>
using namespace std;

/*
    list ->
    matrix ->


    @algorithm:
        Dijekstra( G,S ):
        1. Initialize_Single_Source(G, S)
        2. s= phi -> empty set contains the finshed nodes
        3. Q = s -> initialize it with the source -> fill it -> choose data structure of this Q
        4. while Q.size()
            1. u = extractMin(Q)
            2. mark that u as visited -> s.push(u)
            3. for each neighbour (nei) to that vertex u
                1. relax (u, nei, w)
*/

// implementing the common subroutines.
struct Node
{
    int distance;
    int parent;
    int ID;
};
// 1- initialize single source
void Initialize_Single_Source(vector<Node> &G, int source)
{
    /*
        @algorithm:
            1. iterate over all nodes
                1. make their parent = -1
                2. make their distance = inf
            2. assign the distance of the source = 0
    */
    int id = 0;
    for (auto &node : G)
    {
        node.distance = INT_MAX;
        node.parent = -1;
        node.ID = id++;
    }

    G[source].distance = 0;
}

// 2- relaxation
bool relax(vector<Node> &G, int source, int dest, int weight)
{
    /*
        @algorithm:
            1. if dest.d > src.d + weight:
                1.  dest.d = src.d + weight
                2. dest.parent = src
                return true
            2. else
                1. return false
    */

    if (G[dest].distance >= G[source].distance + weight)
    {
        G[dest].distance = G[source].distance + weight;
        G[dest].parent = source;
        return true;
    }
    return false;
}

void printGraph(const vector<vector<pair<int, int>>> &G)
{
    int sz = G.size();
    for (int i = 0; i < sz; i++)
    {
        cout << "neighbours of node# " << i << endl;
        for (auto &nei : G[i])
            cout << '{' << nei.first + 1 << ' ' << nei.second << '}';
        cout << endl;
    }
}

vector<vector<pair<int, int>>> buildGraph()
{
    // take user inputs
    cout << "insert No of Nodes and edges: \n";
    int noOFNodes, noOfEdges;
    cin >> noOFNodes >> noOfEdges;
    // undirected matrix representation
    vector<vector<pair<int, int>>> graph(noOFNodes); // NxN matrix, N is noOfNodes

    for (int j = 0; j < noOfEdges; j++)
    {
        // assume that user will insert 1 based values -> 1
        int src, dest, w;
        cin >> src >> dest >> w;
        src--, dest--;
        graph[src].push_back({dest, w});
        graph[dest].push_back({src, w});
    }

    printGraph(graph);
    return graph;
}

vector<Node> dijekstra(const vector<vector<pair<int, int>>> &graph, int src)
{
    // create the vector to be returned
    int sz = graph.size(); // extract no of nodes.
    vector<Node> G(sz);

    // 1. initialize single source
    Initialize_Single_Source(G, src);

    // 2. create vector to mark the finshed nodes.
    vector<bool> finshedNode(sz);

    // 3. create priority queue to set the node with the minimum value at the first.
    auto compareNode = [](const Node &a, const Node &b)
    {
        // apply ur logic
        return a.distance > b.distance;
    };

    priority_queue<Node, vector<Node>, decltype(compareNode)> pq(compareNode);
    pq.push(G[src]);

    // 4. iterate over the Q
    while (pq.size())
    {
        // extract the minimum element
        Node front = pq.top();
        pq.pop();

        // iterate over all its neighbours
        for (auto &nei : graph[front.ID])
            if (nei.second != 0)
            {
                // this is a neighbour
                if (relax(G, front.ID, nei.first, nei.second))
                    if (!finshedNode[nei.first])
                        pq.push(G[nei.first]);
            }

        // mark as finshed
        finshedNode[front.ID] = true;
    }

    return G;
}

int main()
{
    // build Graph
    vector<vector<pair<int, int>>> graph = buildGraph();
    // call dijekstra
    vector<Node> result = dijekstra(graph, 0);
    // print the output
    for (auto &node : result)
        cout << "node# " << node.ID << " --- distance from source is: " << node.distance << endl;
}