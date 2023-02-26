#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string res = "";
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            res += "0";
        else
            res += "1";
    }
    cout << res << endl;
}