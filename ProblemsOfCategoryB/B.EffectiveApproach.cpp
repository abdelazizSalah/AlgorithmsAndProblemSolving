//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ; 
//using ll = long long; 
//void solve()
//{
//	//reading the data
//	int n; cin >> n;
//	vector<int> numbers(n); 
//	vector<int> indcies(n + 1);
//	int idx = 1; 
//	for (int& it : numbers)
//	{
//		cin >> it;
//		indcies[it] = idx++; 
//	}
//
//	int m; cin >> m; 
//	vector<int> quereies(m);  
//	for (int& it : quereies) cin >> it; 
//
//	ll Vasya = 0, Petya = 0;
//	for (int i : quereies)
//	{
//		Vasya += indcies[i];
//		Petya += (n+1) - indcies[i]; 
//	}
//	
//	cout << Vasya << ' ' << Petya; 
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}