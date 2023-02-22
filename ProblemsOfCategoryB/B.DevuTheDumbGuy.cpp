#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    int n, x;
    cin >> n >> x;
    ll res = 0;
    vector<int> subjects(n);
    for (int &s : subjects)
        cin >> s;
    sort(subjects.begin(), subjects.end());
    for (int time : subjects)
    {
        res += (ll)time * x; // 1st wrong ans due to not casting to long long.
        if (x > 1)
            x--;
    }
    cout << res << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}
