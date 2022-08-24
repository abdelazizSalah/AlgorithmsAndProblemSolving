//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
//
//void DFS(const vector<vector<vector<pair<char, pair<int, int>>>>>& graph, vector<vector<bool>>& vis, int i, int j, char c)
//{
//	for (auto node : graph[i][j])
//		if (!vis[node.second.first][node.second.second] && node.first == c)
//		{
//			vis[node.second.first][node.second.second] = true;
//			DFS(graph, vis, node.second.first, node.second.second, c);
//		}
//}
//
////// used to compare the pair according to certain order -> ;) 
////struct myComp {
////	constexpr bool operator()(
////		pair<int, char> const& p1,
////		pair<int, char> const& p2)
////		const noexcept
////	{
////		if (p1.first > p2.first)
////			return false;
////		else if (p2.first > p1.first)
////			return true;
////		else if (p1.second > p2.second)
////			return true;
////		else return false;
////	}
////};
//
//void solve()
//{
//	int cntrtests = 1;
//	int tsts; cin >> tsts;
//	while (cntrtests <= tsts)
//	{
//		//reading the graph
//		int W, H; cin >> H >> W;
//		vector<vector<char>> graph(H, vector<char>(W));
//		vector<vector<vector<pair<char, pair<int, int>>>>> graphList(H, vector<vector<pair<char, pair<int, int>>>>(W)); // O (L * W * 4) 
//		map<char, int> countries; // O (distinct countries) 
//		vector<vector<bool>> vis(H, vector<bool>(W));  // representing the visited using the i and j in the mat -> O(L * W) 
//		for (int i = 0; i < H; i++)
//			for (int j = 0; j < W; j++) // O(H * W) 
//			{
//				cin >> graph[i][j];
//				countries[graph[i][j]] = 0;
//			}
//
//		//setting up the edges
//		for (int i = 0; i < H; i++)
//			for (int j = 0; j < W; j++) // O(H * W) 
//			{
//				//right
//				if (j + 1 <= W - 1)
//					graphList[i][j].push_back({ graph[i][j + 1] , {i , j + 1} });
//
//				//left
//				if (j - 1 >= 0)
//					graphList[i][j].push_back({ graph[i][j - 1] , {i , j - 1} });
//
//				//down
//				if (i + 1 <= H - 1)
//					graphList[i][j].push_back({ graph[i + 1][j], {i + 1 , j} });
//
//				//up
//				if (i - 1 >= 0)
//					graphList[i][j].push_back({ graph[i - 1][j] , {i - 1 , j} });
//			}
//
//		// apply dfs 
//		for (int i = 0; i < H; i++)
//			for (int j = 0; j < W; j++) // O(H * W) 
//				if (!vis[i][j])
//				{
//					countries[graph[i][j]] ++;
//					vis[i][j] = true;
//					DFS(graphList, vis, i, j, graph[i][j]);
//				}
//
//
//		vector<pair<int, char>> v; 
//		for (auto it : countries)
//			v.push_back({ -it.second, it.first }); // insert -ve of the number and sort them all ascendingly
//
//		sort(v.begin(), v.end()); 
//
//		cout << "World #" << cntrtests++ << '\n';
//		for (auto it : v)
//			cout << it.second << ": " << -it.first<< '\n'; 
//		//sorting them acording to the number of countries 
//		//priority_queue<pair<int, char>,vector<pair<int, char>> , myComp> cntrs2;
//		//priority_queue<pair<int, char>, vector<pair<int , char>> , greater<>> cntrs;
//
//
//		//for (auto it : countries)
//		//	cntrs.push(make_pair(-it.second ,it.first));
//
//		////printing them 
//		//cout << "World #" << cntrtests << '\n';
//		//while (cntrs.size())
//		//{
//		//	cout << cntrs.top().second << ": " << -cntrs.top().first << '\n';
//		//	cntrs.pop();
//		//}
//	}
//}
//
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}