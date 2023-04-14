#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using ll = long long;

int base10ToBase6(int num)
{
    int result = 0;
    int base = 1;

    while (num > 0)
    {
        int remainder = num % 6;
        result += remainder * base;
        base *= 10;
        num /= 6;
    }

    return result;
}

void printMaze(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

map<pair<int, int>, int> memo;
ll applyDP(const vector<vector<int>> &grid, int i, int j)
{
    // make it efficient
    auto it = memo.find({i, j});
    if (it != memo.end())
    {
        return it->second;
    }
    // make it work
    if (i >= grid.size() || j >= grid[0].size())
    {
        return 0;
    }
    // base case
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
    {
        memo[{i, j}] = grid[i][j];
        return grid[i][j];
    }

    // try down
    ll down = applyDP(grid, i + 1, j);

    // try right
    ll right = applyDP(grid, i, j + 1);

    // return maximum
    memo[{i, j}] = base10ToBase6(max(down, right) * grid[i][j]);
    return base10ToBase6(max(down, right) * grid[i][j]);
}

void solve()
{
    int r, c;
    cin >> r >> c;
    memo = map<pair<int, int>, int>();
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            // converting the number to base 6
            grid[i][j] = base10ToBase6(grid[i][j]);
        }

    // we need to get the maximum number of trailing zeros
    // in the base 6 representation of the numbers in the grid
    cout << applyDP(grid, 0, 0) << endl;
}

int main()
{
    DPSOLVER;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}