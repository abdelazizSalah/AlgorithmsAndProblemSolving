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

bool isLeaf(TreeNode *head)
{
    return !(head->left || head->right);
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return nullptr;
    if (root->val == p->val)
        return p;
    else if (root->val == q->val)
        return q;
    else if (isLeaf(root))
        return nullptr;

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left == right)
        return left;
    if (!left)
        return right;
    if (!right)
        return left;
    return root;
}

// making use of binary search tree O(lg n)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    int value = root->val;
    if (value < p->val and value < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    else if (value > p->val and value > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else
    {

        return root;
    }
}

int main()
{
    return 0;
}