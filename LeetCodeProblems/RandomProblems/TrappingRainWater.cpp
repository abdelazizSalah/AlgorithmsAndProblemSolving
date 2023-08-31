#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main()
{
    DPSolver;
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vector<int> height = {4, 2, 0, 3, 2, 5};
    // vector<int> height = {2, 0, 4, 2, 3, 2, 2, 0, 0, 3, 2, 0, 3};
    // vector<int> height = {5, 4, 1, 2};
    // vector<int> height = {5, 3, 4, 1, 2};
    vector<int> height = {0, 3, 4, 4, 6, 6};

    // first of all we should start from the heighest two bricks from the two ends
    int end = height.size() - 1;
    int start = 0;
    for (int i = 0; i < end; i++)
        if (height[i + 1] >= height[i])
            start++;
        else
            break;
    for (int i = end; i > 0; i--)
        if (height[i - 1] >= height[i])
            end--;
        else
            break;

    // when we reach this brick we should stop.

    // this indicates number of steps moved in one turn.
    int movedSteps = 0;

    // this is my second pointer
    int secondPointer = start;
    if (start + 1 <= end)
        int secondPointer = start + 1;

    // the total amount of traped water
    int trapedWater = 0;
    while (secondPointer != end && (start < end))
    {
        if (height[secondPointer] < height[start])
        {
            trapedWater += height[start] - height[secondPointer];
            secondPointer++;
            movedSteps++;
        }
        else
        {
            start = secondPointer;
            secondPointer = start + 1;
            movedSteps = 0;
        }
    }

    if (height[secondPointer] < height[start])
    {
        // we need to subtract the diffrance
        while (secondPointer != start)
        {
            secondPointer--;
            trapedWater -= (height[start] - height[secondPointer]);
            if (height[end] > height[secondPointer])
            {
                trapedWater += (height[end] - height[secondPointer]);
            }
            else
                end = secondPointer;
        }
    }

    cout << trapedWater;
    return trapedWater;
}