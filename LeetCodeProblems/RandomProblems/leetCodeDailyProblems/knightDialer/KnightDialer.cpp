#include <bits/stdc++.h>
using namespace std;

#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using ll = long long;
ll mod = 1e9 + 7;
vector<vector<short>> G;
vector<vector<short>> buildG()
{
    return {
        {4, 6},
        {6, 8},
        {7, 9},
        {8, 4},
        {0, 3, 9},
        {},
        {7, 1, 0},
        {6, 2},
        {1, 3},
        {4, 2},
    };
}

map<pair<short, short>, ll> memo;
ll knightDialerDP(short node, short limitedDepth)
{
    // make it efficient
    auto it = memo.find({node, limitedDepth});
    if (it != memo.end())
        return it->second;

    // make it work
    if (!limitedDepth)
    {
        memo[{node, limitedDepth}] = 1;
        return 1;
    }
    ll res = 0;
    for (short nei : G[node])
        res += knightDialerDP(nei, limitedDepth - 1) % mod;
    memo[{node, limitedDepth}] = res;
    return res;
}

ll knightDialer(short n)
{
    DPSolver;
    G = buildG();
    ll res = 0;
    for (short i = 0; i < 10; i++)
        res += knightDialerDP(i, n - 1) % mod;
    return res % mod;
}

int main()
{
    // for (int i = 1; i < 10; i++)
    cout << knightDialer(3131) << endl;
    return 0;
}