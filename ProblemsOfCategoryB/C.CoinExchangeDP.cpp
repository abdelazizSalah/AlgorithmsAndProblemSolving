#include <bits/stdc++.h>
using namespace std;

map<int, int> memo;
int coinChange(vector<int> &coins, int amount, bool notFirstStep = false)
{
    // make it efficient
    auto it = memo.find(amount);
    if (it != memo.end())
        return it->second;

    // make it work
    // base case
    if (amount == 0)
        return 0;
    else if (amount < 0)
    {
        memo[amount] = INT_MAX;
        return INT_MAX;
    }

    int minCoins = INT_MAX;
    for (int c : coins)
        minCoins = min(minCoins, coinChange(coins, amount - c, true));

    if (minCoins == INT_MAX)
    {
        memo[amount] = INT_MAX;
        if (notFirstStep)
            return INT_MAX;
        else
            return -1;
    }
    else
    {
        memo[amount] = minCoins + 1;
        return minCoins + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int amount;
    cin >> amount;
    cout << coinChange(coins, amount);
}