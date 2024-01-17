#include <iostream>
using namespace std; 
void func(int x){
    cout << x; 
}
int main () { 
    void (*n)(int); 
    n = &func; 
    (*n)(1); 
    n(1);
    return 0;  
    deque<int> d; 
    d.push_front(5);
    d.pop_back();  
}
/*
(*n)(1);: Calls the function through the function pointer n with an argument of 1.
 This is a standard way of invoking a function through a function pointer.

n(1);: Calls the function through the function pointer n with an argument of 1.
 The syntax n(1) is a shorthand for (*n)(1) in C++.
*/

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
