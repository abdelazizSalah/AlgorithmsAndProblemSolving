//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define input freopen("in.txt" , "r" , stdin);
//#define output freopen("out.txt" , "w",stdout);
//
//struct node {
//	bool val;
//	int i;
//	int j;
//};
//
//vector<vector<vector<node>>> graph;
//vector<vector<bool>> vis;
//
//void dfs(int i, int j) {
//	for (auto& node : graph[i][j])
//		if (!vis[node.i][node.j])
//		{
//			vis[node.i][node.j] = true;
//			dfs(node.i, node.j);
//		}
//}
//
//node CreateNode(int x, int y)
//{
//	node n;
//	n.i = x;
//	n.j = y;
//	return n;
//}
//
//void solve() {
//	//reading data
//	//input; 
//	int loopCounter = 1;
//	int n;
//	while (cin >> n)
//	{
//		vector<vector<char>>graphTaker(n, vector<char>(n));
//		graph = vector<vector<vector<node>>>(n, vector<vector<node>>(n));
//		vis = vector<vector<bool>>(n, vector<bool>(n));
//
//		//reading the first graph
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				cin >> graphTaker[i][j];
//
//		//setting the edges 
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//			{
//				//not eagle 
//				if (graphTaker[i][j] == '0')
//					continue;
//
//				//left 
//				if (j > 0 && graphTaker[i][j - 1] == '1')
//					graph[i][j].push_back(CreateNode(i, j - 1));
//
//				//right
//				if (j + 1 < n && graphTaker[i][j + 1] == '1')
//					graph[i][j].push_back(CreateNode(i, j + 1));
//
//
//				//up
//				if (i > 0 && graphTaker[i - 1][j] == '1')
//					graph[i][j].push_back(CreateNode(i - 1, j));
//
//				//down
//				if (i + 1 < n && graphTaker[i + 1][j] == '1')
//					graph[i][j].push_back(CreateNode(i + 1, j));
//
//
//				//up left 
//				if (j > 0 && i > 0 && graphTaker[i - 1][j - 1] == '1')
//					graph[i][j].push_back(CreateNode(i - 1, j - 1));
//
//
//				//up right
//				if (j + 1 < n && i > 0 && graphTaker[i - 1][j + 1] == '1')
//					graph[i][j].push_back(CreateNode(i - 1, j + 1));
//
//
//				//down left
//				if (j > 0 && i + 1 < n && graphTaker[i + 1][j - 1] == '1')
//					graph[i][j].push_back(CreateNode(i + 1, j - 1));
//
//				// down right
//				if (j + 1 < n && i + 1 < n && graphTaker[i + 1][j + 1] == '1')
//					graph[i][j].push_back(CreateNode(i + 1, j + 1));
//			}
//
//		//applying dfs and counting the result 
//		int cntr = 0;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				if (!vis[i][j] && graphTaker[i][j] == '1')
//				{
//					vis[i][j] = true;
//					dfs(i, j);
//					cntr++;
//				}
//
//		cout << "Image number " << loopCounter++ << " contains " << cntr << " war eagles.";
//	}
//}
//
////de bdl ma t3ml check b2edak 3la kol condition
//bool valid(int i, int j, int n)
//{
//	return i >= 0 && j >= 0 && i < n&& j < n;
//}
//
//
////dol bn3mlhom 34an ne3ml all valid passes bdl brdu ma no3od neb3thom wahda wahda
////                  l    r   u   d  lu   ld  ru  rd
//vector<int> validX{ -1 , 1 , 0 , 0 , -1, -1, 1 ,1 };
//vector<int> validy{ 0 ,  0 , -1 , 1, -1,  1, -1, 1 };
//
//
//void dfsbetter(int i, int j, const vector<vector<char>>& g, vector<vector<bool>>& vis)
//{
//	input; 
//	//mark as visited 
//	vis[i][j] = true;
//
//	for (int xax = 0; xax < 8; xax++) // 8 de bt3br 3n 3addad el valid directions
//	{
//		//get them from the array
//		int x = validX[xax] + i;
//		int y = validy[xax] + j;
//
//		if (valid(x, y, g.size()) && !vis[x][y] && g[x][y] == '1')
//			dfsbetter(x, y, g, vis);
//	}
//
//}
//
//
//void betterSolution()
//{
//	int n;
//	int lvl = 0;
//	while (cin >> n)
//	{
//		int cntr = 0; 
//		vector<vector<char>> graph(n, vector<char>(n));
//		vector<vector<bool>> seen(n, vector<bool>(n));
//
//		//reading the graph
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				cin >> graph[i][j];
//
//		//applying dfs
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				if (!seen[i][j] && graph[i][j] == '1')
//				{
//					dfsbetter(i, j, graph, seen);
//					cntr++;
//				}
//
//		cout << "Image number " << ++lvl << " contains " << cntr << " war eagles.";
//	}
//}
//int main()
//{
//	fast;
//	betterSolution();
//	return 0;
//}