#include <bits/stdc++.h>
using namespace std;
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                v[i][j] = 1;
            }
            else if (i == j + 1)
            {
                v[i][j] = 1;
            }
            else if (i == j - 1)
            {
                v[i][j] = 1;
            }
            else if (i == n - 1 && j == 0)
            {
                v[i][j] = 1;
            }
            else if (i == 0 && j == n - 1)
            {
                v[i][j] = 1;
            }
            else
            {
                v[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    DPSolver;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}