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
}
/*
(*n)(1);: Calls the function through the function pointer n with an argument of 1.
 This is a standard way of invoking a function through a function pointer.

n(1);: Calls the function through the function pointer n with an argument of 1.
 The syntax n(1) is a shorthand for (*n)(1) in C++.
*/