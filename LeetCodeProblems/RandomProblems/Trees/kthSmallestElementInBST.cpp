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
int kthSmallest(TreeNode *root, int k)
{
    if (!root)
        return 1;
    int left = kthSmallest(root->left, k);
    int right = kthSmallest(root->right, k);
    if (left == k)
        return root->val;
    else if (right == k)
        return root->val;
    else
        return min(left, right) + 1;
}