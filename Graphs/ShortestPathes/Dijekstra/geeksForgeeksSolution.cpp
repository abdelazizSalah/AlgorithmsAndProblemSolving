//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
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

        return G;
    }

    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<vector<pair<int, int>>> graph = buildTheGraph(V, adj);
        // call dijekstra
        auto resGraph = Dijekstra(graph, S);
        vector<int> res;
        for (auto rs : resGraph)
            res.push_back(rs.distance);
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends