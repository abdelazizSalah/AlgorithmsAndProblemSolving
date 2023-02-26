#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int noOfAstrixs = floor(n / 2);
    int noOfD = 1;
    for (int i = 0; i < n; i++)
    {

        for (int k = 0; k < noOfAstrixs; k++)
            cout << "*";
        for (int k = 0; k < noOfD; k++)
            cout << "D";
        for (int k = 0; k < noOfAstrixs; k++)
            cout << "*";

        cout << endl;
        if (i < n / 2)
        {
            noOfAstrixs--;
            noOfD += 2;
        }
        else
        {
            noOfAstrixs++;
            noOfD -= 2;
        }
    }
}