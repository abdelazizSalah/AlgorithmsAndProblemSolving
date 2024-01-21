#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
using ll = long long;

bool isOutSide(int i, int j, int rows, int cols)
{
    return i >= rows || i < 0 || j < 0 || j >= cols;
}

map <pair<int,int>, ll> memo; 
ll dp(const vector<vector<int>> &matrix, int i, int j)
{
    // make it efficient 
    auto it = memo.find({i,j}); 
    if (it != memo.end())
        return it->second; 
    // make it work
    //  base cases
    if (isOutSide(i, j, matrix.size(), matrix[0].size())){
        memo[{i,j}] = INT_MAX; 
        return INT_MAX;}
    if (i == matrix.size() - 1){
        memo[{i,j}] = matrix[i][j]; 
        return matrix[i][j];}

    // recursive case

    ll left = dp(matrix, i + 1, j - 1) ;
    ll down = dp(matrix, i + 1, j) ;
    ll right = dp(matrix, i + 1, j + 1) ;

    vector<int> vec; 
    if (left != INT_MAX)
        vec.push_back(left+ matrix[i][j]);
    if (down != INT_MAX)
        vec.push_back(down+ matrix[i][j]);
    if (right != INT_MAX)
        vec.push_back(right+ matrix[i][j]);
    
    memo[{i,j}]= vec.size()?  *min_element(vec.begin(), vec.end()) : INT_MAX;
    return vec.size()?  *min_element(vec.begin(), vec.end()) : INT_MAX;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    DPSolver;
    int cols = matrix[0].size(); 
    ll mn = INT_MAX; 
    for (int i = 0 ; i < cols; i ++)
        mn = max(mn, dp(matrix, 0, i)); 
    return mn; 
}

int main () {
    vector<vector<int>> mat = {
        {2,1,3}, 
        {6,5,4}, 
        {7,8,9},
    };
    cout << minFallingPathSum(mat); 
    return 0; 
}


// tabulation 
class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int> (n, -1));
        for(int i = 0; i<n; i++)
        {
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int rowIdx = n-2; rowIdx >= 0; rowIdx--)
        {
            for(int colIdx = 0; colIdx < n; colIdx++)
            {
                // Down
                int down = matrix[rowIdx][colIdx] + dp[rowIdx + 1][colIdx];

                // Left Diagonal
                int leftDiagonal = matrix[rowIdx][colIdx] + (colIdx - 1 < 0 ? 1e9 : dp[rowIdx + 1][colIdx - 1]);

                // Right Diagonal
                int rightDiagonal = matrix[rowIdx][colIdx] + (colIdx + 1 >= n ? 1e9 : dp[rowIdx + 1][colIdx + 1]);

                dp[rowIdx][colIdx] = min(down, min(leftDiagonal, rightDiagonal));
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            ans = min(ans, dp[0][i]);
        }

        return ans;
        

    }
};