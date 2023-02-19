#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto it = s.begin();
    for (int i = 0; i < n - 1; i++)
        if ((s[i] == '0' && s[i + 1] == '1') || (s[i] == '1' && s[i + 1] == '0'))
        {
            s.erase(it, it + 2);
            n -= 2;
            i -= 2;
            it--;
        }
        else
            it++;

    cout << n;
}

void solve2()
{
    int n;
    cin >> n;
    int noOfOnes = 0, noOfZeros = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '0')
            noOfZeros++;
        else
            noOfOnes++;
    }
    cout << abs(noOfOnes - noOfZeros);
}

int main()
{
    fast;
    solve2();
    return 0;
}