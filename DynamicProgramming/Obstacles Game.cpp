#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
using ll = long long; 
ll Obstacles(vector<vector<int>>& grid, int x, int y, int i, int j , vector<vector<ll>>& memo)
{
	//problem difinition:
	// 	   you have a grid and you want to start from the top left cell 
	//     to reach the bottom right cell and there are some obstacles in the road,
	//     you are required to determine in how many ways you can 
	//	   reach this cell by using dynamic programming
	// out of boundries
	if (i > x || j > y) 
		return 0;
	//if obstacle return 
	if (grid[i][j] == -1)
		return 0;
	//memoization
	if (memo[i][j])
		return memo[i][j];
	//base case 
	if (i == x && y == j)
	{
		memo[i][j] = 1;
		return memo[i][j];
	}
	ll cntr = 0;
	//go right
	cntr += Obstacles(grid, x, y, i, j + 1 , memo);
	//go down
	cntr += Obstacles(grid, x, y, i + 1, j , memo);

	//memoization
	memo[i][j] = cntr;
	return memo[i][j];
}

void solve()
{
	//reading input
	int x, y; cin >> x >> y;
	vector<vector<int>> grid(x, vector<int>(y));
	for (auto& it : grid)
		for (auto& it2 : it)
			cin >> it2;
	vector<vector<ll>> memo(x, vector<ll>(y));
	cout << Obstacles(grid, x - 1, y - 1, 0, 0, memo);
	return;
}

int main()
{
	fast;
	solve();
	return 0;
}