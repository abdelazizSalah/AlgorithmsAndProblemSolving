#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
void backTracking(set<vector<int>> &res, const vector<int> &nums, int i, int sz, vector<int> sentr)
{
    if (i == sz)
    {
        sort(sentr.begin(), sentr.end());
        res.insert(sentr);
        return;
    }

    sentr.push_back(nums[i]);
    backTracking(res, nums, i + 1, sz, sentr);
    sentr.pop_back();
    backTracking(res, nums, i + 1, sz, sentr);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    DPSolver;
    set<vector<int>> res;
    int sz = nums.size();
    vector<int> sent;
    backTracking(res, nums, 0, sz, sent);
    vector<vector<int>> res2;
    for (auto vec : res)
        res2.push_back(vec);
    return res2;
}

int main()
{
    DPSolver;
    vector<int> nums = {4, 4, 4, 1, 4};
    subsetsWithDup(nums);
    return 0;
}