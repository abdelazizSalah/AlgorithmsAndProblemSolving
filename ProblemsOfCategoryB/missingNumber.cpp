#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int sz = nums.size();
    vector<bool> vis(sz + 1);
    for (int num : nums)
        vis[num] = true;

    for (int i = 0; i < sz; i++)
        if (!vis[i])
            return i;

    return sz;
}

// another solution.
int missingNumber2(vector<int> &nums)
{
    int sz = nums.size();
    int res = (sz * (sz + 1)) / 2;
    int sum = 0;
    for (int num : nums)
        sum += num;
    return res - sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << missingNumber(nums);
}