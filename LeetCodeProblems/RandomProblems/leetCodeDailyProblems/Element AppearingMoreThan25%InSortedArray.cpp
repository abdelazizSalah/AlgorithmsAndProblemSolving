#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        DPSolver;
        short sz = arr.size();
        short quartile = ceil(sz / 4);
        bool changed = false;
        int currentVal = arr[0];
        int counter = 1;
        for (int i = 1; i < sz; i++)
        {
            if (counter > quartile)
                return currentVal;
            if (currentVal != arr[i])
            {
                counter = 1;
                currentVal = arr[i];
            }
            else
                counter++;
        }
        return currentVal;
    }
};