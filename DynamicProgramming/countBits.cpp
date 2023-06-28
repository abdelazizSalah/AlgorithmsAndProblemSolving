#include <bits/stdc++.h>
using namespace std;

#define DPsolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

long returnExponent(int base, int exp)
{
    long b = base;
    for (int i = 1; i < exp; i++)
        b *= base;
    return b;
}

int main()
{
    DPsolver;
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    // inserting the seeds
    dp[0] = 0;
    dp[1] = 1;
    int exponent = 1;
    int counter = returnExponent(2, exponent);
    // start tabulation algorithm
    for (int i = 2; i <= n; i++)
    {
        if (counter == 0)
        {
            exponent++;
            counter = returnExponent(2, exponent);
            dp[i] = 1;
        }
        else
        {
            counter--;
            if (i & 1)
                // odd
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i - 1];
        }
    }
}