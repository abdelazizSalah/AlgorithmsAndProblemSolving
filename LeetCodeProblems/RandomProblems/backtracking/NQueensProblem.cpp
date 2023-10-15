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
// These are the all possible movements for a hourse
map<string, pair<int, int>> horsePossibleDirs = {
    {"UR", {-2, 1}},
    {"UL", {-2, -1}},
    {"RU", {-1, 2}},
    {"RD", {1, 2}},
    //!-------------
    {"DR", {2, 1}},
    {"DL", {2, -1}},
    {"LU", {-1, -2}},
    {"LD", {1, -2}},

};
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

pair<int, int> horseMovement(int i, int j, string dir)
{
    return {
        i + horsePossibleDirs[dir].first,
        j + horsePossibleDirs[dir].second,
    };
}
bool backTracking(set<vector<string>> &res, vector<vector<char>> board, vector<vector<bool>> vis, int i, int j, int n, int Qnum)
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
            reverse(rowString.begin(), rowString.end());
            validBoard2.push_back(rowString);
        }
        res.insert(validBoard1);
        res.insert(validBoard2);
        return true;
    }

    //? Recursive case
    // mark all board elements
    markBoard(vis, i, j, n);
    board[i][j] = 'Q';
    bool found = false;
    for (auto movDir : horsePossibleDirs)
    {
        // if (found)
        //     return true;
        auto ij = horseMovement(i, j, movDir.first);
        if (validIdx(ij.first, ij.second, n))
            found = backTracking(res, board, vis, ij.first, ij.second, n, Qnum + 1);
    }
    return false;
}

vector<vector<string>> solveNQueens(int n)
{
    // if (n == 2 || n == 3)
    //     return {{}};
    if (n == 1)
        return {{"Q"}};

    set<vector<string>> res;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<bool>> vis(n, vector<bool>(n));
    // if (n & 1)
    //     n = ceil((float)n / 2);
    // else
    //     n /= 2;
    for (int i = 0; i < n; i++)
    {
        board[i][0] = 'Q';
        backTracking(res, board, vis, i, 0, vis.size(), 1);
        board[i][0] = '.';
    }
    vector<vector<string>> res2;
    for (auto item : res)
        res2.push_back(item);
    return res2;
}

int main()
{
    auto res = solveNQueens(5);
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