#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

string frequencySort(string s)
{
    DPSolver;
    map<char,int> alphabets;
    for (char c : s)
        alphabets[c]++;
    s.clear();
    priority_queue<pair<int,char>> pq;
    for (auto item : alphabets)
        pq.push({item.second, item.first}); 
    while(pq.size()) {
        auto top = pq.top(); 
        while (top.first){
            s+= top.second; 
            top.first--; 
        }
        pq.pop();
    }
    return s; 
}

int main () {
    string s = "Aabb";
    string s2 = "cccaaa";
    string s3 = "tree";
    cout << frequencySort(s) << endl;
    cout << frequencySort(s2) << endl;
    cout << frequencySort(s3) << endl;
    return 0;
}