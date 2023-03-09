#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<int, int> memo;
ll climbingStairs(int n)
{
    // make it efficient
    auto it = memo.find(n);
    if (it != memo.end())
        return memo[n];

    // define base case
    if (n == 0)
        return 1;
    else if (n < 0)
    {
        memo[n] = 0;
        return 0;
    }
    else
    {
        memo[n] = climbingStairs(n - 1) + climbingStairs(n - 2);
        return memo[n];
    }
}

int main()
{
    int n;
    cin >> n;
    cout << climbingStairs(n);
    return 0;
}