#pragma once
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void solve()
{
    // reading the data
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    // applying the logic

    // if they start at the same location then we are done
    if (x1 == x2)
    {
        cout << "YES";
        return;
    }

    // if they are moving with the same velocity
    // and they were not on the same position then it is impossible to meet again
    if (v1 == v2)
    {
        cout << "NO";
        return;
    }

    /// it is very important to apply casting here
    float res = float(x1 - x2) / (v2 - v1); // this is the result equation
    int intRes = int(res);                  // the int from that result

    // if the result is float or negative then the result is wrong
    if (res != intRes || res < 0)
    {
        cout << "NO";
        return;
    }

    cout << "YES";
}

int main()
{
    fast;
    solve();
    return 0;
}