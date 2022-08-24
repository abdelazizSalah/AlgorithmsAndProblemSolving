//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ; 
//
//void solve()
//{
//	//priority_queue<pair<char, int>> let; 
//	map<char, int> let; 
//	let['A'] = 0;
//	let['B'] = 0;
//	let['C'] = 0;
//	string s;
//	int cntr = 3;
//	while (cntr--)
//	{
//		cin >> s;
//		if (s[1] == '<')
//			let[s[2]] ++;
//		else
//			let[s[0]] ++; 
//	}
//
//	bool found = false; 
//	for (auto it : let)
//		if (it.second == 2)
//		{
//			found = true; 
//			break; 
//		}
//
//	if (!found)
//	{
//		cout << "Impossible"; 
//		return; 
//	}
//	priority_queue<pair<int, char> > pq; 
//	pq.emplace(make_pair( let['A'],'A' ));
//	pq.push(make_pair(let['B'], 'B'));
//	pq.push(make_pair(let['C'], 'C'));
//
//	s = "";
//	while (pq.size())
//	{
//		s+=pq.top().second; 
//		pq.pop(); 
//	}
//
//	cout << s[2] << s[1] << s[0]; 
//}
//
//int main()
//{
//	fast;
//	solve(); 
//	return 0; 
//}