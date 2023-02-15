#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<char, bool> colorMap;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                char c;
                cin >> c;
                colorMap[c] = true;
            }

        cout << colorMap.size() - 1 << '\n';
    }
}