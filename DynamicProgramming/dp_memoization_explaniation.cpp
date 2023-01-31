#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double
using namespace std;

map<int, ll> mp;
ll fib(int n)
{
    // make it efficient.
    // memoization
    auto it = mp.find(n);
    if (it != mp.end())
    {
        return it->second;
    }
    // make it work.
    if (n == 0 || n == 1)
    {
        mp[n] = n;
        return n;
    }
    else
    {
        ll res = fib(n - 1) + fib(n - 2);
        mp[n] = res;
        return res;
    }
}

map<pair<int, int>, ll> gridMemo;
ll gridTraveler(const int &rows, const int &cols, int r, int c)
{
    // make it efficient.
    // applying memoization
    auto it = gridMemo.find({r, c});
    if (it != gridMemo.end())
    {
        return it->second;
    }
    // make it work.
    if (r == rows - 1 && c == cols - 1)
    {
        gridMemo[{r, c}] = 1;
        return 1;
    }
    else if (r >= rows || c >= cols)
    {
        gridMemo[{r, c}] = 0;
        return 0;
    }
    else
    {
        ll res = gridTraveler(rows, cols, r + 1, c) + gridTraveler(rows, cols, r, c + 1);
        gridMemo[{r, c}] = res;
        return res;
    }
}

map<int, bool> canSumMemo;
bool canSum(const vector<int> &myBags, const int &trgt, int res)
{
    // make it efficient
    // apply memoization
    auto it = canSumMemo.find(res);
    if (it != canSumMemo.end())
    {
        return it->second;
    }

    // make it work
    // base case
    if (res == 0)
    {
        return true;
    }
    else if (res < 0)
    {
        return false;
    }
    else
    {
        for (int bag : myBags)
        {
            if (canSum(myBags, trgt, res - bag))
            {
                canSumMemo[res] = true;
                return true;
            }
        }
        canSumMemo[res] = false;
        return false;
    }
}

void solve()
{
    int trgt;
    cin >> trgt;
    int size;
    cin >> size;
    vector<int> myBags(size);
    for (int &bag : myBags)
    {
        cin >> bag;
    }

    cout << boolalpha << canSum(myBags, trgt, trgt) << endl;
}

int main()
{
    fast;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}