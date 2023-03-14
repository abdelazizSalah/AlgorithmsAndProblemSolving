#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    DPSOLVER
    string s;
    cin >> s;
    if (s[0] == '0')
        return cout << 0, 0;
    int cntr = 0;
    reverse(s.begin(), s.end());
    bool prevOnes = false;
    int sz = s.size();
    for (int i = 0; i < sz; i++)
        if (s[i] == '1')
        {
            if (i != sz - 1)
                prevOnes = true;
            else if (i == sz - 1 && !(i + 1 & (1 << 0)))
                prevOnes = true;
            cntr = ceil((i + 1) / 2.0);
        }
    if (!prevOnes)
        cout << cntr - 1;
    else
        cout << cntr;
}