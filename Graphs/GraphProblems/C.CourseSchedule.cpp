/// accepted 2 times :).
#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool solve()
{
    // reading inputs
    int noOfCourses, noOfPrerequisites;
    cin >> noOfCourses >> noOfPrerequisites;
    vector<vector<int>> prerequisites(noOfPrerequisites, vector<int>(2));
    for (int i = 0; i < noOfPrerequisites; i++)
        cin >> prerequisites[i][0] >> prerequisites[i][1];

    // creating the graph
    vector<vector<int>> graph(noOfCourses, vector<int>());
    for (int i = 0; i < noOfPrerequisites; i++)
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

    // counting the indegree of each node
    vector<int> indegree(noOfCourses, 0);
    for (int i = 0; i < noOfCourses; i++)
        for (int j = 0; j < graph[i].size(); j++)
            indegree[graph[i][j]]++;

    queue<int> q;
    for (int i = 0; i < noOfCourses; i++)
        if (indegree[i] == 0)
            q.push(i); // start with the nodes which has no prerequisites.

    vector<int> topologicalOrder;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topologicalOrder.push_back(node);
        for (int i = 0; i < graph[node].size(); i++)
        {
            indegree[graph[node][i]]--; // mark that one of the prerequisites has been completed.
            if (indegree[graph[node][i]] == 0)
                q.push(graph[node][i]); // if all the prerequisites has been completed, then push it to the queue, to be done.
        }
    }

    if (topologicalOrder.size() == noOfCourses) // if the number of the nodes in the topological order is equal to the number of nodes in the graph, then there is no cycle.
        return true;
    else
        return false; // this means that some nodes has not been done.
}

/// @brief this function is used to check if the graph is cyclic or not, by passing through
/// the graph using dfs
/// @param adjGraph -> the graph which is being traversed.
/// @param black -> list contains the nodes which has been visited and finished
/// @param grey  -> list contains the nodes which has been visited but not finished
/// @param node  -> the node which is being visited.
bool dfs(const vector<vector<int>> &adjGraph, vector<bool> &black, vector<bool> &grey, int node)
{
    grey[node] = true;
    for (int neighbour : adjGraph[node])
        if (!black[neighbour] && !grey[neighbour]) // if neighbour still unfinished, and unvisited, go and finish it.
        {
            if (!dfs(adjGraph, black, grey, neighbour))
                return false;
        }
        else if (grey[neighbour]) // if you are trying to visit a node, which is visited but not finished, then there is a cycle.
            return false;

    grey[node] = false; // remove from the unfinished list
    black[node] = true; // place it in the finished list.
    return true;
}

bool mySolution()
{
    /// reading the input.
    int noOfCourses, noOfPrerequisites;
    cin >> noOfCourses >> noOfPrerequisites;
    vector<pair<int, int>> prerequisites(noOfPrerequisites);
    for (pair<int, int> &prerequisite : prerequisites)
        cin >> prerequisite.first >> prerequisite.second;

    /// creating the graph.
    vector<vector<int>> graph(noOfCourses); // build it as adjacent list.
    for (pair<int, int> prerequisite : prerequisites)
        graph[prerequisite.first].push_back(prerequisite.second);

    // applying dfs
    vector<bool> black(noOfCourses, false);
    vector<bool> grey(noOfCourses, false);
    for (int i = 0; i < noOfCourses; i++)
        if (!dfs(graph, black, grey, i))
            return false;
    return true;
}

int main()
{
    fast;
    solve();
    return 0;
}