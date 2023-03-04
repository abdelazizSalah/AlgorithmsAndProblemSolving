#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
// ll noOfStepsTopDown(int& n, int noOfStepss, int lvlIndcator, map<pair<int, int>, ll>& memo)
//{
//	//memoization
//	auto it = memo.find({ lvlIndcator,noOfStepss });
//	if (it != memo.end())
//		return memo[{lvlIndcator, noOfStepss}];
//	//base case
//	else if (noOfStepss == n)
//	{
//		memo[{lvlIndcator, noOfStepss}] = 1;
//		return memo[{lvlIndcator, noOfStepss}];
//	}
//	else if (noOfStepss > n) // lw odamy slmten akhry anot slmten msh hnot 3 slalm wna odamy anot 2 bs fahm
//	{
//		memo[{lvlIndcator, noOfStepss}] = 0;
//		return memo[{lvlIndcator, noOfStepss}];
//	}
//
//	ll cntr = 0;
//	cntr += noOfStepsTopDown(n, noOfStepss + 1, lvlIndcator + 1, memo); // 1 step
//	cntr += noOfStepsTopDown(n, noOfStepss + 2, lvlIndcator + 1, memo);
//	cntr += noOfStepsTopDown(n, noOfStepss + 3, lvlIndcator + 1, memo);
//
//	memo[{lvlIndcator, noOfStepss}] = cntr;
//	return memo[{lvlIndcator, noOfStepss}];
// }
//
// ll noOfStepsBottomUp(vector<ll>& Table)
//{
//	//initialization
//	int len = Table.size();
//	Table[len - 1] = 1;
//	Table[len - 2] = 2;
//	Table[len - 3] = 4;
//
//	//BottomUp Approch
//	for (int i = len - 4; i >= 0; i--)
//		Table[i] += Table[i + 1] + Table[i + 2] + Table[i + 3];
//
//	return Table[0];
// }
//
//
// void p1()
//{
//	int n; cin >> n;
//	map<pair<int, int>, ll> memo;
//	vector<ll> Table(n);
//	cout << noOfStepsTopDown(n, 0, 0, memo) << '\n' << noOfStepsBottomUp(Table);
// }
//
// ll CatalanTopDown(int n, vector<ll>& memo)
//{
//	if (memo[n])return memo[n];
//	//base case
//	if (n == 0)
//	{
//		memo[n] = 1;
//		return memo[n];
//	}
//	ll cntr = 0;
//
//	for (int i = 0; i < n; i++)
//		cntr += CatalanTopDown(i, memo) * CatalanTopDown(n - i - 1, memo);
//
//	memo[n] = cntr;
//	return cntr;
// }
//
//
// ll CatalanBottomUp(vector<ll>& Table)
//{
//	Table[0] = 1; // initial Value
//	int len = Table.size();
//	for (int i = 1; i < len; i++)
//		for (int j = 0; j < i; j++)
//			Table[i] += Table[j] * Table[i - j - 1];
//
//	return Table[len - 1];
// }
// void p2()
//{
//	int n; cin >> n;
//	vector<ll>memo(n + 1);
//	cout << CatalanTopDown(n, memo) << '\n' << CatalanBottomUp(memo);
// }
//
// ll LISTopDown(vector<ll>& LIS, vector<ll>& memo, int h)
//{ // de keda btbuild el vector LIS
//	// memoization
//	if (memo[h]) return memo[h];
//
//	int curr = 1;
//	for (int i = 0; i < h; i++)
//	{
//		ll cntr = LISTopDown(LIS, memo, i);
//		if (LIS[i] < LIS[h] && cntr >= curr)
//			curr = cntr + 1;
//	}
//	memo[h] = curr;
//	return  memo[h] ;
//  //}
//  //
//  int LIS(vector<ll>& LIS, int n)
//  {
//  	vector<ll> dp(n, 0);
//  	LISTopDown(LIS, dp, n - 1);
//  	ll lis = LLONG_MIN;
//  	for (auto x : dp)
//  		lis = max(lis, x);
//  	cout<< lis; // to print the length of the LIS
//  	return 0;
//  }
//
// bool sortSecond(pair<int, int> &p1, pair<int, int> &p2)
// {
//     if (p1.second > p2.second)
//         return true;
//     else
//         return false;
// }
// vector<int> LISBottomUp(vector<pair<int, int>> &Table)
// {
//     int len = Table.size();
//     for (int i = 0; i < len; i++)
//         for (int j = 0; j < i; j++)
//             if (Table[i].first > Table[j].first && Table[j].second + 1 > Table[i].second && i != j)
//                 Table[i].second++;
//     sort(Table.begin(), Table.end(), sortSecond); // sort according to which has greater value in  the table
//     vector<int> result;
//     auto cntr = Table[0];
//     result.push_back(cntr.first);
//     for (int i = 1; i < Table.size(); i++)
//     {
//         if (Table[i].second == cntr.second || Table[i].first >= cntr.first)
//             continue;
//         result.push_back(Table[i].first);
//         cntr = Table[i];
//     }
//     return result;
// }
// void p3()
//{
//	/*int n; cin >> n;
//	vector<pair<int, int>> LISTable(n, {0,1});
//	vector<ll> memo(n);
//	for (auto& lon : LISTable) cin >> lon.first;
//	auto vec = LISBottomUp(LISTable);
//	cout << "Length of the LIS is : " << vec.size();
//	cout << "\nthe sequence is: ";
//	for (auto it = vec.rbegin(); it != vec.rend(); it++)
//		cout << *it << ' ';*/
//
//	// TopDown Solution
//	int n;  cin >> n;
//	vector<ll> LIs(n);
//	for (ll& l : LIs) cin >> l;
//	LIS(LIs, LIs.size()); // this is how we get the number of max element
// }
//
// void p4()
//{
//	// kol el fekra enk lw 3ndk increasing subsequence fa lw edrt t7ot el elements el fadlen fl amakn el monsba yeb2a enta edrt t sort el vector
//	int n; cin >> n;
//	vector<pair<int, int>> v(n, {0,1});
//	for (auto& i : v) cin >> i.first;
//	auto vec = LISBottomUp(v);
//	cout << n - vec.size();
// }
//
//
// int main()
//{
//	fast;
//	cout << ((7-9)*10 + 2) % 13;
//	return 0;
// }