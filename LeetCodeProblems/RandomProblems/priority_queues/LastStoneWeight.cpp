#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int lastStoneWeight(vector<int> &stones)
{
    DPSolver;
    priority_queue<int> pq;
    for (auto stone : stones)
        pq.push(stone);

    while (pq.size())
    {
        int top1 = pq.top();
        pq.pop();
        if (pq.empty())
            return top1;
        int top2 = pq.top();
        pq.pop();
        if (top1 <= top2)
        {
            if (top1 == top2)
                continue;
            else
            {
                top2 -= top1;
                pq.push(top2);
            }
        }
        else
        {
            if (top1 == top2)
                continue;
            else
            {
                top1 -= top2;
                pq.push(top1);
            }
        }
    }
    return 0;
}