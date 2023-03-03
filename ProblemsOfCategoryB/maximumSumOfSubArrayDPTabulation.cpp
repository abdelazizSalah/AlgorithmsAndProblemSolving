/// DP SOLVERRRRRR (TABULATION)

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sz = nums.size();
    vector<int> res(sz);
    res[sz - 1] = nums[sz - 1];
    for (int i = sz - 2; i > -1; i--)
        res[i] = max(res[i + 1] + nums[i], nums[i]);

    return *max_element(res.begin(), res.end());
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &n : nums)
        cin >> n;

    cout << maxSubArray(nums);
}