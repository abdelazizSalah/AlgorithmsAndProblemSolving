#include <bits/stdc++.h>
using namespace std; 


bool validIdx (int rows, int cols, int i, int j){ 
    return i > -1 && j > -1 && i < rows && j < cols; 
}

bool  dfs(const vector<string>& graph, map<pair<int,int>, bool> &visNodes, int numRows, int numCols, int i, int j ) { 
    // check that the index is valid
    if (!validIdx(numRows, numCols, i,j) || graph[i][j] == '1')
        return false;

    // if visited before 
    if (visNodes[{i,j}])
        return false; 
    
    /// mark this node as visited 
    visNodes[{i,j}] = true; 
    
    // check up 
    dfs(graph, visNodes, numRows, numCols, i - 1, j);
    /// check down
    dfs(graph, visNodes, numRows, numCols, i + 1, j);
    /// check left
    dfs(graph, visNodes, numRows, numCols, i , j- 1);
    /// check right
    dfs(graph, visNodes, numRows, numCols, i , j+ 1);

    return true;
}


int main () { 
    vector<string> graph; 
    int numRows; cin >> numRows; 
    for(int i = 0; i < numRows; i++){ 
        string s; cin >> s; 
        graph.push_back(s); 
    }
    
    int numCols = graph[0].size();
    map<pair<int,int>, bool> visNodes; 
    int numOfComponents = 0;
    for (int i = 0; i < numRows; i ++){
        for(int j = 0; j < numCols; j++) { 
            if(dfs(graph, visNodes, numRows, numCols, i, j))
                numOfComponents ++; 
        }
    } 
    cout << numOfComponents; 
    return 0; 
}