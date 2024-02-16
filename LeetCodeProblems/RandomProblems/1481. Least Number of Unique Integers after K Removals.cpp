#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;


int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; 
        map<int,int> mp;
        for (int i : arr)
            mp[i] ++; 
        for (auto item : mp)
            pq.push({item.second, item.first}); 
        while (pq.size()) {
            auto tp = pq.top(); 
            if (tp.first <= k){
                k-= tp.first; 
                pq.pop(); 
            } else 
                return pq.size(); 
        }
        return 0;
    }