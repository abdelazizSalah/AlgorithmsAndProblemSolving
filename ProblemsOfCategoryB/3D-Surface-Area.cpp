#pragma once
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

// complexity O(W*H)
void computeResLR(int &res, const vector<vector<int>> &Mat, int width, int height)
{
    // computing the left view values
    for (int i = 0; i < 1; i++)
        for (int j = 0; j < width; j++)
            res += Mat[i][j];

    // computing the internal sides
    for (int j = 0; j < width; j++)
        for (int i = 0; i < height - 1; i++)
            res += abs(Mat[i][j] - Mat[i + 1][j]);

    // computing the right view values
    for (int i = height - 1; i < height; i++)
        for (int j = 0; j < width; j++)
            res += Mat[i][j];
}

// complexity O(W*H)
void computeResFB(int &res, const vector<vector<int>> &Mat, int width, int height)
{
    // computing the front view values
    for (int j = 0; j < 1; j++)
        for (int i = 0; i < height; i++)
            res += Mat[i][j];

    // computing the internal sides
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width - 1; j++)
            res += abs(Mat[i][j] - Mat[i][j + 1]);

    // computing the right view values
    for (int j = width - 1; j < width; j++)
        for (int i = 0; i < height; i++)
            res += Mat[i][j];
}

// complexity O(W*H)
void solve()
{
    // reading the input
    int H, W;
    cin >> H >> W;
    vector<vector<int>> Grid(H, vector<int>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> Grid[i][j];

    /// computing the result
    /// computing the top and bottom view
    int sum = 2 * W * H;

    /// computing the left and right view
    computeResLR(sum, Grid, W, H);

    /// computing the front and back view
    computeResFB(sum, Grid, W, H);

    /// printint the result
    cout << sum;
}

int main()
{
    fast;
    solve();
    return 0;
}