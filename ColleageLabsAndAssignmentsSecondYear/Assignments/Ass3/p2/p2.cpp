#include<bits/stdc++.h>	
#include <unordered_map>
#define fast ios_base::sync_with_stdio(0) , cin.tie(0), cout.tie(0)
using namespace std;

//void solve()
//{
//	int n; cin >> n; /// number of nodes 
//	map<int, int> mp; // representation for bt
//	vector<int> v(n);
//	for (auto& it : v)
//		cin >> it;
//	int e; cin >> e;
//	bool leftlinkedlist = true; 
//	while (e--)
//	{
//		char c; cin >> c;
//		if (c == 'R') leftlinkedlist = false; 
//		int p, ch; cin >> p >> ch;
//		if (c == 'L') // left child
//			mp[2 * p + 1] = v[ch];
//		else
//			mp[2 * p + 2] = v[ch];
//	}
//	int height = log2(mp.rbegin()->first); // value of the max
//	if (leftlinkedlist) height++;
//
//	map<int , pair<int ,int>> heightcalc; // first -> min sec-> sum;
//	heightcalc[0].first = heightcalc[0].second = v[0]; //root
//	int idx = 1;
//	for (int i = 1 ; i <= height;  i++)
//	{
//		int min = INT_MAX;
//		int lim = pow(2, i);
//		for (int j = 0; j < lim; j++)
//		{
//			heightcalc[i].second += mp[idx];
//			if (mp[idx] != 0 && mp[idx] < min) min = mp[idx];
//			idx++;
//		}
//		heightcalc[i].first = min; 
//	}
//	int L = v[0] % (height+1);
//	int k = heightcalc[L].first % (height + 1); 
//	if (k == 0) k ++; 
//	string ans = "";
//	for (int i = 0; i <= height; i += k)
//		ans += to_string(heightcalc[i].second); 
//
//	cout << ans;
//}

// solved
struct node
{
	node* left;
	node* right;
	int hi; 
	int val;
};

void insert(vector<node>& v , char c, int p, int ch)
{
	if (c == 'L')
		v[p].left = &v[ch];
	else
		v[p].right = &v[ch];
}

void DFS(node* n, map<int , pair <int, int>> &mp ,int& max_height , int h)
{
	if (n == nullptr)
	{
		max_height = max(max_height, h);
		return; 
	}
	n->hi = h;
	if (mp[h].first == 0) mp[h].first = INT_MAX; 
	mp[h].second += n->val; 
	if (n->val < mp[h].first) mp[h].first = n->val;
	DFS(n->left, mp,max_height, h + 1);
	DFS(n->right, mp,max_height, h + 1);
}

void solve()
{
	int n; cin >> n;
	vector<node> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].val;

	int e; cin >> e; 
	for (int i = 0; i < e; i++)
	{
		char c; 
		int p, ch;
		cin >> c >> p >> ch;
		insert(vec ,c, p, ch);
	}
	int mxh, h; 
	mxh = h = 0;
	map<int, pair<int, int>> hmp;  // height val , min , sum
	DFS(&vec[0], hmp,mxh, h);

	int L = vec[0].val % mxh;
	int k = hmp[L].first % mxh; 
	if (!k) k++;

	string s = "";
	for (int i = 0; i < mxh; i+= k)
		s += to_string(hmp[i].second); 
	
	cout << s; 
}
int main()
{
	fast;
	solve();
	return 0;
}
