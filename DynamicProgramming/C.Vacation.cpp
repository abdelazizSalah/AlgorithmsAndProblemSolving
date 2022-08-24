////Accepted first Time :D
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0),cin.tie(0), cout.tie(0); 
//using ll = long long;
//
//void solve() {
//	//reading the data 
//	int n; cin >> n;
//	vector <int> days(n);
//	for (auto& it : days)
//		cin >> it;
//
//	int tomorow = 0, yesterday = 0, rest = 0;
//	for (int it = 0; it < n; it++)
//	{
//		switch (days[it])
//		{
//		case 0:
//			rest++;
//			yesterday = 0;
//			break;
//		case 1:
//			if (yesterday == 1) {
//				yesterday = 0;
//				rest++;
//			}
//			else 
//				yesterday = 1;
//			break;
//		case 2:
//			if (yesterday == 2) {
//				yesterday = 0;
//				rest++;
//			}
//			else 
//				yesterday = 2;
//			break;
//		case 3:
//			if (yesterday == 1)
//				yesterday = 2;
//			else if (yesterday == 2)
//				yesterday = 1;
//			else if (it < n - 1 ){
//				tomorow = days[it + 1]; 
//				if(tomorow == 1)
//					yesterday = 2;
//				else if (tomorow == 2)
//					yesterday = 1;
//				else
//					yesterday = 0;
//			}
//			break;
//		default:
//			break;
//		}
//	}
//
//	cout << rest;
//}
//
//int main() {
//	fast;
//	solve();
//	return 0;
//}