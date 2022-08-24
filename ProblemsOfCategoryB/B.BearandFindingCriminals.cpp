//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base ::sync_with_stdio(0), cin.tie(0),cout.tie(0) 
//using ll = long long;
//
//void solve()
//{
//	//reading input
//	int n, a; cin >> n >> a; 
//	vector <int> cities(n); 
//	for (int& it : cities)
//		cin >> it; 
//	int cntr = 0; 
//	// if he is in the first city
//	if (a == 1)
//	{
//		for (int i = 0; i < n; i++)
//			if (cities[i] == 1)
//				cntr++;
//		cout << cntr;
//		return;
//	}
//	// if he is in the last city
//	else if (a == n)
//	{
//		for (int i = n-1; i >=0; i--)
//			if (cities[i] == 1)
//				cntr++;
//		cout << cntr;
//		return;
//	}
//
//	// decrement the a to work 0 based 
//	a--; 
//
//	//intiate the counter with the value of the city he stays in 
//	cntr = cities[a]; 
//
//	// using 2 pointers do the logic
//	for (int i = a-1 , j = a+1; i >=0  || j < n; i-- , j++)
//		if (i >= 0 && j >= n)
//		{
//			if (cities[i])
//				cntr++;
//		}
//		else if (i < 0 && j < n)
//		{
//			if (cities[j])
//				cntr++; 
//		}
//		else if (cities[i] == cities[j])
//		{
//			cntr += 2 * cities[i]; 
//		}
//
//	// print the output
//	cout << cntr; 
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}