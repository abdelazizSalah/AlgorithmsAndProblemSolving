#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void printVector(const vector<int> &nums)
{
    for (int num : nums)
        cout << num << ' ';
    cout << '\n';
}

int main()
{
    vector<int> nums = {0, -1, 1};
    sort(nums.begin(), nums.end());
    do
    {
        printVector(nums);
        // it generate the greater lexicographical orders only, so if we want to get all the
        // possible permutations, we should sort the system.
    } while (next_permutation(nums.begin(), nums.end()));
    return 0;
}