//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
///**
//
//	A child is running up a staircase with n steps and can hop either 1 step, 2
//	steps, or 3 steps at a time. Implement a method to count how many possible
//	ways the child can run up the stairs
//
//*/
//
//ll p1(ll n, map<ll, ll>& memo) {
//	//memoization
//	auto it = memo.find(n);
//	if (it != memo.end())
//		return it->second;
//
//	//base cases
//	if (n == 0)
//		return 1;
//
//	if (n < 0) {
//		memo[n] = 0;
//		return 0;
//	}
//
//	ll cntr = 0;
//	for (ll i = 1; i <= 3; i++) {
//		cntr += p1(n - i, memo);
//	}
//
//	memo[n] = n;
//	return cntr;
//}
//
//
///*
//	Compute nth Catalan number according to the formula:
//	𝐶0 = 1 and 𝐶𝑛+1 = ∑ 𝐶𝑖𝐶𝑛−𝑖
//	𝑛
//	𝑖=0
//	for 𝑛 ≥ 0
//*/
//
//ll p2(ll n, map <ll, ll> memo) {
//	//memoization
//	auto it = memo.find(n);
//	if (it != memo.end())
//		return it->second;
//
//	//base cases 
//	if (n == 0 || n == 1)
//		return 1;
//
//	//odd
//	bool odd = false;
//	if (n % 2)
//		odd = true;
//
//	ll val = 0;
//	for (ll i = 0; i < n / 2; i++) { // b3d el nos bnbd2 nkrr nfs el arkam tany fa msh lazm n7sbhom, fa bndrbhom fe 2 3ltoul 
//		val += p2(i, memo) * p2(n - 1 - i, memo);
//	}
//
//	val *= 2;
//	if (odd)
//		val += pow(p2(n / 2, memo), 2);
//
//	memo[n] = val;
//	return val;
//}
//
///*
//	Given an array of integers, find the length of the Longest Increasing
//	Subsequence (LIS) inside the array such that all elements of the
//	subsequence are sorted in increasing order. For example, the length of LIS
//	for {12, 24, 9, 35, 21, 50, 41, 62, 82} is 6 and LIS is {12, 24, 35, 50, 62, 82}.
//*/
//deque<int> LISBottomUp(const vector<int>& vals) {
//	int sz = vals.size();
//	vector<int> table(sz, 1);
//	int mxval = INT_MIN;
//	for (int i = 1; i < sz; i++) {
//		int mx = 1;
//		for (int j = 0; j < i; j++) {
//			if (vals[i] > vals[j]) {
//				mx = max(mx, table[i] + table[j]);
//				mxval = max(mxval, mx);
//			}
//		}
//		table[i] = mx;
//	}
//
//
//	deque<int> res;
//	for (int i = sz - 1; i >= 0; i--) {
//		if (table[i] == mxval) {
//			mxval--;
//			res.push_front(vals[i]);
//		}
//	}
//
//	return res;
//}
//
//// used for the min sort
//deque<int> LIncOrEqSBottomUp(const vector<int>& vals) {
//	int sz = vals.size();
//	vector<int> table(sz, 1);
//	int mxval = INT_MIN;
//	for (int i = 1; i < sz; i++) {
//		int mx = 1;
//		for (int j = 0; j < i; j++) {
//			if (vals[i] >= vals[j]) { // increasing or equal 
//				mx = max(mx, table[i] + table[j]);
//				mxval = max(mxval, mx);
//			}
//		}
//		table[i] = mx;
//	}
//
//	deque<int> res;
//	for (int i = sz - 1; i >= 0; i--) {
//		if (table[i] == mxval) {
//			mxval--;
//			res.push_front(vals[i]);
//		}
//	}
//
//	return res;
//}
//
//
//// here we don't apply the memoization in the same approach as we used to we iterate over the whole sample space and evaluate the best sequance for that pos
//int LISTopDown(const vector<int>& vals, int idx, vector<int>& dp) {
//	if (idx == 0)
//		return dp[idx] = 1;
//
//	dp[idx] = 1;
//	for (int i = 0; i < idx; i++) {
//		if (dp[i] == -1)
//			dp[i] = LISTopDown(vals, i, dp);
//
//		if (vals[idx] > vals[i])
//			dp[idx] = max(dp[idx], dp[i] + 1);
//	}
//
//	return dp[idx];
//}
//
//void LIS(const vector<int>& vals) {
//	vector<int> memo(vals.size(), -1);
//	int size = LISTopDown(vals, vals.size() - 1, memo);
//	cout << "The length of the longest increasing subSequance is " << size;
//	cout << "\nThe increasing subSequence is : \n";
//	for (auto it : LISBottomUp(vals))
//		cout << it << ' ';
//}
//
//
///*
//	Given an array of integer numbers, we need to sort this array in a
//	minimum number of steps where in one step we can insert any array
//	element from its position to any other position.
//	Examples :
//	Input : arr = [2, 3, 5, 1, 4, 7, 6]
//	Output : 3
//	We can sort above array in 3 insertion
//	steps as shown below,
//	1 before array value 2
//	4 before array value 5
//	6 before array value 7
//	Input : arr = {4, 6, 5, 1}
//	Output : 2
//*/
//int minSort(const vector<int>& arr) {
//	// lw gebt el LIS da keda sorted increasingly fa ana msh h7tag 8er eny a7ot ba2y el elements elly msh mtrtben 
//	// el fekra bs hena el lazm el LIS yeb2a msh increasing bs, la yeb2a >= 
//	// 34an test case zy de keda htbwz el denya 
//	//vector<int> res{ 1,2,2,2,2,3,4 }; will return 3 instead of 0
//	return  arr.size() - LIncOrEqSBottomUp(arr).size();
//}
//
///*
//	Given an array of numbers, find the maximum product formed by
//	multiplying numbers of an increasing subsequence of that array.
//	Examples:
//	Input : arr = { 3, 100, 4, 5, 150, 6 }
//	Output : 45000
//	Maximum product is 45000 formed by the
//	increasing subsequence 3, 100, 150. Note
//	that the longest increasing subsequence
//	is different {3, 4, 5, 6}
//	Input : arr = { 10, 22, 9, 33, 21, 50, 41, 60 }
//	Output : 21780000
//	Maximum product is 21780000 formed by the
//	increasing subsequence 10, 22, 33, 50, 60.
//
//*/
//ll maxProductTabul(const vector<ll>& costs) {
//	int sz = costs.size();
//	vector<ll> res(costs);
//	ll mxval = INT_MIN;
//	for (int i = 0; i < sz; i++) {
//		ll mx = costs[i];
//		for (int j = 0; j < i; j++) {
//			if (costs[i] > costs[j]) {
//				mx = max(mx, costs[i] * res[j]);
//				mxval = max(mxval, mx);
//			}
//		}
//		res[i] = mx;
//	}
//	return mxval;
//}
//
//
///*
//	Given two strings str1 and str2 and below operations that can be
//	performed on str1. Find minimum number of edits (operations) required to
//	convert ‘str1’ into ‘str2’.
//	a. Insert
//	b. Remove
//	c. Replace
//	All of the above operations are of equal cost.
//*/
////starting from the end 
//map <pair<string, pair<int, int>>, int> memo;
//int minOperations(const string& s2, string s1, int s2idx, int s1idx) {
//	//memoization
//	auto it = memo.find({ s1, {s2idx, s1idx} });
//	if (it != memo.end())
//		return it->second;
//	//the remaining will be added 
//	if (s1 == "")
//		return s2.length();
//	if (s2 == "")
//		return s1.length();
//	if (s1idx == 0) {
//		memo[{s1, { s2idx, s1idx }}] = s2idx;
//		return s2idx;
//	}
//	//the remaining will be removed
//	if (s2idx == 0)
//	{
//		memo[{s1, { s2idx, s1idx }}] = s1idx;
//		return s1idx;
//	}
//	//if the same char just move the pointers 1 step
//	if (s2[s2idx - 1] == s1[s1idx - 1]) {
//		memo[{s1, { s2idx, s1idx }}] = minOperations(s2, s1, s2idx - 1, s1idx - 1);
//		return 	memo[{s1, { s2idx, s1idx }}];
//	}
//	else {
//		// brute force by tring the operations
//		int ins = minOperations(s2, s1, s2idx, s1idx - 1);
//		int rep = minOperations(s2, s1, s2idx - 1, s1idx - 1);
//		int del = minOperations(s2, s1, s2idx - 1, s1idx);
//		priority_queue<int, vector<int>, greater<>> pq;
//		if (ins != -1)
//			pq.push(ins + 1);
//		if (rep != -1)
//			pq.push(rep + 1);
//		if (del != -1)
//			pq.push(del + 1);
//		memo[{s1, { s2idx, s1idx }}] = pq.top();
//		return pq.top();
//	}
//}
//
//// starting from the beginning 
//int minOperations2(const string& s1, string s2, int s1idx, int s2idx) {
//	//memoization
//	auto it = memo.find({ s2,  {s1idx,s2idx } });
//	if (it != memo.end())
//		return it->second;
//
//	//base cases 
//	//if we reached the end of the fisrt string return the remaining length of chars to the other
//	//the remaining will be added 
//	if (s1 == "")
//		return s2.length();
//	if (s2 == "")
//		return s1.length();
//	if (s1idx == s1.length() - 1) {
//		memo[{ s2, { s1idx, s2idx }}] = s2.length() - s2idx - 1;
//		return s2.length() - s2idx - 1;
//	}
//	if (s2idx == s2.length() - 1) {
//		memo[{ s2, { s1idx, s2idx }}] = s1.length() - s1idx - 1;
//		return s1.length() - s1idx - 1;
//	}
//
//	//if the same char then we need to move to the next one 
//	if (s1[s1idx] == s2[s2idx])
//		return minOperations2(s1, s2, s1idx + 1, s2idx + 1);
//
//	//applying the three operations and try to find the best of them 
//	int del = 0, rep = 0, add = 0;
//	del = minOperations2(s1, s2, s1idx + 1, s2idx);
//	add = minOperations2(s1, s2, s1idx, s2idx + 1);
//	rep = minOperations2(s1, s2, s1idx + 1, s2idx + 1);
//	priority_queue <int, vector<int>, greater<>> pq;
//	pq.push(++del);
//	pq.push(++rep);
//	pq.push(++add);
//	memo[{ s2, { s1idx, s2idx }}] = pq.top();
//	return pq.top();
//}
//
//void BigIntegerRep() {
//	BigInteger b1 = 1;
//	for (int i = 0; i < 100; i++)
//	{
//		b1 = b1 * 10;
//		b1 = b1 + b1;
//		b1.print();
//		cout << '\n';
//	}
//}
//
//int LISTabul(const vector<int>& vals) {
//	int sz = vals.size();
//	vector<int> table(sz, 1);
//
//	int mxval = INT_MIN;
//	for (int i = 0; i < sz; i++) {
//		int mx = table[i];
//		for (int j = 0; j < i; j++) {
//			if (vals[i] > vals[j]) {
//				mx = max(table[i] + table[j], table[i]);
//				mxval = max(mx, mxval);
//			}
//		}
//		table[i] = mx;
//	}
//
//	return mxval; 
//}
//
//
//int main() {
//	cout << LISTabul(vector<int> {1, 2, 5, 4, 9}); 
//	return 0;
//}