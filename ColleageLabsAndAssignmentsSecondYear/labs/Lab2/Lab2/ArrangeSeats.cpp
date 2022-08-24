#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0),cin.tie(0) , cout.tie(0) ; 

void arrangeSeats(vector<pair<string, bool>>& v, vector<string>sts ,int idx ,  int i, int n, int& cntr)
{
	//base case 
	if (i == n) return; 
	if (idx == n)
	{
		bool cntfrm = false;
		for (int j = 0; j < n - 1; j++)
		{
			int len = sts[j].size() - 1; 
			if (sts[j][len] == sts[j + 1][0])
			{
				cntfrm = true;
				break;
			}
		}
		//can form a seat
		if (!cntfrm)cntr++;
		i++; 
		return;
	}

	
	for (int j = 0; j < n ; j++)
	{
		if (!v[j].second)
		{
			v[j].second = true;
			sts.push_back(v[j].first); 
			arrangeSeats(v, sts, idx + 1, i, n, cntr); 
			sts.pop_back();
			v[j].second = false;
		}
	}
}

void solve()
{
	int n; cin >> n;
	vector<pair<string, bool>> nms(n);
	vector<string> sts;
	for (auto& it : nms) cin >> it.first;
	int cntr = 0;
	arrangeSeats(nms, sts, 0, 0, n, cntr);
	cout << cntr;

}

int main()
{
	fast;
	solve();
	return 0;
}