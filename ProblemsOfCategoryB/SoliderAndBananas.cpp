#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll k, n, w;
    cin >> k >> n >> w;
    ll totalCost = (w * (w + 1) * k) / 2;
    if (totalCost > n)
        cout << totalCost - n;
    else
        cout << 0;
}