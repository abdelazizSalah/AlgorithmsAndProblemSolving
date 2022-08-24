//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0); 
//using ll = long long;
//
//void solve()
//{
//	float P, PA, T, TA; cin >> P >> PA >> T >> TA;
//	while (P + PA < T - TA)
//	{
//		P += PA; 
//		T -= TA; 
//	}
//
//	if (PA + P > T && PA + P > T - TA)
//		cout << T;
//	else
//		cout << PA + P;
//}
//
//
//void solve2()
//{
//	float P, PA, T, TA; cin >> P >> PA >> T >> TA;
//	bool Pturn = true;
//
//	while (T != P)
//	{
//		if (Pturn) // person's turn
//		{
//			if (T > (P + PA)) // if the taxi's offer is greater than my next offer then i will offer my next offer
//			{
//				P += PA;
//				Pturn = false;
//			}
//			else // else i will take his offer 
//				P = T; 
//		}
//		else // taxi's turn 
//		{
//			if (P < (T - TA)) // if the person's offer is less than my next offer then i will offer my offer
//			{
//				T -= TA;
//				Pturn = true;
//			}
//			else // else i will take his offer
//				T = P;
//		}
//	}
//
//	cout << P; 
//}
//int main()
//{
//	fast;
//
//	solve2();
//	return 0;
//}
