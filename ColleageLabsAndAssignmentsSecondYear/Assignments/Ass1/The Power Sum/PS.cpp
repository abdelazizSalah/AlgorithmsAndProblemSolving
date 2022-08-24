#include <bits/stdc++.h>
using namespace std;
#define fast ios_base :: sync_with_stdio(0),cin.tie(0), cout.tie(0);
//time limit exceed
//int Ps(deque<int>& v, int i, int sum, const int& n, const  int& x)
//{
//	int p = pow(v[i], n);
//	if (sum + p > x)
//		return 0;
//	else if (sum + p == x)
//	{
//		auto it = v.begin() + i;
//		v.erase(v.begin(), it + 1);
//		return 1;
//	}
//	else return Ps(v, i + 1, sum + p, n, x);
//}
//
//int solve()
//{
//	int x, n;
//	cin >> x >> n;
//	int lrg = 0;
//	//determine the largest element -> 10 / 4^2 = 0 but 10/ 3^2 not 0
//	for (int i = 1; i <= x + 1; i++)
//	{
//		int p = pow(i, n);
//		if ((x / p == 0))
//		{
//			lrg = i;
//			break;
//		}
//	}
//	//from 1 to lrg in deque
//	deque<int> v(lrg);
//	for (int i = 1; i <= lrg; i++)
//		v[i - 1] = i;
//
//	int cntr = 0;
//	do {
//		cntr += Ps(v, 0, 0, n, x);
//	} while (next_permutation(v.begin(), v.end()));
//
//	return cntr;
//}

void ps(vector<pair<int, bool >> &v, int& cntr, int i, const int& x ,int m, int sum )
{
	int pw = pow(v[i].first, m);
	sum += pw;
	if (sum > x || i >= v.size())
		return;
	if (sum == x)
	{
		cntr++;
		return;
	}
	else
	{
		v[i].second = true;
		// hya de el bgrb beha mara akhud el element w mara mkhdush
		ps(v, cntr, i + 1, x, m, sum - pw);//m5dosh 
		ps(v, cntr, i + 1, x, m, sum);
	}
}
void solve()
{
	int x, n; cin >> x >> n;
	int lrgs;
	for (int i = 1; i <= x; i++)
	{
		int pw = pow(i, n); 
		if (x / pw == 0)
		{
			lrgs = i;
		}
	}
	vector<pair<int, bool >>v(lrgs);
	for (int i = 1; i <= lrgs; i++)
		v[i - 1].first = i;
	
	int cntr = 0;
	int sum = 0;
	ps(v, cntr, 0, x,n, sum);
	cout << cntr;
}
int main()
{
	fast;
	solve();
	return 0;
}