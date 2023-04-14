// Accepted :D
#include <bits/stdc++.h>
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
using namespace std;

int main()
{
    // reading the input
    DPSOLVER;
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> ass(n);
    for (auto &it : ass)
        cin >> it.first >> it.second;

    // sort ass depending on the ddl
    sort(ass.begin(), ass.end());

    // solution
    ll penalty = 0;
    ll end = s;
    for (auto as : ass)
    {
        end += as.first;
        penalty += (end - as.second);
    }

    cout << penalty;
}