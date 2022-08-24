//#include<bits/stdc++.h>
//using namespace std;
//#define fast ios_base ::sync_with_stdio(0), cin.tie(0),cout.tie(0); 
//
//
//void solve() {
//	//reading the data 
//	int n; cin >> n;
//	deque <int> ans(n);
//	vector<int> vals(n);
//	for (auto& it : vals)
//		cin >> it;
//
//	//the most right building is always luxry
//	ans[n - 1] = 0;
//	//setting its height to be a refrence 
//	int max = vals[n - 1];
//	
//	//starting from the most right building 
//	for (int i = n - 2; i >= 0; i--)
//		if (vals[i] > max) { // if the height of the next building is greater than the right building so it is the new refrenece
//			max = vals[i];
//			ans[i] = 0; // it doesn't need any more floors
//		}
//		else // otherwise set the required floors to the diffrence between them + 1 
//			ans[i] = max - vals[i] + 1;
//
//	//printing the ans
//	for (auto it : ans)
//		cout << it << ' ';
//}
//
//int main() {
//	fast;
//	solve();
//	return 0;
//}