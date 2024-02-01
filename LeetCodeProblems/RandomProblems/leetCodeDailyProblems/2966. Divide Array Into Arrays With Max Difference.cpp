#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

void countSort(vector<int> &unSortedVector, int maxRange)
{
    // create a count vector.
    vector<int> count(maxRange + 1);
    for (int x : unSortedVector)
        count[x]++;
    int sz = unSortedVector.size();

    // create a vector to store the indicies.
    vector<int> indicies(maxRange + 1);
    for (int i = 1; i <= maxRange; i++)
        indicies[i] = indicies[i - 1] + count[i - 1]; // increment

    // sort the elements.
    vector<int> sortedVec(sz);
    for (int i = 0; i < sz; i++)
    {
        int idx = indicies[unSortedVector[i]];
        sortedVec[idx] = unSortedVector[i];
        indicies[unSortedVector[i]]++;
    }
    unSortedVector = sortedVec;
}

bool validateVector(vector<int> v3, int k)
{
    if (
        v3[1] - v3[0] > k ||
        v3[2] - v3[0] > k ||
        v3[2] - v3[1] > k)
        return false;

    return true;
}

vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    DPSolver; 
    int sz = nums.size();
    int maxRange = *max_element(nums.begin(), nums.end());
    countSort(nums, maxRange);
    vector<vector<int>> res = {};
    int resSize = -1;
    int elements = 0;
    for (int i = 0; i < sz; i++)
    {
        if (elements == 0)
        {
            res.push_back({nums[i]});
            resSize++;
            elements++; 
        } else if (elements == 1){
            res[resSize].push_back(nums[i]); 
            elements++;
        }else {
            res[resSize].push_back(nums[i]); 
            elements = 0; 
            if (!validateVector(res[resSize], k))
                return {};
        }
    }

    return res;
}
int main()
{
    vector<int> v1 = {1,3,3,2,7,3};
    int k = 3;
    auto res = divideArray(v1, k); 
    for (auto vec : res)
    {
        for (int i : vec)
            cout << i << ' ' ; 
        cout << '\n'; 
    }
    return 0;
}