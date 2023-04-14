// Accepted :D
#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

void solve()
{
    // Read the data
    int n;
    cin >> n;
    vector<int> v(n);
    pair<bool, bool> comb = {false, false};
    for (int &i : v)
    {
        cin >> i;
        if (i & 1)
            comb.first = true;
        else
            comb.second = true;
    }
    if (comb.first && comb.second)
        sort(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
}
int main()
{
    DPSOLVER;
    solve();
    return 0;
}
