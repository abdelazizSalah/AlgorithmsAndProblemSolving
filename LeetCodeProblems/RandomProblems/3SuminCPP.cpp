#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// int main()
// {
// set<vector<int>> res;
//     vector<int> nums = {-1, 0, 1, 2, -1, 4};
//     int sz = nums.size();
//     for (int i = 0; i < sz; i++)
//         for (int j = i + 1; j < sz; j++)
//             for (int k = j + 1; k < sz; k++)
//                 if (!(nums[i] + nums[j] + nums[k]))
//                 {
//                     vector<int> dum = {nums[i], nums[j], nums[k]};
//                     sort(dum.begin(), dum.end());
//                     res.insert(dum);
//                 }
// vector<vector<int>> finalRes;
// for (auto list : res)
//     finalRes.push_back(list);

//     return 0;
// }

int main()
{
    set<vector<int>> res;
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    for (int i = 0; i < sz; i++)
    {

        int trgt = -nums[i];
        int bgn = i + 1;
        int end = sz - 1;
        while (bgn < end)
        {
            if (nums[bgn] + nums[end] == trgt)
            {
                vector<int> dum = {nums[i], nums[bgn], nums[end]};
                sort(dum.begin(), dum.end());
                res.insert(dum);
                bgn++;
                end--;
            }
            else if (nums[bgn] + nums[end] < trgt)
                bgn++;
            else
                end--;
        }
    }

    vector<vector<int>> finalRes;
    for (auto list : res)
        finalRes.push_back(list);

    return 0;
}