#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void printGraph(vector<vector<pair<bool, bool>>> &canReachNodes, int noOfRows, int noOfColumns)
{
    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < noOfColumns; j++)
        {
            cout << '(' << canReachNodes[i][j].first << "," << canReachNodes[i][j].second << ") ";
        }
        cout << endl;
    }
}

void iterateOverCode(int noOfRows, int noOfColumns, const vector<vector<int>> &graph, vector<vector<pair<bool, bool>>> &canReachNodes)
{
    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < noOfColumns; j++)
        {

            // check up
            if (i > 0)
            {
                if (graph[i - 1][j] >= graph[i][j])
                {
                    canReachNodes[i - 1][j].first |= canReachNodes[i][j].first;
                    canReachNodes[i - 1][j].second |= canReachNodes[i][j].second;
                }
            }

            // check down
            if (i <= noOfRows - 2)
            {
                if (graph[i + 1][j] >= graph[i][j])
                {
                    canReachNodes[i + 1][j].first |= canReachNodes[i][j].first;
                    canReachNodes[i + 1][j].second |= canReachNodes[i][j].second;
                }
            }

            // check left
            if (j > 0)
            {
                if (graph[i][j - 1] >= graph[i][j])
                {
                    canReachNodes[i][j - 1].first |= canReachNodes[i][j].first;
                    canReachNodes[i][j - 1].second |= canReachNodes[i][j].second;
                }
            }

            // check right
            if (j <= noOfColumns - 2)
            {
                if (graph[i][j + 1] >= graph[i][j])
                {
                    canReachNodes[i][j + 1].first |= canReachNodes[i][j].first;
                    canReachNodes[i][j + 1].second |= canReachNodes[i][j].second;
                }
            }
        }
    }
    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = noOfColumns - 1; j >= 0; j--)
        {

            // check up
            if (i > 0)
            {
                if (graph[i - 1][j] >= graph[i][j])
                {
                    canReachNodes[i - 1][j].first |= canReachNodes[i][j].first;
                    canReachNodes[i - 1][j].second |= canReachNodes[i][j].second;
                }
            }

            // check down
            if (i <= noOfRows - 2)
            {
                if (graph[i + 1][j] >= graph[i][j])
                {
                    canReachNodes[i + 1][j].first |= canReachNodes[i][j].first;
                    canReachNodes[i + 1][j].second |= canReachNodes[i][j].second;
                }
            }

            // check left
            if (j > 0)
            {
                if (graph[i][j - 1] >= graph[i][j])
                {
                    canReachNodes[i][j - 1].first |= canReachNodes[i][j].first;
                    canReachNodes[i][j - 1].second |= canReachNodes[i][j].second;
                }
            }

            // check right
            if (j <= noOfColumns - 2)
            {
                if (graph[i][j + 1] >= graph[i][j])
                {
                    canReachNodes[i][j + 1].first |= canReachNodes[i][j].first;
                    canReachNodes[i][j + 1].second |= canReachNodes[i][j].second;
                }
            }
        }
    }
}

vector<vector<int>> solve()
{
    int noOfRows, noOfColumns;
    cin >> noOfRows >> noOfColumns;
    vector<vector<int>> graph(noOfRows, vector<int>(noOfColumns, 0));
    vector<vector<pair<bool, bool>>> canReachNodes(noOfRows, vector<pair<bool, bool>>(noOfColumns, {0, 0}));
    vector<vector<int>> finalResult;
    for (int i = 0; i < noOfRows; i++)
        for (int j = 0; j < noOfColumns; j++)
        {
            if (i == 0 || j == 0)
                canReachNodes[i][j].first = true;

            if (i == noOfRows - 1 || j == noOfColumns - 1)
                canReachNodes[i][j].second = true;

            cin >> graph[i][j];
        }

    iterateOverCode(noOfRows, noOfColumns, graph, canReachNodes);
    for (int i = 0; i < noOfRows; i++)
        for (int j = 0; j < noOfColumns; j++)
            if (canReachNodes[i][j].first && canReachNodes[i][j].second)
                finalResult.push_back({i, j});

    return finalResult;
}

int main()
{
    fast;
    solve();
    return 0;
}