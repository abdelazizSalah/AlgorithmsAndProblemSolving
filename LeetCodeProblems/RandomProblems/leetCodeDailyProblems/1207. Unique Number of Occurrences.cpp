#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{   
    DPSolver; 
    priority_queue<int> pq; 
    map<int, int> mp; 
    for (int a : arr) 
        mp[a]++; 
    
    for (auto item : mp)
        pq.push(item.second); 
    
    while(pq.size()){
        int tp = pq.top(); 
        pq.pop(); 
        if (pq.size() && tp == pq.top())
            return false; 
    }
   const int * p = &arr[0]; 
    return true; 
}


void increment(const int&i ){
    ++ const_cast<int&>(i); 
}

struct S {
    ~S() {cout << 'x';} ;
}

int main () {
    string s1 = "hello";
    string s2 = move(s1);
    cout << s1.size(); 
    cout << s2.size(); 
    return 0;  
}
