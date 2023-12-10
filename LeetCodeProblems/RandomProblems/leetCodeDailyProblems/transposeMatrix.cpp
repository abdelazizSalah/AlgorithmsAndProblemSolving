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
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        DPSolver;
        int rows = matrix[0].size();
        int cols = matrix.size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        for (int j = 0; j < rows; j++)
            for (int i = 0; i < cols; i++)
            {
                res[j][i] = matrix[i][j];
            }
        return res;
    }
};