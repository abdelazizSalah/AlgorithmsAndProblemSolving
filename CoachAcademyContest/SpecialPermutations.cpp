#include <bits/stdc++.h>
using namespace std;
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    int x;
    cin >> x;
    vector<int> v(x);
    for (int i = x, j = 1; i > 0; i--, j++)
        v[i - 1] = j;
    if (x & 1)
    {
        swap(v[x - 1], v[x / 2]);
    }
    for (int i = 0; i < x; i++)
        cout << v[i] << " ";

    cout << endl;
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