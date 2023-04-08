#include <bits/stdc++.h>
using namespace std;
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool isPalindrome(string s)
{
    int n = s.length();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    DPSolver;
    int t;
    // cin >> t;
    // while (t--)
    // {
    string s;
    cin >> s;
    if (s.length() <= 3)
    {
        cout << "Yes" << endl;
        return 0;
    }
    bool tru = isPalindrome(s);
    if (!tru)
    {
        cout << "No" << endl;
    }
    else
    {
        s = s.substr(0, (s.length() - 1) / 2);
        tru = isPalindrome(s);
        if (!tru)
        {
            cout << "No" << endl;
        }
        else
        {
            s = s.substr((s.length() + 3) / 2, s.length());
            if (isPalindrome(s))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    // }
    return 0;
}