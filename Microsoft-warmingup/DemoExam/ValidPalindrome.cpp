#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
    int n = s.size();
    if (n == 1)
        return true;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (!isalnum(s[i]))
        { // to neglect spaces
            i++;
            continue;
        }
        if (!isalnum(s[j]))
        { // to neglect spaces
            j--;
            continue;
        }
        if (tolower(s[i]) != tolower(s[j]))
            return false;
        i++;
        j--;
    }
    return true;
}
