#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

vector<int> solve2()
{
    int k, n;
    cin >> k >> n;
    vector<int> v;
    int newNum = 1;
    int factor = 1;
    while (((newNum <= n && v.size() == k - 1) || (newNum < n)) && v.size() < k) // el condition m7tag yetzbt seka
    {
        v.push_back(newNum);
        newNum += factor;
        factor++;
    }
    int sz = k - v.size();
    if (sz != 0)
        while (sz)
        {
            auto it = *(v.end() - 1);
            v.push_back(it + 1);
            sz--;
        }
    return v;
}

vector<int> solve()
{
    int k, n;
    cin >> k >> n;
    vector<int> v(1, 1);
    for (int i = 1; i <= n && ((n - (v.back() + i)) >= (k - (v.size() + 1))) && (v.back() + i <= n); i++)
        v.push_back(v.back() + i);
    while (v.size() < k)
        v.push_back(v.back() + 1);
    return v;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        for (auto it : solve())
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}