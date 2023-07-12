#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define maxSize 1e9
using ll = long long;

ll tabulation()
{
    vector<ll> table(100);
    table[0] = 0;
    table[1] = 1;
    table[2] = 1;
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
        table[i] = table[i - 1] + table[i - 2] + table[i - 3];

    cout << table[n];
    return table[n];
}

map<int, ll> memo;
ll memoization(int n)
{
    // memoization
    auto it = memo.find(n);
    if (it != memo.end())
        return it->second;
    // base case
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;

    // normal condition
    memo[n] = memoization(n - 1) + memoization(n - 2) + memoization(n - 3);
    return memo[n];
}

int main()
{
    cout << memoization(0);
}