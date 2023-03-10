#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pq priority_queue
const int cst = -10000;
vector<int> solve(vector<int> nums, int k)
{
    map<int, int> mp;
    for (int num : nums)
        mp[num]++;
    vector<pair<int, int>> v;
    for (auto it : mp)
        v.push_back({it.second, it.first});
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    vector<int> ans;
    for (int i = 0; i < k; i++)
        ans.push_back(v[i].second);
    return ans;
}

int main()
{
    fast;
    for (int i : solve({1}, 1))
        cout << i << ' ';
    return 0;
}