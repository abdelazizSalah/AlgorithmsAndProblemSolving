#include <bits/stdc++.h>
using namespace std;

int diagonalDifference(vector<vector<int>> arr)
{
    int sum = 0;
    int inverseSum = 0;
    for (int i = 0, a = arr.size() - 1; i < arr.size(); i++, a--)
    {

        sum += arr[i][i];
        inverseSum += arr[i][a];
    }
    return abs(sum - inverseSum);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> myArr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> myArr[i][j];
        }
    }

    cout << diagonalDifference(myArr);
}