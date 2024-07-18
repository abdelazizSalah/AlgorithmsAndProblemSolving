#include <bits/stdc++.h>
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std; 
vector<bool> vis(1e5 + 7); 
int minIncrementForUnique(vector<int> &nums)
{
    DPSolver; 
    /// sort the given vector. 
    sort(nums.begin(), nums.end()); 

    int cntr = 0; 
    for (int digit : nums){ 
        int iterator = 0; 
        while (vis[digit + iterator]){
            iterator ++, cntr++; 
        }
        vis[digit + iterator] = true; 
    }
    return cntr; 
}

int main()
{
    vector<int> v = {3,2,1,2,1,7};
    cout << minIncrementForUnique(v); 
    return 0; 
}