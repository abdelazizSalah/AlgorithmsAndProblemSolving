//#pragma once
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0) 
//
//void solve()
//{
//	//reading data 
//	int n, m; cin >> n >> m;
//	char c; cin >> c;
//	map<char, bool> deputies;
//	vector<pair<int, int>> idx; // to store the idx of the president desk
//	//reading the matrix
//	vector<vector<char>> office(n, vector<char>(m));
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//		{
//			cin >> office[i][j];
//			if (office[i][j] == c)
//				idx.push_back({ i,j });
//		}
//
//	int size = idx.size();
//	for (int i = 0; i < size; i++)
//	{
//		//look up
//		if (idx[i].first - 1 >= 0)
//			if (office[idx[i].first - 1][idx[i].second] != '.' && office[idx[i].first - 1][idx[i].second] != c && !deputies[office[idx[i].first - 1][idx[i].second]])
//				deputies[office[idx[i].first - 1][idx[i].second]] = true;
//
//		//look down
//		if (idx[i].first + 1 < n )
//			if (office[idx[i].first + 1][idx[i].second] != '.' && office[idx[i].first + 1][idx[i].second] != c && !deputies[office[idx[i].first + 1][idx[i].second]])
//				deputies[office[idx[i].first + 1][idx[i].second]] = true;
//		
//
//		//look left
//		if (idx[i].second - 1 >= 0)
//			if (office[idx[i].first][idx[i].second - 1] != '.' && office[idx[i].first][idx[i].second - 1] != c && !deputies[office[idx[i].first][idx[i].second - 1]])
//				deputies[office[idx[i].first][idx[i].second - 1]] = true;
//
//
//		//look right
//		if (idx[i].second + 1 < m)
//			if (office[idx[i].first][idx[i].second + 1] != '.' && office[idx[i].first][idx[i].second + 1] != c && !deputies[office[idx[i].first][idx[i].second + 1]])
//				deputies[office[idx[i].first][idx[i].second + 1]] = true;
//		
//	}
//
//	cout << deputies.size();
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}