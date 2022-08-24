#include <bits/stdc++.h>
using namespace std;
#define fast ios_base ::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
using ll = long long;

struct node
{
	int val;
	vector<node*> children;
	node* parent;
};

int maxSum(node* head ,map<node* , int>& memo)
{
	auto it = memo.find(head);
	if (it != memo.end())
		return memo[head];
	//base case 
	if (!head) // if null return 0 
		return 0;
	ll sumwith = head->val;
	ll sumwithout = 0;
	for (int i = 0; i < head->children.size(); i++)
	{
		if (head->children.size())
			for (int j = 0; j < head->children[i]->children.size(); j++)
			{
				sumwith += maxSum(head->children[i]->children[j] , memo);
			}
		sumwithout += maxSum(head->children[i] , memo);
	}

	memo[head] = max(sumwith, sumwithout); 
	return memo[head];
}
void solve()
{
	int n; cin >> n;
	vector<node*> tree(n);
	for (auto& it : tree) // creating tree
	{
		it = new node;
		cin >> it->val;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int p, c; cin >> p >> c;
		tree[c]->parent = tree[p];
		tree[p]->children.push_back(tree[c]);
	}
	map<node*, int> mp; 
	cout << maxSum(tree[0] , mp);
}

int main()
{
	fast;
	solve();
	return 0;
}