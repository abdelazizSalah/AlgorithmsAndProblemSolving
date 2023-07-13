#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// el mushkela delw2ty fl backtracking :(

map<pair<int, pair<int, int>>, int> memo;
int solve(const vector<int> &vals, vector<bool> &vis, int val, int idx, int lvl, int parent)
{
    /// make it work
    // base case
    if (vis[val])
    {
        memo[{val, {lvl, parent}}] = 0;
        return 0;
    }
    else if (idx == vals.size() - 1)
    {
        vis[val + 1] = true;
        vis[val - 1] = true;
        return val;
    }

    // make it efficient
    // auto it = memo.find({val, {lvl, parent}});
    // if (it != memo.end())
    //     return it->second;

    // recursive logic
    int sum = val;
    int sz = vals.size();
    int mx = 0;
    bool used = false;
    for (int i = idx + 1; i < sz; i++)
    {
        vis[val + 1] = true;
        vis[val - 1] = true;
        int res = solve(vals, vis, vals[i], i, lvl + 1, val);
        if (mx < res)
        {
            used = true;
            mx = res;
        }
    }
    sum += mx;
    // backtracking logic
    // if (!used)
    // {
    vis[val + 1] = false;
    vis[val - 1] = false;
    // }

    // memo[{val, {lvl, parent}}] = sum;
    return sum;
}

int tabulationAlgo(vector<int> &vals);
int main()
{
    DPSolver;
    // vector<bool> vis(1e9);
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int &val : vals)
        cin >> val;
    cout << tabulationAlgo(vals) << endl;

    // int mx = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     swap(vals[0], vals[i]);
    //     mx = max(mx, solve(vals, vis, vals[0], 0, 1, -1));
    // }

    // cout << mx << endl;
    // return 0;
}

int tabulationAlgo(vector<int> &vals)
{
    int n = *max_element(vals.begin(), vals.end());
    vector<int> nums(n + 1);
    for (int num : vals)
        nums[num] += num;
    for (int i = 2; i <= n; i++)
        nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);

    return nums[n];
}