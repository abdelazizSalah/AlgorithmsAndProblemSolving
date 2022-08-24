#include <bits/stdc++.h>
using namespace std; 
#define fast ios_base :: sync_with_stdio(0),cin.tie(0), cout.tie(0);

//Accepted
void stringGen(set<string> &set , int N, int idx , int h, string s = "")
{
	if (idx == N) // baseCase
	{
		int cntr = 0;
		for (int i = 0; i < N; i++)
		{
			if (s[i] == '1')
				cntr++;
		}
		if (cntr == h)
			set.emplace(s);
		return; 
	}

	for (char i = '0'; i < '2'; i++)
	{
		stringGen(set, N, idx + 1, h, s + i);
	}
}
void solve()
{
	int n, h; cin >> n >> h; 
	set<string>s; 
	stringGen(s, n, 0, h); 
	for (auto it : s)
		cout << it << '\n';
}
int main()
{
	fast; 
	solve();
	return 0;
}

