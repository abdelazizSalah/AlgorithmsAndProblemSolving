//#include<bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
////   f    l   r
//vector<int> Xdir{ 0 , -1,  1 };
//vector<int> Ydir{ -1,  0,  0 };
//vector<vector<char>> graph;
//vector<vector<bool>> vis;
//queue <string> path;
//const string KeyWord = "IEHOVA#";
//int r, c;
//bool finish = false;
//
//bool valid(int i, int j) {
//	return i >= 0 && j >= 0 && i < r&& j < c;
//}
//
//void setThePath(int d) {
//	switch (d) {
//	case 0:
//		path.push("forth");
//		break;
//	case 1:
//		path.push("left");
//		break;
//	case 2:
//		path.push("right");
//		break;
//	default:
//		break;
//	}
//
//}
//void dfs(int i, int j, int idx)
//{
//	//{
//	//	if (vis[i][j])
//	//		return;
//	//
//	//	//mark as visited
//	//	vis[i][j] = true;
//	if (idx > KeyWord.length())
//		return;
//
//	for (int d = 2; d >= 0; d--) {
//		int x = Ydir[d] + i;
//		int y = Xdir[d] + j;
//
//		if (valid(x, y)) {
//			if (finish)
//				return;
//
//			if (graph[x][y] == KeyWord[idx] && graph[x][y] == '#') {
//				setThePath(d);
//				while (path.size()) {
//					cout << path.front() << " ";
//					path.pop();
//				}
//				finish = true;
//				return;
//			}
//
//			else if (graph[x][y] == KeyWord[idx]) {
//				setThePath(d);
//				dfs(x, y, idx + 1);
//				if (path.size())
//					path.pop();
//			}
//
//		}
//	}
//}
//
//int tsts;
//void solve()
//{
//	finish = false;
//	cin >> r >> c;
//	pair<int, int> startidx;
//	graph = vector<vector<char>>(r, vector<char>(c));
//	vis = vector<vector<bool>>(r, vector<bool>(c));
//
//	for (int i = 0; i < r; i++)
//		for (int j = 0; j < c; j++) {
//			cin >> graph[i][j];
//			if (graph[i][j] == '@')
//			{
//				startidx.second = j;
//				startidx.first = i;
//			}
//		}
//	path = queue<string>();
//	dfs(startidx.first, startidx.second, 0);
//	if (tsts)
//		cout << "\n";
//}
//
//int main()
//{
//	fast;
//	cin >> tsts;
//	while (tsts--)
//		solve();
//	return 0;
//}