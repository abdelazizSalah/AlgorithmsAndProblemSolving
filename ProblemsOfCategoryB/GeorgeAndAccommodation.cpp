#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int noOfRooms = 0;
    for (int i = 0; i < n; i++)
    {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2)
            noOfRooms++;
    }
    cout << noOfRooms;
}