#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
using ll = long long;
vector<int> allPossibleSequentialVals;
void constructAllPossibleCombinations()
{
    vector<int> intList = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++)
    {
        int val = intList[i];
        for (int j = i + 1; j < 9; j++)
        {
            val *= 10;
            val += intList[j];
            allPossibleSequentialVals.push_back(val);
        }
    }
    sort(allPossibleSequentialVals.begin(), allPossibleSequentialVals.end());
}

vector<int> sequentialDigits(int low, int high)
{
    DPSolver;
    constructAllPossibleCombinations();
    vector<int> res;
    for (auto item : allPossibleSequentialVals)
    {
        if (item < low)
            continue;
        res.push_back(item);
        if (item > high)
        { // decresing the complexity by constant factor.
            res.pop_back();
            return res;
        }
    }
    return res;
}

int main()
{
    constructAllPossibleCombinations();
    return 0;
}