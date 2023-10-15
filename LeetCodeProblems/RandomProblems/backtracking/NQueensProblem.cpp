/*
    I am so close, just debug why when we remove the condition
        if(found) = true
    this case becomes acceptable ?
    ["..Q.","Q...","...Q",".Q.."]
    debug and you will solve it easily.
*/
#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// This checks if we are inside the board or not.
bool validIdx(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}
// these all possible combinations by which we can move diagonally in a board.
vector<pair<int, int>> diagMovements = {
    {-1, -1},
    {-1, 1},
    {1, -1},
    {1, 1},
};

// This is responsible for marking all gaurded cells.
// 1. all rows
// 2. all columns
// 3. all diagonals.
void markBoard(vector<vector<bool>> &vis, int i, int j, int n)
{
    for (int k = 0; k < n; k++)
    {
        // mark all rows
        vis[k][j] = true;
        // mark all jolumns
        vis[i][k] = true;
    }

    // mark all diagonals
    for (int k = 0; k < 4; k++)
    {
        int startRow = i;
        int startCol = j;
        while (validIdx(startRow, startCol, n))
        {
            vis[startRow][startCol] = true;
            startRow += diagMovements[k].first;
            startCol += diagMovements[k].second;
        }
    }
}
bool backTracking(vector<vector<string>> &res, vector<vector<char>> board, vector<vector<bool>> vis, int i, int j, int n, int Qnum)
{
    //? Base Cases

    // there is a queen attacking this position.
    if (vis[i][j])
        return false;
    // we have formed a valid board.
    if (Qnum == n)
    {
        board[i][j] = 'Q';
        vector<string> validBoard1;
        vector<string> validBoard2;
        for (auto s : board)
        {
            string rowString = "";
            for (char c : s)
                rowString += c;
            // we should insert the current board and its flip cause both will be valid
            validBoard1.push_back(rowString);
        }
        res.push_back(validBoard1);
        return true;
    }

    //? Recursive case
    // mark all board elements
    markBoard(vis, i, j, n);
    board[i][j] = 'Q';
    bool found = false;
    for (int k = 0; k < n; k++)
        found = backTracking(res, board, vis, k, j + 1, n, Qnum + 1);

    return false;
}

vector<vector<string>> solveNQueens(int n)
{

    if (n == 1)
        return {{"Q"}};

    vector<vector<string>> res2;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<bool>> vis(n, vector<bool>(n));

    for (int i = 0; i < n; i++)
    {
        board[i][0] = 'Q';
        backTracking(res2, board, vis, i, 0, vis.size(), 1);
        board[i][0] = '.';
    }
    return res2;
}

int main()
{
    auto res = solveNQueens(4);
    for (auto vec : res)
    {
        cout << " [ ";
        cout << " [ ";
        for (auto str : vec)
            cout << str << endl;
        cout << " ] \n";
    }
    return 0;
}