#include <bits/stdc++.h>
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


map<pair<int,int>,int> pairDist; 
map<int, int> leafDist; 

int nodeNumber = 0; 
void makeAllNodesUnique(TreeNode* &root) { 
    if(!root)
        return ; 
    root->val = nodeNumber++;
    makeAllNodesUnique(root->left);
    makeAllNodesUnique(root->right);
}

int countPairs (TreeNode* root, int distance) { 
    /// if empty tree
    if (!root) return {}; 

    evalDist(root); 

    int counter = 0;
    for (auto &item : pairDist) 
        if (item.second <= distance)
            counter ++; 
    
    return counter; 
}

vector<int> evalDist(TreeNode* root) { 
   
    /// if leaf 
    if (!root->left && !root->right) {
        leafDist[root->val] = 1; 
        return {root->val}; 
    }

    /// recursivly visit left nodes and right nodes.
    vector<int> left = evalDist(root->left); 
    vector<int> right = evalDist(root->right); 

    /// calculate the distance between each node from the left to the right
    int leftSize = left.size(); 
    int rightSize = right.size(); 
    for (int i = 0 ; i < leftSize; i++){
        for (int j = 0; j < rightSize; j++) {
            pairDist[{left[i],right[j] }] = leafDist[left[i]] + leafDist[right[j]]; 
        }
        leafDist[left[i]] ++; 
    }


    /// return all leaf from that node. 
    vector<int> res(left);
    for(auto item : right){
        leafDist[item] ++; 
        res.push_back(item); 
    }
    
    return res; 
}