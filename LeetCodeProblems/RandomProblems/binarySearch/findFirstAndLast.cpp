#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

vector<int> getIndcies(vector<int> &nums, int startingIdx, int trgt)
{
    int b = startingIdx;
    int e = startingIdx;
    int sz = nums.size();
    while (b >= 0 && e <= sz - 1)
    {
        bool change = false;
        if (b - 1 >= 0 && nums[b - 1] == trgt)
        {
            b--;
            change = true;
        }
        if (e + 1 < sz && nums[e + 1] == trgt)
        {
            e++;
            change = true;
        }
        if (!change)
            return {b, e};
    }
    return {b, e};
}

vector<int> searchRange(vector<int> &nums, int trgt)
{
    DPSolver;
    // apply binary search to find the position of the first element.
    if (nums.size() == 1)
        if (trgt == nums[0])
            return {0, 0};
        else
            return {-1, -1};
    int b = 0;
    int e = nums.size() - 1;
    int m = (e + b) / 2;
    while (b <= e)
    {
        if (nums[m] == trgt)
            return getIndcies(nums, m, trgt);

        else if (nums[m] < trgt)
            b = m + 1;
        else
            e = m;
        m = (e + b) / 2;
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {1, 1, 4};
    searchRange(nums, 1);
    return 0;
}