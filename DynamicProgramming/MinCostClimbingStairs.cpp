#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

map<int, int> memo;
ll minCost(const vector<int> &costs, const int sz, int idx)
{
    // make it efficient
    auto it = memo.find(idx);
    if (it != memo.end())
        return it->second;

    // defining the base case
    if (idx >= sz)
    {
        memo[idx] = 0;
        return 0;
    }

    // defining the recursive case
    ll oneStep = minCost(costs, sz, idx + 1);
    ll twoSteps = minCost(costs, sz, idx + 2);
    memo[idx] = costs[idx] + min(oneStep, twoSteps);
    return costs[idx] + min(oneStep, twoSteps);
}

int main()
{
    fast;
    vector<int> cost(1000, 12);

    cout << min(minCost(cost, cost.size(), 0), minCost(cost, cost.size(), 1));
}