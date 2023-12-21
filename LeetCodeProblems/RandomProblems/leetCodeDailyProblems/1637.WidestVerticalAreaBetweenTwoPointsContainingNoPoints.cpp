#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>> &points)
{
    DPSolver; 
    sort(points.begin(), points.end());
    int mxDif = INT_MIN;
    int sz = points.size();
    for (int i = 0; i < sz - 1; i++)
        mxDif = max(mxDif, points[i + 1][0] - points[i][0]);
    return mxDif;
}

int main()
{
    vector<vector<int>> points;
    points.push_back({1, 2});
    points.push_back({5, 2});
    points.push_back({3, 2});
    points.push_back({4, 2});
    maxWidthOfVerticalArea(points);
    return 0;
}