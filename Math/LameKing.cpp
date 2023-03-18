#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        a = abs(a), b = abs(b);
        if (a == b)
        {
            cout << a + b;
            cout << '\n';
            continue;
        }
        if (a < b)
            swap(a, b);
        int ans = b * 2 + (a - b) + (a - b - 1);
        cout << ans << '\n';
    }
    return 0;
}