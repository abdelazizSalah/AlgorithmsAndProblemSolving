#pragma once
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0) 
using ll = long long;
using ld = long double;
void solve()
{
	/// reading the data
	string s; cin >> s;
	ll n; cin >> n;
	ll len = s.length();

	/// applying the logic
	vector<int> aPos;
	ll finalRes = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'a')
			aPos.push_back(i + 1);
	}

	for (int a : aPos) {
		ll n2 = n;
		ld res = (n2 - a) / (ld)(len);
		while ((ll)res != res && n2 > 0) {
			n2--;
			res = (n2 - a) / (ld)(len);
		}
		if (n2 == 0)
			continue;
		else {
			finalRes += 1 + res;
		}
	}
	/// printing the output
	cout << finalRes;
}

int main()
{
	fast;
	solve();
	return 0;
}