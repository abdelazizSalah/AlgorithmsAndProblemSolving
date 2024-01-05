#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
#include<bits/stdc++.h>
using namespace std;


 int lengthOfLIS(vector<int>& nums) {
    DPSolver;
        int sz = nums.size(); 
        vector<short> countLIS(sz,1);
        countLIS[0] = 1; 
        for(int i = 0; i < sz; i++)
           for(int j = 0; j < i; j++) {
               if(nums[i] > nums[j] && countLIS[j] + 1 > countLIS[i])
                    countLIS[i]++; 
           }
        
        return *max_element(countLIS.begin(), countLIS.end());
    }