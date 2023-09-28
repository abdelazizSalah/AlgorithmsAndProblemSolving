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

vector<int> buildTheOrder(vector<int> &preorder, vector<int> &inorder)
{
    // 1. Create a map which keys are the inorder elements, and the values are the indicies.
    map<int, int> inOrderIdx;
    int sz = inorder.size();
    for (int i = 0; i < sz; i++)
        inOrderIdx[inorder[i]] = i;

    // 2. create a stack, and insert the first element of preorder in it.
    stack<int> st;
    st.push(preorder[0]);

    // 3. create a vector in which we will store the result
    vector<int> result(1e4 + 5, INT_MIN); // 1e3 is enough but to be in safe zone.

    // iterate over the preorder nodes
    for (int i = 1; i < sz; i++)
    {
        bool notLeft = false;
        int lastNode = st.top();
        while (st.size())
        {
            if (inOrderIdx[preorder[i]] < st.top())
            {
                if (notLeft)
                {
                    st.push(lastNode);
                    st.push(inOrderIdx[preorder[i]]);
                    result[(2 * lastNode) + 2] = preorder[i];
                }
                else
                {
                    st.push(inOrderIdx[preorder[i]]);
                    result[(2 * lastNode) + 1] = preorder[i];
                }
                break;
            }
            else
            {
                if (st.size() == 1)
                {
                    st.push(inOrderIdx[preorder[i]]);
                    result[(2 * lastNode) + 2] = preorder[i];
                    break;
                }
                else
                {
                    lastNode = st.top();
                    st.pop();
                }
            }
        }
    }
    return result;
}

void buildRelation(const vector<int> &result, int idx, TreeNode *&node)
{
    if (result[(2 * idx + 1)] != INT_MIN)
        node->left = &TreeNode(result[(2 * idx + 1)]);
    else
        node->left = nullptr;
    if (result[(2 * idx + 2)] != INT_MIN)
        node->right = nullptr;
    else
        node->right = &TreeNode(result[(2 * idx + 2)]);
}
void printRes(const vector<int> &res)
{
    for (auto r : res)
        if (r != INT_MIN)
            cout << r << ' ';
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    vector<int> res = buildTheOrder(preorder, inorder);
    TreeNode *tree = &TreeNode(preorder[0]);
    TreeNode *left = tree;
    TreeNode *right = tree;
    for (int i = 1; i < preorder.size(); i++)
    {
        if (left)
            buildRelation(res, i, left);
        if (right)
            buildRelation(res, i, right);

        left = tree->left;
        right = tree->right;
    }
    printRes(res);
    return tree;
}

void build(vector<int> &res, int idx, TreeNode *&root)
{
    if (!root)
        return;
}

int main()
{
    DPSolver;
    return 0;
}