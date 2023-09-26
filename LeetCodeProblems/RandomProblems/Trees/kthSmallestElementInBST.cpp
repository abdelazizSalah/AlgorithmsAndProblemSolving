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

void dfs(TreeNode *root, queue<TreeNode *> &nodes)
{
    // empty tree
    if (!root)
        return;
    // leaf node
    if (!root->left && !root->right)
    {
        nodes.push(root);
        return;
    }
    // has right child only
    if (!root->left)
    {
        nodes.push(root);
        dfs(root->right, nodes);
    }
    else if (!root->right)
    {
        // has left child only
        dfs(root->left, nodes);
        nodes.push(root);
    }
    else
    {
        // has both children
        dfs(root->left, nodes);
        nodes.push(root);
        dfs(root->right, nodes);
    }
}

int kthSmallest(TreeNode *root, int k)
{
    queue<TreeNode *> nodes;
    dfs(root, nodes);
    while (k--)
        nodes.pop();
    return nodes.front()->val;
}

// better solution  -> more compact, but same complexity.
void inOrderTraversal(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;

    // left, root, right
    inOrderTraversal(root->left, v);
    v.push_back(root->val);
    inOrderTraversal(root->right, v);
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> v;
    inOrderTraversal(root, v);
    return v[k - 1];
}