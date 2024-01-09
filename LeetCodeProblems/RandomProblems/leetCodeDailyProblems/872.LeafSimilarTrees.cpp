#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void get_leaves(TreeNode *root, vector<int> &leaves)
{
    if (!root)
        return; 
    if (!root->left && !root->right)
        leaves.push_back(root->val); 
    // get left leaves
    get_leaves(root->left,leaves);
    // get right leaves
    get_leaves(root->right,leaves);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    DPSolver;
    vector<int> root1Leaves;
    vector<int> root2Leaves;
    get_leaves(root1, root1Leaves);
    get_leaves(root2, root2Leaves);
    if (root1Leaves.size() != root2Leaves.size())
        return false;
    else {
        int sz = root1Leaves.size(); 
        for (int i = 0; i < sz ; i ++)
            if(root1Leaves[i] != root2Leaves[i])
                return false; 
    }
    return true; 
}

int main (){

}