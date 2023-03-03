
#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n)
{
    int cntr = 0;
    for (int i = 0; i < 32; i++)
    {
        if (n & (1 << i))
            cntr++;
    }
    return cntr;
}

int main()
{
    uint32_t n;
    cin >> n;
    cout << hammingWeight(n);
}