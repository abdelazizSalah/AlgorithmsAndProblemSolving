#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int hammingDistance(int x, int y)
{
    DPSolver;
    int cntr = 0;
    while (x || y)
    {
        //! getting the value of LSB in both x, y.
        if ((x & 1) != (y & 1))
            //? if they are not equal, we should increment hamming distance by 1.
            cntr++;
        x >>= 1;
        y >>= 1;
    }
    return cntr;
}

int main()
{
    cout << hammingDistance(1, 4) << ' ' << hammingDistance(3, 1);
    return 0;
}