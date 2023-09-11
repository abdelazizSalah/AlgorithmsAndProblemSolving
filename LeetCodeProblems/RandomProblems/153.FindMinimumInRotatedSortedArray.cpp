#include <bits/stdc++.h>
using namespace std;
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int findMin(vector<int> &nums)
{
    int sz = nums.size();
    int bgn = 0;
    int end = sz - 1;
    int mn = nums[0];
    int md = (end + bgn) / 2;
    while (end > bgn)
    {
        if (nums[md] < nums[bgn] && nums[md] < nums[end])
            end = md;

        else if (nums[md] > nums[bgn] && nums[md] > nums[end])
            bgn = md + 1;
        else if (nums[md] > nums[bgn] && nums[md] < nums[end])
            end = md;
        else
        {
            mn = min(nums[md + 1], nums[md]);
            break;
        }
        if (nums[md] < mn)
            mn = nums[md];
        md = (end + bgn) / 2;
    }
    if (md < sz && md > 0)
        mn = min(mn, nums[md]);
    return mn;
}

int main()
{
    DPSolver;
    // vector<int> nums = {3, 4, 5, 1, 2};
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums = {11, 13, 15, 17};
    cout << findMin(nums);
    return 0;
}