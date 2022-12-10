// https://www.hackerrank.com/challenges/common-child/problem?isFullScreen=false
#pragma once
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0) 
using ll = long long;
/// Brute force solution
//void createMap(int idx, string stringBuilder, const string& mainString, map<string,pair<int,short>> & storage, short turn) {
//	if (idx == mainString.size()) {
//		if (storage[stringBuilder].second != turn) {
//			storage[stringBuilder].second = turn;
//			storage[stringBuilder].first ++; 
//		}
//		return; 
//	}
//
//	// take the char 
//	createMap(idx + 1, stringBuilder + mainString[idx], mainString,storage, turn);
//
//	// leave the char 
//	createMap(idx + 1, stringBuilder , mainString,storage, turn);
//}
//
//void solve()
//{
//	// reading the input 
//	string s1, s2;
//	cin >> s1 >> s2; 
//	map<string, pair<int,short>> s1Map;
//
//	// applying the logic 
//	createMap(0, "", s1, s1Map, 3); 
//	createMap(0, "", s2, s1Map, 5); 
//
//	
//	// iterating over the map and getting all items with value = 2
//	int len = 0;
//	for (auto item : s1Map) 
//		if (item.second.first == 2 && item.first != "") 
//			len = max(len, (int) item.first.length()); 
//
//	// printing the output 
//	cout << len; 
//}

int commonChild(string s1, string s2) {
	vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1)); 

	for (int i = 1; i <= s1.length(); i++)
		for (int j = 1; j <= s2.length(); j++)
			if (s1[i - 1] == s2[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1] + 1; 
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);


	return dp[s1.length()][s2.length()]; 
}



void solve() {
	string s1, s2; cin >> s1 >> s2; 
	cout << commonChild(s1, s2); 
}

int main()
{
	fast;
	solve();
	return 0;
}