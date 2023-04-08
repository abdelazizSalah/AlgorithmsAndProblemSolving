#include <bits/stdc++.h>
using namespace std;
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    int no;
    cin >> no;
    string S;
    cin >> S;
    if (no == 1)
    {
        cout << "YES" << '\n';
        return;
    }
    map<char, bool> suss;
    char current = S[0];
    for (int i = 1; i < no; i++)
    {
        if (S[i] != current)
        {
            if (suss[S[i]])
            {
                cout << "NO" << endl;
                return;
            }
            suss[current] = true;
            current = S[i];
        }
    }
    cout << "YES" << endl;
}
int main()
{
    DPSolver;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}