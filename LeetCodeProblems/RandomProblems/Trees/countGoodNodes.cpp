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

void count(TreeNode *root, int mx, int &cnt)
{
    if (!root)
        return;
    if (root->val >= mx)
        cnt++;
    count(root->left, max(mx, root->val), cnt);  // left subtree
    count(root->right, max(mx, root->val), cnt); // right subtree
}

int goodNodes(TreeNode *root)
{
    int cnt = 0;
    count(root, root->val, cnt);
    return cnt;
}

int main()
{
    DPSolver;

    return 0;
}