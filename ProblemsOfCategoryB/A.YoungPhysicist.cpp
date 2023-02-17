#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> z[i];

    int sumx = 0, sumy = 0, sumz = 0;
    for (int i = 0; i < n; i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumz += z[i];
    }
    if (sumx == 0 && sumy == 0 && sumz == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}