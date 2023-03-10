#include <bits/stdc++.h>
using namespace std;
#define DPMEMOSolver                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define pb push_back

map<pair<int, char>, pair<pair<ll, char>, pair<int, bool>>> memo;
pair<pair<ll, char>, pair<int, bool>> dpMEMO(const string &s, int idx, char num)
{
    // make it efficient
    auto it = memo.find({idx, num});
    if (it != memo.end())
        return it->second;

    // make it work
    if (idx == s.size() - 1)
    {
        if (num != '?')
        {
            memo[{idx, num}] = {{1, num}, {0, false}};
            return {{1, num}, {0, false}};
        }
        else
        {
            memo[{idx, num}] = {{2, '0'}, {1, false}};
            return {{1, num}, {0, true}};
        }
    }

    if (num == '0')
    {
        auto res = dpMEMO(s, idx + 1, s[idx + 1]);
        if (res.second.second && num == res.first.second) // if it return from ? and we took the same number, then we need to consider the other case only.
            res.first.first++;

        if (res.first.second == '0')
        {
            memo[{idx, num}] = {{res.first.first + 1, '0'}, {0, false}};
            return {{res.first.first + 1, '0'}, {0, false}};
        }
        else
        {
            memo[{idx, num}] = {{res.first.first + res.second.first + 2, '0'}, {res.second.first + 1, false}};
            return {{res.first.first + res.second.first + 2, '0'}, {res.second.first + 1, false}};
        }
    }
    else if (num == '1')
    {
        auto res = dpMEMO(s, idx + 1, s[idx + 1]);
        if (res.second.second && num == res.first.second) // if it return from ? and we took the same number, then we need to consider the other case only.
            res.first.first++;

        if (res.first.second == '1')
        {
            memo[{idx, num}] = {{res.first.first + 1, '1'}, {0, false}};
            return {{res.first.first + 1, '1'}, {0, false}};
        }
        else
        {
            memo[{idx, num}] = {{res.first.first + res.second.first + 2, '1'}, {res.second.first + 1, false}};
            return {{res.first.first + res.second.first + 2, '1'}, {res.second.first + 1, false}};
        }
    }
    else
    {
        auto res0 = dpMEMO(s, idx, '0');
        auto res1 = dpMEMO(s, idx, '1');
        if (res0.first.first > res1.first.first)
        {
            res0.second.second = true;
            memo[{idx, num}] = res0;
            return res0;
        }
        else
        {
            res1.second.second = true;
            memo[{idx, num}] = res1;
            return res1;
        }
    }
}

ll dpTab(string s)
{
    int sz = s.size();
    vector<vector<ll>> dp(sz, vector<ll>(2, 0));
    dp[0][0] = s[0] != '1';
    dp[0][1] = s[1] != '0';
    for (int i = 1; i < sz; i++)
    {
        if (s[i] == '?')
        {
            dp[i][0] = 1 + dp[i - 1][1];
            dp[i][1] = 1 + dp[i - 1][0];
        }
        else if (s[i] == '1')
            dp[i][0] = 1 + dp[i - 1][1];
        else
            dp[i][1] = 1 + dp[i - 1][0];
    }

    ll ans = 0;
    for (int i = 0; i < sz; i++)
        ans += max(dp[i][0], dp[i][1]);
    return ans;
}

void solve()
{
    memo.clear();
    string s;
    cin >> s;
    cout << dpTab(s) << endl;
}

int main()
{
    DPMEMOSolver;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}