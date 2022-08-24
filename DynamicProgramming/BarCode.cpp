#include <bits/stdc++.h>
using namespace std;
#define fast ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0); 

//time limit sol
map<pair<pair<int, int>, pair<int, bool>>, int> memo;
int barCode(int width, int val, int idx, bool black, const vector<int>& dots, const int mn, const int mx, const int rows) {
	//memoization
	auto it = memo.find({ {width, val}, {idx, black} });
	if (it != memo.end())
		return it->second;
	//base cases
	//invalid root
	if (idx == dots.size() - 1 && (width < mn || width > mx)) {
		memo[{ {width, val}, { idx, black } }] = INT_MAX;
		return INT_MAX;
	}

	//end of the root and valid one 
	if (idx == dots.size() - 1) {
		memo[{ {width, val}, { idx, black } }] = val;
		return val;
	}

	int Hash = INT_MAX, dot = INT_MAX;
	if (width < mx) {
		if (black) {
			Hash = barCode(width + 1, dots[idx + 1], idx + 1, true, dots, mn, mx, rows);
			dot = barCode(1, rows - dots[idx + 1], idx + 1, false, dots, mn, mx, rows);
		}
		else {
			Hash = barCode(1, dots[idx + 1], idx + 1, true, dots, mn, mx, rows);
			dot = barCode(width + 1, rows - dots[idx + 1], idx + 1, false, dots, mn, mx, rows);
		}
	}
	else if (black)
		dot = barCode(1, rows - dots[idx + 1], idx + 1, false, dots, mn, mx, rows);
	else
		Hash = barCode(1, dots[idx + 1], idx + 1, true, dots, mn, mx, rows);

	if (dot == INT_MAX && Hash == INT_MAX) {
		memo[{ {width, val}, { idx, black } }] = INT_MAX;
		return INT_MAX;
	}

	if (dot == INT_MAX) {
		memo[{ {width, val}, { idx, black } }] = Hash + val;
		return Hash + val;
	}
	else if (Hash == INT_MAX) {
		memo[{ {width, val}, { idx, black } }] = dot + val;
		return dot + val;
	}
	else if (width < mn) {
		if (black) {
			Hash += val;
			memo[{ {width, val}, { idx, black } }] = Hash;
			return Hash;
		}
		else {
			dot += val;
			memo[{ {width, val}, { idx, black } }] = dot;
			return dot;
		}
	}
	else {
		memo[{ {width, val}, { idx, black } }] = min(Hash, dot) + val;
		return min(Hash, dot) + val;
	}
}


void solve() {
	//reading the data
	memo = map<pair<pair<int, int>, pair<int, bool>>, int>();
	int r, c, mn, mx; cin >> r >> c >> mn >> mx;
	vector<int> dots(c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			char c; cin >> c;
			if (c == '.')
				dots[j] ++;
		}

	//applying with diffrent starts 
	int StartWithHash = barCode(1, dots[0], 0, true, dots, mn, mx, r);
	int StratWithDot = barCode(1, r - dots[0], 0, false, dots, mn, mx, r);

	//printing the result 
	cout << min(StartWithHash, StratWithDot);
}

int main() {
	fast;
	solve();
	return 0;
}

/*
* correct solution 
// http://c...content-available-to-author-only...s.com/problemset/problem/225/C

#include <bits/stdc++.h>
using namespace std;


#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
typedef long long ll;

int n, m, x, y;

// n - dotsCount[i] = # of hashes
int dotsCount[1000+9];			// +9 for safety and little thinking
int memo[1000+9][1000+9][3];	// 3: 0 (dots), 1 (hashes), 2 (nothing)

// 0-1 style with restrictions on # of connectives of same value
int solve(int col, int wid, int last)
{
	if(col == m)
	{
		// Make sure invalid states to invalidated
		if(wid < x || wid > y)
			return 100000000;
		return 0;	// we are done
	}

	int &ans = memo[col][wid][last];

	if(ans != -1)
		return ans;

	int dots = 100000000;	// max answer is 1000x1000
	// nothing before or bigger block is valid or old block is allowed
	if(col == 0 || (last == 0 && wid+1 <= y) || (last == 1 && wid >= x))
		dots = n - dotsCount[col] + solve(col+1, (last == 0) ? wid + 1 : 1, 0);

	int hashes = 100000000;
	if(col == 0 || (last == 1 && wid+1 <= y) || (last == 0 && wid >= x))
		hashes = dotsCount[col] + solve(col+1, (last == 1) ? wid + 1 : 1, 1);

	ans = min(dots, hashes);

	return ans;
}
// Your turn: Convert to tabulation style

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.txt", "rt", stdin);
#endif

	cin>>n>>m>>x>>y;

	// read and accumulate each column
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch;
			cin>>ch;

			if(ch == '.')
				dotsCount[j]++;
		}
	}

	clr(memo, -1);
	cout<<solve(0, 0, 2);

	return 0;
}

*/