////accepted ans
//#include<bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0),cin.tie(0),cout.tie(0); 
//using ll = long long;
//
//int k;
//vector<vector<int>> graph;
//bool CycleDetected = false;
//int nodeToPrint = -1;
//vector<ll> Time(1e6);
//vector<bool> vis(1e6);
//
//void dfs(int source, int time) {
//	//set the time of the node
//	Time[source] = time;
//	for (auto node : graph[source]) {
//		if (!vis[node]) {
//			vis[node] = true;
//			dfs(node, time + 1);
//			if (CycleDetected && k) {
//				cout << ++nodeToPrint << ' ';
//				nodeToPrint = source;
//				k--;
//				return;
//			}
//			else if (CycleDetected)
//				return;
//		}
//		else if (Time[source] >= Time[node] + k) {
//			k = Time[source] - Time[node];
//			cout << k + 1 << '\n';
//			cout << node + 1 << ' ';
//			nodeToPrint = source;
//			CycleDetected = true;
//			return;
//		}
//	}
//
//
//}
//void solve() {
//	int n, m; cin >> n >> m >> k;
//	graph = vector<vector<int>>(n);
//	for (int i = 0; i < m; i++)
//	{
//		int u, v; cin >> u >> v;
//		graph[--u].push_back(--v);
//		graph[v].push_back(u);
//	}
//	vis[0] = true; 
//	dfs(0, 1);
//}
//
//int main() {
//	fast;
//	solve();
//	return 0;
//}

//Time Limit Exceeded
//vector<vector<int>> graphList;
//vector<short>vis;
//map<queue<int>, bool> notValidCycles;
//int k;
//int cycleidx;
//bool CyclesHasBeenDetected = false;
// void FindCyclesDFS(int src, int parent, queue<int>&Ans) {
//		for (auto node : graphList[src]) {
//			if (node == parent)
//				continue; 
//			if (vis[node] != 1 ) {
//				vis[node] = 1;
//				FindCyclesDFS(node, src, Ans);
//				vis[node] = 2;
//				if (CyclesHasBeenDetected && cycleidx != src) {
//					Ans.push(src);
//					return;
//				}
//				else if (CyclesHasBeenDetected && cycleidx == src && !notValidCycles[Ans]) {
//					if (Ans.size() + 1 > k) {
//						cout << Ans.size() + 1 << '\n' << src << ' ';
//						while (Ans.size()) {
//							cout << Ans.front() << ' ';
//							Ans.pop();
//						}
//						CyclesHasBeenDetected = true;
//						return;
//					}
//					else {
//						while (Ans.size()) {
//							notValidCycles[Ans] = true;
//							CyclesHasBeenDetected = false;
//							int Qnode = Ans.front();
//							vis[Qnode] = 1;
//							queue<int> newQ; 
//							vis[src] = 2; 
//							FindCyclesDFS(Qnode, Qnode, newQ);
//							vis[Qnode] = 2;
//							Ans.pop();
//						}
//						return; 
//					}
//				}
//				CyclesHasBeenDetected = false;
//			}
//			else {
//				CyclesHasBeenDetected = true;
//				cycleidx = node;
//				Ans.push(src);
//				return;
//			}
//		}
//}
//
//void solve() {
//	int noOfNodes, noOfEdges; cin >> noOfNodes >> noOfEdges >> k;
//	vis = vector<short>(noOfNodes + 1);
//	graphList = vector<vector<int>>(noOfNodes + 1);
//
//	//reading the edges and building the graph 
//	for (int i = 0; i < noOfEdges; i++) {
//		int u, v; cin >> u >> v;
//		graphList[u].push_back(v);
//		graphList[v].push_back(u);
//	}
//
//	queue<int> Ans;
//	for (int i = 1; i < noOfNodes; i++) {
//		if (!vis[i] && !CyclesHasBeenDetected) {
//			vis[i] = 1;
//			FindCyclesDFS(i, i, Ans);
//		}
//	}
//}

//int main() {
//	fast;
//	solve();
//	return 0;
//}

//Wrong Ans
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0); 
//
//vector<vector<int>> graph;
//vector<bool> vis;
//int n, m, k;
//vector<int> ans;
//bool  dfs(int node, int parent, int cntr) {
//	for (auto it : graph[node]) {
//		if (it != parent)
//			if (!vis[it]) {
//				vis[it] = true;
//				if (dfs(it, node, cntr + 1)) {
//					ans.push_back(node);
//					return true;
//				}
//			}
//			else if (cntr > k) {
//				ans.push_back(node);
//				return true;
//			}
//	}
//	return false;
//}
//void detectCycles() {
//	for (int i = 0; i < n; i++)
//	{
//		if (!vis[i]) {
//			vis[i] = true;
//			if (dfs(i, i, 1))
//				break;
//		}
//	}
//	cout << ans.size() << '\n';
//	for (auto it : ans)
//		cout << it + 1 << ' ';
//}
//
//void solve() {
//	cin >> n >> m >> k;
//	graph = vector<vector<int>>(n);
//	vis = vector<bool>(n);
//	for (int i = 0; i < m; i++)
//	{
//		int u = 0, v = 0; cin >> u >> v;
//		graph[--u].push_back(--v);
//		graph[v].push_back(u);
//	}
//
//	detectCycles();
//}
//
//int main() {
//	fast;
//	solve();
//	return 0;
//}

