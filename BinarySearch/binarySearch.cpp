#include <bits/stdc++.h>
using namespace std;
// this function returns the index of the element which we look for using the concept of the binary search.
int Binarysearch(vector<int> &nums, int trgt)
{
    if (nums.size() == 1)
    {
        if (nums[0] == trgt)
            return 0;
        else
            return -1;
    }
    int beg = 0;
    int end = nums.size() - 1;
    int mid = floor((beg + end) / 2);
    while (end > beg)
    {
        if (nums[mid] == trgt)
            return mid;
        else if (nums[mid] > trgt)
        {
            // search left
            end = mid;
            mid = floor((beg + end) / 2);
        }
        else
        {
            beg = mid + 1;
            mid = floor((beg + end) / 2);
        }
    }
    if (mid < nums.size() && mid >= 0)
        if (nums[mid] == trgt)
            return mid;
    return -1;
}
int main()
{
}