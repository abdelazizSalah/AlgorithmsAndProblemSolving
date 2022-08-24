#include <bits/stdc++.h>	
//Accepted first time :D
using namespace std;
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) ,cout.tie(0);
using ll = long long; 
struct node
{
	node* left;
	node* right;
	int val;
};
ll absDif(node* head, ll r, int& cntr);
void insert(vector<node>& v, char c, int p, int ch);
void solve()
{
	int n;
	ll r;
	cin >> n >> r; 
	vector<node> v(n); 
	for (auto& it : v)
		cin >> it.val; 

	int e; cin >> e; 
	while (e--) // building the tree
	{
		char c; cin >> c; 
		int p, ch; cin >> p >> ch;
		insert(v, c, p, ch);
	}

	int cntr = 0; 
	absDif(&v[0], r, cntr);
	cout << cntr; 

}

int main()
{
	fast;
	solve();
	return 0;
}

ll absDif(node* head, ll r, int& cntr )
{
	//base case 
	if (!head)
		return 0; 
	ll sumLeft = absDif(head->left, r, cntr);
	ll sumright = absDif(head->right, r, cntr);
	if (abs(sumLeft - sumright) <= r) cntr++; 
	return  (sumLeft + sumright + head->val);
}

void insert(vector<node>& v  , char c, int p, int ch)
{
	if (c == 'L')
		v[p].left = &v[ch];
	else
		v[p].right = &v[ch]; 
}
