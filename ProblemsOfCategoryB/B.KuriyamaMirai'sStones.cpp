//#include <bits/stdc++.h>
//using namespace std; 
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0) 
//
//using ll = long long; 
////void prefixSum(vector<ll>& v, int size)
////{
////	for (int i = 1; i <=size ; i++)
////		v[i] += v[i - 1]; 
////}
//
//void solve()
//{
//	//reading data
//	int n; cin >> n; 
//	vector<ll> v(n + 1 , 0);
//	for (int i = 1; i <= n; i++)
//		cin >> v[i]; 
//	vector<ll>sortedVec = v;
//	
//	sort(sortedVec.begin(), sortedVec.end()); 
//
//	
//	prefixSum(v , n);
//	prefixSum(sortedVec, n);
//
//	int quereies; cin >> quereies;
//	while (quereies--)
//	{
//		short c; cin >> c; 
//		int s, e; cin >> s >> e; 
//		switch (c)
//		{
//		case 1:
//			cout << v[e] - v[s-1] ; 
//			break; 
//		case 2:
//			cout << sortedVec[e] - sortedVec[s -1];  
//		}
//
//		cout << '\n';
//	}
//
//}
//
//int main()
//{
//	fast;
//	solve(); 
//	return 0; 
//}