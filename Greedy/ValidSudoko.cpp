#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool isValidSudoku(vector<vector<char>> board)
{
    int n = 9;
    for (int i = 0; i < n; i++)
    {
        vector<bool> row(9, false);
        vector<bool> col(9, false);
        // iterate over the whole row
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                if (row[board[i][j] - '1'] == true)
                {
                    return false;
                }
                else
                    row[board[i][j] - '1'] = true;
            }
            if (board[j][i] != '.')
            {
                if (col[board[j][i] - '1'] == true)
                {
                    return false;
                }
                else
                    col[board[j][i] - '1'] = true;
            }
        }
    }
    return true;
}
