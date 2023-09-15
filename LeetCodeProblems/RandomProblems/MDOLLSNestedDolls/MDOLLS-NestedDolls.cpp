#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool getBigger(pair<pair<int, int>, vector<int>> &p1, pair<pair<int, int>, vector<int>> &p2)
{
    return p1.second.size() >= p2.second.size();
}

map<pair<int, int>, pair<pair<int, int>, vector<int>>> memo;
pair<pair<int, int>, vector<int>> countMaxDolls(vector<pair<int, int>> &dolls, const int m, vector<bool> &taken, int idx)
{
    // make it efficient
    auto it = memo.find(dolls[idx]);
    if (it != memo.end())
        return it->second;
    // make it work

    // define base case
    if (idx >= m)
    {
        memo[{idx, idx}] = {{INT_MAX, INT_MAX}, {}};
        return {{INT_MAX, INT_MAX}, {}};
    }
    else if (idx == m - 1)
    {
        memo[dolls[idx]] = {dolls[idx], {idx}};
        return {dolls[idx], {idx}};
    }

    // normal case
    priority_queue<pair<pair<int, int>, vector<int>>> PossibleResults;
    for (int i = idx + 1; i < m; i++)
    {
        if (!taken[i])
        {
            pair<pair<int, int>, vector<int>> R = countMaxDolls(dolls, m, taken, i);
            if (PossibleResults.empty())
                PossibleResults.push(R);
            else
            {
                auto top = PossibleResults.top();
                if (getBigger(R, top))
                    // R is bigger
                    PossibleResults.push(R);
            }
        }
    }
    if (PossibleResults.size())
    {
        int mxSize = PossibleResults.top().second.size();
        pair<pair<int, int>, vector<int>> top = PossibleResults.top();
        while (PossibleResults.size())
        {
            auto top = PossibleResults.top();
            if (top.second.size() < mxSize)
                break;
            else
            {
                if (dolls[idx].first > top.first.first && dolls[idx].second > top.first.second)
                {
                    top.second.push_back(idx);
                    memo[dolls[idx]] = {dolls[idx], {idx}};
                    return {dolls[idx], top.second};
                }
            }
            PossibleResults.pop();
        }
        return top;
    }
    else
    {
        memo[dolls[idx]] = {dolls[idx], {idx}};
        return {dolls[idx], {idx}};
    }
}

void solve()
{
    memo = map<pair<int, int>, pair<pair<int, int>, vector<int>>>();
    int m;
    cin >> m;
    vector<pair<int, int>> dolls(m);

    for (int i = 0; i < m; i++)
    {
        int w, h;
        cin >> w >> h;
        dolls[i] = {w, h};
    }
    sort(dolls.begin(), dolls.end(), greater<pair<int, int>>());
    vector<bool> taken(m);
    int numberOfDolls = 0;
    int numberOfIterations = 0;
    int i = 0;
    while (i < m && numberOfIterations < m)
        if (!taken[i])
        {
            numberOfDolls++;
            auto R = countMaxDolls(dolls, m, taken, i);
            for (auto idx : R.second)
                taken[idx] = true;
            if (taken[i] == 0)
                continue;
            else
                i++;

            numberOfIterations++;
        }
        else
        {
            i++;
            numberOfIterations++;
        }

    cout << numberOfDolls << '\n';
}

int main()
{
    DPSolver;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}