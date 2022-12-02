#include <bits/stdc++.h>
using namespace std;
#define fast ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void solve()
{
    /// reading the data
    int homeStart, homeEnd;
    cin >> homeStart >> homeEnd;
    int appleTreeLoc, orangeTreeLoc;
    cin >> appleTreeLoc >> orangeTreeLoc;
    int numberOfApples, numberOfOranges;
    cin >> numberOfApples >> numberOfOranges;

    vector<int> applesDist(numberOfApples), orangeDist(numberOfOranges);

    for (int &apple : applesDist)
        cin >> apple;

    for (int &orange : orangeDist)
        cin >> orange;

    // applying the logic
    int appleCntr = 0;
    int orangeCntr = 0;

    for (int &apple : applesDist)
    {
        if (apple < 0)
            continue;
        else if (apple + appleTreeLoc <= homeEnd && apple + appleTreeLoc >= homeStart)
            appleCntr++;
    }

    for (int &orange : orangeDist)
    {
        if (orange > 0)
            continue;
        else if (orange + orangeTreeLoc <= homeEnd && orange + orangeTreeLoc >= homeStart)
            orangeCntr++;
    }

    // printing the output
    cout << appleCntr << '\n'
         << orangeCntr;
}

int main()
{
    fast;
    solve();
    return 0;
}