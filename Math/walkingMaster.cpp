#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = b - d + c;
    if (x > a || d < b || (c > a && d == b))
    {
        cout << -1 << '\n';
        return;
    }

    cout << a - x + d - b << '\n';
}

int main()
{
    DPSOLVER;
    int t;
    cin >> t;
    while ((t--))
        solve();
    return 0;
}