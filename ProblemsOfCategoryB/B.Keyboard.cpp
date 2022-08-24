//#pragma once
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0) 
//
//void solve()
//{
//	int r, c, a;  cin >> r >> c >> a;
//	map <char, vector<pair<int, int>>> grid;
//	map<char, bool> letters;
//	vector<pair<int, int> >SInd;
//	for (int i = 1; i <= r; i++)
//		for (int j = 1; j <= c; j++)
//		{
//			char c; cin >> c;
//			letters[c] = true;
//			if (c == 'S')
//				SInd.push_back({ i , j });
//			grid[c - 32].push_back({ i , j });
//		}
//
//	int size; cin >> size;
//	string s; cin >> s;
//	int cntr = 0;
//	for (auto it : s)
//	{
//
//		// neglect small letters
//		if (it >= 'a')
//		{
//			// if the char doesn't exists 
//			if (!letters[it])
//			{
//				cout << -1;
//				return;
//			}
//			else
//				continue;
//		}
//
//		// if capital but no shift
//		char C = it + 32;
//		int len = SInd.size();
//
//		if (!letters[C] || SInd.size() == 0)
//		{
//			cout << -1;
//			return;
//		}
//		else {
//			int len2 = grid[it].size();
//			bool found = false;
//			for (int i = 0; i < len2; i++)
//			{
//				pair<int, int> charInd = grid[it][i];
//
//
//				for (int i = 0; i < len; i++)
//				{
//					float res = sqrt(pow((SInd[i].first - charInd.first), 2) + pow(SInd[i].second - charInd.second, 2));
//					if (res <= a)
//					{
//						found = true;
//						break;
//					}
//				}
//				if (found)
//					break;
//
//			}
//			if (!found)
//				cntr++;
//		}
//
//	}
//
//	cout << cntr;
//} // time limit exceeded solution at 51
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}