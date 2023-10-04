#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
void backTracking(vector<vector<int>> &res, const vector<int> &nums, int i, int sz, vector<int> &sentr)
{
    if (i == sz)
    {
        res.push_back(sentr);
        return;
    }

    sentr.push_back(nums[i]);
    backTracking(res, nums, i + 1, sz, sentr);
    sentr.pop_back();
    backTracking(res, nums, i + 1, sz, sentr);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    DPSolver;
    vector<vector<int>> res;
    int sz = nums.size();
    vector<int> sent;
    backTracking(res, nums, 0, sz, sent);

    for (auto vec : res)
    {
        for (auto elem : vec)
            cout << elem << ' ';
        cout << endl;
    }
    return res;
}

int main()
{
    DPSolver;
    vector<int> nums = {1, 2, 3, 4};
    // vector<int> nums = {0};
    subsets(nums);
    return 0;
}