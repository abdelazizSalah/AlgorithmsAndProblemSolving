//#include<bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0),  cin.tie(0) , cout.tie(0); 
//
//void solve()
//{
//	int n; cin >> n; 
//	vector<vector<char>> grid(n , vector<char>(n));
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)//O(n^2)
//			cin >> grid[i][j];
//	for (int i = 0; i < n; i++)
//		sort(grid[i].begin(), grid[i].end()); // O(n^2lgn)
//
//	for (int i = 0; i < n; i++)//O(n^2)
//		for (int j = 0; j < n - 1; j++)
//			if (grid[j][i] > grid[j + 1][i])
//			{
//				cout << "NO\n";
//				return;
//			}
//
//	cout << "YES\n"; 
//}
//
//int main()
//{
//	fast;
//	int t; cin >> t;
//	while (t--)
//		solve();
//	return 0;
//}