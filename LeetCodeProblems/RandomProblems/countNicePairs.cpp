#include <bits/stdc++.h
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int mod = 1000000007;
int reverseInt(int num)
{
    int rev = 0;
    while (num > 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}
int getDiff(int num1, int num2)
{
    return num1 - num2;
}
int countSimilar(vector<int> &nums, int idx, int n)
{
    long count = 0;
    for (int i = idx + 1; i < n; i++)
        if (nums[i] == n)
            count++;
        else
            return count;
    return count;
}
int countNicePairs(vector<int> &nums)
{
    DPSolver;
    for (int &num : nums)
        num = getDiff(num, reverseInt(num));
    sort(nums.begin(), nums.end());
    long count = 1;
    long res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        count += countSimilar(nums, i, nums[i]);
        res = (res % mod + (count * (count - 1)) / 2) % mod;
    }
    return count;
}

int main()
{
    vector<int> nums = {42, 11, 1, 97};
    cout << countNicePairs(nums);
    return 0;
}