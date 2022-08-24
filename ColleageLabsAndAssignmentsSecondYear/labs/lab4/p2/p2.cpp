#include <bits/stdc++.h>	
//Accepted first time :D
using namespace std;
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) ,cout.tie(0);
struct node
{
	node* left; 
	node* right; 
	int val;
};
void insert(vector<node>& v, char c, int p, int ch);
void MOP(node* head, multiset<int> ms, int& cntr , int lvl);

void solve()
{
	int n; cin >> n;
	vector<node> v(n); 
	for (auto& it : v) // reading nodes
		cin >> it.val;

	int e; cin >> e; 
	while (e--) // building the tree
	{
		char c; cin >> c; 
		int p, ch; cin >> p >> ch; 
		insert(v, c, p, ch);
	}
	multiset<int> ms; 
	int cntr = 0 ; 
	int lvl = 1;
	MOP(&v[0], ms, cntr , lvl); 
	cout << cntr;
}

int main()
{
	fast; 
	solve();
	return 0; 
}

void insert(vector<node>& v, char c, int p, int ch)
{
	if (c == 'L')
		v[p].left = &v[ch];
	else
		v[p].right = &v[ch];
}

void MOP(node* head, multiset<int> ms, int& cntr , int lvl)
{
	//base case 
	if (!head) return; 
	if (!(lvl % 2)) { // neglect even levels
		ms.emplace(head->val); 
		MOP(head->left, ms, cntr, lvl+1);
		MOP(head->right, ms, cntr, lvl+1);
		return;
	}
	else
	{ // odd level
		ms.emplace(head->val);
		auto it = ms.begin(); 
		for (int i = 0; i < ms.size() / 2; i++)
			it++; // move with the ptr till reaching the middle of the set

		if (*it == head->val) cntr++;
		MOP(head->left, ms, cntr, lvl + 1);
		MOP(head->right, ms, cntr, lvl + 1);
	}
}

void DFS(node* head, int h)
{
	if (!head)
		return; 

}
