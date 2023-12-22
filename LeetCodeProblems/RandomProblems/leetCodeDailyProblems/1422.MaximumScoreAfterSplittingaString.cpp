#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
int maxScore(string s)
{
    DPSolver;
    int sz = s.length();
    int leftScore = 0;
    int rightScore = count(s.begin(), s.end(), '1');
    int mx = 0;

    for (int i = 0; i < sz - 1; ++i)
    {
        if (s[i] == '0')
            leftScore++;
        else
            rightScore--;
        mx = max(leftScore + rightScore, mx);
    }
    return mx;
}

int main()
{
    cout << maxScore("0100");
}
