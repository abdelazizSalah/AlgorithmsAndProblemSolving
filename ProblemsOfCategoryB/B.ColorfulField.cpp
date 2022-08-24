//#pragma once
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0) 
////
////void solve()
////{
////	int r, c, k, q; cin >> r >> c >> k >> q; 
////	char **field = new char *[r]; 
////	for (int i = 0; i < r; i++)
////		field[i] = new char[c]; 
////
////	while (k--)
////	{
////		int ro, co; cin >> ro >> co; 
////		field[--ro][--co] = 'W';
////	}
////	
////	int cntr = 0; 
////	for (int i = 0; i < r; i++)
////	{
////		for (int j = 0; j < c; j++)
////		{
////			if (field[i][j] == 'W')
////				continue; 
////			switch (cntr)
////			{
////			case 0:
////				field[i][j] = 'C';
////				break; 
////			case 1:
////				field[i][j] = 'K';
////				break;
////			case 2:
////				field[i][j] = 'G';
////				break;
////			default:
////				break;
////			}
////			cntr++;
////			cntr %= 3; 
////		}
////	}
////
////	while (q--)
////	{
////		int ro, co; cin >> ro >> co;
////		switch (field[--ro][--co])
////		{
////		case 'C': 
////			cout << "Carrots" << '\n';
////			break;
////
////		case 'W':
////			cout << "Waste" << '\n';
////			break;
////		case 'G':
////
////			cout << "Grapes" << '\n';
////			break;
////
////		case 'K':
////			cout << "Kiwis" << '\n';
////			break;
////		default:
////			break;
////		}
////	}
////
////	// free the memory
////	for (int i = 0; i < r; i++)
////		delete [] field[i];
////	delete[] field; 
////}
//// this is the easies dumb solution
//
//void solve()
//{
//	//better solution
//	set<int> waste; 
//	int r, c, k, q; cin >> r >> c >> k >> q;
//	while (k--)
//	{
//		int x, y; cin >> x >> y; 
//		x--; y--; 
//		waste.insert(x * c + y); 
//	}
//	
//	while (q--)
//	{
//		int ro, co; cin >> ro >> co; 
//		int res = --ro * c + --co; 
//		int cntr = 0; 
//		if (binary_search(waste.begin(), waste.end(), res))
//		{
//			cout << "Waste\n";
//			continue; 
//		}
//		for (auto it : waste)
//			if (it < res)
//				cntr++;
//			else
//				break; 
//
//		switch ((res - cntr) % 3)
//		{
//		case 0:
//			cout << "Carrots\n";
//			break;
//		case 1:
//			cout << "Kiwis\n";
//			break;
//		case 2:
//			cout << "Grapes\n";
//			break;
//		default:
//			break;
//		}
//	}
//}
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}