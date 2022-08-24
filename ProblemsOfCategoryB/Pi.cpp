//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0),cin.tie(0), cout.tie(0); 
//using ld = long double;
//
//// to count the total number of pairs
//ld Comb(int a , int b)
//{		ld res = 1;
//		int NmM = a - b;
//		for (int i = a, j = b; i > NmM || j > 0; i--, j--)
//			res *= (ld)i / j;
//		return res; 
//}
//
//// to check if there is a common factor or not
//int GCD(int a, int b)
//{
//	if (b == 0) return a;
//
//	return GCD(b, a % b); 
//}
//
//void solve()
//{
//	int n; 
//	while (cin >> n)
//	{
//		if (n == 0) return; 
//		
//		// reading the data
//		ld cntr = 0;
//		vector<int> v(n);	
//		for (int& i : v) cin >> i; 
//		
//		//determine the pairs with no common factor
//		for (int i = 0; i < n; i++)
//			for (int j = i+1; j < n; j++)
//				if (GCD(v[i], v[j])==1)
//					cntr++; 
//		
//		// if there is no pairs with no common factor
//		if (!cntr) {
//			cout << "No estimate for this data set.\n"; 
//			continue; 
//		}
//
//		// determine the total number of pairs
//		ld tot = Comb(n, 2); 
//		
//		// computing pi => 6/pi^2 = nocommontpairs / total numer of pairs
//		cout << sqrt(6 * tot / cntr)<<'\n'; 
//	}
//}
//
//int main()
//{
//	fast;
//	cout << fixed << setprecision(6);
//	solve(); 
//	return 0;
//}