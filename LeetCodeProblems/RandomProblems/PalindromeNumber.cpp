#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool isPalindrome(int x)
{
    DPSolver;
    // any -ve value is always value- , so it is not palindrome.
    if (x < 0)
        return false;

    //? what if we want to solve it using ints not strings.
    // 1. get the number of digits in that number;
    int numberOfDigits = int(log10(x) + 1);
    int powersOf10 = pow(10, numberOfDigits - 1);
    while (numberOfDigits > 1)
    {
        int units = x % 10;
        int lastDigit = x / powersOf10;
        if (units != lastDigit)
            return false;
        x %= powersOf10 * lastDigit;
        x /= 10;
        powersOf10 /= 100;
        numberOfDigits -= 2;
    }
    return true;

    //! convert it to string, and solve it easily.
    string s = to_string(x);
    int len = s.length();
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - 1 - i])
            return false;

    return true;
}

int main()
{
    DPSolver;
    cout << boolalpha << isPalindrome(9999) << '\n';
    return true;
}