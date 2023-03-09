#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void solve()
{
    int n, k;
    cin >> n >> k;
    map<char, int> mp;
    int cntr = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if ('a' <= c && c <= 'z')
        {
            if (mp[toupper(c)] > 0)
            {
                cntr++;
                mp[toupper(c)]--;
            }
            else
                mp[c]++;
        }
        else
        {
            if (mp[tolower(c)] > 0)
            {
                cntr++;
                mp[tolower(c)]--;
            }
            else
                mp[c]++;
        }
    }

    for (auto it : mp)
    {
        if (k <= 0)
            break;
        while (it.second >= 2)
        {
            if (k <= 0)
                break;
            cntr++;
            k--;
            it.second -= 2;
        }
    }
    cout << cntr << '\n';
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}