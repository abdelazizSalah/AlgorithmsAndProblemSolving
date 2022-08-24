//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
//using ll = long long;
//
//map<ll, ll> memo;
//ll FibMemo(ll n) {
//	//memoization
//	auto it = memo.find(n);
//	if (it != memo.end())
//		return it->second;
//
//	//base case 
//	if (n == 1 || n == 0) {
//		memo[n] = 1;
//		return memo[n];
//	}
//
//	memo[n] = FibMemo(n - 1) + FibMemo(n - 2);
//	return memo[n];
//}
//
//
//ll FibTab(ll n) {
//	//tabulation
//	vector<ll> table((ll)n + (ll)1);
//	//setting the intial values
//	table[0] = table[1] = 1;
//	//applying the logic
//	for (int i = 2; i < n + 1; i++)
//		table[i] = table[i - 1] + table[i - 2];
//	//returning the required value
//	return table[n];
//}
//
//bool validDir(int x, int y, int n, int m) {
//	return x < n&& y < m&& x >= 0 && y >= 0;
//}
//
////                   D  R
//vector<int> Diry = { 0, 1 };
//vector<int> Dirx = { 1, 0 };
//
//vector<vector<ll>> memo2;
//ll gridTraveler(const vector<vector<ll>>& grid, int i, int j, int n, int m) {
//	//memoization
//	if (memo2[i][j])
//		return memo2[i][j];
//
//	//base case 
//	if (i == n - 1 && j == m - 1) {// the end of the grid  
//		memo2[i][j] = 1;
//		return memo2[i][j];
//	}
//
//	ll cntr = 0;
//
//	for (int k = 0; k < 2; k++) {
//		int xpos = Dirx[k] + i;
//		int ypos = Diry[k] + j;
//		if (validDir(xpos, ypos, n, m))
//			cntr += gridTraveler(grid, xpos, ypos, n, m);
//	}
//	memo2[i][j] = cntr;
//	return memo2[i][j];
//}
//
//ll gridTravelerTabl(vector<vector<ll>>& map, int n, int m) {
//	map[0][0] = 1;
//	for (int i = 0; i < n; i++) // iterating over all rows 
//		for (int j = 0; j < m; j++) // iterating over all columns 
//			for (int k = 0; k < 2; k++) // iterating over all possible directions
//			{
//				int xpos = Dirx[k] + i; //move one step down
//				int ypos = Diry[k] + j; //move one step right
//				if (validDir(xpos, ypos, n, m))
//					map[xpos][ypos] += map[i][j];
//			}
//
//	//return the value at the last idx
//	return map[n - 1][m - 1];
//}
//
//bool canSumwithMemo(map<int, bool>& memo, int trgt, const vector<int>& vals) {
//
//	//memoization
//	auto it = memo.find(trgt);
//	if (it != memo.end())
//		return memo[trgt];
//
//	//base cases 
//	if (trgt == 0) {
//		memo[trgt] = true;
//		return memo[trgt];
//	}
//	else if (trgt < 0) {
//		memo[trgt] = false;
//		return false;
//	}
//
//	bool found = false;
//	int size = vals.size();
//	for (int i = 0; i < size; i++)
//	{
//		found |= canSumwithMemo(memo, trgt - vals[i], vals);
//		if (found) {
//			memo[trgt] = found;
//			return memo[trgt];
//		}
//	}
//
//	memo[trgt] = found;
//	return memo[trgt];
//}
//
//
//bool canSum(map<int, bool>& memo, int trgt, const vector<int>& vals) {
//	//base cases 
//	if (trgt == 0) {
//		memo[trgt] = true;
//		return true;
//	}
//	else if (trgt < 0)
//		return false;
//
//	bool found = false;
//	int size = vals.size();
//	for (int i = 0; i < size; i++) {
//		found |= canSum(memo, trgt - vals[i], vals);
//		if (found) {
//			memo[trgt] = found;
//			return found;
//		}
//	}
//	return found;
//}
//
//bool checkNotOutOfRange(int num, int range) {
//	return num <= range;
//}
//
////mysolution
//bool CanSumTabl1(const vector <int>& vals, int trgt) {
//	vector<bool> check(trgt + 1);
//	check[0] = true;
//	int sz = vals.size();
//	for (int i = 0; i < sz; i++) {
//		for (int j = 0; j < sz; j++) {
//			int num = vals[i];
//			while (checkNotOutOfRange(num, trgt)) {
//				check[num] = true;
//				num += vals[j];
//			}
//		}
//	}
//
//	return check[trgt];
//}
//
////better version of my solution
//bool CanSumTabl2(const vector <int>& vals, int trgt) {
//	vector<bool> check(trgt + 1);
//	check[0] = true;
//	for (int i = 0; i <= trgt; i++) {
//		if (check[i])
//			for (auto it : vals)
//				if (checkNotOutOfRange(it + i, trgt))
//					check[it + i] = true;
//	}
//
//	return check[trgt];
//}
//
//
//bool howSumMemo(map<int, bool>& memo, int trgt, const vector<int>& vals, vector<int>& res) {
//	//memoization
//	auto it = memo.find(trgt);
//	if (it != memo.end())
//		return memo[trgt];
//
//	//base cases 
//	if (trgt == 0) {
//		memo[trgt] = true;
//		return true;
//	}
//
//	if (trgt < 0) {
//		memo[trgt] = false;
//		return memo[trgt];
//	}
//
//	bool found = false;
//	int size = vals.size();
//	for (int i = 0; i < size; i++)
//	{
//		found |= howSumMemo(memo, trgt - vals[i], vals, res);
//		if (found) {
//			res.push_back(vals[i]);
//			memo[trgt] = true;
//			return memo[trgt];
//		}
//	}
//
//	memo[trgt] = found;
//	return memo[trgt];
//}
//
//
//vector<int> howSumTabl(const vector<int>& vals, const int& trgt) {
//	vector<vector<int>> res(trgt + 1, vector<int>(1, -1));
//	res[0] = vector<int>{};
//
//	//iterate over all the elements
//	for (int i = 0; i <= trgt; i++) {
//		// add all elements of the element[i] into the element i + vals[j]
//		int sz = vals.size();
//		if ((i == 0 && res[i].empty()) || res[i][0] != -1) {
//			for (int j = 0; j < sz; j++) {
//				//if not out of range copy all the elements in it
//				if (checkNotOutOfRange(i + vals[j], trgt)) {
//					res[i + vals[j]] = vector<int>(res[i]);
//					res[i + vals[j]].push_back(vals[j]);
//				}
//			}
//		}
//	}
//	return res[trgt];
//}
//
//vector<int> bestSum(map<pair<int, int>, vector<int>>& memo, int trgt, const vector<int>& vals, int num) {
//	//memoization
//	// note fe el memoization bshof eh kol el 7agat el btt8yr w b5leha el key bta3 el map bt3ty
//	// fhena 3ndy 2 byt8yro el trgt wl num el mb3ot m3 el trgt
//	//flazm el key yeb2a pair of el etnen dol 
//
//	auto it = memo.find({ trgt,num });
//	if (it != memo.end())
//		return memo[{trgt, num}];
//
//	//base case 
//	if (trgt == 0) {
//		return vector<int> {num};
//	}
//
//	if (trgt < 0) {
//		return vector<int> {-1};
//	}
//
//	vector<int> best;
//	vector<int> now;
//	bool inserted = false;
//	int size = vals.size();
//	for (int i = 0; i < size; i++) {
//		now = bestSum(memo, trgt - vals[i], vals, vals[i]);
//		if (now.size() <= best.size() && best.size() && now.size() && now[0] != -1) {
//			best.clear();
//			best = now;
//			inserted = true;
//		}
//		else if (now.size() && now[0] != -1 && best.size() == 0) {
//			inserted = true;
//			best = now;
//		}
//	}
//	if (inserted)
//		best.push_back(num);
//	memo[{trgt, num}] = best;
//	return memo[{trgt, num}];
//}
//
//
//vector<int> BestSumTabl(const vector<int>& vals, const int& trgt) {
//	vector<vector<int>> res(trgt + 1, vector<int>(1, -1));
//	res[0] = vector<int>{};
//
//	//iterate over all the elements
//	for (int i = 0; i <= trgt; i++) {
//		// add all elements of the element[i] into the element i + vals[j]
//		int sz = vals.size();
//		if ((i == 0 && res[i].empty()) || res[i][0] != -1) {
//			for (int j = 0; j < sz; j++) {
//				//if not out of range copy all the elements in it
//				if (checkNotOutOfRange(i + vals[j], trgt)) {
//					if (res[i + vals[j]].size() && res[i + vals[j]][0] == -1) {
//						res[i + vals[j]] = vector<int>(res[i]);
//						res[i + vals[j]].push_back(vals[j]);
//					}
//					else if (res[i + vals[j]].size() > res[i].size() + 1) {
//						res[i + vals[j]] = vector<int>(res[i]);
//						res[i + vals[j]].push_back(vals[j]);
//					}
//				}
//			}
//		}
//	}
//	return res[trgt];
//}
//
//bool validString(string trgt, string sent) {
//	if (sent.size() > trgt.size())
//		return false;
//	int size = sent.size();
//	for (int i = 0; i < size; i++) {
//		if (sent[i] != trgt[i])
//			return false;
//	}
//	return true;
//}
//
///**
//* @author Abdelaziz Salah
//* @returns whethere there is a way to form the trgt string from the given wordBank
//*/
//map<string, bool> memoS;
//bool canConstruct(const string& trgt, const vector<string>& WordBank, string val) {
//	//memoization 
//	auto it = memoS.find(val);
//	if (it != memoS.end())
//		return it->second;
//
//	if (trgt == val)
//		return true;
//
//	//check that the sent string is valid 
//	if (!validString(trgt, val)) {
//		memoS[trgt] = false;
//		return memoS[trgt];
//	}
//
//	bool found = false;
//	int size = WordBank.size();
//	for (int i = 0; i < size; i++) {
//		found |= canConstruct(trgt, WordBank, val + WordBank[i]);
//		if (found) {
//			memoS[val] = found;
//			return memoS[val];
//		}
//	}
//
//	memoS[val] = found;
//	return memoS[val];
//}
//
//bool canConstructTabul(string trgt, vector<string> vals) {
//	int len = trgt.length();
//	vector<bool> res(++len);
//	res[0] = true;
//	for (int i = 0; i < len; i++) {
//		if (res[i]) {
//			int sz = vals.size();
//			for (int j = 0; j < sz; j++) {
//				bool notValid = false;
//				int idx = i;
//				int len = vals[j].length();
//				for (int k = 0; k < len; k++) {
//					if (vals[j][k] != trgt[idx++]) {
//						notValid = true;
//						break;
//					}
//				}
//				if (!notValid)
//					res[i + len] = true;
//			}
//		}
//	}
//
//	return res[trgt.length()];
//}
//
///**
//* @author Abdelaziz Salah
//* @returns how many number of ways are there to form the trgt string from the given wordBank
//*/
//map<string, int> memoC;
//int countConstruct(string trgt, vector<string> wordBank, string val) {
//	//memoization 
//	auto it = memoC.find(val);
//	if (it != memoC.end())
//		return it->second;
//
//	// base case 
//	if (trgt == val)
//		return 1;
//
//	if (!validString(trgt, val)) {
//		memoC[trgt] = 0;
//		return memoC[trgt];
//	}
//
//	int cntr = 0;
//	int size = wordBank.size();
//	for (int i = 0; i < size; i++)
//		cntr += countConstruct(trgt, wordBank, val + wordBank[i]);
//
//	memoC[val] = cntr;
//	return memoC[val];
//}
//
//string slicer(string trgt, string word) {
//	string sent;
//	int len = word.length();
//	int sz = trgt.size();
//	for (int i = len; i < sz; i++) {
//		sent += trgt[i];
//	}
//	return sent;
//}
//
//
//
////even if we have used the DP still have an exponential complexity
//map <string, vector<deque<string>>> memoAllCos;
//vector<deque<string>> allConstruct(string trgt, const vector<string>& wordBank) {
//	//memoization
//	auto it = memoAllCos.find(trgt);
//	if (it != memoAllCos.end())
//		return it->second;
//
//	//base case 
//	if (trgt == "")
//		return vector<deque<string>>{deque<string>{"valid"}};
//
//	//vector contains all possible ways to form the main trgt
//	vector<deque<string>> allWays;
//
//	//vector contains all possible ways to form the sent suffix
//	vector<deque<string>> suffixWays;
//
//	// cntr to determine the idx of the sent vector
//	int cntr = -1;
//	int size = wordBank.size();
//	for (int i = 0; i < size; i++) {
//		if (validString(trgt, wordBank[i])) {
//			//remove the prefix that has been found 
//			string suffix = slicer(trgt, wordBank[i]);
//
//			//recurse on the new suffix till reaching ' '
//			suffixWays = allConstruct(suffix, wordBank);
//
//			// push the certain string that has been removed in the suffixWays
//			for (auto& it : suffixWays)
//				if (it[0] == "valid") // if it was valid branch but new one
//					it[0] = wordBank[i];
//				else
//					it.push_front(wordBank[i]); // if it was valid branch but has elements 
//
//			//update the branch with the new suffix values 
//			for (int i = 0; i < suffixWays.size(); i++)
//				allWays.push_back(suffixWays[i]);
//		}
//	}
//
//	//memorize the answer
//	memoAllCos[trgt] = allWays;
//	return allWays;
//}
//
//void solve() {
//	cout << boolalpha << canConstructTabul("enterapotentpot", vector<string>{"a", "p", "ent", "enter", "ot", "o", "t"});
//}
//
//int main() {
//	fast;
//	solve();
//	return 0;
//}