//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ; 
//void solve()
//{
//	int n; cin >> n;
//	vector<char> eggs(n);
//	for (char& e : eggs) e = '0'; 
//	eggs[n - 1] = 'B';
//	eggs[n - 2] = 'I';
//	eggs[n - 3] = 'V';
//
//	vector<char>Rainbow = { 'R' , 'O' , 'Y' , 'G' , 'B' , 'I' , 'V' }; 
//	for (int i = 0; i < 7; i++)
//		for (int j = i , cntr = 0; j < n; j+= 4)
//			if (eggs[j] == '0')
//				eggs[j] = Rainbow[i]; 
//
//	for (char e : eggs)
//		cout << e; 
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}