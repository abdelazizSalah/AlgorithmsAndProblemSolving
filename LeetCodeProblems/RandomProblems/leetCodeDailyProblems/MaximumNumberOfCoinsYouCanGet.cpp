#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int maxCoins(vector<int> &piles)
{
    DPSolver;
    sort(piles.begin(), piles.end());
    int b = 0;
    int e = piles.size() - 1;
    int res = 0;
    while (e - b > 0)
    {
        b++;               // letting bob take the minimum coin
        e--;               // leetinc alice take the maximum
        res += piles[e--]; // taking the second maximum
    }
    return res;
}

int main()
{
    vector<int> p = {3, 4, 5};
    // vector<int> p = {1,2,3,6,9,5,7,8,4};
    cout << maxCoins(p);
    return 0;
}