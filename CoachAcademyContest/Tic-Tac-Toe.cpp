// Accepted :)
#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
void solve()
{
    // reading the input
    vector<vector<char>> game(3, vector<char>(3));
    int numX = 0, numO = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> game[i][j];
            if (game[i][j] == 'X')
                numX++;
            else if (game[i][j] == '0')
                numO++;
        }
    // showing non valid cases
    if (numX - numO > 1 || numO > numX)
    {
        cout << "illegal" << endl;
        return;
    }

    // checking the columns
    for (int i = 0; i < 3; i++)
    {
        if (game[0][i] == game[1][i] && game[1][i] == game[2][i])
        {
            if (game[0][i] == 'X')
            {
                if (numX - numO == 1)
                {
                    cout << "the first player won" << endl;
                    return;
                }
                else
                {
                    cout << "illegal" << endl;
                    return;
                }
            }
            else if (game[0][i] == '0')
            {
                if (numX == numO)
                {
                    cout << "the second player won" << endl;
                    return;
                }
                else
                {
                    cout << "illegal" << endl;
                    return;
                }
            }
        }
    }
    // checking the rows
    for (int i = 0; i < 3; i++)
    {
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2])
        {
            if (game[i][0] == 'X')
            {
                if (numX - numO == 1)
                {
                    cout << "the first player won" << endl;
                    return;
                }
                else
                {
                    cout << "illegal" << endl;
                    return;
                }
            }
            else if (game[i][0] == '0')
            {
                if (numX == numO)
                {
                    cout << "the second player won" << endl;
                    return;
                }
                else
                {
                    cout << "illegal" << endl;
                    return;
                }
            }
        }
    }
    // checking the diagonals
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2])
    {
        if (game[0][0] == 'X')
        {
            if (numX - numO == 1)
            {
                cout << "the first player won" << endl;
                return;
            }
            else
            {
                cout << "illegal" << endl;
                return;
            }
        }
        else if (game[0][0] == '0')
        {
            if (numX == numO)
            {
                cout << "the second player won" << endl;
                return;
            }
            else
            {
                cout << "illegal" << endl;
                return;
            }
        }
    }

    // checking the other diagonal
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0])
    {
        if (game[0][2] == 'X')
        {
            if (numX - numO == 1)
            {
                cout << "the first player won" << endl;
                return;
            }
            else
            {
                cout << "illegal" << endl;
                return;
            }
        }
        else if (game[0][2] == '0')
        {
            if (numX == numO)
            {
                cout << "the second player won" << endl;
                return;
            }
            else
            {
                cout << "illegal" << endl;
                return;
            }
        }
    }

    // checking if the game is finished
    if (numX + numO == 9)
    {
        cout << "draw" << endl;
        return;
    }

    // else check whose turn is this
    if (numX - numO == 1)
    {
        cout << "second" << endl;
        return;
    }
    else
    {
        cout << "first" << endl;
        return;
    }
}

int main()
{
    DPSOLVER;
    solve();
    return 0;
}