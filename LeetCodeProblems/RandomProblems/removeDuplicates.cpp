#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int removeDuplicates(vector<int> &nums)
{
    map<int, bool> mp;
    // int cntr = 0;
    short sz = nums.size();
    for (int i = 0; i < sz; i++)
        if (mp[nums[i]])
        {
            // cntr++;
            nums.erase(nums.begin() + i--);
            sz--;
        }
        else
            mp[nums[i]] = true;
    return sz;
}

int main()
{
    // vector<int> n = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> n = {1, 1, 2};
    cout << removeDuplicates(n);
    for (auto i : n)
        cout << '\n'
             << i;
}