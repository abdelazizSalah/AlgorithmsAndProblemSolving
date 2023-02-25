#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int back = 0, chest = 0, biceps = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i % 3 == 0)
            chest += x;
        else if (i % 3 == 1)
            biceps += x;
        else if (i % 3 == 2)
            back += x;
    }
    int mx = max(chest, biceps);
    mx = max(biceps, mx);
    mx = max(back, mx);
    if (mx == chest)
        return cout << "chest" << endl, 0;
    else if (mx == biceps)
        return cout << "biceps " << endl, 0;
    else if (mx == back)
        return cout << "back" << endl, 0;
}