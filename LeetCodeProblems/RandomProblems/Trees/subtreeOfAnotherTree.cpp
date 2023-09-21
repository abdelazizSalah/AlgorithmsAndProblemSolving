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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    // base cases
    //? 1. if one root is null, and the other is not.
    if (p == nullptr && q)
        return false;
    if (q == nullptr && p)
        return false;

    //? if both are empty
    if (p == nullptr && q == nullptr)
        return true;

    //? if we reached leaf node for both
    if (isLeaf(p) && isLeaf(q))
        return p->val == q->val;

    //? if the current state, has different values
    if (p->val != q->val)
        return false;

    bool leftAreSame = isSameTree(p->left, q->left);
    bool rightAreSame = isSameTree(p->right, q->right);
    return leftAreSame && rightAreSame;
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (isLeaf(root) && isLeaf(subRoot))
        return root->val == subRoot->val;
    if (root->val == subRoot->val)
        if (isSameTree(root, subRoot))
            return true;
    bool left = isSubtree(root->left, subRoot);
    bool right = isSubtree(root->right, subRoot);
    return left || right;
}

int main()
{
    DPSolver;
    cout << boolalpha << true;
    return 0;
}