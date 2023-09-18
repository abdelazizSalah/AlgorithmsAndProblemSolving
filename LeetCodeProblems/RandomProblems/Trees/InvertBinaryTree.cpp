#include <bits/stdc++.h>
using namespace std;
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root)
{
    // base case
    if (!root || (root->left == nullptr && root->right == nullptr))
        return root;

    // go visit left
    TreeNode *left = invertTree(root->left);

    // go visit right
    TreeNode *right = invertTree(root->right);

    // swap pointers
    root->left = right;
    root->right = left;
    return root;
}

void printTree(TreeNode *root)
{
    if (!root)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main()
{
    DPSolver;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    // root->left = new TreeNode
    printTree(root);
    cout << endl;
    root = invertTree(root);
    printTree(root);
    cout << endl;
    return 0;
}