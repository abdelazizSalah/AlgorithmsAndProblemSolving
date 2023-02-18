#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"

void shift(string &s, int i, int swaps)
{

    ll j = i + swaps;
    char ch = s[j];

    while (j > i)
    {
        s[j] = s[j - 1];
        j--;
    }

    s[j] = ch;
}

void solve()
{

    string s;
    cin >> s;
    ll k;
    cin >> k;

    ll n = s.size();
    // cout << k << "\n";
    for (ll i = 0; i < n && k > 0; i++)
    {

        char ch = s[i];
        ll swaps = 0;

        for (ll j = i + 1; j < n; j++)
        {

            if (j - i > k)
                break;

            if (s[j] > ch)
            {
                swaps = j - i;
                ch = s[j];
            }
        }
        if (swaps == 0)
            continue;

        shift(s, i, swaps);
        k -= swaps;
    }

    cout << s;
}

int main()
{
    fast;
    solve();
    return 0;
}