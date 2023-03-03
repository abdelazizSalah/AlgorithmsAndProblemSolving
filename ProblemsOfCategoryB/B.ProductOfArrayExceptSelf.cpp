#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    long long productOfAll = 1;
    long long productOfAllWithoutZero = 1;
    bool zeroExist = false;
    bool multipleZeros = false;
    int sz = nums.size();
    for (int num : nums)
    {
        if (num == 0 && !zeroExist)
        {
            zeroExist = true;
        }
        else if (zeroExist && num == 0)
            multipleZeros = true;
        else
        {
            productOfAll *= num;
        }
    }

    if (multipleZeros)
    { // all numbers must be zeros.
        return vector<int>(sz, 0);
    }
    vector<int> res(sz, 0);

    for (int i = 0; i < sz; i++)
    {
        if (zeroExist && nums[i] != 0)
        {
            res[i] = 0;
        }
        else if (!zeroExist && nums[i] != 0)
        {
            res[i] = (productOfAll / nums[i]);
        }
        else
        {
            res[i] = productOfAll;
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> res = productExceptSelf(nums);
    for (int num : res)
        cout << num << " ";

    return 0;
}