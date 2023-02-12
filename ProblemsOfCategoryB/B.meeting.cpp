// accepted :)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"

int findingNoOfBlankts(vector<pair<pair<int, int>, bool>> &generals, const vector<pair<pair<int, int>, int>> &radiators)
{
    int noOfBlankts = 0;
    for (auto rad : radiators) // O(n^2)
        for (auto &gen : generals)
            // this general is uncovered
            if (gen.second == false)
                if (sqrt(pow(rad.first.first - gen.first.first, 2) + pow(rad.first.second - gen.first.second, 2)) <= rad.second)
                    gen.second = true;

    for (auto gen : generals) // O(n)
        if (gen.second == false)
            noOfBlankts++;
    return noOfBlankts;
} // O(n^2 + n) = O(n^2)

void fillingGenerals(vector<pair<pair<int, int>, bool>> &generals, pair<int, int> topLeft, pair<int, int> bottomRight)
{
    int beginningX = min(topLeft.first, bottomRight.first);
    int endingX = max(topLeft.first, bottomRight.first);

    // getting the lower and upper generals posiotions
    for (int i = beginningX; i <= endingX; i++)
    {
        generals.push_back({{i, topLeft.second}, false});
        generals.push_back({{i, bottomRight.second}, false});
    }

    int beginningY = min(bottomRight.second, topLeft.second);
    int endingY = max(bottomRight.second, topLeft.second);
    // getting the side generals positions
    for (int j = beginningY + 1; j < endingY; j++)
    {
        generals.push_back({{topLeft.first, j}, false});
        generals.push_back({{bottomRight.first, j}, false});
    }
} // O(n)

void solve()
{
    // reading the positions
    pair<int, int> topLeft, topRight, bottomLeft, bottomRight;
    cin >> topLeft.first >> topLeft.second;         // defining the topLeft point
    cin >> bottomRight.first >> bottomRight.second; // defining the bottomRight point

    // defining the topRight point
    topRight = {bottomRight.first, topLeft.second};
    // defining the bottomLeft point
    bottomLeft = {topLeft.first, bottomRight.second};

    // defining a vector of points
    vector<pair<pair<int, int>, bool>> generals; // (position, isCovered)

    // filling the generals vector
    fillingGenerals(generals, topLeft, bottomRight);

    // reading the radiators
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> radiators(n); // (position, radius)
    for (auto &rad : radiators)
        cin >> rad.first.first >> rad.first.second >> rad.second;

    // apply the algorithm and finding the solution
    cout << findingNoOfBlankts(generals, radiators) << endl;
} // O(n^2 + n) = O(n^2) -> max n = 1000 -> O(10^6) should fit.

int main()
{
    fast;
    solve();
    return 0;
}