#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void bfsIterative(const vector<vector<int>> &G, vector<bool> &grey, vector<bool> &black, int src)
{
    // create queue
    queue<int> q;
    q.push(src);
    grey[src] = true;
    while (q.size())
    {
        // extract the front node
        int node = q.front();
        q.pop();
        grey[node] = false;
        black[node] = true;

        // iterate over all its neighbours and insert them into the queue
        for (auto nei : G[node])
        {
            if (!black[nei] && !grey[nei])
            {
                q.push(nei);
                grey[nei] = true;
            }
        }
        cout << node << ' ';
    }
}

int main()
{
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    vector<vector<int>> graph(noOfNodes);
    vector<bool> grey(noOfNodes);
    vector<bool> black(noOfNodes);
    for (int i = 0; i < noOfEdges; i++)
    {
        int src, dest;
        cin >> src >> dest;
        src--, dest--;
        // undirected
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    bfsIterative(graph, grey, black, 0);
}