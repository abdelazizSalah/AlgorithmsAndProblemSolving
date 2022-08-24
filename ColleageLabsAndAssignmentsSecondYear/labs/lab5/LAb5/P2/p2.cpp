#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0) ,cin.tie(0),  cout.tie(0)
using ll = long long;
//
//ll gridMax(vector<vector<int>>& grid, int x, int y, map<pair<int, int>, bool>indcies, int i, int j)
//{
//	//y -> max right 
//	//x->max down
//	auto it = indcies.find({ i , j });
//	if (it != indcies.end()) return 0;  // if visited return 
//
//	//bn3tbr el 3 visited khlas
//	indcies[{i, j}] = true; // mark me
//
//	if (!indcies[{i + 1, j}]) // mark down
//		indcies[{i + 1, j}] = true;
//
//	if (!indcies[{i - 1, j}]) // mark up
//		indcies[{i - 1, j}] = true;
//
//	if (!indcies[{i, j + 1}]) // mark right
//		indcies[{i, j + 1}] = true;
//
//	if (!indcies[{i, j - 1}]) // mark left
//		indcies[{i, j - 1}] = true;
//
//
//
//	ll rp1, rd, ld, lp1, ur, ul;
//	rp1 = rd = ld = lp1 = ur = ul = 0;
//
//	//consider we cant make except 1 jump
//	if (j + 2 < y) // go right + 2
//		rp1 += gridMax(grid, x, y, indcies, i, j + 2);
//
//	if (j - 2 >= 0) // go left + 2
//		lp1 += gridMax(grid, x, y, indcies, i, j - 2);
//
//	if (j + 1 < y && i + 1 < x) // go right down
//		rd += gridMax(grid, x, y, indcies, i + 1, j + 1);
//
//	if (j - 1 >= 0 && i + 1 < x) // go left down 
//		ld += gridMax(grid, x, y, indcies, i + 1, j - 1);
//
//	if (j - 1 >= 0 && i - 1 >= 0) // go left up
//		ul += gridMax(grid, x, y, indcies, i - 1, j - 1);
//
//	if (j + 1 < y && i - 1 >= 0) // go right up 
//		ur += gridMax(grid, x, y, indcies, i - 1, j + 1);
//
//	indcies[{i, j}] = false;
//	indcies[{i + 1, j}] = false;
//	indcies[{i - 1, j}] = false;
//	indcies[{i, j + 1}] = false;
//	indcies[{i, j - 1}] = false;
//	vector<ll>vals{ rp1, rd, ld, lp1, ur, ul };
//	return *max_element(vals.begin(), vals.end()) + grid[i][j];
//}


ll gridMax()
{
	// TABULATION
}
void solve()
{
	//read data
	int n; cin >> n;
	vector<vector<int>>grid(2, vector<int>(n));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];
	map<pair<int, int>, bool>indcies;
	cout << gridMax(grid, 2, n, indcies, 0, 0);
}

int main()
{
	fast;
	solve();
	return 0;
}