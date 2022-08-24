#include <bits/stdc++.h>
#include <unordered_map>
#include<unordered_set>
#define fast ios_base ::sync_with_stdio(0) , cin.tie(0),cout.tie(0) ;
using namespace std;
using ll = long long;

/*
if (m == 2) // case of 2 done :)
	{
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (v[j] - v[i] == d)
					mp[i] ++;
			}
		}
		ll sum = 0;
		for (auto it : mp)
			sum += it.second;

		cout << sum;
	}
	else
	{
		// i will do sth here
	}
*/
//void solve()
//{
//	int n, d, m; cin >> n >> d >> m;
//
//	vector<int > v(n);
//	for (int i = 0; i < n; i++)
//		cin>> v[i]; 
//
//	if (m == 2)
//	{
//		ll cntr = 0;
//		for (int i = 0; i < n; i++)
//		{
//			auto it = v.begin();
//			while (it != v.end())
//			{
//				it = find(++it, v.end(), v[i] + d);
//				int idx = it - v.begin();
//				if (idx > i && it != v.end()) // found at a pos > i
//					cntr++;
//			}
//		}
//		cout << cntr;
//	}
//	else
//	{
//		int cntr = 0; 
//		for (int i = 0; i < n; i++)
//		{
//			auto it = v.begin();
//			while (it != v.end())
//			{
//				it = find(++it, v.end(), v[i] + d);
//				int idx = it - v.begin();
//				if (idx > i && it != v.end())
//				{
//					auto it2 = it; 
//					while (it2 != v.end())
//					{
//						it2 = find(++it2, v.end(), v[i] + 2 * d);
//						int idx2 = it2 - v.begin();
//						if (idx2 > idx && it2 != v.end())
//							cntr++;
//					}
//				}
//			}
//		}
//			cout << cntr; 
//	}
//
//}

void solve()
{
	int n, d, m; cin >> n >> d >> m;
	set<int> x;
	
	unordered_map<int, vector<int>> mp; 
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x; 
		mp[x].push_back(i); // store indcies 
	}
	
	if (m == 2)
	{
		int cntr = 0;
		for (auto& it : mp)
		{
			for (int i = 0; i < it.second.size(); i++)
			{
				auto it2 = mp.find(it.first + d);
				if (it2 != mp.end())
				{
					// found first
					for (int j = 0; j < it2->second.size(); j++)
					{
						if (it2->second[j] > it.second[i]) // found second
							cntr++;
					}
				}
			}
		}
		cout << cntr;
	}
	else
	{
		int cntr = 0;
		for (auto& it : mp)
		{
			for (int i = 0; i < it.second.size(); i++)
			{
				auto it2 = mp.find(it.first + d);
				if (it2 != mp.end())
				{
					// found first 
					for (int j = 0; j < it2->second.size(); j++)
					{
						if (it2->second[j] > it.second[i]) // found second 
						{
							auto it3 = mp.find(it2->first + d);
							if (it3 != mp.end()) // found third
							{
								for (int k = 0; k < it3->second.size(); k++)
								{
									if (it3->second[k] > it2->second[j]) // if has greater index
										cntr++; 
								}
							}
						}
					}
				}
			}
		}
		cout << cntr;
	}
}


int main()
{
	fast;
	solve();
	return 0;
}

//ACCEPTED :)
