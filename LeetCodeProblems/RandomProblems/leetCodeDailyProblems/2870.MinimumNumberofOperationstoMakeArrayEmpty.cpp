#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

map<pair<int, int>, int> memo;
int dp(int n, int count, bool firstState)
{
    auto it = memo.find({n, count});
    if (it != memo.end())
        return it->second;
    if (count == 1 || count < 0)
    {
        memo[{n, count}] = -1;
        return -1;
    }
    else if (!count)
    {
        memo[{n, count}] = 1;
        return 1;
    }
    int subTwo = dp(n, count - 2, false);
    int subThree = dp(n, count - 3, false);
    if (subTwo == -1 && subThree == -1)
    {
        memo[{n, count}] = -1;
        return -1;
    }
    else if (subTwo == -1)
    {
        memo[{n, count}] = !firstState + subThree;
        return !firstState + subThree;
    }
    else if (subThree == -1)
    {
        memo[{n, count}] = !firstState + subTwo;
        return !firstState + subTwo;
    }
    else
    {
        memo[{n, count}] = !firstState + min(subThree, subTwo);
        return !firstState + min(subThree, subTwo);
    }
    return -1;
}

int minOperations(vector<int> &nums)
{
    DPSolver;
    map<int, int> mp;
    for (int n : nums)
        mp[n]++;

    int operations = 0;
    for (auto item : mp)
    {
        int res = dp(item.first, item.second, true);
        if (res == -1)
            return -1;
        operations += res;
    }
    return operations;
}

int main()
{
    vector<int> nums = {2, 3, 3, 2, 2, 4, 2, 3, 4};
    cout << minOperations(nums);
    return 0;
}