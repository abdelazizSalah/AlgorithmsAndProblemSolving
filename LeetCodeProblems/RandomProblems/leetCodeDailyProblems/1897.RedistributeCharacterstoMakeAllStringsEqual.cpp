#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
bool makeEqual(vector<string> &words)
{
    DPSolver; 
    map<char,int> mp; 
    for (string word : words)
        for (char c : word)
            mp[c]++; 

    int sz = words.size();
    for (auto item : mp)
        if (item.second % sz)
            return false; 
    return true; 
}

int main()
{
}