#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool isBoundry(int x, int y, int i, int j)
{
    return i == x - 1 || i == 0 || j == 0 || j == y - 1;
}

bool notValidIndx(int x, int y, int i, int j)
{
    return i > x - 1 || i < 0 || j < 0 || j > y - 1;
}

int dfs(const vector<vector<int>> &G, vector<vector<bool>> &vis, int srcx, int srcy)
{
    // base cases
    if (notValidIndx(G.size(), G[0].size(), srcx, srcy) || !G[srcx][srcy] || vis[srcx][srcy])
        return 0;

    if (isBoundry(G.size(), G[0].size(), srcx, srcy))
        return -1;
    // mark as visited
    vis[srcx][srcy] = true;

    // visit up
    int up = dfs(G, vis, srcx, srcy - 1);
    // visit down
    int down = dfs(G, vis, srcx, srcy + 1);
    // visit left
    int left = dfs(G, vis, srcx - 1, srcy);
    // visit right
    int right = dfs(G, vis, srcx + 1, srcy);

    if (up != -1 && down != -1 && left != -1 && right != -1)
        return 1 + up + down + left + right;
    else
        return -1;
}

int main()
{
    DPSolver;
    // reading the input
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m));
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int tempRes = dfs(grid, visited, i, j);
            if (tempRes != -1)
                res += tempRes;
        }

    cout << res;
    return 0;
}