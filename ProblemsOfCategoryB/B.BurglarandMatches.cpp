//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base ::sync_with_stdio(0), cin.tie(0),cout.tie(0) 
//using ll = long long;
//void solve()
//{
//	ll n, m; cin >> n >> m; 
//	priority_queue<pair<int,int>> pq;
//
//	int a, b; 
//	for (int i = 0; i < m; i++) {
//		cin >> a >> b; 
//		pq .push({ b,a });
//	}
//
//	ll cntr = 0; 
//	while (n > 0 && !pq.empty())
//		if (n >= pq.top().second)
//		{
//			n -= pq.top().second; 
//			cntr += pq.top().first * pq.top().second;
//			pq.pop(); 
//		}
//		else
//		{
//			cntr += pq.top().first * n;
//			n =0; 
//		}
//
//	cout << cntr;
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}