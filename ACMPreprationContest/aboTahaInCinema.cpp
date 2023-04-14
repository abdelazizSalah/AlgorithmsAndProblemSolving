/// Accepted :D
#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

int main()
{
    ll n;
    cin >> n;
    n--;
    cout << (n * (n + 1)) / 2 + 1 << endl;
}