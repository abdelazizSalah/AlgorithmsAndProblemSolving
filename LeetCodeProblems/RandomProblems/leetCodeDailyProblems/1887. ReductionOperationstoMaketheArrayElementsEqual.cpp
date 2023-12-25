#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

int reductionOperations(vector<int> &nums)
{
    DPSolver;
    map<int, int> mp;
    set<int> s;
    for (int n : nums)
    {
        mp[n]++;
        s.insert(n);
    }
    int counter = 0; 
    int sz = s.size(); 
    int operations = 0; 
    for (int n : s){
        operations += mp[n] * (counter++); 
    }

    return operations; 
}

int main () {
    vector<int> nums = {1,1,2,2,3}; 
    cout << reductionOperations(nums); 
    return 0; 
}