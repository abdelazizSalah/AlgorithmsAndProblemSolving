///**
//* Accepted First time 
//* @author abdelaziz Salah
//*/
//
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0); 
//
//void solve() {
//	int n, m; cin >> n >> m;
//	vector<pair<int, int>> pos(n);
//	priority_queue<int> pq;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++) {
//			char c; cin >> c;
//			switch (c) {
//			case 'G':
//				pos[i].first = j;
//				break;
//			case 'S':
//				if (j - pos[i].first < 0 || j == 0) {// dwarf can't reach that candy
//					cout << -1;
//					return;
//				}
//				pos[i].second = j;
//				pq.push(pos[i].second - pos[i].first);
//				break;
//			default:
//				break;
//			}
//		}
//
//	int cntr = 0;
//	int tp = -1;
//	while (pq.size()) {
//		if (pq.top() != tp) {
//			cntr++;
//			tp = pq.top();
//		}
//		pq.pop();
//	}
//	cout << cntr;
//}
//
//int main() {
//	fast;
//	solve();
//	return 0;
//}