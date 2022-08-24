//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base ::sync_with_stdio(0), cin.tie(0),cout.tie(0) 
//using ll = long long;
//
//void solve()
//{
//	//reading data 
//	int n; cin >> n;  
//	vector <int> v(n);  
//	for (int& it : v)
//		cin >> it; 
//
//	int cntr = 0; 
//	int mn = INT_MAX; 
//	for (int i = 0; i < n - 1; i++)
//	{
//		cntr += v[i] - v[i+1] ;  
//		mn = min(mn, cntr); 
//	}
//
//	if (mn <= 0)
//		cout << v[0] - mn;
//	else
//		cout << v[0]; 
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}