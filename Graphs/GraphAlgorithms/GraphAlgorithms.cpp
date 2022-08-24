#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Matrixgraph(100, vector<int>(100));
vector<vector<int>> Listgraph(100);

void DFSForMatRep(vector<vector<int>> &graph, vector<bool> &vis, int vertex)
{
    int size = graph[vertex].size();
    for (int i = 0; i < size; i++)
        if (graph[vertex][i] && !vis[i]) // if there is an edge between them and !vis
        {
            vis[i] = true;
            DFSForMatRep(graph, vis, i);
        }
}

void DFSForListRep(vector<vector<int>> &graph, int vertex, vector<bool> &vis)
{
    for (auto it : graph[vertex])
        if (!vis[it])
        {
            vis[it] = true;
            DFSForListRep(graph, it, vis);
        }
}
void applyingDFSOnMatrix(vector<vector<int>> &graph, int N, vector<bool> &vis)
{
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            vis[i] = true;
            DFSForMatRep(graph, vis, i);
        }
}

void applyingDFSOnList(vector<vector<int>> &graph, int N, vector<bool> &vis)
{
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            vis[i] = true;
            DFSForListRep(graph, i, vis);
        }
}
void PrintingTheGraphAsMatrix(const vector<vector<int>> &graph, const int &N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << graph[i][j] << ' ';
        cout << '\n';
    }
}

void BFSForMatrixIterative(vector<vector<int>> &graph, queue<int> &Q, int vrtx, int N, vector<bool> &grey, vector<bool> &black)
{
    // insert the vrtx in the Queue
    Q.push(vrtx);

    // mark it as it is in the queue
    grey[vrtx] = true;

    int lvl = 0; /// used to determine the levels in the graph -> optional
    while (Q.size())
    {
        // get the size of the queue
        int sz = Q.size();

        // as long as the Queue is not empty iterate over it
        while (sz--)
        {
            // take the node in the front of the Q
            int node = Q.front();

            // mark it out from the queue
            grey[node] = false;

            // iterate over all the neighbours of that node
            for (int i = 0; i < N; i++)
                if (!grey[graph[node][i]] && !black[graph[node][i]])
                {
                    // insert it in the Queue
                    Q.push(graph[node][i]);

                    // mark as in the Queue
                    grey[graph[node][i]] = true;
                }

            // mark it as finished
            black[node] = true;
            Q.pop();
        }

        // after finishing that level increment it
        lvl++;
    }
}

void BFSCallForMat(vector<vector<int>> &graph, vector<bool> &black, vector<bool> &grey, int N)
{
    queue<int> Q;
    for (int i = 0; i < N; i++)
        if (!black[i])
            BFSForMatrixIterative(graph, Q, i, N, grey, black);
}

void BFSForMatrixRecursive(vector<vector<int>> &graph, queue<int> &Q, int vrtx, int N, vector<bool> &grey, vector<bool> &black)
{
    // iterate over all its neighbours
    for (int i = 0; i < N; i++)
        // if there is an egde
        if (graph[vrtx][i] && !grey[i] && !black[i])
        {
            // push it in the queue
            Q.push(i);

            // mark it as grey
            grey[i] = true;
        }

    // mark that vertex as finished
    if (!black[vrtx])
    {
        grey[vrtx] = false;
        black[vrtx] = true;
    }

    // iterate over the Q and get the next node
    while (Q.size())
    {
        // get the node which has the turn
        int node = Q.front();
        Q.pop();

        // mark it out from the grey
        grey[node] = false;

        // call the BFS on it
        BFSForMatrixRecursive(graph, Q, node, N, grey, black);
    }
}

void BFSforListIterative(vector<vector<int>> &graph, int vrtx, queue<int> Q, vector<bool> &grey, vector<bool> &black)
{
    // insert the vrtx in the Queue
    Q.push(vrtx);

    // mark it as it is in the queue
    grey[vrtx] = true;

    int lvl = 0; /// used to determine the levels in the graph -> optional
    while (Q.size())
    {
        // get the size of the queue
        int sz = Q.size();

        // as long as the Queue is not empty iterate over it
        while (sz--)
        {
            // take the node in the front of the Q
            int node = Q.front();

            // mark it out from the queue
            grey[node] = false;

            // iterate over all the neighbours of that node
            for (auto it : graph[node])
                if (!grey[it] && !black[it])
                {
                    // insert it in the Queue
                    Q.push(it);

                    // mark as in the Queue
                    grey[it] = true;
                }

            // mark it as finished
            black[node] = true;
            Q.pop();
        }

        // after finishing that level increment it
        lvl++;
    }
}

