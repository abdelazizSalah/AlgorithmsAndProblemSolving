////#include <bits/stdc++.h>
////using namespace std;
////#define fast ios_base :: sync_with_stdio(0) ,cin.tie(0), cout.tie(0); 
////using ll = long long;
////
////void PrintGraph(int size) {
////	for (int i = 0; i < size; i++) {
////		for (int j = 0; j < size; j++)
////			if (i != j) cout << 1;
////			else cout << 0;
////		cout << '\n';
////	}
////}
////
////ll fact(int x) {
////	return x * (x - 1) * (x - 2);
////}
////void solve() {
////	int k; cin >> k;
////	int res = 6 * k;
////	bool found = false;
////	int j = 3;
////	do {
////		ll resfact = ceil(fact(j));
////		if (resfact == res) {
////			cout << j << '\n';
////			PrintGraph(j);
////			return;
////		}
////		j++;
////	} while (!found && j <= 100);
////}
////
////int main() {
////	fast;
////	solve();
////	return 0;
////}
////
////#include<iostream>
////int map[110][110], n, k;
////int main() {
////	std::cin >> k; int x = 0;
////	while (x < k)
////	{
////		for (int i = 1; i < n; i++)
////			if (x + (i - 1) <= k)
////			{
////				map[n][i] = map[i][n] = true;
////				x += (i - 1);
////			}
////		n++;
////	}
////	std::cout << n << "\n";
////	for (int i = 1; i <= n; i++)
////	{
////		for (int j = 1; j <= n; j++)
////			std::cout << map[i][j]; std::cout << "\n";
////	}
////}
//
//
//
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
//
//vector<vector<bool>> graph(110, vector<bool>(110));
//
//void solve() {
//	int k; cin >> k;
//	int noOfCycles = 0, noOfNodes = 0;
//	while (noOfCycles < k) {
//		for (int i = 1; i < noOfNodes; i++)
//		{
//			if (noOfCycles + (i - 1) <= k) {
//				noOfCycles += (i - 1);
//				graph[noOfNodes][i] = graph[i][noOfNodes] = true;
//			}
//		}
//			noOfNodes++;
//	}
//
//	cout << --noOfNodes << '\n';
//	for (int i = 1; i <= noOfNodes; i++)
//	{
//		for (int j = 1; j <= noOfNodes; j++)
//			cout << graph[i][j];
//		cout << '\n';
//	}
//}
//
//int main() {
//	fast;
//	solve();
//	return 0;
//}
