// accepted :) Math problem :)
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
    ll n;
    cin >> n;
    ll res = 2022 / 6;
    // ll res = (n * (n + 1) * (4 * n - 1) * div) % mod;
    res *= n;
    res %= mod;
    res *= (n + 1);
    res %= mod;
    res *= (4 * n - 1) % mod;
    res %= mod;
    cout << res << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}