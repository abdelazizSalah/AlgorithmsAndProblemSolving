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
int findHeight(TreeNode *root, bool &balanced)
{
    if (!balanced)
        return -10;
    if (root == nullptr)
        return -1;
    else if (root->left == nullptr && root->right == nullptr)
        return 0;

    int left = findHeight(root->left, balanced);
    int right = findHeight(root->right, balanced);
    if (abs(left - right) > 1)
    {
        balanced = false;
        return -10;
    }
    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root)
{
    bool balanced = true;
    findHeight(root, balanced);
    return balanced;
}
int main()
{
    DPSolver;
}