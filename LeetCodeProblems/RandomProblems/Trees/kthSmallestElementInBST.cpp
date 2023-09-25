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

void findKth(TreeNode *root, int k, bool &found, bool &strt, int &res, int &cntr)
{
    // empty tree
    if (!root)
        return;
    // leaf node
    if (!root->left)
    {
        strt = true;
        if (cntr == k)
        {
            res = root->val;
            found = true;
        }
        return;
    }
    // we have not reached the left most node yet
    if (!strt)
        findKth(root->left, k, found, strt, res, cntr);
    // if we are now standing on it.
    if (cntr == k + 1)
    {
        res = root->val;
        found = true;
        return;
    }
    else
    {
        // base case
        cntr++;
        findKth(root->left, k, found, strt, res, cntr);
        // if we have found it
        if (found)
            return;
        findKth(root->right, k, found, strt, res, cntr);
    }
}

int kthSmallest(TreeNode *root, int k)
{
    bool found = false;
    bool strt = false;
    int res = INT_MIN;
    int cntr = 1;
    findKth(root, k, found, strt, res, cntr);
    return res;
}