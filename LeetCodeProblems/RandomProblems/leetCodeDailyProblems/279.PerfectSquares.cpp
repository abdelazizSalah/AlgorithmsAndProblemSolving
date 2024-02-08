#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

vector<int> perfectSquares; 

void generatePerfectSquares (int n){
    int sqrtt = sqrt(n);
    for (int i = 1;i < sqrtt; i++) 
        perfectSquares.push_back(i*i); 
}

map<int,int> memo;

int numSquares(int n)
{
    auto it = memo.find(n); 
    if(it != memo.end())
        return it->second;

    // this should be solved using dp.
    if (n == 0)
        return 1;
    if (n < 0)
        return INT_MAX; 
    
    // recursive case. 
    int mn = INT_MAX;
    for (auto item : perfectSquares)
        mn = min (mn, numSquares(n-item));
    return mn + 1; 

}

int main()
{
    int n = 12; 
    generatePerfectSquares(n); 
    cout << numSquares(n);

    return 0; 
}