// Accepted :), when you compare slopes you should use ld instead of float cause they may be different in very small numbers
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"

void solve()
{
    // reading input
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    vector<pair<int, int>> points(n);
    for (pair<int, int> &p : points)
        cin >> p.first >> p.second;

    // calculating slopes
    map<ld, bool> slopes; // vector of slopes
    for (auto point : points)
    {
        // slope is y2-y1/x2-x1
        // but we need to avoid division by zero
        int xSlope = point.first - x0;
        int ySlope = point.second - y0;
        if (xSlope == 0)
            slopes[INT_MAX] = true;
        else
            slopes[(ld)ySlope / xSlope] = true;
    }

    cout << slopes.size();
}

void solveEasy()
{
    int noOfAdvancer = 0;
    int n, kth;
    cin >> n >> kth;
    vector<int> points(n);
    for (int &point : points)
        cin >> point;
    for (int point : points)
        if (point >= points[kth - 1] && point > 0)
            noOfAdvancer++;

    cout << noOfAdvancer;
}

int main()
{
    fast;
    solveEasy();
    return 0;
}