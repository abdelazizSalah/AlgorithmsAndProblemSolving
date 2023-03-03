#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    // two pointers problem
    int lastPtr = height.size() - 1;
    int firstPtr = 0;
    int maxArea = 0;
    while (firstPtr < lastPtr)
    {
        int minHeight = min(height[firstPtr], height[lastPtr]);
        maxArea = max(maxArea, (lastPtr - firstPtr) * minHeight);
        if (minHeight == height[firstPtr])
            firstPtr++;
        else
            lastPtr--;
    }

    return maxArea;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];
    cout << maxArea(height);
}