////#include <bits/stdc++.h>
////using namespace std;
////using ll = long long;
////#define fast ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0); 
////
////ll altCount(string s) {
////	ll cntr = 0;
////	ll ln = s.length();
////	for (int i = 1; i < ln; i++) {
////		if (s[i] != s[i - 1])
////			cntr++;
////	}
////	return cntr + 1;
////}
////
////map<string, ll> memo;
////ll altCntr(string s) {
////	auto it = memo.find(s); 
////	if (it != memo.end())
////		return it->second; 
////
////	if (s.length() == 1)
////		return 0;
////	char c = s[0];
////	string news (s.begin() + 1, s.end());
////	int cntr = altCntr(news); 
////	if (c == news[0]) {
////		memo[s] = cntr;
////		return cntr;
////	}
////	else {
////		memo[s] = cntr + 1; 
////		return cntr + 1; 
////	}
////}
////
////// O(n^2 *2m) 
////// n is the lenth of the string 
////// m is the length of the longest sequence of zeros
////void generateTheString(string s) {
////	ll ln = s.length();
////	vector<int> indcies;
////	ll mx = altCntr(s);
////	for (int i = 0; i < ln; i++) { // O(n)
////		int j = i;
////		while (s[j] != '1') { //O(m)
////			indcies.push_back(j);
////			s[j] = '1';
////			ll num = altCntr(s); // O(n)
////			mx = max(mx, num);
////			j++;
////		}
////
////		int sz = indcies.size();
////		while (sz--) { //O(m)
////			s[indcies[sz]] = '0';
////			indcies.pop_back();
////		}
////	}
////
////	cout << mx + 1;
////}
////void solve() {
////	int n; cin >> n;
////	string s; cin >> s;
////	generateTheString(s); 
////}
////
////int main() {
////	fast;
////	solve();
////	return 0;
////}
//
//
//// The solution !!!!!!!!!!1
//#include <bits/stdc++.h>
//using namespace std;
//int main ()
//{
//	string s;
//	int c=3,n;
//	cin>>n;
//	cin>>s;
//	for(int i=1;i<n;i++)
//	{
//		if(s[i]!=s[i-1])c++;
//	}
//	cout<<min(c,n);
//	return 0;
//}
//
//
