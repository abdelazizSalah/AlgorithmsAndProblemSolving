#include <bits/stdc++.h>
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
using namespace std;

vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    DPSolver;        
    int rowSize = matrix.size();
    if(!rowSize)
        return {};  
    int colSize = matrix[0].size(); 
    /// get the maximum number in each row 
    vector<int> rows;
    for (int i = 0; i < rowSize; i ++) 
        rows.push_back(*min_element(matrix[i].begin(), matrix[i].end())); 
    
    vector<int>cols; 
    for (int i = 0; i < colSize; i ++) {
        int maxElement = INT_MIN; 
        for (int j = 0; j < rowSize; j ++)
        {
            maxElement = max(maxElement, matrix[j][i]);
        }
        cols.push_back(maxElement);
    }
    vector<int> lucky; 

    /// now lets find the lucky numbers 
    for (int i = 0; i < rowSize; i++)
        for(int j =0 ; j < colSize; j++) 
            if (matrix[i][j] == rows[i] && matrix[i][j] == cols[j])
                lucky.push_back(matrix[i][j]); 
        
    return lucky; 
    

}

    int main () { 

    }