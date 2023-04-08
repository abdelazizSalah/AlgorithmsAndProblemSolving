#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        bool allSame = true;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i > 0 && v[i] != v[i - 1])
                allSame = false;
        }
        if (allSame)
            cout << -1;
        else
        {
            int max = max_element(v.begin(), v.end()) - v.begin();
            cout << max + 1;
        }
        cout << endl;
    }
    return 0;
}