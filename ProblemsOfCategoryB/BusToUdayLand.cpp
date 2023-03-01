#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> busSeats;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        busSeats.push_back(s);
    }

    bool theySit = false;
    for (int i = 0; i < n; i++)
    {
        bool possibleSeat = false;
        for (int j = 0; j < 5; j++)
        {
            if (possibleSeat)
            {
                if (busSeats[i][j] == 'O')
                {
                    busSeats[i][j] = '+';
                    busSeats[i][j - 1] = '+';
                    possibleSeat = false;
                    theySit = true;
                    break;
                }
                else
                    possibleSeat = false;
            }
            else if (busSeats[i][j] == 'O')
                possibleSeat = true;
            else
                possibleSeat = false;
        }
        if (theySit)
            break;
    }

    if (theySit)
    {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++)
        {
            for (char c : busSeats[i])
                cout << c;
            cout << '\n';
        }
    }
    else
        cout << "NO";
}