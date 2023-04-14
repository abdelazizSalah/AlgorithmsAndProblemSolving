// Accepted :D
#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

void solve()
{
    pair<int, int> HamdyPlace, MangaPlace, HamdyToyPlace, MangaToyPlace;
    cin >> HamdyPlace.first >> HamdyPlace.second;
    cin >> HamdyToyPlace.first >> HamdyToyPlace.second;
    cin >> MangaPlace.first >> MangaPlace.second;
    cin >> MangaToyPlace.first >> MangaToyPlace.second;

    double r1 = sqrt(pow(HamdyPlace.first - HamdyToyPlace.first, 2) + pow(HamdyPlace.second - HamdyToyPlace.second, 2));
    double r2 = sqrt(pow(MangaPlace.first - MangaToyPlace.first, 2) + pow(MangaPlace.second - MangaToyPlace.second, 2));
    double dc = sqrt(pow(HamdyPlace.first - MangaPlace.first, 2) + pow(HamdyPlace.second - MangaPlace.second, 2));

    if (dc <= r1 + r2)
        cout << "Yes";
    else
        cout << "No";
}
int main()
{
    DPSOLVER;
    solve();
    return 0;
}