#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();

int dp(const vector<int> &arr, const int k, int idx)
{
    // base case
    if (idx >= arr.size())
    {
        return 0;
    }

    vector<int> res;
    for (int i = 1; i <= k; i++)
        res.push_back(dp(arr, k, idx + i));
    int mx = arr[idx] + res[0]; // left part is only the left branch + 
    vector<int> temp_elements = {arr[idx]};
    for (int i = 1; i <= k; i++)
    {
        if (idx + i < arr.size())
            temp_elements.push_back(arr[idx + i]);
        else 
            break; // el gy kolo repeated.
        int right_part = *max_element(temp_elements.begin(), temp_elements.end()) * (i + 1); // update
        mx = max(mx, right_part);
    }
    return mx;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    DPSolver;
    // simplest base case.
    if (arr.size() == 1)
        return arr[0];
    return dp(arr, k, 0);
}

int main()
{
    // vector<int> arr = {1,15,7,9,2,5,10};
    // int k = 3;
    // vector<int> arr = {1,4,1,5,7,3,6,1,9,9,3};
    // int k = 4;
    vector<int> arr = {2, 4, 6, 8};
    int k = 2;
    cout << maxSumAfterPartitioning(arr, k);
}