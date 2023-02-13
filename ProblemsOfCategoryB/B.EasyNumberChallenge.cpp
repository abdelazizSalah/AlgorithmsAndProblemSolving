#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
const int mod = 1073741824;
vector<ll> arr(100 * 100 * 100 + 1, -1);

// map<ll, ll> memo;
ll numOfDiv(ll n)
{
    // auto it = memo.find(n);
    // if (it != memo.end())
    //     return it->second;
    if (arr[n] != -1)
        return arr[n];
    ll res = 1;
    for (ll i = 1; i <= n / 2; i++)
        if (n % i == 0)
            res += 1;

    // memo[n] = res;
    arr[n] = res;
    return res;
}

void solve()
{
    ll res = 0;
    int i, j, k;
    cin >> i >> j >> k;
    for (int cnt1 = 1; cnt1 <= i; cnt1++)
        for (int cnt2 = 1; cnt2 <= j; cnt2++)
            for (int cnt3 = 1; cnt3 <= k; cnt3++)
                res += numOfDiv((cnt1 * cnt2 * cnt3) % mod) % mod;
    cout << res;
}

int main()
{
    fast;
    solve();
    return 0;
}