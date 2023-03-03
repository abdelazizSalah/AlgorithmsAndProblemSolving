#include <bits/stdc++.h>
using namespace std;

int mxProduct(const vector<int> &nums, int startingIdx, int endingIdx)
{
    int mxProd = 1;
    if (startingIdx == endingIdx)
        return INT_MIN;
    for (int num = startingIdx; num < endingIdx; num++)
        mxProd *= nums[num];
    return mxProd;
}

int maxProduct(vector<int> &nums)
{
    bool negativeExist = false;
    int negIdx = -1;
    int sz = nums.size();
    if (sz == 1)
        return nums[0];
    // preprocessing loop, to remove all pairs of negatives
    for (int i = 0; i < sz; i++)
    {
        if (!negativeExist && nums[i] < 0)
        {
            negativeExist = true;
            negIdx = i;
        }
        else if (negativeExist && nums[i] < 0)
        {
            nums[i] = -nums[i];
            nums[negIdx] = -nums[negIdx];
            negativeExist = false;
            negIdx = -1;
        }
    }

    // after this array, we will have only one -ve number, so it will be our stoping condition

    // check all multiplications on the left of the negative number
    if (negIdx != -1)
    {
        if (negIdx == 0)

            return mxProduct(nums, 1, sz);

        else if (negIdx == 1 && sz == 3)

            return max(mxProduct(nums, 0, 2), mxProduct(nums, 1, sz));

        else
            return max(mxProduct(nums, 0, negIdx), mxProduct(nums, negIdx + 1, sz));
    }
    else
    {
        return mxProduct(nums, 0, sz);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << maxProduct(nums) << endl;
    return 0;
}
