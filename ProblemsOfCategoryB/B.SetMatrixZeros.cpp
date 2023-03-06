#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
void solve()
{
    // creating a map for rows
    map<int, bool> rows;
    // creating a map for columns
    map<int, bool> cols;

    // reading the actual matrix
    int noOfRows, noOfCols;
    cin >> noOfRows >> noOfCols;
    vector<vector<int>> actualMatrix(noOfRows, vector<int>(noOfCols));
    for (int i = 0; i < noOfRows; i++)
        for (int j = 0; j < noOfCols; j++)
        {
            cin >> actualMatrix[i][j];
            if (actualMatrix[i][j] == 0)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }

    // building the result matrix
    vector<vector<int>> result(noOfRows, vector<int>(noOfCols));

    for (int i = 0; i < noOfRows; i++)
    {
        if (rows[i] == true) // if this row has a zero, then there will be no value in this entire row.
            continue;
        for (int j = 0; j < noOfCols; j++)
        {
            if (cols[j] == true) // if this column has a zero, then there will be no value in this entire column, but we will just leave this position empty for now.
                continue;
            result[i][j] = actualMatrix[i][j];
        }
    }
}
int main()
{
    fast;
    solve();
    return 0;
}