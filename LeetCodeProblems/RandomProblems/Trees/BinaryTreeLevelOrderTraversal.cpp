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
class CompareOnVal
{
public:
    bool operator()(TreeNode *p1, TreeNode *p2)
    {
        return p1->val > p2->val;
    }
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {};
    // apply bfs.
    queue<TreeNode *> pq;
    vector<vector<int>> order = {{root->val}};
    pq.push(root);
    int idx = 0;
    while (pq.size())
    {
        int sz = pq.size();
        order.push_back({});
        idx++;
        while (sz--)
        {
            auto top = pq.front();
            pq.pop();
            if (top->left)
            {
                order[idx].push_back(top->left->val);
                pq.push(top->left);
            }
            if (top->right)
            {
                order[idx].push_back(top->right->val);
                pq.push(top->right);
            }
        }
    }
    order.pop_back();
    return order;
}

int main()
{
    // create  a tree in this order [3,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    auto order = levelOrder(root);
    for (auto &i : order)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}