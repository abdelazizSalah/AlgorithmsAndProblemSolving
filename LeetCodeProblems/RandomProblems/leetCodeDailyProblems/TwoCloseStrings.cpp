#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
bool closeStrings(string word1, string word2)
{
    DPSolver;
    if(word1.length() != word2.length())
        return false; 
    vector<int> freq1(26); 
    vector<int> freq2(26);
    for (char c : word1)
        freq1[c - 'a'] ++;
     
    for (char c : word2)
        freq2[c - 'a'] ++;
    
    for (int i = 0; i <26; i++)
        if (freq1[i] && !freq2[i])
            return false; 
        else if (freq2[i] && !freq1[i])
            return false; 
    sort(freq1.begin(), freq1.end(), greater<int>()); 
    sort(freq2.begin(), freq2.end(), greater<int>()); 
    for (int i = 0; i < word1.length(); i++)
        if (freq1[i] != freq2[i])
            return false;
     

    return true;
}

int main()
{
    cout << boolalpha << closeStrings("babzzcz", "aabbczz");
}