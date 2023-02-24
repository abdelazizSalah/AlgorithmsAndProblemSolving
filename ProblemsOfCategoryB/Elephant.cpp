#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

int main()
{
    vector<short> elephantSteps{5, 4, 3, 2, 1}; // initialize vector with values
    int n;
    cin >> n;
    ll res = 0;
    while (n > 0)
        for (short es : elephantSteps)
            if (n >= es)
            {
                int rem = n % es;
                res += (n - rem) / es;
                n -= es * res;
            }

    cout << res << endl;
}