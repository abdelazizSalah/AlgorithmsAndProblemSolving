#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<int> dp(const vector<pair<int, int>> &vals, int idx, int num, int val)
{
    // define base case
    if (num < 0)
        return {}; // empty vector
    if (idx == vals.size())
    {
        if (num == 0)
            return {val}; // empty vector
        else
            return {}; // empty vector
    }
    auto res1 = dp(vals, idx + 1, vals[idx].first + num, vals[idx].first);
    auto res2 = dp(vals, idx + 1, vals[idx].second + num, vals[idx].second);
    if (res1.size() > 0)
    {
        res1.push_back(vals[idx].first);
        return res1;
    }
    else if (res2.size() > 0)
    {
        res2.push_back(vals[idx].second);
        return res2;
    }
    else
        return {};
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vals(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & (1 << 0)) // odd
        {
            vals[i].first = ceil(x / 2.0);
            vals[i].second = floor(x / 2.0);
        }
        else
        {
            vals[i].first = x / 2;
            vals[i].second = x / 2;
        }
    }
    auto res = dp(vals, 0, vals[0].first, vals[1].second);
    for (auto it : res)
        cout << it << ' ';
}

int main()
{
    DPSOLVER
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}