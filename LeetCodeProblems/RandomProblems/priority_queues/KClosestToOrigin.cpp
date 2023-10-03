#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    DPSolver;
    priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<>> pq;

    for (auto point : points)
    {
        float dis = sqrt(pow(point[0], 2) + pow(point[1], 2));
        pq.push({dis, {point[0], point[1]}});
    }
    vector<vector<int>> res;
    while (k-- && pq.size())
    {
        res.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }
    return res;
}

int main()
{
    DPSolver;
    return 0;
}