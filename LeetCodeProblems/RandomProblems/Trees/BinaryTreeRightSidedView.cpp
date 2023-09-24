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

vector<int> firstIdeaSolution(TreeNode *root)
{
    vector<int> res;
    while (!root)
    {
        res.push_back(root->val);
        if (!root->right)
            root = root->right;
        else if (!root->left)
            root = root->left;
        else
            break;
    }
    return res;
}

// we will need to apply bfs
// and insert only one element
// we start inserting from right side.
// if we found any node we will insert it.
// otherwise we will just break;
vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return {};
    // apply bfs.
    queue<TreeNode *> pq;
    vector<int> order = {root->val};
    vector<bool> lvls(205);
    pq.push(root);
    int idx = 0;
    while (pq.size())
    {
        int sz = pq.size();

        while (sz--)
        {
            auto top = pq.front();
            pq.pop();
            if (top->right)
            {

                pq.push(top->right);
                if (!lvls[idx])
                {
                    order.push_back(top->right->val);
                    lvls[idx] = true;
                }
            }
            if (top->left)
            {
                pq.push(top->left);
                if (!lvls[idx])
                {
                    order.push_back(top->left->val);
                    lvls[idx] = true;
                }
            }
        }
        idx++;
    }
    // order.pop_back();
    return order;
}

int main()
{
    return 0;
}