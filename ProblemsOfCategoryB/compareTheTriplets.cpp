#pragma once
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void solve()
{
    vector<int> Alice(3);
    vector<int> Bob(3);
    int aliceRes = 0;
    int bobRes = 0;

    for (int &a : Alice)
        cin >> a;
    for (int &b : Bob)
        cin >> b;

    for (int i = 0; i < 3; i++)
        if (Alice[i] > Bob[i])
            aliceRes++;
        else if (Bob[i] > Alice[i])
            bobRes++;

    cout << aliceRes << ' ' << bobRes;
}

int main()
{
    fast;
    solve();
    return 0;
}