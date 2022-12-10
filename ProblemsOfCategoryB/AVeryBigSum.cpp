#pragma once
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }

    cout << sum;
}

int main()
{
    fast;
    solve();
    return 0;
}