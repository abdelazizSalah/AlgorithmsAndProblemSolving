#include <bits/stdc++.h>
using namespace std;

#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void movePointers(int &bgnPtr, int &endPtr, int sz)
{
    if (endPtr < sz - 1)
        endPtr++;
    bgnPtr++;
}
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int wsum = 0, l = 0, r;
        int ans = INT_MAX;
        for (r = 0; r < n; r++)
        {
            wsum += nums[r];
            while (wsum >= target)
            {
                wsum -= nums[l];
                ans = min(ans, r - l + 1);
                l++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};