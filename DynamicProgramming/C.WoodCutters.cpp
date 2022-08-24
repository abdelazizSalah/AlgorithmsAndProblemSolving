//Accepted First time 
// problem link https://codeforces.com/contest/545/problem/C
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0), cin.tie(0),cout.tie(0) ; 
//using ll = long long;
//
//map<pair<int, int>, int> memo;
//int woodCutter(const vector<pair<int, int>>& vals, int idx, int sentval, vector<bool>& vis) {
//	//memoization
//	auto it = memo.find({ idx , sentval });
//	if (it != memo.end())
//		return it->second;
//
//	//can't cut in this way 
//	if (sentval >= vals[idx].first || vis[idx]) {
//		memo[{idx, sentval}] = 0;
//		return 0;
//	}
//
//	//base case 
//	if (idx == vals.size() - 1) {
//		memo[{idx, sentval}] = 1;
//		return 1;
//	}
//
//	//mark as vis
//	vis[idx] = true;
//	// try left 
//	int left = vals[idx].first - vals[idx].second;
//	int cutLeft = 0;
//	priority_queue<int> pq;
//	pq.push(0);
//	if (idx > 0 && left > vals[idx - 1].first && left > sentval)
//		cutLeft = woodCutter(vals, idx + 1, left, vis);
//
//	//try right 
//	int right = vals[idx].first + vals[idx].second;
//	int cutRight = woodCutter(vals, idx + 1, right, vis);
//
//	//try not to cut
//	int noCut = 0;
//	if (!cutRight && !cutLeft)
//		noCut = woodCutter(vals, idx + 1, vals[idx].first, vis);
//
//	if (noCut)
//		pq.push(noCut);
//
//	if (cutRight)
//		pq.push(++cutRight);
//
//	if (cutLeft)
//		pq.push(++cutLeft);
//
//	// mark as unvisited 
//	vis[idx] = false;
//	memo[{idx, sentval}] = pq.top();
//
//	return pq.top() ;
//}
//
//void solve() {
//	//reading the data 
//	int n; cin >> n;
//
//	vector<pair<int, int>> v(n);
//	vector<bool> vis(n);
//	for (auto& it : v)
//		cin >> it.first >> it.second;
//	vis[0] = true;
//	//we always can cut at least 2 trees in diffrent directions left and right.
//	if (n <= 2) {
//		cout << n;
//		return;
//	}
//	cout << woodCutter(v, 1, v[0].first, vis) + 1;
//}
//
//int main() {
//	fast;
//	solve();
//	return 0;
//}