#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int sz = nums.size();
    if (sz < 3)
    {
        return *max_element(nums.begin(), nums.end());
    }
    else
    {
        vector<int> money(sz, 0);
        money[0] = nums[0];
        money[1] = nums[1];
        money[2] = nums[2] + nums[0];
        for (int i = 3; i < sz; i++)
            money[i] = max(nums[i] + money[i - 2], nums[i] + money[i - 3]);

        return *max_element(money.begin(), money.end());
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << rob(nums);
}