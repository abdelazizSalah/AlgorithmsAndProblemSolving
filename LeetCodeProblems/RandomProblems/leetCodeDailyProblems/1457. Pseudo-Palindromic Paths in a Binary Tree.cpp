#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
using ll = long long;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    Define utility functions here
*/

bool isPalindrome(string path)
{
    map<int, int> freq;
    for (auto element : path)
        freq[element]++;
    bool oneExist = false;
    for (auto item : freq)
    {
        if (item.second % 2 != 0)
        {
            if (oneExist)
                return false;
            else
            {
                oneExist = true;
                continue;
            }
        }
    }
    return true; 
}

void getPaths(TreeNode *root,int&counter,  bitset<10> parity)
{
    if (!root)
        return ; 
    parity[root->val] = ~parity[root->val]; // inverting the bit. 
    if (!root->left && !root->right)
    {
        // this is a leaf
        if(parity.count() <=1) // this count number of ones in the bits. 
        // if we have 0 or 1, then we should increment the number of paths. 
            counter ++; 
        return;
    }

    if (root->left)
        getPaths(root->left, counter, parity);
    if (root->right)
        getPaths(root->right, counter, parity);
}


int pseudoPalindromicPaths(TreeNode *root)
{
    vector<vector<int>> allPahtes;
    bitset<10> path;
    int counter = 0; 
    getPaths(root, counter, path);
    return counter;
}

int main()
{
    // pseudoPalindromicPaths();
    return 0;
}