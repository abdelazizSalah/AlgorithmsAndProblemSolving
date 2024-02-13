#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

bool isPalindrome (const string &s) {
    int bgn = 0, end = s.length() - 1;
    while (bgn >= end) {
        if (s[bgn++] != s[end--])
            return false;

    }
    return true; 
}

string firstPalindrome(vector<string> &words)
{
    DPSolver; 
    for (string s : words)
        if(isPalindrome(s))
            return s;
    return "" ;
}

int main()
{
    
}