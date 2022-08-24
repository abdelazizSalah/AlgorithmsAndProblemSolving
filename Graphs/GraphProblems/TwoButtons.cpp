//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base:: sync_with_stdio(0) ,cin.tie(0), cout.tie(0);
//using ll = long long;
////vector<vector<int>> graph(10005);
////vector<pair<ll, bool>> vis(10005);
////vector<bool> visBool(100005);
//
//ll twoButtons(int node, int trgt, vector<vector<int>>& graph, vector<bool>& vis)
//{
//	queue<int> Q;
//	Q.push(node); 
//	vis[node] = true; 
//	ll lvl = 0;
//	while (Q.size())
//	{
//		int sz = Q.size(); 
//		while (sz--)
//		{
//			int n = Q.front();
//			Q.pop();
//
//			if (trgt == n)
//				return lvl; 
//			if (n < trgt && !vis[2 * n])
//			{
//				vis[2 * n] = true;
//				Q.push(2 * n); 
//			}
//
//			if (1 < n && !vis[n - 1])
//			{
//				vis[n - 1] = true;
//				Q.push(n - 1);
//			}
//		}
//		lvl++;
//	}
//
//	return lvl; 
//}
//
//void solve()
//{
//	int n, m; cin >> n >> m; 
//	vector<vector<int>> graph(n + 1);
//	vector<bool> vis(10005);
//	cout << twoButtons(n , m, graph , vis); 
//}
//
//
//int main()
//{
//	fast; 
//	solve(); 
//	return 0; 
//}
//
////ll TwoButtons(int depth, ll num, const int& target)
////{
////	//base cases 
////	if (num == target) // found it
////		return depth;
////
////	if (num == 0)
////		return LLONG_MAX;  // not that path 
////
////	if (num > target) // greater than it
////		return depth + num - target;
////
////	if (vis[num].second) // visited before
////		return vis[num].first;
////
////	vis[num].second = true;
////
////	// double the value 
////	ll path1 = TwoButtons(depth + 1, num * 2, target);
////
////	//value -1 
////	ll path2 = TwoButtons(depth + 1, num - 1, target);
////
////	if (path1 != 0 && path2 != 0)
////		vis[num].first = min(path1, path2);
////	else if (path1 == 0 && path2 == 0)
////		vis[num].first = LLONG_MAX;
////	else if (path1 == 0)
////		vis[num].first = path2;
////	else if (path2 == 0)
////		vis[num].first = path1;
////
////	return vis[num].first;
////}
////
////void CreatingTheList(int node, const int& m)
////{
////	// base case 
////	if (visBool[node] || node == 0 || node == m)
////		return;
////
////	visBool[node] = true;
////	if (node > m)
////	{
////		graph[node].push_back(node - 1);
////		CreatingTheList(node - 1, m);
////	}
////	else {
////		graph[node].push_back(node * 2);
////		graph[node].push_back(node - 1);
////		CreatingTheList(node * 2, m);
////		CreatingTheList(node - 1, m);
////	}
////}
////
////
////// ana  b3ml cast lel bfs 3la 7asab ana 3auz a3ml a
//////5lek dayman faker en el bfs btgeblk el shortest path lw unweighted
////int bfs(int node, int& target)
////{
////	int lvl = 0;
////	queue <int> Q;
////	Q.push(node);
////	visBool[node] = true;
////	while (Q.size())
////	{
////		int sz = Q.size();
////		while (sz--)
////		{
////			int n = Q.front();
////			Q.pop();
////
////			if (n == target)
////				return lvl;
////			if (!visBool[2 * n] && n < target)
////			{
////				visBool[2 * n] = true;
////				Q.push(2 * n);
////			}
////
////			if (!visBool[n - 1] && 1 < n)
////			{
////				visBool[n - 1] = true;
////				Q.push(n - 1);
////			}
////
////		}
////		lvl++;
////	}
////
////	return lvl;
////}
////void solve()
////{
////	int n, m; cin >> n >> m;
////	if (n == m) {
////		cout << 0;
////		return;
////	}
////	cout << bfs(n, m);
////
////}
////
////int main()
////{
////	fast;
////	solve();
////	return 0;
////}