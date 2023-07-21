// logic of the problem:
// find shortest path using dijekstra
// check if this path has alternating colors.
/*
    @Algorithm
        1. Read the Inputs
        2. build the graph in list representation, with keeping the color instead of the weight
        3. create a visited vector
        4. create a distance vector and initialize it with -1
        5. set D[0] = 0, because we will always start from node 0
        6. apply BFS
            1. to insert a node in the queue, the color of the edge should be different than the color of the current node
            2. initialy insert the color of node 0 as black.
            3. after visiting all the node's neighbours, increment the level.
            4. mark the node as visited, and store the distance [node] = lvl
        7. return the distance vector.
*/

#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool canInsert(pair<int, char> neighbour, pair<int, char> node)
{
    return node.second != neighbour.second;
}

void bfs(const vector<vector<pair<int, char>>> &G, vector<int> &distances, vector<bool> &visitedBlue, vector<bool> &visitedRed)
{

    queue<pair<int, char>> queue;
    queue.push({0, 'x'});
    int lvl = 0;
    while (queue.size())
    {
        int sz = queue.size();
        while (sz--)
        {
            // extract the node from the queue
            auto node = queue.front();
            queue.pop();
            for (auto nei : G[node.first])
            {
                if (nei.second == 'B')
                {

                    // insert the neibour into the queue under our condition
                    if (!visitedBlue[nei.first] && canInsert(nei, node))
                    {
                        // insert into the queue
                        queue.push(nei);
                    }
                }
                else
                {
                    // insert the neibour into the queue under our condition
                    if (!visitedRed[nei.first] && canInsert(nei, node))
                    {
                        // insert into the queue
                        queue.push(nei);
                    }
                }
            }
            // mark the node as finshed
            vis[node.first] = true;
            // set the distance of the neighbour
            distances[node.first] = lvl;
        }
        // after finishing that level go the next one.
        lvl++;
    }
}
void printGraph(const vector<vector<pair<int, char>>> &G)
{
    for (int i = 0; i < G.size(); i++)
    {
        cout << "Neighbours of node " << i << " are: \n";
        for (auto nei : G[i])
            cout << "nei #: " << nei.first << " with edge color: " << nei.second << '\n';
        cout << endl;
    }
}

int main()
{
    DPSolver;
    int noOfNodes, noOfRedEdges, noOfBlueEdges;
    cin >> noOfNodes >> noOfRedEdges >> noOfBlueEdges;
    vector<vector<pair<int, char>>> G(noOfNodes);
    // insert red Nodes first
    for (int i = 0; i < noOfRedEdges; i++)
    {
        int src, dest;
        cin >> src >> dest;
        G[src].push_back({dest, 'R'});
    }

    // insert blue Nodes first
    for (int i = 0; i < noOfBlueEdges; i++)
    {
        int src, dest;
        cin >> src >> dest;
        G[src].push_back({dest, 'B'});
    }

    // print the Graph
    printGraph(G);

    // apply bfs;
    vector<int> distances(noOfNodes, -1);
    distances[0] = 0;
    vector<bool> visited(noOfNodes);
    bfs(G, distances, visited);
    for (auto dis : distances)
        cout << dis << ' ';
    return 0;
}