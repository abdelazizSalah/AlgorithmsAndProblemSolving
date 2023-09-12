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
    int mn = 0;
    int md = (end + bgn) / 2;
    while (end > bgn)
    {
        if ((nums[md] < nums[bgn] && nums[md] < nums[end]) || nums[md] > nums[bgn] && nums[md] < nums[end])
            end = md;

        else if (nums[md] > nums[bgn] && nums[md] > nums[end])
            bgn = md + 1;
        else
        {
            if (nums[md + 1] < nums[md] && nums[md + 1] < nums[mn])
                mn = md + 1;
            else if (nums[md] < nums[mn])
                mn = md;

            break;
        }
        if (md < mn)
            mn = md;
        md = (end + bgn) / 2;
    }
    if (md < sz && md > 0 && nums[md] < nums[mn])
        return md;
    return mn;
}
int findMax(vector<int> &nums)
{
    int sz = nums.size();
    int bgn = 0;
    int end = sz - 1;
    int mx = 0;
    int md = (end + bgn) / 2;
    while (end > bgn)
    {
        if (nums[md] < nums[bgn] && nums[md] < nums[end])
            end = md;
        else if ((nums[md] > nums[bgn] && nums[md] > nums[end]) || (nums[md] < nums[end] && nums[md] > nums[bgn]))
            bgn = md + 1;
        else
        {
            if (nums[md + 1] > nums[md])
            {
                if (nums[md + 1] > nums[mx])
                    mx = md + 1;
            }
            else
            {
                if (nums[md] > nums[mx])
                    mx = md;
            }

            break;
        }
        if (nums[md] > nums[mx])
            mx = md;
        md = (end + bgn) / 2;
    }
    if (md < sz && md > 0)
        if (nums[md] > nums[mx])
            return md;
    return mx;
}

int BS(vector<int> &nums, int strtPos, int endPos, int trgt)
{
    if (strtPos == endPos)
        return nums[strtPos] == trgt ? strtPos : -1;
    int mdPos = (endPos + strtPos) / 2;
    while (endPos > strtPos)
    {
        if (nums[mdPos] > trgt)
            endPos = mdPos;
        else if (nums[mdPos] < trgt)
            strtPos = mdPos + 1;
        else
            return mdPos;
        mdPos = (endPos + strtPos) / 2;
    }
    if (mdPos <= endPos && mdPos >= strtPos)
        if (nums[mdPos] == trgt)
            return mdPos;
    return -1;
}

int search(std::vector<int> &nums, int target)
{
    int mxIdx = findMax(nums);
    int mnIdx = findMin(nums);
    if (mnIdx < mxIdx)
        return BS(nums, mnIdx, mxIdx, target);
    else
    {
        int leftPart = BS(nums, 0, mxIdx, target);
        int rightPart = BS(nums, mnIdx, nums.size() - 1, target);
        if (leftPart != -1)
            return leftPart;
        else if (rightPart != -1)
            return rightPart;
        else
            return -1;
    }
}

int main()
{
    DPSolver;
    vector<int> nums = {3, 4, 5, 1, 2};
    // nums = {2, 3, 4, 5, 6, 1};
    // nums = {4, 5, 1, 2, 3};
    // nums = {2, 3, 4, 5, 1};
    // nums = {5, 1, 2, 3, 4};
    // nums = {2, 3, 1};
    // nums = {2, 1};
    nums = {3, 1};
    nums = {5, 7, 8, 0, 3, 4};
    // nums = {4, 5, 6, 7, 0, 1, 2};
    // nums = {11, 13, 15, 17};
    // nums = {11, 13, 15, 17};
    // cout << nums[findMax(nums)] << ' ' << nums[findMin(nums)];
    // cout << nums[findMin(nums)] << ' ' << nums[findMax(nums)];
    cout << search(nums, 7);
    return 0;
}