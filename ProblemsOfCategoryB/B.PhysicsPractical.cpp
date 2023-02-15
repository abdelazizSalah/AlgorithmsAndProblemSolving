#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
#define readFile freopen("input.txt", "r", stdin);
#define writeFile freopen("output.txt", "w", stdout);

// invalid solution.
// map<pair<pair<int, int>, char>, int> dp;
// int findMinRemovals(const vector<int> &mesurements, int i, int j, char op)
// {
//     // applying memoization
//     auto it = dp.find({{i, j}, op});
//     if (it != dp.end())
//         return it->second;

//     // base case
//     if (mesurements[j] <= 2 * mesurements[i])
//         if (op == 'B')
//         {
//             dp[{{i, j}, op}] = 1;
//             return 1;
//         }
//         else
//         {
//             dp[{{i, j}, op}] = 0;
//             return 0;
//         }

//     // recursive case
//     int minRemovals = INT_MAX;

//     // move left
//     int left = findMinRemovals(mesurements, i, j - 1, 'L');
//     // move right
//     int right = findMinRemovals(mesurements, i + 1, j, 'R');
//     // move left and right
//     int both = findMinRemovals(mesurements, i + 1, j - 1, 'B');

//     // return the minimum
//     if (op == 'B')
//         minRemovals = 2 + min(minRemovals, min(left, min(right, both)));
//     else
//         minRemovals = 1 + min(minRemovals, min(left, min(right, both)));

//     dp[{{i, j}, op}] = minRemovals;
//     return minRemovals;
// }

// void solve()
// {
//     // reading input
//     int n;
//     cin >> n;
//     vector<int> measurments(n);
//     for (int &m : measurments)
//         cin >> m;

//     /// applying the algorithm
//     // 1. sort the measurments
//     sort(measurments.begin(), measurments.end());
//     cout << findMinRemovals(measurments, 0, n - 1, 'L');
// }

void solve2()
{
    // reading the inputs
    int n;
    cin >> n;
    vector<int> mesurments(n);
    for (int &m : mesurments)
        cin >> m;

    // applying the algorithm
    // 1. sort the mesurments
    sort(mesurments.begin(), mesurments.end());

    // 2. find the minimum number of removals
    int minRemovals = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(mesurments.begin(), mesurments.end(), 2 * mesurments[i]) - mesurments.begin();
        minRemovals = min(minRemovals, n - (pos) + i);
    }

    cout << minRemovals;
}

int main()
{
    fast;
    readFile;
    writeFile;
    solve2();
    return 0;
}