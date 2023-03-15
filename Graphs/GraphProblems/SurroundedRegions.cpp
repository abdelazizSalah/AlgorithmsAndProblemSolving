// fe mushkela fl code e3mlha debug w 7lha bukra
#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
//            right, left, down, up
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
short dfs(vector<vector<char>> &graph, vector<vector<short>> visited, int i, int j, int proNeg = 1)
{
    int rows = graph.size();
    int cols = graph[0].size();
    // define base case
    if (proNeg == -1 || (i == rows - 1 || j == cols - 1 || i == 0 || j == 0) && graph[i][j] == 'O')
    {
        visited[i][j] = -1;
        proNeg = -1;
        // return -1;
    }

    if (visited[i][j] != -1)
        visited[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        int newX = i + dx[k];
        int newY = j + dy[k];
        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && visited[newX][newY] == 0)
        {
            if (graph[newX][newY] == 'O')
                if (dfs(graph, visited, newX, newY, proNeg) != 1)
                {
                    return -1;
                }
                else
                {
                    graph[i][j] = 'X';
                    return 1;
                }
        }
    }
    // if I have no neighbours with O and I am not on the boarder , then I am a region which satisfy the equation.
    if (visited[i][j] != -1 && proNeg != -1)
    {
        graph[i][j] = 'X';
        return 1;
    }
    else
        return -1;
}

void solve(vector<vector<char>> &graph)
{
    int n = graph.size();
    int m = graph[0].size();
    vector<vector<short>> visited(n, vector<short>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'O' && !visited[i][j])
            {
                dfs(graph, visited, i, j);
            }
        }
}

void solveGraph()
{

    vector<vector<char>>
        board = {{'O', 'O', 'O', 'O', 'X', 'X'},
                 {'O', 'O', 'O', 'O', 'O', 'O'},
                 {'O', 'X', 'O', 'X', 'O', 'O'},
                 {'O', 'X', 'O', 'O', 'X', 'O'},
                 {'O', 'X', 'O', 'X', 'O', 'O'},
                 {'O', 'X', 'O', 'O', 'O', 'O'}};
    solve(board);
    for (auto it : board)
    {
        for (char c : it)
            cout << c;
        cout << '\n';
    }
}

int main()
{
    DPSOLVER;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solveGraph();
    }
    return 0;
}