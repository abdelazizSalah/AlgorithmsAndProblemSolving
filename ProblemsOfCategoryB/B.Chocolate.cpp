#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, res = 1;
    bool flag = false;
    cin >> n;
    int arr[105];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1) // if flag is not toggeled this means that there is no nuts
            flag = true;
    }

    if (!flag)
        return cout << 0, 0;

    for (int i = 0; i < n; i++)
        if (arr[i] == 1)
            for (int j = i + 1; j < n; j++)
                if (arr[j] == 1)
                {
                    res *= (j - i);
                    break;
                }

    cout << res;
    return 0;
}
