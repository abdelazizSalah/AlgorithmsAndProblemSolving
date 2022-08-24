//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0), cin.tie(0) , cout.tie(0)
//
//vector<vector<int>>graph(10005);
//bool vis[10005]; 
//
//pair<int, int> bfs(int node)
//{
//  	pair<int, int> p; 
//	queue<int> Q; 
//	Q.push(node); 
//	vis[node] = true; 
//	int lvl = 0; 
//	while (Q.size())
//	{
//		int sz = Q.size(); 
//		while (sz--)
//		{
//			int n = Q.front(); 
//			Q.pop(); 
//			for (auto g : graph[n])
//				if (!vis[g])
//				{
//					vis[g] = true; 
//					Q.push(g); 
//					p = { g , lvl+1 }; // always set the leaf to the last node you have reached
//				}
//		}
//		lvl++; 
//	}
//	return p;
//}
//
//void solve()
//{
//	//setting the initial value for the arrays values 
//	memset(vis, false, sizeof(bool) * 10005);
//	int n; cin >> n;
//	
//	// reading the edges of the tree
//	for (int  i = 0; i < n -1 ; i++)
//	{
//		int u, v; 
//		cin >> u >> v; 
//		graph[u].push_back(v);
//		graph[v].push_back(u);
//	}
//
//	//we need 2 bfs -> 1 to find the leaf and the other to find the result
//	auto p = bfs(1);
//
//	memset(vis, false, sizeof(bool) * 10005);
//	cout << bfs(p.first).second; 
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////#include <bits/stdc++.h>
////using namespace std;
////#define fast ios_base::sync_with_stdio(0) , cin.tie(0) ,cout.tie(0) ;
////
////int DFSToFindLeaf(vector<vector<int>>& graph, int vertex, int parent)
////{
////	if (graph[vertex].size() > 1)
////	{
////		if (parent != graph[vertex][0])
////			DFSToFindLeaf(graph, graph[vertex][0], vertex);
////		else
////			DFSToFindLeaf(graph, graph[vertex][1], vertex);
////	}
////	else
////		return vertex;
////}
////
////int DFS(vector<vector<int>>& graph, int vertex, vector <bool>& vis, int depth)
////{
////	int maxDepth = 0;
////	int dp = depth;
////	for (int i = 0; i < graph[vertex].size(); i++)
////	{
////		if (!vis[graph[vertex][i]])
////		{
////			vis[graph[vertex][i]] = true;
////			dp = DFS(graph, graph[vertex][i], vis, ++depth);
////			maxDepth = max(maxDepth, dp);
////			depth--;
////		}
////	}
////	return max(dp, maxDepth);
////}
////
////// solution using 2 dfs 
////int LongestPathFounder(vector<vector<int>>& graph, int N, vector<bool>& vis)
////{
////	int leaf = DFSToFindLeaf(graph, graph[0][0], 0);
////
////	//apply DFS to get the longest path
////	return DFS(graph, leaf, vis, 0);
////}
////
////
//////bfs in the iterative version
////pair<int, int> bfs(int n, const vector<vector<int>>& graph, vector<bool>& vis)
////{
////	pair<int, int> p = { n, 0 };
////	queue<int> Q;
////	int lvl = 0;
////	Q.push(n);
////	vis[n] = true;
////	while (Q.size())
////	{
////		int sz = Q.size();
////		while (sz--)
////		{
////			int node = Q.front();
////			Q.pop();
////			for (auto g : graph[node])
////				if (!vis[g])
////				{
////					Q.push(g);
////					vis[g] = true;
////					p = { g , lvl + 1 };
////				}
////		}
////
////		lvl++;
////	}
////	return p;
////}
////
////// solution using 2 bfs
////void solve()
////{
////	int noOfNodes; cin >> noOfNodes;
////	vector<vector<int>> graphList(noOfNodes);
////	vector<bool> vis(noOfNodes);
////
////	for (int i = 0; i < noOfNodes - 1; i++)
////	{
////		int x, y; cin >> x >> y;
////
////		// for representing it as a list
////		graphList[--x].push_back(--y);
////		graphList[y].push_back(x);
////	}
////
////	auto p = bfs(0, graphList, vis);
////	vis = vector<bool>(noOfNodes);
////	cout << LongestPathFounder(graphList, noOfNodes, vis);
////	// cout << bfs(p.first, graphList, vis).second;
////	return;
////}
////
////int main() {
////	fast;
////	solve();
////	return 0;
////}
//
