#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using ll = long long;
using namespace std;
#pragma GCC optimize("O3", "unroll-loops")

string customSortString(string order, string s)
{
    DPSolver; 

    /// create a map 
    ///     key: characters in the order string
    ///     value: their index. 
    map<char,int> mp; 
    int orderLen = order.length(); 
    for (int i = 0; i < orderLen; i++)
        mp[order[i]] = i+1; 
    
    /// create a vector of pairs
    ///     first: the value from the map. 
    ///     second: character
    vector<pair<int,char>> permutedS; 

    /// iterate over s, and insert {mp[s[i]], s[i]}
    for(char c:s)
        permutedS.push_back({mp[c], c});

    /// sort them 
    sort(permutedS.begin(), permutedS.end()); 

    string result= ""; 
    for (auto item : permutedS)
        result += item.second; 
    
    return result; 
}

int main()
{

    return 0;
}