#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

/// accepted solution
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    // we compare on 3 values
    // 1. the value in the index
    // 2. the value in the index * the max product till now
    // 3. the value in the index * the min product till now
    // and finally we take the max of all 3
    int maxProduct = 1;
    int minProduct = 1;
    int ans = INT_MIN;
    for (int num : nums)
    {
        int dp_max = num * maxProduct;
        int dp_min = num * minProduct;
        maxProduct = max(num, max(dp_max, dp_min));
        minProduct = min(num, min(dp_max, dp_min));
        ans = max(ans, maxProduct);
    }
    return ans;
}
/// slow solution
// int maxProduct(vector<int> num)
// {
//     int sz = num.size();
//     vector<int> res = {num[0]};
//     int mx = num[0];
//     for (int i = 0; i < sz; i++) // this is O(n^2)
//     {
//         int product = num[i];
//         for (int j = i + 1; j < sz; j++)
//         {
//             product *= num[j];
//             mx = max(mx, product);
//         }
//     }
//     return mx;
// }
// dp solution should make it in O(n)

int main()
{
    DPSOLVER;
    cout << maxProduct({-2, 0, -1});
}