#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
void solve()
{
    ll a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    if (a1 == 0)
    {
        cout << 1 << '\n';
        return;
    }
    // writing one condition
    ll mn = min(a2, a3);
    ll mx = max(a2, a3);
    if (a1 + mn >= mx)
    {
        ll sum = a1 + a2 + a3;
        if (a4 > (mn + a1 + 1 - mx))
        {
            cout << sum + (mn + a1 + 1 - mx) << '\n';
            return;
        }
        else
        {
            cout << sum + a4 << '\n';
            return;
        }
    }
    else
        cout << 2 * (mn + a1) + 1 << '\n';
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