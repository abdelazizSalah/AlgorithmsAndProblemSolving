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

bool isValid(TreeNode *root, int leftBound, int rightBound, bool &res)
{
    if (!root)
        return true;
    if (root->val < rightBound && root->val > leftBound)
    {
        bool left = isValid(root->left, leftBound, root->val, res);
        if (res && left)
            bool right = isValid(root->right, root->val, rightBound, res);
        else
            res = false;
    }
    else
        res = false;
    return res;
}

bool isValidBST(TreeNode *root)
{
    DPSolver;
    bool res = true;
    isValid(root, LLONG_MAX, LLONG_MIN, res);
    return res;
}

int main()
{
    DPSolver;
    // create test case [120,70,140,50,100,130,160,20,55,75,110,119,135,150,200]
    TreeNode *root = new TreeNode(120);
    root->left = new TreeNode(70);
    root->right = new TreeNode(140);
    root->left->left = new TreeNode(50);
    root->left->right = new TreeNode(100);
    root->right->left = new TreeNode(130);
    root->right->right = new TreeNode(160);
    root->left->left->left = new TreeNode(20);
    root->left->left->right = new TreeNode(55);
    root->left->right->left = new TreeNode(75);
    root->left->right->right = new TreeNode(110);
    root->right->left->left = new TreeNode(119);
    root->right->left->right = new TreeNode(135);
    root->right->right->left = new TreeNode(150);
    root->right->right->right = new TreeNode(200);
    cout << boolalpha << isValidBST(root) << endl;
    return 0;
}