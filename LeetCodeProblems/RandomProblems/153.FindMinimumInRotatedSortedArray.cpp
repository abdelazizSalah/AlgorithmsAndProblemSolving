#include <bits/stdc++.h>
using namespace std;
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int findMin(vector<int> &nums)
{

    int sz = nums.size();
    if (sz == 1)
        return nums[0];
    int bgn = 0;
    int end = sz;

    int md = (end + bgn) / 2;
    int mn = nums[0];
    while (end > bgn && md != 0 && md != sz - 1)
    {
        // apply binary search
        if (nums[md] > nums[md - 1] && nums[md] > nums[md + 1])
            // the number is on the md right
            bgn = md + 1;
        // else if (nums[md] > nums[md - 1] && nums[md] < nums[md + 1])
        //     end = md;
        else if (nums[md] > nums[md - 1] && nums[md] < nums[md + 1]) // normal place
            if (nums[md] > nums[bgn])
                end = md;
            else
                bgn = md + 1;
        md = (end + bgn) / 2;
        mn = nums[md];
    }

    return mn;
}

int main()
{
    DPSolver;
    // vector<int> nums = {3, 4, 5, 1, 2};
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> nums = {11, 13, 15, 17};
    cout << findMin(nums);
    return 0;
}