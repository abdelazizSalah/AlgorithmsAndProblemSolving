#include <bits/stdc++.h>
using namespace std;

map<int, int> memo;
int climbStairs(int n)
{
    // make it efficient
    auto it = memo.find(n);
    if (it != memo.end())
        return it->second;

    // make it work
    // base case
    if (n == 0)
        return 1;
    if (n < 0)
    {
        memo[n] = 0;
        return 0;
    }
    memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return memo[n];
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n);
}