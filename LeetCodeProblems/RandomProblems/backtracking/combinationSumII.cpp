#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
bool backTracking(vector<vector<int>> &res, const vector<int> &nums, const int &trgt, int i, int sz, vector<int> summerVec, int sum)
{
    if (trgt == sum)
    {
        res.push_back(summerVec);
        return true;
    }
    else if (trgt < sum || i == sz)
        return false;
    summerVec.push_back(nums[i]);
    bool with = backTracking(res, nums, trgt, i + 1, sz, summerVec, sum + nums[i]);
    summerVec.pop_back();
    if (!with)
        return true;
    int j = i + 1;
    while (j < sz)
        if (nums[i] == nums[j])
            j++;
        else
            break;
    bool without = false;
    if (j < sz)
        without = backTracking(res, nums, trgt, j, sz, summerVec, sum);
    return with || without;
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    DPSolver;
    sort(candidates.begin(), candidates.end());
    int sum = 0;
    vector<int> summer;
    int sz = candidates.size();
    vector<vector<int>> res;
    backTracking(res, candidates, target, 0, sz, summer, sum);
    return res;
}

int main()
{
    DPSolver;
    vector<int> nums = {2, 5, 2, 1, 2};
    int trgt = 5;
    combinationSum2(nums, trgt);
    return 0;
}