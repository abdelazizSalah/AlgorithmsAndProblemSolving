#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntr = 1;
    for (int i = 2; i < n; i++)
        if (s[i] != s[i - 2])
            cntr++;
    return cntr;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}