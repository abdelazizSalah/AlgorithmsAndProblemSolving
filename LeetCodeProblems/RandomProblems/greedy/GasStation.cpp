#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int sz = gas.size();
    int totalAvailableGas = 0;
    int totalCost = 0;
    priority_queue<pair<pair<int, int>, int>> HighestGasLowestCost;
    for (int i = 0; i < sz; i++)
    {
        totalAvailableGas += gas[i];
        totalCost += cost[i];
        // - as pq sort Descendingly, And I want to sort by highest gas and lowest cost, so -2 will be > -8.
        if (gas[i] >= cost[i])
            HighestGasLowestCost.push({{gas[i], -cost[i]}, i});
    }
    if (totalCost > totalAvailableGas)
        return -1;
    while (HighestGasLowestCost.size())
    {
        // getting the idx of this element.
        auto topIdx = HighestGasLowestCost.top().second;
        bool createdACircuit = false;
        auto beginingStation = HighestGasLowestCost.top().first;
        int availableGasInTank = 0;
        int numberOfStations = 0;
        while (!createdACircuit)
        {
            if (numberOfStations == sz)
                return topIdx;
            availableGasInTank += gas[(topIdx + numberOfStations) % sz];
            int currentCost = cost[(topIdx + numberOfStations) % sz];
            if (availableGasInTank < currentCost)
            {
                HighestGasLowestCost.pop();
                break;
            }
            availableGasInTank -= currentCost;
            numberOfStations++;
        }
    }
    return -1;
}

int main()
{
    DPSolver;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas, cost);
    return 0;
}