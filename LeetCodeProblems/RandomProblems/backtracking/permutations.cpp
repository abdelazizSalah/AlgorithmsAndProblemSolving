#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void permutations(const vector<int> &nums, vector<vector<int>> &res, vector<bool> &taken, vector<int> per, const int sz, int lvl)
{
    if (lvl == sz)
    {
        res.push_back(per);
        return;
    }
    for (int i = 0; i < sz; i++)
    {
        if (!taken[i])
        {
            taken[i] = true;
            per.push_back(nums[i]);
            permutations(nums, res, taken, per, sz, lvl + 1);
            per.pop_back();
            taken[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    DPSolver;
    vector<vector<int>> res;
    vector<bool> taken(nums.size());
    vector<int> per;
    permutations(nums, res, taken, per, nums.size(), 0);
    for (auto vec : res)
    {
        for (auto num : vec)
            cout << num << ' ';
        cout << endl;
    }
    return res;
}
int main()
{
    DPSolver;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    permute(nums);
    return 0;
}