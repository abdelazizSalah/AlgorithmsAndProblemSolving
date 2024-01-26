// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
// static const auto DPSolver = []()
// { std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

bool isOutside(int i, int j, int m, int n)
{
    return i < 0 || j < 0 || i >= m || j >= n;
}

map<pair<pair<int, int>, int>, int> memo;
int findPaths(const int m, const int n, int maxMove, int startRow, int startColumn)
{
    //?  make it efficient
    auto it = memo.find({{startRow, startColumn}, maxMove});
    if (it != memo.end())
        return it->second;
    //? make it work
    // base cases
    if (isOutside(startRow, startColumn, m, n))
    {
        memo[{{startRow, startColumn}, maxMove}] = 1;
        return 1;
    }

    else if (maxMove == 0)
        return 0;

    // recursive case
    int up = findPaths(m, n, maxMove - 1, startRow - 1, startColumn) % mod;
    int down = findPaths(m, n, maxMove - 1, startRow + 1, startColumn) % mod;
    int left = findPaths(m, n, maxMove - 1, startRow, startColumn - 1) % mod;
    int right = findPaths(m, n, maxMove - 1, startRow, startColumn + 1) % mod;

    memo[{{startRow, startColumn}, maxMove}] = (((((up + down) % mod) + left) % mod) + right) % mod;
    return (((((up + down) % mod) + left) % mod) + right) % mod;
}

int main()
{
    char digit = '1'; 
    string number = "1231"; 
    int sz = number.length(); 
    string number1 = number;
    string number2 = number; 
    for (int i =sz -1 ; i >=0; i-- )
        if (digit == number1[i]){
            number1.erase(i,1); 
            break;  
        }
    for (int i =0 ; i < sz; i++ )
        if (digit == number2[i]){
            number2.erase(i,1); 
            break;  
        }
    if (number1 > number2) cout << number1; else cout << number2 ;
    return 0; 
}