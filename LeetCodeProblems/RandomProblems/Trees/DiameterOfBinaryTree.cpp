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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int diameterOfBinaryTreeWithBool(TreeNode *root, int &mx)
{
    if (root == nullptr)
        return -1;
    else if (root->left == nullptr && root->right == nullptr)
    {
        mx = max(mx, 0);
        return 0;
    }

    int left = diameterOfBinaryTreeWithBool(root->left, mx);
    int right = diameterOfBinaryTreeWithBool(root->right, mx);
    int h = 1 + max(left, right);
    int d = left + right + 1 + 1;
    mx = max(d, mx);
    return h;
}
int diameterOfBinaryTree(TreeNode *root)
{
    DPSolver;
    int mx = INT_MIN;
    int cntr = 0;
    diameterOfBinaryTreeWithBool(root, mx);
    return mx;
}

int main()
{
    // create root = 1
    // root -> left = 2, root -> right = 3
    // root -> left -> left = 4, root -> left -> right = 5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);

    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}
// solution video link.
// https://www.youtube.com/watch?v=bkxqA8Rfv04