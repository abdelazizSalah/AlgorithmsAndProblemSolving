#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool tree2strVoid(TreeNode *root, string &res)
{
    if (!root)
        return false;
    res += to_string(root->val);

    bool left = false;
    bool right = false;

    if (root->left)
    {
        res += '(';
        tree2strVoid(root->left, res);
        res += ')';
    }
    // if (root->right){
    res += '(';
    tree2strVoid(root->right, res);
    res += ')';
    // }
    return left || right;
}

string tree2str(TreeNode *root)
{
    DPSolver;
    string res = "";
    tree2strVoid(root, res);
    return res;
}