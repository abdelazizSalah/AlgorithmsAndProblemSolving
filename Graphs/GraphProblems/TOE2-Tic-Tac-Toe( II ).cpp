////accepted
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
//
//
//bool isWin(string board) {
//	bool row = (board[0] != '.' && board[0] == board[1] && board[1] == board[2] ||
//		board[3] != '.' && board[3] == board[4] && board[4] == board[5] ||
//		board[6] != '.' && board[6] == board[7] && board[7] == board[8]);
//
//
//	bool column = (board[0] != '.' && board[0] == board[3] && board[3] == board[6] ||
//		board[1] != '.' && board[1] == board[4] && board[4] == board[7] ||
//		board[2] != '.' && board[2] == board[5] && board[5] == board[8]
//		);
//
//
//	bool diag1 = (board[0] != '.' && board[0] == board[4] && board[4] == board[8] ||
//		board[6] != '.' && board[6] == board[4] && board[4] == board[2]);
//
//	return diag1 || column || row;
//}
//
//bool tie(string s)
//{
//	for (char c : s)
//		if (c == '.')
//			return false;
//
//	return true; 
//}
//void solve()
//{
//	string board;
//	while (cin >> board && board != "end")
//	{
//		string start = ".........";
//		queue<pair<string, bool>> Q;
//		Q.push({ start, true });
//		string ans = "invalid";
//		while (Q.size())
//		{
//			auto cur = Q.front();
//			Q.pop();
//			if (cur.first == board && (isWin(cur.first) || tie(cur.first)))
//			{
//				ans = "valid";
//				break;
//			}
//
//			if (isWin(cur.first))
//				continue;
//
//			for (int i = 0; i < 9; i++)
//			{
//				if (cur.first[i] == '.')
//				{
//					cur.first[i] = (cur.second ? 'X' : 'O');
//					if (cur.first[i] == board[i])
//						Q.push({ cur.first, 1 ^ cur.second });
//
//					cur.first[i] = '.';
//				}
//			}
//		}
//		cout << ans << '\n';
//	}
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}