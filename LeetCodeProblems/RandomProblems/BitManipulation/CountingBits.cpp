#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
vector<int> countBitsUsingBuiltInFunction(int n)
{
    DPSolver;
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++)
        v[i] = __builtin_popcount(i);
    return v;
}
vector<int> countBits(int n)
{
    DPSolver;
    vector<int> v(n + 1);
    int power = 2;
    v[0] = 0;
    v[1] = v[2] = 1;
    long powersOfTwo = pow(2, power - 1);
    double nextStop = pow(2, power);
    for (int i = 3; i <= n; i++)
        if (i == nextStop)
        {
            v[i] = 1;
            powersOfTwo = nextStop;
            nextStop = pow(2, ++power);
        }
        else
            v[i] = v[powersOfTwo] + v[i - powersOfTwo];

    return v;
}

int main()
{
    auto res = countBits(5);
    for (auto i : res)
        cout << i << ' ';
    return 0;
}
