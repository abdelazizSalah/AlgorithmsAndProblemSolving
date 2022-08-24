//#include <bits/stdc++.h> 
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0),cin.tie(0),cout.tie(0); 
//
//// el color hwa hwa el width 3moman :D
//map<pair<pair<int, int>, pair<int, bool>>, pair<int, int>> memo;
//pair<int, int> BarCode(const vector<int>& dots, const int rows, const int mn, const int mx, int val, int idx, bool clr, int width) {
//	auto it = memo.find({ {val, idx} , {width, clr} });
//	if (it != memo.end())
//		return it->second;
//	//base case 
//	if (idx + 1 == dots.size() && width < mn)
//		return { INT_MAX,INT_MAX };
//
//	if (idx + 1 == dots.size())
//		return { val,width };
//
//	pair<int, int>hashs = { INT_MAX,INT_MAX }, dot = { INT_MAX,INT_MAX };
//	if (width < mx) {
//		if (clr) {
//			hashs = BarCode(dots, rows, mn, mx, dots[idx + 1], idx + 1, false, 1);
//			dot = BarCode(dots, rows, mn, mx, rows - dots[idx + 1], idx + 1, true, width + 1);
//		}
//		else {
//			hashs = BarCode(dots, rows, mn, mx, dots[idx + 1], idx + 1, false, width + 1);
//			dot = BarCode(dots, rows, mn, mx, rows - dots[idx + 1], idx + 1, true, 1);
//		}
//	}
//	else if (clr)
//		hashs = BarCode(dots, rows, mn, mx, dots[idx + 1], idx + 1, false, 1);
//	else
//		dot = BarCode(dots, rows, mn, mx, rows - dots[idx + 1], idx + 1, true, 1);
//
//	if (dot.first == INT_MAX && hashs.first == INT_MAX || ((dot.second < mn || dot.second > mx) && (hashs.second <mn || hashs.second > mx))) {
//		memo[{ {val, idx}, { width, clr }}] = { INT_MAX,INT_MAX };
//		return { INT_MAX,INT_MAX };
//	}
//	if (dot.second == INT_MAX || dot.second > mx) {
//		hashs.first += val;
//		memo[{ {val, idx}, { width, clr }}] = hashs;
//		return hashs;
//	}
//	else if (hashs.second == INT_MAX || hashs.second > mx) {
//		dot.first += val;
//		memo[{ {val, idx}, { width, clr }}] = dot;
//		return dot;
//	}
//
//	//black 
//	if (!clr) {
//		if (width < mn) {
//			hashs.first += val;
//			memo[{ {val, idx}, { width, clr }}] = hashs;
//			return hashs;
//		}
//		if (width > mn) {
//			if (hashs.first < dot.first) {
//				hashs.first += val;
//				memo[{ {val, idx}, { width, clr }}] = hashs;
//				return hashs;
//			}
//			else {
//				dot.first += val;
//				memo[{ {val, idx}, { width, clr }}] = dot;
//				return dot;
//			}
//		}
//	}
//	else if (clr) {
//		if (width < mn) {
//			dot.first += val;
//			memo[{ {val, idx}, { width, clr }}] = dot;
//			return dot;
//		}
//		if (width > mn) {
//			if (hashs.first < dot.first) {
//				hashs.first += val;
//				memo[{ {val, idx}, { width, clr }}] = hashs;
//				return hashs;
//			}
//			else {
//				dot.first += val;
//				memo[{ {val, idx}, { width, clr }}] = dot;
//				return dot;
//			}
//		}
//	}
//	/*if (dot.first < hashs.first && width >= mn && width <= mx) {
//		memo[{ {val, idx}, { width, clr }}] = { dot.first + val, dot.second };
//		return { dot.first, dot.second };
//	}
//	else {
//		memo[{ {val, idx}, { width, clr }}] = { hashs.first + val, hashs.second };
//		return { hashs.first, hashs.second };
//	}*/
//}
//
//void solve() {
//	//reading the data 
//	int r, c, mn, mx; cin >> r >> c >> mn >> mx;
//
//	//storing the number of dots 
//	vector<int> dots(c);
//	for (int i = 0; i < r; i++) {
//		for (int i = 0; i < c; i++) {
//			char c; cin >> c;
//			if (c == '.')
//				dots[i] ++;
//		}
//	}
//
//	// starting with counting the hashes 
//	int stWithHash = BarCode(dots, r, mn, mx, dots[0], 0, false, 1).first;
//	//starting with counting the dots 
//	int stWithdots = BarCode(dots, r, mn, mx, r - dots[0], 0, true, 1).first;
//
//	//printing the output
//	cout << min(stWithdots, stWithHash);
//}
//
//int main() {
//	fast;
//	solve();
//	return 0;
//}