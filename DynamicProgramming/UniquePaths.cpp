#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
map<pair<int, int>, int> memo;
int Memoization(int i, int j, const int &noOfRows, const int &noOfCols)
{
    // make it efficient
    auto it = memo.find({i, j});
    if (it != memo.end())
        return it->second;
    // make it work
    // base case
    if (i >= noOfRows || j >= noOfCols)
        return 0;
    else if (i == noOfRows - 1 && j == noOfCols - 1) // bottom right
        return 1;

    int right = Memoization(i, j + 1, noOfRows, noOfCols);
    int down = Memoization(i + 1, j, noOfRows, noOfCols);
    memo[{i, j}] = right + down;
    return right + down;
}

bool validIndx(int i, int j, int m, int n)
{
    return i < n && j < m && i >= 0 && j >= 0;
}
int tabulation(int n, int m)
{
    vector<vector<int>> table(n, vector<int>(m));
    table[n - 1][m - 1] = 1;
    for (int j = n - 1; j >= 0; j--)
        for (int k = m - 1; k >= 0; k--)
        {
            // check on right
            if (validIndx(j, k + 1, m, n))
                table[j][k] += table[j][k + 1];

            // check on down
            if (validIndx(j + 1, k, m, n))
                table[j][k] += table[j + 1][k];
        }

    return table[0][0];
}

int main()
{
    DPSolver;
    int n, m;
    cin >> n >> m;
    cout << tabulation(n, m);
    return 0;
}