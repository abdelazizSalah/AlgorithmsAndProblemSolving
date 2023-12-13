#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;


bool check (vector<vector<int>> &mat, int i , int j, int rows, int cols) {
    // loop over the whole row ( other cols)
    for (int x = 0; x  < cols; x++)
        if (x == i)
            continue; 
        else if (mat[x][j])
            return false; 
    // loop over the whole cols
    for (int x = 0; x  < rows; x++)
        if (x == j)
            continue; 
        else if (mat[i][x])
            return false; 
    
    return true; 
}
int numSpecial(vector<vector<int>> &mat)
{
    DPSolver; 
    int rows = mat.size();
    int cols = mat[0].size();
    vector<bool> rowsFlags(rows); 
    vector<bool> colsFlags(cols); 

    int res = 0; 
    for (int i = 0 ; i < rows; i ++){
        for (int j = 0 ; j < cols; j ++){
            if (mat[i][j])
                if(!rowsFlags[i] && !colsFlags[j])
                    res += check(mat, i, j, rows, cols); 
        }
    }
    return res; 
}