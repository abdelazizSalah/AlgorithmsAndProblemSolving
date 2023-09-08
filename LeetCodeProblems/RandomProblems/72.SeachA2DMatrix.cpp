#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool binary_search(const vector<int> &list, int trgt)
{
    int bgn = 0;
    int end = list.size() - 1;
    int md = floor((bgn + end) / 2);
    while (end > bgn)
        if (list[md] == trgt)
            return true;
        else if (list[md] > trgt)
        {
            end = md;
            md = floor((bgn + end) / 2);
        }
        else
        {
            bgn = md + 1;
            md = floor((bgn + end) / 2);
        }
    if (md < list.size() && md >= 0)
        if (list[md] == trgt)
            return true;
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int start_row = 0;
    int end_row = matrix.size() - 1;
    int mid_row = floor((end_row + start_row) / 2);
    while (end_row > start_row)
        if (target < matrix[mid_row][0])
        {
            end_row = mid_row;
            mid_row = floor((end_row + start_row) / 2);
        }
        else if (target > matrix[mid_row][matrix[mid_row].size() - 1])
        {
            start_row = mid_row + 1;
            mid_row = floor((end_row + start_row) / 2);
        }
        else
            return binary_search(matrix[mid_row], target);

    if (mid_row < matrix.size() && mid_row >= 0)
        return binary_search(matrix[mid_row], target);

    return false;
}

int main()
{
    DPSolver;
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    cout << boolalpha << searchMatrix(mat, 3) << '\n';
    cout << boolalpha << searchMatrix(mat, 13);
    return 0;
}