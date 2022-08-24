//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0) ,cout.tie(0) ;
//
//void DFS(int n, const vector<vector<int>>& graph, vector<bool>& vis)
//{
//	for (auto u : graph[n])
//	{
//		if (!vis[u])
//		{
//			vis[u] = true; 
//			DFS(u, graph, vis); 
//		}
//	}
//}
//void solve()
//{
//	int n, m; cin >> n >> m; 
//	if (m != n - 1) // check on that number of edges == number of nodes -1 
//	{
//		cout << "NO";
//		return;
//	}
//
//	vector<vector<int>> graph(n +1); 
//	vector<bool> vis(n + 1); 
//	for (int i = 0; i < m; i++)
//	{
//		int u, v; cin >> u >> v;
//		graph[u].push_back(v); 
//		graph[v].push_back(u); 
//	}
//
//	int cntr = 0; 
//	for (int i = 1; i <= n; i++)
//	{
//		if (cntr > 1) // check it is a single component
//		{
//			cout << "NO"; 
//			return; 
//		}
//
//		if (!vis[i])
//		{
//			DFS(i , graph ,vis); 
//			cntr++; 
//		}
//	}
//
//	cout << "YES"; 
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
////void DFSForListRep(vector<vector<int>>& graph, int vertex, vector <bool>& vis)
////{
////	for (int i = 0; i < graph[vertex].size(); i++)
////		if (!vis[graph[vertex][i]])
////		{
////			vis[graph[vertex][i]] = true;
////			//cout << graph[vertex][i] + 1 << ' ';
////			DFSForListRep(graph, graph[vertex][i], vis);
////		}
////}
////
////int NumberOfConnectedComponentsusingList(vector<vector<int>>& graph, int N, vector<bool>& vis)
////{
////	int cntr = 0;
////	for (int i = 0; i < N; i++)
////		if (!vis[i])
////		{
////			if (cntr == 0) // if there is more than one component then it is not a tree 
////				cntr++;
////			else
////				return -1;
////			DFSForListRep(graph, i, vis);
////		}
////	return cntr;
////}
////
////void solve()
////{
////	int noOfNodes, noOfEdges; cin >> noOfNodes >> noOfEdges; 
////	vector<vector<int>> graphList(noOfNodes);
////	vector<bool> vis(noOfNodes);
////
////	if (noOfEdges != noOfNodes - 1)
////	{
////		cout << "NO";
////		return;
////	}
////
////	for (int i = 0; i < noOfEdges; i++)
////	{
////		int x, y; cin >> x >> y;
////
////		// for representing it as a list
////		graphList[--x].push_back(--y);
////		graphList[y].push_back(x);
////	}
////
////	if (NumberOfConnectedComponentsusingList(graphList, noOfNodes, vis) == -1)
////		cout << "NO";
////	else
////		cout << "YES"; 
////
////}
////
////int main()
////{
////	fast; 
////	solve(); 
////	return 0; 
////}