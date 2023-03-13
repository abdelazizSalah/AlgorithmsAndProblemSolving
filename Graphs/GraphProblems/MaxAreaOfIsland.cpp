#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

int dfs(const vector<vector<int>> &graph, int nodeX, int nodeY, vector<vector<bool>> &vis)
{
    // mark the node as visited
    vis[nodeX][nodeY] = true;
    int noOfRows = graph.size();
    int noOfCols = graph[0].size();
    int area = 1;
    for (int i = 0; i < 4; i++)
    {
        int newX = nodeX + dx[i];
        int newY = nodeY + dy[i];
        if (newX >= 0 && newX < noOfRows && newY < noOfCols && newY >= 0)
            if (!vis[newX][newY] && graph[newX][newY] == 1)
                area += dfs(graph, newX, newY, vis);
    }
    return area;
}

int maxAreaOfIsland(const vector<vector<int>> &grid)
{
    // iterate over the graph and find all components
    int mx = 0; // max area of island
    int numberOfRows = grid.size();
    int numberOfCols = grid[0].size();
    vector<vector<bool>> visited(numberOfRows, vector<bool>(numberOfCols, false));

    // iterate over the graph
    for (int i = 0; i < numberOfRows; i++)
        for (int j = 0; j < numberOfCols; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                // dfs
                int area = dfs(grid, i, j, visited);
                mx = max(mx, area);
            }
        }
    return mx;
}

void solve()
{
    // reading the input
    int noOfRows, noOfColumns, noOfEdges;
    cin >> noOfRows >> noOfColumns;
    vector<vector<int>> graph(noOfRows, vector<int>(noOfColumns, false));
    for (int i = 0; i < noOfRows; i++)
        for (int j = 0; j < noOfColumns; j++)
            cin >> graph[i][j];

    // applying the logic
    cout << maxAreaOfIsland(graph);
}

int main()
{
    DPSOLVER
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}