void BFSforListRecursive(vector<vector<int>> &graph, int vrtx, queue<int> Q, vector<bool> &grey, vector<bool> &black)
{
    // iterate over all its neighbours
    for (auto it : graph[vrtx])
        if (!black[it] && !grey[it])
        {
            // push it in the queue
            Q.push(it);

            // mark it as grey
            grey[it] = true;
        }

    // mark that vertex as finished
    if (!black[vrtx])
    {
        grey[vrtx] = false;
        black[vrtx] = true;
    }

    // iterate over the Q and get the next node
    while (Q.size())
    {
        // get the node which has the turn
        int node = Q.front();
        Q.pop();

        // mark it out from the grey
        grey[node] = false;

        // call the BFS on it
        BFSforListRecursive(graph, node, Q, grey, black);
    }
}

void BFSCallForList(vector<vector<int>> &graph, int N, vector<bool> &grey, vector<bool> &black)
{
    queue<int> Q;
    for (int i = 0; i < N; i++)
        if (!black[i])
            BFSforListIterative(graph, i, Q, grey, black);
}

int NumberOfConnectedComponentsusingMat(vector<vector<int>> &graph, int N, vector<bool> &vis)
{
    int cntr = 0;
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            vis[i] = true;
            DFSForMatRep(graph, vis, i);
            cntr++;
        }

    return cntr;
}

int NumberOfConnectedComponentsusingList(vector<vector<int>> &graph, int N, vector<bool> &vis)
{
    int cntr = 0;
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            vis[i] = true;
            DFSForListRep(graph, i, vis);
            cntr++;
        }

    return cntr;
}

// Complexity O(V + E) -> get the shortest path for all nodes from certain vertex
void SSSPUsingBFSforMat(vector<vector<int>> &graph, queue<int> &Q, int vrtx, int N, vector<bool> &grey, vector<bool> &black, int dist, vector<int> &Dists)
{
    // iterate over all its neighbours
    for (int i = 0; i < N; i++)
        // if there is an egde
        if (graph[vrtx][i] && !grey[i] && !black[i])
        {
            // push it in the queue
            Q.push(i);

            // mark it as grey
            grey[i] = true;

            // count the dist
            Dists[i] = dist;
        }

    // mark that vertex as finished
    if (!black[vrtx])
    {
        grey[vrtx] = false;
        black[vrtx] = true;
    }

    // iterate over the Q and get the next node
    while (Q.size())
    {
        // get the node which has the turn
        int node = Q.front();
        Q.pop();

        // mark it out from the grey
        grey[node] = false;

        // call the BFS on it
        SSSPUsingBFSforMat(graph, Q, node, N, grey, black, Dists[node] + 1, Dists);
    }
}

void SSSPUsingBFSAndList(vector<vector<int>> &graph, queue<int> &Q, int vrtx, int N, vector<bool> &grey, vector<bool> &black, int dist, vector<int> &Dists)
{
    // iterate over all its neighbours
    for (auto it : graph[vrtx])
        // if there is an egde
        if (!grey[it] && !black[it])
        {
            // push it in the queue
            Q.push(it);

            // mark it as grey
            grey[it] = true;

            // count the dist
            Dists[it] = dist;
        }

    // mark that vertex as finished
    if (!black[vrtx])
    {
        grey[vrtx] = false;
        black[vrtx] = true;
    }

    // iterate over the Q and get the next node
    while (Q.size())
    {
        // get the node which has the turn
        int node = Q.front();
        Q.pop();

        // mark it out from the grey
        grey[node] = false;

        // call the BFS on it
        SSSPUsingBFSAndList(graph, Q, node, N, grey, black, Dists[node] + 1, Dists);
    }
}

bool isThereIsAPath(int src, int dest, vector<vector<int>> &graph, queue<int> &Q, int vrtx, int N, vector<bool> &grey, vector<bool> &black, int dist, vector<int> &Dists)
{
    Dists[src] = 0;
    SSSPUsingBFSforMat(graph, Q, src, N, grey, black, 0, Dists);
    if (Dists[dest])
        cout << "yes";
    else
        cout << "no";

    return Dists[dest];
}

