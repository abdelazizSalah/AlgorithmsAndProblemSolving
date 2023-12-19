#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

bool validIdx(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int evalWindow(vector<vector<int>> &img, int i, int j)
{
    int sum = 0;
    int rows = img.size();
    int cols = img[0].size();
    int noOfCells = 0;
    for (int x = i - 1; x < i + 2; x++)
        for (int y = j - 1; y < j + 2; y++)
            if (validIdx(x, y, rows, cols))
            {
                sum += img[x][y];
                noOfCells++;
            }
    return sum / noOfCells; 
}

vector<vector<int>> imageSmoother(vector<vector<int>> &img)
{
    DPSolver;
    int rows = img.size();
    int cols = img[0].size();
    vector<vector<int>> smoothedImg(rows, vector<int>(cols));
    for (int i = 0 ; i < rows; i++)
        for (int j = 0; j < cols; j++)  
            smoothedImg[i][j] = evalWindow(img, i, j); 
    return smoothedImg; 
}

int main()
{
}