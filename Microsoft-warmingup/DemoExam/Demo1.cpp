// Getting 100% score in Codility.
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl "\n"
#define pq priority_queue
int solve()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    int cntr = 1;
    for (auto i : s)
        if (i < 1)
            continue;
        else if (i == cntr)
            cntr++;
        else
            return cntr;

    return cntr;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cout << solve();
    }
    return 0;
}