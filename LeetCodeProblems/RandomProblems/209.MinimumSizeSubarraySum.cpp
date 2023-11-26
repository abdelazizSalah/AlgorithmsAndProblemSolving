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
int minSubArrayLen(int target, vector<int> &nums)
{

    DPSolver;
    int bgnPtr = 0;
    int endPtr = 1;
    int sz = nums.size();
    int mnSize = INT_MAX;
    int cumSum = nums[0];
    bool stopAdding = false;
    while (endPtr <= sz - 1 && bgnPtr != endPtr)
    {
        if (cumSum + (nums[endPtr] * !stopAdding) >= target)
        {
            if (!stopAdding)
                cumSum += nums[endPtr];
            if (endPtr < sz - 1)
                endPtr++;
            else
                stopAdding = true;
            mnSize = min(mnSize, endPtr - bgnPtr);
            cumSum -= nums[bgnPtr];
            bgnPtr++;
        }
        // else if (cumSum + nums[endPtr] > target)
        // {
        //     cumSum -= nums[bgnPtr];
        //     bgnPtr++;
        // }
        else
            // less
            cumSum += nums[endPtr++];
    }
    return mnSize + 1;
}

int main()
{
    int tr = 11;
    vector<int> v = {1, 2, 3, 4, 5};
    cout << minSubArrayLen(tr, v);
    return 0;
}