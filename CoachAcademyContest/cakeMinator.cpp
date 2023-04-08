#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using ll = long long;
void solve()
{
    // reading the grid
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    map<int, bool> colsExist;
    map<int, bool> rowsExist;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                colsExist[j] = true;
                rowsExist[i] = true;
            }
        }
    // iterate over cols first
    ll ans = 0;
    int colsCount = 0;
    for (int i = 0; i < c; i++)
    {
        if (!colsExist[i])
        {
            ans += r;
            colsCount++;
        }
    }
    // iterate over rows
    for (int i = 0; i < r; i++)
    {
        if (!rowsExist[i])
        {
            ans += c - colsCount;
        }
    }
    cout << ans << endl;
}

int main()
{
    DPSOLVER;
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}