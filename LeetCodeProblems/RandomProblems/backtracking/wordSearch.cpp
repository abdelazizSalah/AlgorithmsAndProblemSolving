#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool validIndex(int m, int n, int r, int c)
{
    return r < m && r >= 0 && c < n && c >= 0;
}

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

bool backtracking(const vector<vector<char>> &board, vector<vector<bool>> &vis, const string &trgt,
                  const int &m, const int &n, int i, int j, string s)
{
    // base cases
    if (s.length() > trgt.length())
        return false;
    if (s == trgt)
        return true;
    if (!validIndex(m, n, i, j))
        return false;
    if (vis[i][j])
        return false;

    // marking visited
    vis[i][j] = true;

    // trying 4 directions
    // bool right = false;
    // bool left = false;
    // bool down = false;
    // bool up = false;

    // compact way of writing the logic
    bool can = false;
    for (int k = 0; k < dx.size(); k++)
    {
        if (can)
            return can;
        if (board[i][j] == trgt[s.length()])
            can = backtracking(board, vis, trgt, m, n, i + dx[k], j + dy[k], s + board[i][j]);
    }

    // if (board[i][j] == trgt[s.length()])
    //     right = backtracking(board, vis, trgt, m, n, i, j + 1, s + board[i][j]);

    // if (right)
    //     return true;

    // if (board[i][j] == trgt[s.length()])
    //     down = backtracking(board, vis, trgt, m, n, i + 1, j, s + board[i][j]);

    // if (down)
    //     return true;

    // if (board[i][j] == trgt[s.length()])
    //     left = backtracking(board, vis, trgt, m, n, i, j - 1, s + board[i][j]);

    // if (left)
    //     return true;

    // if (board[i][j] == trgt[s.length()])
    //     up = backtracking(board, vis, trgt, m, n, i - 1, j, s + board[i][j]);

    // if (up)
    //     return true;
    // applying backtracking
    vis[i][j] = false;
    return can;
    // return right || down || left || up;
}

bool exist(vector<vector<char>> &board, string word)
{
    DPSolver;
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (backtracking(board, vis, word, m, n, i, j, ""))
                return true;
    return false;
}

int main()
{
    DPSolver;
    // board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    return 0;
}