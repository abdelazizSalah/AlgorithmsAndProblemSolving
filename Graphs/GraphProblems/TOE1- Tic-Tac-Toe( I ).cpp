//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio (0), cin.tie(0), cout.tie(0); 
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
//void solve()
//{
//	//read the board 
//	string board = "";
//	for (int i = 0; i < 3; i++)
//	{
//		string row; cin >> row;
//		board += row;
//	}
//
//	//create a starting board where all cells are emtpy
//	string start = ".........";
//
//
//	//BFS 
//
//	//         the board, turn -> x is true
//	queue<pair<string, bool>> Q;
//	Q.push({ start, true });
//
//	string ans = "no";
//	while (Q.size())
//	{
//		auto cur = Q.front();
//		Q.pop();
//		if (cur.first == board) // if we reached the solution then stop
//		{
//			ans = "yes";
//			break;
//		}
//
//		//if we have a winning situation we can't continue 
//		if (isWin(cur.first))
//			continue;
//
//		//brute force by placing X or O in all possible cells at that situation
//		for (int i = 0; i < 9; i++)
//			if (cur.first[i] == '.')
//			{
//				cur.first[i] = (cur.second ? 'X' : 'O');
//
//				//if after inserting the letter we have valid board -> insert it in the Q
//				if (cur.first[i] == board[i])
//					Q.push({cur.first, !cur.second}); // push the board and change the turn
//				
//				//set it as empty again to apply another solution for next time 
//				cur.first[i] = '.';
//			}
//	}
//
//	cout << ans << '\n';
//}
//
//
//int main()
//{
//	//PLAY();
//	fast;
//	int tsts; cin >> tsts;
//	while (tsts--)
//		solve();
//	return 0;
//}
//
//
////my Wrong ans solution 
////struct node
////{
////	int i;
////	int j;
////	string d;
////};
////
//////this carries the edges of the graph
////vector<vector<vector<node>>> graphList(3, vector<vector<node>>(3));
////vector<vector<char>>grid(3, vector<char>(3));
////vector<vector<int>> vis(3, vector<int>(3));
//////				  l  r  u  d  lu  ld  ru rd
////vector<int> Xdir{ -1, 1, 0, 0, -1, -1, 1, 1 };
////vector<int> Ydir{ 0, 0, -1, 1, -1, 1, -1, 1 };
////
////int xCntr = 0;
////int oCntr = 0;
////
////
////
////bool validDir(int x, int y)
////{
////	return x >= 0 && y >= 0 && x < 3 && y < 3;
////}
////
////bool sameChar(char x, char y)
////{
////	return x == y;
////}
////
////bool recBFS(int i, int j, int cntr, string d)
////{
////	if (vis[i][j] == 1)
////		return false;
////	vis[i][j] = 1;
////	bool found = false;
////	for (node n : graphList[i][j])
////	{
////		if (n.d == d) // found
////			if (cntr == 1)
////				return true;
////			else
////				found |= recBFS(n.i, n.j, cntr + 1, d);
////
////		//first direction
////		if (d == "N")
////			found |= recBFS(n.i, n.j, cntr + 1, n.d);
////	}
////	vis[i][j] = 2; 
////	return found;
////}
////string getDir(int k)
////{//				  l  r  u  d  lu  ld  ru rd
////	char c = '\0';
////	if (k == 0)
////		return "l";
////	else if (k == 1)
////		return "r";
////	else if (k == 2)
////		return "u";
////	else if (k == 3)
////		return "d";
////	else if (k == 4)
////		return "lu";
////	else if (k == 5)
////		return "ld";
////	else if (k == 6)
////		return "ru";
////	else
////		return "rd"; 
////}
////void solve()
////{
////	//reading the grid
////	vis  = vector<vector<int>>(3, vector<int>(3)); 
////	grid = vector<vector<char>>(3, vector<char>(3)); 
////	oCntr = 0;
////	xCntr = 0;
////	for (int i = 0; i < 3; i++)
////		for (int j = 0; j < 3; j++)
////		{
////			cin >> grid[i][j];
////			if (grid[i][j] == 'O')
////				oCntr++;
////			else if (grid[i][j] == 'X')
////				xCntr++; 
////		}
////
////	if (oCntr > xCntr || xCntr > oCntr + 1)
////	{
////		cout << "no\n";
////		return;
////	}
////
////
////	//creating the edges 
////	for (int i = 0; i < 3; i++)
////		for (int j = 0; j < 3; j++)
////			if (grid[i][j] == 'O' || grid[i][j] == 'X')
////				for (int k = 0; k < 8; k++) // iterating over all possible directions
////				{
////					int xaxis = Xdir[k] + j;
////					int yaxis = Ydir[k] + i;
////					if (validDir(xaxis, yaxis) && sameChar(grid[i][j], grid[yaxis][xaxis]))
////					{
////						node n = { yaxis,xaxis, getDir(k) };
////						graphList[i][j].push_back(n);
////					}
////				}
////
////	//bfs over X and try to find a sequence 
////	if (oCntr == xCntr || oCntr > 3)
////		for (int i = 0; i < 3; i++)
////			for (int j = 0; j < 3; j++)
////				if (vis[i][j] != 1 && grid[i][j] == 'X' && recBFS(i, j, 0, "N"))
////				{
////					cout << "no\n";
////					return;
////				}
////
////	//bfs over O and try to find a sequence 
////	if (oCntr < xCntr)
////		for (int i = 0; i < 3; i++)
////			for (int j = 0; j < 3; j++)
////			{
////				if (vis[i][j] != 1 && grid[i][j] == 'O' && recBFS(i, j, 0, "N"))
////				{
////					cout << "no\n";
////					return;
////				}
////			}
////
////	cout << "yes\n";
////}
