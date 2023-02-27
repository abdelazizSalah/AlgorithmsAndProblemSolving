#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> BBus;
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool first = true;
    for (char c : s)
        if (c == 'B')
        {
            if (first)
            {
                BBus.push_back(1);
                first = false;
            }
            else
                BBus[BBus.size() - 1]++;
        }
        else
            first = true;

    cout << BBus.size() << endl;
    for (int c : BBus)
        cout << c << " ";
}