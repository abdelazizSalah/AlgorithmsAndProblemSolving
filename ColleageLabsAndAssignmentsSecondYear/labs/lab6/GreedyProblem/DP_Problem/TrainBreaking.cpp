#include <bits/stdc++.h>
using namespace std;
#define fast ios_base :: sync_with_stdio(0), cin.tie(0) , cout.tie(0)
using ll = long long;

//ll TrainCuts(vector<pair<int, bool>>& train,int mypos,int cuts , const int m , int trgt )
//{
//	//base case 
//	if (cuts == m + 1)
//		return 0;
//	train[mypos].second = true; // mark as cut
//	ll leftSum = 0;
//	ll RightSum = 0;
//	//left loop
//	int leftidx = 0;
//	int rightidx = train.size() - 1;
//	if(mypos!=0)
//	for (int i = mypos - 1; i >= 0; i--)
//	{
//		//search till find the first cut 
//		if (train[i].second)
//		{
//			leftidx = i;
//			break;
//		}
//	}
//
//	if (mypos < train.size())
//	{
//		for (int i = mypos + 1; i < train.size(); i++)
//		{
//			if (train[i].second)
//			{
//				rightidx = i; 
//				break; 
//			}
//		}
//	}
//
//	trgt = train[rightidx].first - train[leftidx].first;
//	ll minleft = LLONG_MAX; 
//	//left Search
//	for (int i = mypos - 1; i > 0; i--)
//	{
//		if (!train[i].second)  // not visited before
//		{
//			leftSum=TrainCuts(train, i, cuts + 1, m , trgt );
//			minleft = min(minleft, leftSum);  // minimum for all left loop
//		}
//	}
//
//	//right loop
//	ll minRight = LLONG_MAX; // minimum for all right loop
//    for (int i = mypos + 1; i < train.size(); i++)
//	{
//		if (!train[i].second)  // not visited before
//		{
//			RightSum = TrainCuts(train, i, cuts + 1, m , trgt);
//			minRight = min(minRight, RightSum);
//		}
//	}
//
//	//mark as uncut
//	train[mypos].second = false;
//	return minRight +minleft + trgt; 
//}
//void solve()
//{
//	int n , m ; cin >> n >> m ;
//	vector<pair<int,bool>> locs(m + 2); 
//	locs[0] = { 0 , true };
//	locs[m + 1] = { n , true };
//	for (int i = 1; i < m+ 1; i++)
//	{
//		cin >> locs[i].first;
//	}
//	cout << TrainCuts(locs, 0, 0, m, n);
//
//}


int BreakTrain(vector<int>& L, int i, int j, vector<vector<int>> & memo) {

	// TODO: check if you solved the problem before (memoization) (add this part after you implement the whole function)
	if (memo[i][j] != -1)
		return memo[i][j];

	// TODO: step 2: add base case
	if (i + 1 == j)
		return 0;

	// TODO: step 1: write the optimal structure for the solution using subproblems to get the minimum total cost
	int left = 0;
	int right = 0;
	int mn = INT_MAX;
	for (int k = i+1; k <j; k++)
	{
		left = BreakTrain(L, i, k, memo);
		right = BreakTrain(L, k, j, memo);
		mn = min(left + right, mn);
	}
	// TODO: save the minimum total cost in memo (add this part after you implement the whole function)
	memo[i][j] = mn + L[j] - L[i];

	// TODO: return the minimum total cost
	return memo[i][j];
}


void solve()
{
	int N, M;
	cin >> N >> M;

	vector<int> L(M);
	vector<vector<int>> memo(M + 2 , vector<int>(M+2 , -1));
	for (int i = 0; i < M; i++)
	{
		cin >> L[i];
	}

	L.insert(L.begin(), 0);
	L.push_back(N);

	cout << BreakTrain(L, 0, L.size() - 1 , memo) << '\n';
}
int main()
{
	fast;
	solve();
	return 0;
}