#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
using ll = long long;


int main()
{
    DPSolver; 
    string s; cin >> s; 
    // 1. add $ to the end of the string
    s += '$';

    // 2. while length of s is not 2 ^ k, append characters in cyclic way.
    int sz = s.length();
    vector<int> positions (sz), classes (sz); 
    {
        // initial phase 
        vector <pair<char,int>> currentState (sz); 
        for (int i = 0; i < sz; i++) currentState[i] = {s[i], i};
        sort(currentState.begin(), currentState.end()); 
        for (int i = 0; i < sz; i++) positions[i] = currentState[i].second; 
        classes[positions[0]] = 0; 
        for (int i = 1 ; i < sz; i++){
            if (currentState[i].first == currentState[i-1].first)
                classes[positions[i]] =classes[positions[i - 1]];
            else 
                classes[positions[i]] = classes[positions[i- 1]] + 1;    
        }  
    }

    int k = 0; 
    while ((1 << k) < sz) { // till 2^k
        vector<pair<pair<int,int>, int>> newState(sz) ;
        for (int i = 0; i < sz; i ++)
            newState[i] = {{classes[i], classes[(i + (1<<k))%sz]}, i}; //! left part and right part and the position -> ana el satr da el msh fahmo....
        sort (newState.begin(), newState.end()); 
        for (int i = 0; i < sz; i++) positions[i] = newState[i].second; 
        classes[positions[0]] = 0; 
        for (int i = 1 ; i < sz; i++){
            if (newState[i].first == newState[i-1].first)
                classes[positions[i]] =classes[positions[i - 1]];
            else 
                classes[positions[i]] = classes[positions[i- 1]] + 1;    
        }  
        k++; 
    }

    for (int i = 0 ; i < sz ; i ++)
        cout << positions[i] << ' '; 
    
    return 0; 

}
