//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0); 
//using ll = long long ;
//
//map <pair<int , int>, ll> memo; 
//ll goldCollector(vector<vector<ll>>& grid, int n, int m, int x
//	, int y)
//{
//	//basecase 
//	auto it = memo.find({ x , y });
//	if (it != memo.end()) return memo[{x , y}]; // if computed before return it 
//	if (x == n - 1 && y == m - 1)
//	{
//		memo[{x, y}] = grid[x][y];
//		return memo[{x, y}];
//	}
//
//	ll r = LLONG_MIN, d = LLONG_MIN, rd = LLONG_MIN;
//	if (x < n - 1 && y < m - 1) // go right down 
//		rd = goldCollector(grid, n, m, x + 1, y + 1);
//	if (y < m - 1 ) // go right 
//		r = goldCollector(grid, n, m, x, y + 1);
//	if (x < n - 1) // go down 
//		d = goldCollector(grid, n, m, x + 1, y);
//	
//
//	vector<ll> mxelm{ r , rd ,d };
//	memo[{x, y}] = grid[x][y] + *max_element(mxelm.begin(), mxelm.end()); // memoization
//	return  memo[{x, y}];
//}
//
//void solve()
//{
//	int n, m; cin >> n >> m;
//	vector<vector<ll>>grid(n, vector<ll>(m));
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			cin >>  grid[i][j] ;
//	cout << goldCollector(grid, n, m, 0, 0);
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}