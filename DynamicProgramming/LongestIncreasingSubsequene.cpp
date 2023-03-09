#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int sz = nums.size();
        vector<short> countLIS(sz, 1);
        countLIS[0] = 1;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && countLIS[j] + 1 > countLIS[i])
                    countLIS[i]++;
            }

        return *max_element(countLIS.begin(), countLIS.end());
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution s;
    cout << s.lengthOfLIS(nums);
    return 0;
}