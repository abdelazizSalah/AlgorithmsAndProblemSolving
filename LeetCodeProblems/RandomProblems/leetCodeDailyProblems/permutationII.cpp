#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    set<vector<int>> res;
    sort(nums.begin(), nums.end());
    do
    {
        res.insert(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    vector<vector<int>> final_res;
    for (auto element : res)
        final_res.push_back(element);
    return final_res;
}


int main () {
    return 0; 
}