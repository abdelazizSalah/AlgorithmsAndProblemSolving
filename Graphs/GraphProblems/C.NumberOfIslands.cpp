#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl '\n'

//           down, right, up, left
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

void dfs(const vector<vector<bool>> &Graph, const int rows, const int columns,
         vector<vector<bool>> &visited, int nodex, int nodey)
{
    for (int i = 0; i < 4; i++)
        if (rows > nodex + dx[i] && nodex + dx[i] >= 0 && columns > nodey + dy[i] && nodey + dy[i] >= 0)
            if (Graph[nodex + dx[i]][nodey + dy[i]] && !visited[nodex + dx[i]][nodey + dy[i]])
            {
                visited[nodex + dx[i]][nodey + dy[i]] = true;
                dfs(Graph, rows, columns, visited, nodex + dx[i], nodey + dy[i]);
            }
}

void solve()
{
    /// building the graph
    int noOfRows, noOfColumns, noOfEdges;
    cin >> noOfRows >> noOfColumns >> noOfEdges;
    vector<vector<bool>> graph(noOfRows, vector<bool>(noOfColumns, false));
    for (int i = 0; i < noOfEdges; i++)
    {
        int src, dest;
        cin >> src >> dest;
        graph[--src][--dest] = true;
    }

    vector<vector<bool>> visited(noOfRows, vector<bool>(noOfColumns, false));
    int noOfIslands = 0;
    for (int i = 0; i < noOfRows; i++)
        for (int j = 0; j < noOfColumns; j++)
            if (graph[i][j] && !visited[i][j])
            {
                visited[i][j] = true; // mark the current node as visited
                noOfIslands++;
                dfs(graph, noOfRows, noOfColumns, visited, i, j);
            }

    cout << noOfIslands << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}