#pragma once
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void findMinSwaps(const vector<int> &myArr, vector<bool> &vis, int &sum, int cntr, int element)
{
    // base case
    if (vis[element])
    {
        sum += cntr - 1;
        return;
    }

    vis[element] = true;
    cntr++;
    findMinSwaps(myArr, vis, sum, cntr, myArr[element - 1]);
}

/// @brief complexity O(N)
void solve()
{
    /// reading the data
    int sz;
    cin >> sz;
    vector<int> myArr(sz);
    for (int &i : myArr)
        cin >> i;

    /// applying the logic
    vector<bool> vis(sz + 1);
    int totalSwaps = 0;
    for (int i : myArr)
    {
        int cntr = 0;
        if (!vis[i])
        {
            vis[i] = true;
            cntr++;
            findMinSwaps(myArr, vis, totalSwaps, cntr, myArr[i - 1]);
        }
    }

    /// printing the output
    cout << totalSwaps;
}

int main()
{
    fast;
    solve();
    return 0;
}