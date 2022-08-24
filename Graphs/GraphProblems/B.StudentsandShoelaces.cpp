//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
//int n;
//vector<vector<bool>> graphAsMat;
//
///***
//* iterate over each bond and check if it has exactly 1 bond or more
//*
//* @returns the indecies which has exactly only one bond
//*/
//vector<int> CheckForOnes() {
//	vector<int> elements;
//	//O(N^2)
//	for (int i = 0; i < n; i++)
//	{
//		int moreThanOne = 0;
//		for (int j = 0; j < n; j++)
//			if (graphAsMat[i][j])  // if there is a bond mark it
//				moreThanOne++;
//
//		if (moreThanOne == 1) // if only one bond push it in the idx vector
//			elements.push_back(i);
//
//	}
//	return elements;
//}
//
///**
//* Set all elements that are kicked out to zeros
//*/
//void SetZeros(vector<int> elements) {
//	//O(N^2)
//	for (auto it : elements)
//		for (int i = 0; i < n; i++) {
//			graphAsMat[i][it] = 0;
//			graphAsMat[it][i] = 0;
//		}
//}
//void solve() {
//	//read the data
//	int m; cin >> n >> m;
//	graphAsMat = vector<vector<bool>>(n, vector<bool>(n));
//	// O(m)
//	for (int i = 0; i < m; i++)
//	{
//		int u, v; cin >> u >> v;
//		graphAsMat[--u][--v] = true;
//		graphAsMat[v][u] = true;
//	}
//	int cntr = 0;
//	bool Change;
//
//	do {
//		Change = false;
//		vector<int> idx = CheckForOnes();//O(n^2)
//		if (idx.size()) {
//			Change = true;
//			SetZeros(idx); // O(n^2)
//			cntr++;
//		}
//		else break;
//	} while (Change);
//	cout << cntr;
//}
//int main() {
//	fast;
//	solve();
//	return 0;
//}