void SSSP(const vector<vector<int>> &graph, int src, vector<int> &Dists, vector<bool> &grey, vector<bool> &black, queue<int> &Q, int dist)
{

    // iterating over the vertex neighbours
    for (auto it : graph[src])
        if (!grey[it] && !black[it])
        { // not done and not in the Q {
            // insert it in the Queue
            Q.push(it);

            // mark it as entered the queue
            grey[it] = true;

            // give it the distance sent
            Dists[it] = dist;
        }

    // mark this node as finished
    if (!black[src])
    {
        // mark it as finished
        black[src] = true;

        // mark it out from the queue too
        grey[src];
    }

    // iterate over the remaining element
    while (Q.size())
    {

        // get the element in the front of the Queue
        int node = Q.front();

        // get it out from the Queue
        Q.pop();

        // mark it as out from the queue
        grey[node] = true;

        // BSF again on it
        SSSP(graph, node, Dists, grey, black, Q, Dists[node] + 1);
    }
}

bool isThereAPath(int src, int dest, vector<vector<int>> &graph, vector<int> &Dists)
{
    queue<int> Q;
    vector<bool> grey;
    vector<bool> black;
    SSSP(graph, src, Dists, grey, black, Q, 1);
    if (Dists[dest])
        cout << "Yes";
    else
        cout << "No";

    return Dists[dest];
}

void DFS(vector<vector<int>> &graph, vector<bool> &vis, int node)
{
    // iterating over the node neighbours
    for (auto n : graph[node])
    {
        if (!vis[n])
        {
            vis[n] = true;
            DFS(graph, vis, n);
        }
    }
}

/**
 * @author Abdelaziz Salah
 *
 * @return int Number of the connected components in the graph
 */
int noOfConnectedComponents(vector<vector<int>> &graph, vector<bool> &vis)
{
    int size = graph.size();
    int noOfConnectedComp = 0;
    for (int i = 0; i < size; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            DFS(graph, vis, i);
            noOfConnectedComp++;
        }
    }

    return noOfConnectedComp;
}

void iterativeBFS(vector<vector<int>> &graph, vector<bool> &grey, vector<bool> &black, int node)
{
    // create the queue
    queue<int> Q;

    // initialize the levels to 0
    int lvl = 0;

    // insert the first node in the queue
    Q.push(node);

    // mark it as insertedd in the queue
    grey[node] = true;

    // as long as there are elements in the queue
    while (Q.size())
    {

        // get the size out
        int sz = Q.size();

        // iterating over the size which are all nodes in the same level
        while (sz--)
        {
            // get the element in the front
            int n = Q.front();

            // get it out from the Q
            Q.pop();

            // iterate over all its nighbours
            for (auto it : graph[n])
            {
                // if it is not visited before
                if (!grey[it] && !black[it])
                {
                    // insert it in the Q
                    Q.push(it);

                    // mark it as inserted
                    grey[it] = true;
                }
            }
        }

        // increse the level
        lvl++;
    }
}

// Done
void DFSForMatRep2(vector<vector<int>> &graph, vector<bool> &vis, int vertex)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[vertex][i] && !vis[i])
        {
            vis[i] = true;
            DFSForMatRep2(graph, vis, i);
        }
    }
}
// Done
void applyingDFSOnMatrix2(vector<vector<int>> &graph, int N, vector<bool> &vis)
{
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            vis[i] = true;
            DFSForMatRep2(graph, vis, i);
        }
}

// Done
void DFSForListRep2(vector<vector<int>> &graph, int vertex, vector<bool> &vis)
{
    for (auto it : graph[vertex])
        if (!vis[it])
        {
            vis[it] = true;
            DFSForListRep2(graph, it, vis);
        }
}

// Done
void applyingDFSOnList2(vector<vector<int>> &graph, int N, vector<bool> &vis)
{
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            vis[i] = true;
            DFSForListRep2(graph, i, vis);
        }
}
// Done
void PrintingTheGraphAsMatrix2(const vector<vector<int>> &graph, const int &N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}

