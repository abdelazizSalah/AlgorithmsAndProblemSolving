#include <bits/stdc++.h>
using namespace std;
#define DPsolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int findJudge(int n, vector<vector<int>> &trust)
{
    // trust is the edges and n is the number of nodes.

    // 1. build the graph
    vector<vector<int>> graph(n);
    for (auto edge : trust)
        graph[edge[0] - 1].push_back(edge[1] - 1);

    // 2. get the element with 0 outgoing
    int judgeIndex = -1;
    for (int i = 0; i < n; i++)
        if (graph[i].size() == 0)
        {
            judgeIndex = i;
            break;
        }

    if (judgeIndex == -1)
        // no judger
        return -1;

    // check that the judger exists in all the others neighbours.
    int personNum = 0;
    for (auto person : graph)
    {
        if (judgeIndex == personNum)
            continue;
        bool judgeExist = false;
        for (auto truster : person)
            if (truster == judgeIndex)
            {
                judgeExist = true;
                break;
            }
        if (judgeExist == false)
            return -1;
        personNum++;
    }
    return judgeIndex;
}

int main()
{
    DPsolver;
    vector<vector<int>> v = {{1, 2}};
    cout << findJudge(2, v);
}