//#include <bits/stdc++.h>
//using namespace std;
//
//int arraySumWayDown(const vector<int>& vals, int sum, int idx) {
//	if (idx == vals.size())
//		return sum;
//	return arraySumWayDown(vals, sum + vals[idx], idx + 1);
//}
//
//void arraySumWayDownWithByRef(const vector<int>& vals, int idx, int& res) {
//	if (idx == vals.size())
//		return;
//
//	res += vals[idx];
//	arraySumWayDownWithByRef(vals, idx + 1, res);
//}
//
//int arraySumWayUp(const vector<int>& vals, int sum, int idx) {
//	if (idx == vals.size())
//		return 0;
//	return arraySumWayUp(vals, sum, idx + 1) + vals[idx];
//}
//
//int maxSum(const vector<int>& vals) {
//	int mx = INT_MIN;
//	int size = vals.size();
//	for (int i = 0; i < size; i++) {
//		int res = vals[i];
//		for (int j = i + 1; j < size; j++) {
//			mx = max(mx, res + vals[j]);
//		}
//	}
//	return mx;
//}
//
//int maxSumRec(const vector<int>& vals, int idx, int cntr) {
//	int size = vals.size();
//	// base case 
//	if (size == idx)
//		return 0;
//
//	if (cntr == 2)
//		return vals[idx];
//
//	int mx = INT_MIN;
//	for (int i = 0; i < size; i++) {
//		for (int j = idx + 1; j < size; j++) {
//			mx = max(mx, vals[idx] + maxSumRec(vals, j, cntr + 1));
//		}
//		mx = max(mx, maxSumRec(vals, i + 1, 0));
//	}
//	return mx;
//}
//
//bool findBinaryString(string s, const int& n, const vector<string>& vals) {
//
//	//base case 
//	if (s.length() == n) {
//		for (auto it : vals) {
//			if (s.find(it) == string::npos) {
//				return false;
//			}
//		}
//		cout << s << '\n';
//		return true;
//	}
//
//	bool found = false;
//	// logic 
//	for (char c = '0'; c <= '1'; c++) {
//		found |= findBinaryString(s + c, n, vals);
//	}
//
//	return found;
//}
//
//int maxFormedNo(const vector<int>& vals, int idx, map<int, bool>& vis, int parent) {
//	//base case 
//	if (idx == vals.size()) {
//		return parent;
//	}
//
//	int mx = INT_MIN;
//	for (auto it : vals) {
//		if (!vis[it]) {
//			//mark as visited
//			vis[it] = true;
//
//			int num = maxFormedNo(vals, idx + 1, vis, it);
//			if (num > mx) {
//				mx = num;
//			}
//			//backtracking 
//			vis[it] = false;
//		}
//	}
//	parent *= pow(10, vals.size() - idx);
//	parent += mx;
//
//	return parent;
//}
//
////sheet 1 problems 
//
///*
//	[Recursion] Write a recursive function to print all k^n value for a given
//	radix k and n. Example: given k = 3 and n = 3, print “000”, “001”,
//	“002”,”010”...,”222
//*/
//void printKpowNradix(const int& k, const int& n, string s) {
//	//base case 
//	if (s.length() == n) {
//		cout << s << '\n';
//		return;
//	}
//
//	//generating the string 
//	for (char i = '0'; i < '0' + k; i++) {
//		printKpowNradix(k, n, s + i);
//	}
//}
//
//
///*
//	[Brute-force] Given an array of integers, find the length of the Longest
//	Increasing Subsequence (LIS) inside the array such that all elements
//	of the subsequence are sorted in increasing order. For example, the
//	length of LIS for {12, 24, 9, 35, 21, 50, 41, 62, 82} is 6 and LIS is {12,
//	24, 35, 50, 62, 82}.
//*/
//
//vector<int> LIS(const vector<int>& vals, int idx, int parent) {
//
//	//base case
//	int sz = vals.size();
//	if (idx >= sz) {
//		return vector<int> {};
//	}
//
//	// with
//	vector<int> with = LIS(vals, idx + 1, vals[idx]);
//
//	//without 
//	vector<int> without = LIS(vals, idx + 1, parent);
//
//	if (with.size() >= without.size()) {
//		with.push_back(vals[idx]);
//		return with;
//	}
//	else
//		return without;
//}
//vector<int> LISgoingDown(const vector<int>& vals, int idx, vector<int> elems) {
//	//{ 12, 24,9,35,21 };
//	//base case
//	int sz = vals.size();
//	if (idx >= sz) {
//		for (int i = 1; i < elems.size(); i++) {
//			if (elems[i] < elems[i - 1])
//				return vector<int>{};
//		}
//		return elems; 
//	}
//
//	// with
//	elems.push_back(vals[idx]); 
//	vector<int> with = LISgoingDown(vals, idx + 1, elems);
//
//	//without 
//	elems.pop_back(); 
//	vector<int> without = LISgoingDown(vals, idx + 1, elems);
//
//	int wsz = with.size(), wwsz = without.size();
//	if (wsz > wwsz)
//		return with;
//	else 
//		return without; 
//}
//
//bool validDir(int i, int j, int n, int m) {
//	return i < n&& j < m&& i >= 0 && j >= 0;
//}
//
//bool endOfMaze(int i, int j, int n, int m) {
//	return i == n - 1 && j == m - 1;
//}
////                u,  d, l, r
//vector<int> dirX{ -1, 1, 0, 0 };
//vector<int> dirY{ 0, 0, -1, 1 };
//
//map<pair<int, int>, pair<int, deque<int>>> memo;
//pair<int, deque <int> > minCost(const vector<vector<int>>& maze, vector<vector<bool>>& vis, int i, int j, const int& n, const int& m) {
//	//memoization
//	auto it = memo.find({ i,j });
//	if (it != memo.end())
//		return it->second;
//
//	// base case 
//	if (endOfMaze(i, j, n, m))
//		return { maze[i][j],deque<int> {maze[i][j]} };
//
//	int mn = INT_MAX;
//	pair<int, deque<int>> res;
//
//	//logic
//	for (int k = 0; k < 4; k++) {
//		int xpos = dirX[k] + i;
//		int ypos = dirY[k] + j;
//		if (validDir(xpos, ypos, n, m) && !vis[xpos][ypos]) {
//			vis[xpos][ypos] = true;
//			auto rslt = minCost(maze, vis, xpos, ypos, n, m);
//			if (mn > rslt.first) {
//				mn = rslt.first;
//				res = rslt;
//			}
//			vis[xpos][ypos] = false;
//		}
//	}
//
//	res.second.push_front(maze[i][j]);
//	res.first += maze[i][j];
//	memo[{i, j}] = res;
//	return res;
//}
//
//
//int main() {
//	vector<int> List = { 12, 24, 9, 35, 21, 50, 41, 62, 82 };
//	auto res = LISgoingDown(List, 0, vector<int>{});
//	for (auto it : res)
//		cout << it << ' ';
//
//}