// Done
void BFSForMatrixIterative2(vector<vector<int>> &graph, queue<int> &Q, int vrtx, int N, vector<bool> &grey, vector<bool> &black)
{
    // inserting the fisrt vertex in the Q
    Q.push(vrtx);

    // var to determine the level
    int lvl = 0;

    // mark it as in the Q
    grey[vrtx] = true;

    // as long as the Q is not empty
    while (Q.size())
    {

        // get the number of neighbours in the Q
        int sz = Q.size();

        // as long as there are some neighbours
        while (sz--)
        {

            // get the first one
            int node = Q.front();

            // mark it out from the Q
            grey[node] = false;
            Q.pop();

            // iterating over the neighbours of the that node
            for (int i = 0; i < N; i++)
            {
                // if not visited and neighbour and not in the Q
                if (graph[node][i] && !grey[i] && !black[i])
                {
                    // insert it in the queue
                    Q.push(node);
                    // mark it as in the Q
                    grey[i] = true;
                }
            }
            // mark the node as done
            black[node] = true;
        }
        // after finishing all the neighbours increase the level
        lvl++;
    }
}

// Done
void BFSCallForMat2(vector<vector<int>> &graph, vector<bool> &black, vector<bool> &grey, int N)
{
    queue<int> Q;
    for (int i = 0; i < N; i++)
    {
        if (!black[i])
        {
            BFSForMatrixIterative2(graph, Q, i, N, grey, black);
        }
    }
}

// Done
void BFSForMatrixRecursive2(vector<vector<int>> &graph, queue<int> &Q, int vrtx, int N, vector<bool> &grey, vector<bool> &black)
{
    // iterating over all the neighbours
    for (int i = 0; i < N; i++)
    {
        if (graph[vrtx][i] && !grey[i] && !black[i])
        {
            grey[i] = true;
            Q.push(i);
        }
    }

    // after finishing the neigbours mark the element as finished
    if (!black[vrtx])
    {
        grey[vrtx] = false;
        black[vrtx] = true;
    }

    if (Q.size())
    {
        // get the node in the front of the Q
        int node = Q.front();
        Q.pop();

        // mark it out from the Q
        grey[node] = false;

        // BFS on the next node
        BFSForMatrixRecursive2(graph, Q, node, N, grey, black);
    }
}

// Done
void BFSforListIterative2(vector<vector<int>> &graph, int vrtx, queue<int> Q, vector<bool> &grey, vector<bool> &black)
{
    // inserting the fisrt vertex in the Q
    Q.push(vrtx);

    // var to determine the level
    int lvl = 0;

    // mark it as in the Q
    grey[vrtx] = true;

    // as long as the Q is not empty
    while (Q.size())
    {

        // get the number of neighbours in the Q
        int sz = Q.size();

        // as long as there are some neighbours
        while (sz--)
        {

            // get the first one
            int node = Q.front();

            // mark it out from the Q
            grey[node] = false;
            Q.pop();

            // iterating over the neighbours of the that node
            for (auto it : graph[node])
            {
                // if not visited and neighbour and not in the Q
                if (!grey[it] && !black[it])
                {
                    // insert it in the queue
                    Q.push(node);
                    // mark it as in the Q
                    grey[it] = true;
                }
            }
            // mark the node as done
            black[node] = true;
        }
        // after finishing all the neighbours increase the level
        lvl++;
    }
}

// Done
void BFSforListRecursive2(vector<vector<int>> &graph, int vrtx, queue<int> Q, vector<bool> &grey, vector<bool> &black)
{
    // iterating over all the neighbours
    for (auto i : graph[vrtx])
    {
        if (!grey[i] && !black[i])
        {
            grey[i] = true;
            Q.push(i);
        }
    }

    // after finishing the neigbours mark the element as finished
    if (!black[vrtx])
    {
        grey[vrtx] = false;
        black[vrtx] = true;
    }

    if (Q.size())
    {
        // get the node in the front of the Q
        int node = Q.front();
        Q.pop();

        // mark it out from the Q
        grey[node] = false;

        // BFS on the next node
        BFSforListRecursive2(graph, node, Q, grey, black);
    }
}

// Done
void BFSCallForList2(vector<vector<int>> &graph, int N, vector<bool> &grey, vector<bool> &black)
{
    queue<int> Q;
    for (int i = 0; i < N; i++)
    {
        if (!black[i])
        {
            BFSforListIterative2(graph, i, Q, grey, black);
        }
    }
}

// Done
void DFS2(vector<vector<int>> &graph, vector<bool> &vis, int node)
{
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            vis[it] = true;
            DFS2(graph, vis, it);
        }
    }
}

