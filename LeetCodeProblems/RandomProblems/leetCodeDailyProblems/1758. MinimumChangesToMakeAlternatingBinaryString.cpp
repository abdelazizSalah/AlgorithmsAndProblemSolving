#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

int evaluate(string s)
{
    char lastDig = s[0];
    int len = s.length();
    int counter = 0;
    for (int i = 1; i < len; i++)
    {
        if (lastDig == s[i])
        {
            counter++;
            lastDig = s[i] == '0' ? '1' : '0';
        }
        else
            lastDig = s[i];
    }
    return counter;
}

int minOperations(string s)
{
    DPSolver;
    int withoutModification = evaluate(s);
    s[0] = s[0] == '0' ? '1' : '0';
    int withModification = evaluate(s) + 1;
    return min(withoutModification, withModification);
}

int main()
{
    cout << minOperations("0100") << endl;
    cout << minOperations("01") << endl;
    cout << minOperations("1111") << endl;
    cout << minOperations("10010100") << endl;

    return 0;
}