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

void bfsIterativeMatrix(const vector<vector<int>> &graph, vector<bool> &visited, int startingNode)
{
    // storing the size of the graph for later use
    int sz = graph.size();

    // creating a queue to help us in organizing the opeartion of visiting :D
    queue<int> whosTurn;

    // creating a vector to tell wethere the node in the queue or not.
    vector<bool> inQueue(sz);

    // inserting the first node in the queue
    whosTurn.push(startingNode);

    // starting the operation of looping till visiting all nodes :D
    while (whosTurn.size())
    {
        // marking the node in the front as visited and getting it out of the queue
        int node = whosTurn.front();
        visited[node] = true;
        whosTurn.pop();
        inQueue[node] = false;

        // iterating over all its neighbour to give them the chance of visiting :)
        for (int i = 0; i < sz; i++)
        {
            /* there are three conditions to visit this node
             1. it should be neigbour.
             2. it should not be visited before.
             3. it should not be in the queue
             */
            if (graph[node][i] && !visited[i] && !inQueue[i])
            {
                // inserting the neighbour in the queue
                whosTurn.push(i);

                // marking it as in the queue;
                inQueue[i] = true;
            }
        }

        // printing the visited node
        cout << node + 1 << ' ';
    }
}
void bfsIterativeList(const vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int startingNode)
{
    // storing the size of the graph for later use
    int sz = graph.size();

    // creating a queue to help us in organizing the opeartion of visiting :D
    queue<int> whosTurn;

    // creating a vector to tell wethere the node in the queue or not.
    vector<bool> inQueue(sz);

    // inserting the first node in the queue
    whosTurn.push(startingNode);

    // starting the operation of looping till visiting all nodes :D
    while (whosTurn.size())
    {
        // marking the node in the front as visited and getting it out of the queue
        int node = whosTurn.front();
        visited[node] = true;
        whosTurn.pop();
        inQueue[node] = false;

        // iterating over all its neighbour to give them the chance of visiting :)
        for (auto neighbour : graph[node])
        {
            /* there are three conditions to visit this node
             1. it should be neigbour. => always satisfied using this for each loop :)
             2. it should not be visited before.
             3. it should not be in the queue
             */
            if (!visited[neighbour.first] && !inQueue[neighbour.first])
            {
                // inserting the neighbour in the queue
                whosTurn.push(neighbour.first);

                // marking it as in the queue;
                inQueue[neighbour.first] = true;
            }
        }

        // printing the visited node
        cout << node + 1 << ' ';
    }
}

void bfsRecursiveMatrix(const vector<vector<int>> &graph, vector<bool> &black, vector<bool> &grey, queue<int> &Q)
{
    // get the node out from the queue
    int node = Q.front();
    Q.pop();
    // mark it as visited
    black[node] = true;

    // mark it out of the queue
    grey[node] = false;

    int sz = black.size();
    // iterating over all its neighbours and inserting them in the queue
    for (int i = 0; i < sz; i++)
    {
        /* there are three conditions to visit this node
             1. it should be neigbour. => always satisfied using this for each loop :)
             2. it should not be visited before.
             3. it should not be in the queue
             */
        if (graph[node][i] && !black[i] && !grey[i])
        {
            // then this is a neigbour

            // insert it in the queue
            Q.push(i);

            // mark it as in the queue
            grey[i] = true;
        }
    }

    cout << node + 1 << ' ';
    while (Q.size())
        bfsRecursiveMatrix(graph, black, grey, Q);
}

int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    auto mat = matrixRepresentation(numberOfNodes, numberOfEdges, false, false, true);
    vector<bool> visited(numberOfNodes);
    vector<bool> grey(numberOfNodes);
    queue<int> Q;
    Q.push(0);
    bfsRecursiveMatrix(mat, visited, grey, Q);
    return 0;
}