// Done
int NumberOfConnectedComponentsusingMat2(vector<vector<int>> &graph, int N, vector<bool> &vis)
{
    int cntr = 0;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            DFSForMatRep2(graph, vis, i);
            cntr++;
        }
    }

    return cntr;
}

// Done
int NumberOfConnectedComponentsusingList2(vector<vector<int>> &graph, int N, vector<bool> &vis)
{
    int cntr = 0;
    for (int i = 0; i < N; i++)
        if (!vis[i])
        {
            vis[i] = true;
            DFSForListRep2(graph, i, vis);
            cntr++;
        }

    return cntr;
}

// Done
void SSSPUsingBFSforMatIterative(vector<vector<int>> &graph, queue<int> &Q, int vrtx, int N, vector<bool> &grey, vector<bool> &black, int dist, vector<int> &Dists)
{
    // insert the sent node into the Q
    Q.push(vrtx);

    // mark it as in the Q
    grey[vrtx] = true;

    // make a variable to count the number of levels
    int lvl = 1;

    while (Q.size())
    {
        int sz = Q.size();
        while (sz--)
        {
            // get the first element in the Q
            int node = Q.front();

            // get it out from the Q and mark it out from the grey
            Q.pop();
            grey[node] = false;

            // iterate over all its neighbours
            for (int i = 0; i < N; i++)
            {
                // if there is a edge and not finished or in the Q
                if (graph[node][i] && !grey[i] && !black[i])
                {
                    // insert it in the Q
                    Q.push(i);
                    // mark it as in the Q
                    grey[i] = true;
                    // store the distance from the first node
                    Dists[i] = lvl;
                }
            }
            // mark the node as done
            black[node] = true;
        }
        lvl++;
    }
}

// Done
void SSSPUsingBFSforMatRec2(vector<vector<int>> &graph, queue<int> &Q, int vrtx, const int &N, vector<bool> &grey, vector<bool> &black, int dist, vector<int> &Dists)
{
    // itertate over all the neigbours
    for (int i = 0; i < N; i++)
    {
        if (graph[vrtx][i] && !grey[i] && !black[i])
        {
            // insert it in the Q
            Q.push(i);

            // mark it as inserted
            grey[i] = true;

            // evaluate the distance
            Dists[i] = dist;
        }
    }

    // mark it as finished
    if (!black[vrtx])
    {
        black[vrtx] = true;
        grey[vrtx] = false;
    }

    // if there are more elements in the Q recurse on them
    if (Q.size())
    {
        int node = Q.front();
        Q.pop();
        grey[node] = false;
        SSSPUsingBFSforMatRec2(graph, Q, node, N, grey, black, Dists[node] + 1, Dists);
    }
}

// Done
void SSSPUsingBFSAndList2(vector<vector<int>> &graph, queue<int> &Q, int vrtx, vector<bool> &grey, vector<bool> &black, int dist, vector<int> &Dists)
{
    // iterate over all the neighbours
    for (auto it : graph[vrtx])
    {
        if (!black[it] && !grey[it])
        {
            Q.push(it);
            grey[it] = true;
            Dists[it] = dist;
        }
    }

    if (!black[vrtx])
    {
        black[vrtx] = true;
        grey[vrtx] = false;
    }

    if (Q.size())
    {
        int node = Q.front();
        Q.pop();
        grey[node] = false;
        SSSPUsingBFSAndList2(graph, Q, node, grey, black, Dists[node] + 1, Dists);
    }
}

// Done
bool isThereIsAPath2(int src, int dest, vector<vector<int>> &graph, queue<int> &Q, int vrtx, int N, vector<bool> &grey, vector<bool> &black, int dist, vector<int> &Dists)
{
    Dists[src] = 0;
    SSSPUsingBFSAndList2(graph, Q, src, grey, black, 0, Dists);
    if (Dists[dest])
    {
        cout << "Yes";
    }
    else
        cout << "NO";

    return Dists[dest];
}

// Done
int noOfConnectedComponents2(vector<vector<int>> &graph, vector<bool> &vis)
{
    int cntr = 0;
    int sz = graph.size();
    for (int i = 0; i < sz; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            DFS(graph, vis, i);
            cntr++;
        }
    }
    return cntr;
}

int main()
{
    // try whatever you want all is working :D
}
/////doneeeeeeeeeeeeeeeee :D