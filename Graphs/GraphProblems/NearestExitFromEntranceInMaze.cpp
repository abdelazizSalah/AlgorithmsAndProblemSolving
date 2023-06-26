#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

//               l,r,u,d
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

bool isExit(int i, int j, int noOfRows, int noOfCols, int entrancePosx, int entrancePosY)
{
    return !(entrancePosx == i && entrancePosY == j) && (i == 0 || j == 0 || j == noOfCols - 1 || i == noOfRows - 1);
}
bool insideBoundries(int i, int j, int noOfRows, int noOfCols)
{
    return i >= 0 && j >= 0 && j < noOfCols && i < noOfRows;
}

int bfs(const vector<vector<char>> &G, map<pair<int, int>, bool> &black, map<pair<int, int>, bool> &grey, int rSt, int cSt)
{
    queue<pair<int, int>> q;
    q.push({rSt, cSt});
    grey[{rSt, cSt}] = true;
    int level = 0;
    int noOfRows = G.size();
    int noOfCols = G[0].size();
    while (q.size())
    {
        int sz = q.size();
        while (sz--)
        {
            auto node = q.front();
            q.pop();
            if (isExit(node.first, node.second, noOfRows, noOfCols, rSt, cSt))
                return level;
            black[{rSt, cSt}] = true;
            grey[{rSt, cSt}] = false;
            for (int i = 0; i < 4; i++)
            {
                if (insideBoundries(node.first + dx[i], node.second + dy[i], noOfRows, noOfCols) &&
                    !black[{node.first + dx[i], node.second + dy[i]}] && !grey[{node.first + dx[i], node.second + dy[i]}])
                    if (G[node.first + dx[i]][node.second + dy[i]] == '.')
                    {
                        q.push({node.first + dx[i], node.second + dy[i]});
                        grey[{node.first + dx[i], node.second + dy[i]}] = true;
                    }
            }
        }
        level++;
    }
    return -1;
}

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    map<pair<int, int>, bool> grey;
    map<pair<int, int>, bool> black;
    return bfs(maze, black, grey, entrance[0], entrance[1]);
}

int main()
{
    DPSolver;
    int noOfRows, noOfCol;
    cin >> noOfRows >> noOfCol;
    vector<vector<char>> maze(noOfRows, vector<char>(noOfCol));
    for (int i = 0; i < noOfRows; i++)
        for (int j = 0; j < noOfCol; j++)
            cin >> maze[i][j];
    int r, c;
    cin >> r >> c;
    vector<int> entrance = {r, c};
    cout << nearestExit(maze, entrance);
}