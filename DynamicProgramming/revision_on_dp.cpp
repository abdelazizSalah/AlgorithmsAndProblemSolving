/// @author Abdelaziz Salah
/// @date 27-1-2023
/// @breif this file contains some functions that are used in dp problems, as a revision for the DP topic.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

map<ll, ll> mp;
ll fibMemo(ll n)
{
    /// searching in the map
    auto finder = mp.find(n);
    if (finder != mp.end())
    {
        return finder->second;
    }
    else if (n == 1 || n == 0)
    {
        mp[n] = n;
        return n;
    }
    mp[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return fibMemo(n - 1) + fibMemo(n - 2);
}

map<pair<int, int>, int> grid;

ll gridTravelMemo(const int &len, const int &wid, int x, int y)
{
    auto finder = grid.find({x, y});
    if (finder != grid.end())
    {
        return finder->second;
    }
    if (x == len - 1 && y == wid - 1)
    {
        grid[{x, y}] = 1;
        return 1; // working 0 based
    }
    if (x >= len || y >= wid)
        return 0;

    // try one down and one right
    ll res = gridTravelMemo(len, wid, x + 1, y) + gridTravelMemo(len, wid, x, y + 1);
    grid[{x, y}] = res;
    return res;
}

map<int, bool> canMemo;
bool canSum(const vector<int> &myArr, const int &trgt, int rem)
{
    auto finder = canMemo.find(rem);
    if (finder != canMemo.end())
    {
        return finder->second;
    }
    if (rem == 0)
    {
        canMemo[rem] = true;
        return true;
    }
    else if (rem < 0)
    {
        canMemo[rem] = false;
        return false;
    }
    else
    {
        /// here we should subtract a new value from the rem values
        for (int val : myArr)
        {
            if (canSum(myArr, trgt, rem - val))
            {
                canMemo[rem] = true;
                return true;
            }
        }
        canMemo[rem] = false;
        return false;
    }
}

void solve()
{
    int size;
    cin >> size;
    vector<int> vals(size);
    for (int &val : vals)
    {
        cin >> val;
    }
    int trgt;
    cin >> trgt;
    cout << boolalpha << canSum(vals, trgt, trgt);
}
int main()
{
    fast;
    int t = 1;
    solve();
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    return 0;
}