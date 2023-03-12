#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n';
void solve()
{
    int n;
    cin >> n;
    int maxPossibleOperations = 2 * n;
    vector<int> nums(n);
    for (int &num : nums)
    {
        cin >> num;
        if (num == 1)
            num++;
        maxPossibleOperations--;
    }

    for (int i = 1; i < n; i++)
    {
        while (!(nums[i] % nums[i - 1]) && maxPossibleOperations)
        {
            nums[i]++;
            maxPossibleOperations--;
        }
    }

    for (int num : nums)
        cout << num << ' ';
    cout << endl;
}

int main()
{
    DPSOLVER;
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}