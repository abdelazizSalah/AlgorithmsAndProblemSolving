//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base ::sync_with_stdio(0), cin.tie(0),cout.tie(0) 
//using ll = long long;
//
//void solve()
//{
//	int n; cin >> n;
//	if (n == 1) {
//		cout << 1;
//		return;
//	}
//	vector <int> rects(n);
//	for (auto& it : rects)
//		cin >> it;
//
//	int mx = INT_MIN;
//	for (int i = 0; i < n; i++)
//	{
//		int cntr = 1;
//		// right
//		for (int j = i + 1; j < n; j++)
//			if (rects[j] <= rects[j - 1])
//				cntr++;
//			else break;
//
//		//left 
//		for (int j = i - 1; j >= 0 && i != 0; j--)
//			if (rects[j] <= rects[j + 1])
//				cntr++;
//			else break;
//		mx = max(cntr, mx);
//	}
//
//	cout << mx;
//}
//
//int main()
//{
//	fast;
//	/*	int k;
//		cin >> k;
//		while (k--)
//			*/solve();
//			return 0;
//}