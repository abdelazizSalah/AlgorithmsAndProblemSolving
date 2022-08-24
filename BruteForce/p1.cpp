#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0) ;

void strGen(string s, int& cntr, vector<string> needed, int n, int k)
{
	if (s.length() == n)
	{
		int cntr2 = k;  // AC AB ACAB
		for (int i = 0; i < needed.size(); i++)
		{
			if (s.find(needed[i]) != string::npos)
			{
				cntr2--;
			}
			if (!cntr2)
			{ // if found the number of strings
				cntr++;
				return;
			}
		}
		return; // k not = 0 
	}
	for (char a = 'A'; a < 'F'; a++)
	{
		strGen(s + a, cntr, needed, n, k);
	}
}
int findMax(const vector<int>& v, int i, int max)
{
	//base case ''
	if (i == v.size())
		return max;

	if (v[i] > max)
		return findMax(v, i + 1, v[i]);
	else
		return findMax(v, i + 1, max);
}

int maxSum(vector<pair<int, bool>>& v, int idx, int mx)
{
	if (idx == v.size())
		return mx;
	v[idx].second = true; // de est5dmtha 34an mkrrsh 3mlyat ana 3mltha abl keda fa b3ml optimization lel 7l bta3y 
	int sum = v[idx].first;
	for (int i = 0; i < v.size(); i++)
	{
		if (!v[i].second && v[i] != v[idx])
		{
			sum += v[i].first;
		}
		mx = max(sum, mx); //kol ma bgm3 rkm b3mlo maximization m3 el b3do 
		if (sum != v[idx].first)
			sum -= v[i].first; // bgm3 rkmen bs m3 b3d fa b5ly kol ma agm3 rkm ams7o tany w agm3 el b3do
	}
	return maxSum(v, idx + 1, mx);
}

void BinaryString(const vector<string>& v, const int& n, const int& m, string s = "")
{
	// base case
	if (s.length() == n)
	{
		for (int i = 0; i < v.size(); i++)
			if (s.find(v[i]) == string::npos) // npos da m3naha enha ml2tsh haga
				return;

		cout << s << '\n';
		return;
	}
	for (char c = '0'; c < '2'; c++)
	{
		BinaryString(v, n, m, s + c);
	}
}

void minCost(vector<vector<pair<int, bool>>>& v, int i, int j, int n, int sum, int& mn, int& mx)
{
	//alphabeta pruning solution :) -> de m3naha eny a7sn el performance bs bt5ly el complexity zy ma hya 
	//if (sum + v[i][j].first < mn) // lw el rkm el ana hkhdo da hy5leny akbr ml minimum yb2a mlosh lazma akhdu 
	//	sum += v[i][j].first;
	//else
	//	return;
	sum += v[i][j].first;

	// base case
	if (i == j && i == n - 1)
	{
		mn = min(sum, mn);
		mx = max(sum, mx);
		return;
	}

	//mark as visited -> el fekra de bnst5dmha lama nkon msh 3auzen n3dy 3la nfs el haga aktur mn mra :)))
	v[i][j].second = true;

	//down
	if (i != n - 1 && !v[i + 1][j].second)
		minCost(v, i + 1, j, n, sum, mn, mx);
	//right
	if (j != n - 1 && !v[i][j + 1].second)
		minCost(v, i, j + 1, n, sum, mn, mx);

	//up
	if (i != 0 && !v[i - 1][j].second)
		minCost(v, i - 1, j, n, sum, mn, mx);

	//left
	if (j != 0 && !v[i][j - 1].second)
		minCost(v, i, j - 1, n, sum, mn, mx);

	//undo step of visit
	v[i][j].second = false; // da keda esmo backtracking 34an b3ml undo operation 
}
int main()
{
	//Hacker rank problem 5
	/* int n , m, k; cin >> m >> n >> k;
	vector<string>s(m);
	for (auto& it : s)
		cin >> it;
	int cntr = 0;
	strGen("", cntr, s, n, k);
	cout << cntr; */

	//sheet p1
	//vector<int> v{ 200 , 250 , 3000 ,-1 , 230};
	//cout << findMax(v, 0, INT_MIN);

	//sheet p2 
	/*int n; cin >> n;
	vector<pair<int, bool>> v(n);
	for (auto& it : v)
		cin >> it.first;
	cout << maxSum(v, 0 , INT_MIN);*/

	//sheet p3 
	/*int m, n; cin >> m >> n;
	vector<string> v(m);
	for (auto& it : v)
		cin >> it;
	BinaryString(v, n, m);*/

	////sheet p4
	//int n; cin >> n;
	//vector<pair<int,bool>> v(n);
	//for (auto& it : v)
	//	cin >> it.first;
	//int sum = INT_MIN;
	//cout << MaxFrmNum(v, n, sum);

	//sheet p5 & p6
	int n; cin >> n;
	vector<vector<pair <int, bool>>> v(n, vector<pair<int, bool>>(n));

	for (auto& it : v)
		for (int i = 0; i < n; i++)
			cin >> it[i].first;

	int mn = INT_MAX; // dayman lw 3auz min 7ot int max lw 3auz max 7ot int min
	int mx = INT_MIN; // de gd3na meny keda 34an ageb el mx path :) 

	minCost(v, 0, 0, n, 0, mn, mx);
	cout << "min path is: " << mn << "\nmax path is: " << mx;
	return 0;
}