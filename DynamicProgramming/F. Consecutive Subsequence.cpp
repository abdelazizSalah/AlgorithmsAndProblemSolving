//#include<bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
//
//// LIS
//// Slow solution O(n^2) 
//deque<int> LIS(const vector<int>& arr) {
//	int sz = arr.size();
//	vector<int> table(sz, 1);
//	deque<int> res;
//
//	int mxVal = INT_MIN;
//	for (int i = 0; i < sz; i++) {
//		int mx = table[i];
//		for (int j = 0; j < i; j++) {
//			if (arr[i] == arr[j] + 1)
//				mx = max(mx, table[i] + table[j]);
//			mxVal = max(mx, mxVal);
//		}
//		table[i] = mx;
//	}
//
//	//search for the indx with the largest val 
//	int LastElement = 0;
//	int Lastidx = 0;
//	for (int i = 0; i < sz; i++) {
//		if (table[i] == mxVal) {
//			Lastidx = i;
//			LastElement = arr[i];
//		}
//	}
//
//	res.push_front(Lastidx + 1);
//	mxVal--;
//	for (int i = Lastidx - 1; i >= 0; i--) {
//		if (table[i] == mxVal && arr[i] == LastElement - 1) {
//			LastElement = arr[i];
//			mxVal--;
//			res.push_front(i + 1);
//		}
//	}
//	return res;
//}
//
////O(N Lg N)
//deque<int> LISForConsecutiveSequance(const vector<int>& vals) { // hena el fekra en fe condition 5alany msh lazm eny 23ml iteration 3la kol el elements mn el awl khales, ana kol el m7tag a3rfo hal i - 1 mwgod wla la w lw mwgod ably hakhud el rkm el m3aya w agm3 3leh 1 w a5zno gwaya :D.
//	map<int, int> dp;
//	int mxVal = 1;
//	int LastElement = 0;
//	int sz = vals.size();
//	dp[vals[0]] = 1;
//	for (int i = 1; i < sz; i++) {
//		dp[vals[i]] = 1;
//		auto it = dp.find(vals[i] - 1);
//		if (it != dp.end())
//			dp[vals[i]] = max(dp[vals[i]], it->second + 1);
//		if (mxVal < dp[vals[i]]) {
//			mxVal = dp[vals[i]];
//			LastElement = vals[i];
//		}
//	}
//
//	deque<int> res;
//	for (int i = sz - 1; i >= 0; i--) {
//		if (vals[i] == LastElement) {
//			LastElement--;
//			res.push_front(i + 1);
//		}
//	}
//
//	return res;
//	////search for the indx with the largest val 
//	//int Lastidx = 0;
//	//for (int i = 0; i < sz; i++) {
//	//	if (dp[vals[i]] == mxVal) {
//	//		Lastidx = i;
//	//		LastElement = vals[i];
//	//	}
//	//}
//
//	//res.push_front(Lastidx + 1);
//	//mxVal--;
//	//for (int i = sz - 1; i >= 0; i--) {
//	//	if (dp[vals[i]] == mxVal && vals[i] == LastElement - 1) {
//	//		LastElement = vals[i];
//	//		mxVal--;
//	//		res.push_front(i + 1);
//	//	}
//	//}
//	//return res;
//}
//void solve() {
//	//reading the data
//	int n; cin >> n;
//	vector<int> v(n);
//	for (auto& it : v)
//		cin >> it;
//
//	auto res = LISForConsecutiveSequance(v);
//	if (res.empty()) {
//		cout << 1 << '\n' << 1;
//		return;
//	}
//	cout << res.size() << '\n';
//	for (auto it : res)
//		cout << it << ' ';
//}
//
//int main() {
//	fast;
//	//while (1)
//	solve();
//	return 0;
//}