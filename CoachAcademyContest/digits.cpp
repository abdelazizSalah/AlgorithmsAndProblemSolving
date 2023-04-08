#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll log_a_to_base_b(ll val, ll base)
{
    return ceil(log2(val) / log2(base));
}

int main()
{
    ll x, y;
    cin >> x >> y;
    int res = log_a_to_base_b(x, y);
    if (res == 0)
        cout << 1;
    else
        cout << res;
}