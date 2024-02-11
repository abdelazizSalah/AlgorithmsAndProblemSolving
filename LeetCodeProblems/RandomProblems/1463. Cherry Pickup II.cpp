#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

bool inside(int maxRows, int maxCols, int i, int j)
{
    return i < maxRows && i > -1 && j < maxCols && j > -1;
}

map<pair<pair<int, int>, pair<int, int>>, int> memo;
vector<int> directions = {-1, 0, 1};
int dp(const vector<vector<int>> &grid, const int maxRows, const int maxCols, int i1, int j1, int i2, int j2)
{
    // make it efficient
    auto it = memo.find({{i1, j1}, {i2, j2}});
    if (it != memo.end())
        return it->second;

    // make it work.
    // base cases.
    if (!inside(maxRows, maxCols, i1, j1) || !inside(maxRows, maxCols, i2, j2))
    {
        memo[{{i1, j1}, {i2, j2}}] = 0;
        return 0;
    }
    if (i1 == maxRows - 1)
    {
        if (j1 == j2)
        {
            memo[{{i1, j1}, {i2, j2}}] = grid[i1][j1];
            return grid[i1][j1];
        }

        memo[{{i1, j1}, {i2, j2}}] = grid[i1][j1] + grid[i2][j2];
        return grid[i1][j1] + grid[i2][j2];
    }
    int mx = INT_MIN;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mx = max(mx,
                     dp(grid, maxRows, maxCols, i1 + 1, j1 + directions[i], i2 + 1, j2 + directions[j]));
        
    // recursive cases
    /// we have 9 cases
    // int c1 = dp(grid, maxRows, maxCols, i1 + 1, j1 - 1, i2 + 1, j2 - 1);
    // int c2 = dp(grid, maxRows, maxCols,
    //             i1 + 1,
    //             j1,
    //             i2 + 1,
    //             j2 - 1);
    // int c3 = dp(grid, maxRows, maxCols,
    //             i1 + 1,
    //             j1 + 1,
    //             i2 + 1,
    //             j2 - 1);

    // int c4 = dp(grid, maxRows, maxCols,
    //             i1 + 1,
    //             j1 - 1,
    //             i2 + 1,
    //             j2);
    // int c5 = dp(grid, maxRows, maxCols,
    //             i1 + 1,
    //             j1,
    //             i2 + 1,
    //             j2);
    // int c6 = dp(grid, maxRows, maxCols,
    //             i1 + 1,
    //             j1 + 1,
    //             i2 + 1,
    //             j2);

    // int c7 = dp(grid, maxRows, maxCols,
    //             i1 + 1,
    //             j1 - 1,
    //             i2 + 1,
    //             j2 + 1);
    // int c8 = dp(grid, maxRows, maxCols,
    //             i1 + 1,
    //             j1,
    //             i2 + 1,
    //             j2 + 1);
    // int c9 = dp(grid, maxRows, maxCols,
    //             i1 + 1,
    //             j1 + 1,
    //             i2 + 1,
    //             j2 + 1);

    // vector<int> v = {
    //     c1,
    //     c2,
    //     c3,
    //     c4,
    //     c5,
    //     c6,
    //     c7,
    //     c8,
    //     c9,
    // };
    // int mx = *max_element(v.begin(), v.end());
    memo[{{i1, j1}, {i2, j2}}] = j1 == j2 ? mx + grid[i1][j1] : mx + grid[i1][j1] + grid[i2][j2];
    return j1 == j2 ? mx + grid[i1][j1] : mx + grid[i1][j1] + grid[i2][j2];
}

int cherryPickup(vector<vector<int>> &grid)
{
    // DP Problem, and it should be easy to be solved, why hard?
    // maybe because we have 2 agents which are working simultanously.
    DPSolver;
    return dp(grid, grid.size(), grid[0].size(), 0, 0, 0, grid[0].size() - 1);
}

int main()
{
    vector<vector<int>> mat = {{10, 9, 7, 7, 9}, {9, 3, 4, 8, 9}, {3, 9, 3, 5, 10}};
    cherryPickup(mat);
    return 0;
}