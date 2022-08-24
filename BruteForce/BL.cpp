#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0),cin.tie(0) , cout.tie(0) ; 

void minCost(vector<vector<vector<pair<int, bool>>>>& v, int i, int j, int k, int n, int sum, int& mn )
{
	//alphabeta pruning solution :) -> de m3naha eny a7sn el performance bs bt5ly el complexity zy ma hya 
	if (sum + v[i][j][k].first < mn) // lw el rkm el ana hkhdo da hy5leny akbr ml minimum yb2a mlosh lazma akhdu 
		sum += v[i][j][k].first;
	else
		return;

	// base case
	if (i == j && j == k && i == n - 1)
	{
		mn = min(sum, mn);
		return;
	}

	//mark as visited -> el fekra de bnst5dmha lama nkon msh 3auzen n3dy 3la nfs el haga aktur mn mra :)))
	v[i][j][k].second = true;

	//up
	if (i != n - 1 && !v[i + 1][j][k].second)
		minCost(v, i + 1, j , k, n, sum, mn);
	//right
	if (j != n - 1 && !v[i][j + 1][k].second)
		minCost(v, i, j + 1, k, n, sum, mn);
	//down
	if (k != n - 1 && !v[i][j][k + 1].second)
		minCost(v, i , j, k + 1, n, sum, mn);

	//undo step of visit
	v[i][j][k].second = false; // da keda esmo backtracking 34an b3ml undo operation 

}

void solve()
{
	int n; cin >> n;
	vector<vector<vector<pair <int, bool>>>> v(n, vector<vector<pair<int, bool>>>(n , vector<pair<int , bool>>(n)));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> v[i][j][k].first; 
			}
		}
	}

	int mn = INT_MAX; // dayman lw 3auz min 7ot int max lw 3auz max 7ot int min

	minCost(v, 0, 0, 0, n, 0, mn);
	cout <<  mn;
}

int main()
{
	fast;
	solve();
	return 0;
}