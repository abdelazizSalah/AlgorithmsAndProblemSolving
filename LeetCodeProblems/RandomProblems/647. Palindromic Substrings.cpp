#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

// two pointers solution.
bool isPalindrome(string &s)
{
    int sz = s.length() - 1;
    int bgn = 0;
    while (bgn <= sz)
    { // O(n / 2)
        if (s[bgn] != s[sz])
            return false;
        bgn++, sz--;
    }
    return true;
}

int countSubstrings(string s)
{
    DPSolver; 
    // brute force solution
    int res = 0;
    int sz = s.length();
    for (int i = 0; i < sz; i++) // O(n)
    {
        string subStr = "";
        subStr += s[i];
        for (int j = i + 1; j < sz; j++) // O(n)
        {
            subStr += s[j];
            res += isPalindrome(subStr); // O(n/2) 
        }
    }
    return res + sz; 
}

int main()
{
    string s = "abc";
    cout << countSubstrings(s); 
    return 0;
}