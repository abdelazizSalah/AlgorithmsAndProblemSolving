#include <bits/stdc++.h>
using namespace std;
static const auto DPSolver = []()

{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();

void countSort(vector<int> &nums)
{
    // get the length of nums
    int sz = nums.size();
    // get the maximum element
    int mx = *max_element(nums.begin(), nums.end()) + 1;

    // create a count vector
    vector<int> count(mx);

    // iterate to fill the count
    for (int num : nums)
        count[num]++;

    // create indicies vector
    vector<int> indicies(mx);

    // assign the indicies
    for (int i = 1; i < mx; i++)
        indicies[i] = indicies[i - 1] + count[i - 1];

    // create new vector to be sorted.
    vector<int> sortedVec(sz);
    for (int i = 0; i < sz; i++)
    {
        int idx = indicies[nums[i]];
        sortedVec[idx] = nums[i];
        indicies[nums[i]]++;
    }

    // assign nums to the new sorted vector
    reverse(sortedVec.begin(), sortedVec.end());
    nums = sortedVec;
}

bool validateAss(const vector<int> &nums) // O(n^2)
{
    int sz = nums.size();
    for (int i = 0; i < sz; i++)
        for (int j = i + 1; j < sz; j++)
            if (nums[i] % nums[j] != 0)
                return false;
    return true;
}
bool validateDss(const vector<int> &nums) // O(n^2)
{
    int sz = nums.size();
    for (int i = 0; i < sz; i++)
        for (int j = i + 1; j < sz; j++)
            if (nums[j] % nums[i] != 0)
                return false;
    return true;
}

map<int, vector<int>> memo;

vector<int> dp(const vector<int> &nums, int idx, int sz, bool ass = false)
{
    // make it efficient
    auto it = memo.find(idx);
    if (it != memo.end())
        return it->second;

    // base cases.
    if (idx == sz - 1)
    {
        memo[idx] = {nums[idx]};
        return {nums[idx]};
    }
    else if (idx > sz)
    {
        memo[idx] = {};
        return {};
    }

    // recursive cases
    auto with = dp(nums, idx + 1, sz, ass);
    auto without = dp(nums, idx + 1, sz, ass); // leave it
    with.push_back(nums[idx]);            // take it.
    bool flagWith = ass ? validateAss(with) : validateDss(with);
    bool flagWithout = ass ? validateAss(without) : validateDss(without);
    if (flagWith && !flagWithout)
    {
        memo[idx] = with;
        return with;
    }
    else if (!flagWith && flagWithout)
    {
        memo[idx] = without;
        return without;
    }
    else if (flagWith && flagWithout)
    {
        if (with.size() > without.size())
        {
            memo[idx] = with;
            return with;
        }
        else
        {
            memo[idx] = without;
            return without;
        }
    }
    else
    {
        memo[idx] = {nums[idx]};
        return {nums[idx]};
    }
}

// 40 / 49 testcases passed
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    DPSolver;
    // countSort(nums);

    sort(nums.begin(), nums.end(), greater<>());
    auto resDss = dp(nums, 0, nums.size());

    sort(nums.begin(), nums.end());
    auto resAss = dp(nums, 0, nums.size(), true);


    return resAss.size() > resDss.size() ? resAss : resDss; 
}
