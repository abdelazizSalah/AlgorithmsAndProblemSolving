#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

int numberOfBeams(vector<string> &bank)
{
    DPSolver;
    int first_floor = 0;
    int res = 0;
    for (string s : bank)
    {
        if (!first_floor)
        {
            first_floor = count(s.begin(), s.end(), '1');
            continue;
        }
        // now first floor must have value.
        int current_floor = count(s.begin(), s.end(), '1');
        if (current_floor)
        {
            res += first_floor * current_floor;
            first_floor = current_floor;
        }
    }
    return res; 
}

int main()
{
}