#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}
();
using namespace std;

int main()
{
    vector<int> nums = {-10,8,6,7,-2,-3};
    map<int, pair<bool, bool>> flags; // first bool for existance of -ve, second for existance of +ve.
    for (int num : nums)
        if (num < 0)
            flags[-num].first = true;
        else
            flags[num].second = true;

    int mx = -1;
    for (auto item : flags)
        if (item.second.first && item.second.second)
            mx = max(mx, item.first);
        
    cout << mx; 
    return 0;
}