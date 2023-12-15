#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

string destCity(vector<vector<string>> &paths)
{
    DPSolver; 
    map<string, int> graph;
    for (auto path : paths){
        graph[path[0]]++; 
        graph[path[1]] = graph[path[1]]; 
    }
    for (auto node : graph)
        if(!node.second)
            return node.first; 
    return "";
    
}