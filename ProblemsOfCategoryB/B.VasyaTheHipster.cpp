#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

void solve()
{
    int red, blue;
    cin >> red >> blue;

    int fashionable = min(red, blue);
    // int nonFashonable = (max(red, blue) - fashionable) / 2;
    cout << fashionable << " " << (max(red, blue) - fashionable) / 2 << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}