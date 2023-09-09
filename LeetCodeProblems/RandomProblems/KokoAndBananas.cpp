#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;

bool valid(const vector<int> &piles, const int k, const int h)
{
    int sum = 0;
    for (auto pile : piles)
        sum += ceil(pile / (ld)k);
    return sum <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    // int sz = piles.size();
    // if (sz == h)
    //     return *max_element(piles.begin(), piles.end());
    // else if (sz == 1)
    //     return ceil((ld)piles[0] / h);
    // int mx_element = *max_element(piles.begin(), piles.end());
    int mx_element = INT_MAX;
    int bgn = 1;
    int end = mx_element;
    int md = (bgn + end) / 2;
    priority_queue<int, vector<int>, greater<>> pq;
    while (end > bgn)
        if (valid(piles, md, h))
        {
            pq.push(md);
            end = md;
            md = (bgn + end) / 2;
        }
        else
        {
            bgn = md + 1;
            md = (bgn + end) / 2;
        }

    if (md >= 0 && md <= mx_element)
        if (valid(piles, md, h))
            pq.push(md);

    return pq.top();
}

int main()
{
    DPSolver;
    // vector<int> piles = {3, 6, 7, 11};
    // vector<int> piles = {30, 11, 23, 4, 20};
    vector<int> piles = {1000000000, 1000000000};
    // int h = 8;
    // int h = 5;
    // int h = 6;
    int h = 3;
    cout << minEatingSpeed(piles, h);
    return 0;
}