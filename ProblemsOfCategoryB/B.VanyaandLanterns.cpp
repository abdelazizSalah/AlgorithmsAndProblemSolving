//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0); 
//using ll = long long;
//
//void solve2()
//{
//	int n; cin >> n;
//	int l; cin >> l;
//
//	vector<int> v(n); 
//	for (auto &it : v)
//		cin >> it;
//
//	sort(v.begin(), v.end()); 
//
//	int mxdist = INT_MIN; 
//	for (int i = 0; i < n - 1; i++)
//		mxdist = max(mxdist, v[i+1] - v[i]); 
//
//	if ((double)mxdist / 2 > v[0] && (double)mxdist / 2 > l - v[n - 1])
//		cout << (double)mxdist / 2;
//	else if (v[0] < l - v[n-1])
//		cout << (double) (l - v[n - 1]);
//	else
//		cout << (double)v[0]; 
//}
//
//int main()
//{
//	fast;
//	cout << fixed << setprecision(10);
//	solve2();
//	return 0;
//}
