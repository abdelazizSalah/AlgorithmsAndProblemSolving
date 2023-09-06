// Ms2la helwa gedaan <3

#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<pair<int, int>> pr;
    int numberOfFleets = position.size();
    if (numberOfFleets == 1)
        return numberOfFleets;
    for (int i = 0; i < numberOfFleets; i++)
        pr.push_back({position[i], speed[i]});

    // sort them according to the position accendingly
    sort(pr.begin(), pr.end());

    // build a number of steps vector
    vector<float> numberOfSteps(numberOfFleets);

    for (int i = 0; i < numberOfFleets; i++)
        numberOfSteps[i] = (target - pr[i].first) / (float)pr[i].second;

    for (int i = position.size() - 1; i > 0; i--)
        if (numberOfSteps[i] >= numberOfSteps[i - 1])
        {
            numberOfFleets--;
            numberOfSteps[i - 1] = numberOfSteps[i];
        }

    return numberOfFleets;
}

int main()
{
    DPSolver;
    // int trgt = 12;
    // int trgt = 10;
    // int trgt = 100;
    int trgt = 10;

    // vector<int> pos = {10, 8, 0, 5, 3};
    // vector<int> pos = {3};
    // vector<int> pos = {0, 2, 4};
    vector<int> pos = {0, 4, 2};

    // vector<int> speed = {2, 4, 1, 1, 3};
    // vector<int> speed = {3};
    vector<int> speed = {2, 1, 3};

    cout << carFleet(trgt, pos, speed);
    return 0;
}