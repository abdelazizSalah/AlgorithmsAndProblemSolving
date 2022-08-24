//#pragma once
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0) 
//using ll = long long;
//void solve()
//{
//	int noOfLines, doubleNo; cin >> noOfLines >> doubleNo;
//	vector<pair<ll, ll>>posVec;
//	ll maxProd = 0;
//	for (int i = 0; i < noOfLines; i++)
//	{
//		int n, c;
//		cin >> n >> c;
//		if (c > n)
//			posVec.push_back({ n , c });
//		else
//			maxProd += c;
//	}
//
//	int size = posVec.size();
//	priority_queue<pair<ll, ll>>possVals;
//	for (int i = 0; i < size; i++)
//	{
//		if (posVec[i].second >= posVec[i].first * 2)
//			possVals.push({ posVec[i].first * 2, posVec[i].first });
//		else
//			possVals.push({ posVec[i].second, posVec[i].first });
//
//	}
//	while (doubleNo-- && possVals.size())
//	{
//		maxProd += possVals.top().first;
//		possVals.pop();
//	}
//
//	while (possVals.size())
//	{
//		maxProd += possVals.top().second;
//		possVals.pop();
//	}
//	cout << maxProd;
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}