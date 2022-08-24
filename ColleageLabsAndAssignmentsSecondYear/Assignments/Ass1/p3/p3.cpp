#include <bits/stdc++.h>
using namespace std;
#define fast ios_base :: sync_with_stdio(0),cin.tie(0), cout.tie(0);

void solve()//ACCEPTED :)
{
	//Reading the Data
	int n; cin >> n; 
	string nm; cin >> nm; 
	int len = nm.length(); // to determine the length of the strings
	vector<deque<char>> s(n, deque<char>(len));
	vector<deque<char>> s2(n, deque<char>(len)); // de 34an kol mara agy akarn akarn bl strings el aslya
	for (int i = 0; i < len; i++)
	{
		s[0][i] = nm[i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < len; j++)
		{
			char c; cin >> c;
			s[i][j] = c;
		}
	}
	s2 = s;
	int cntr = 0 , mncntr = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < len; k++)
			{
				if (i != j && s[i] != s[j])
				{
					cntr++;
					char c = s[j][0];
					s[j].pop_front();
					s[j].push_back(c);
				}
				else
					break;
			}
		}
		for (int i = 0; i < n - 1; i++)
		{ // el case el t5ly mfesh possible solution hya en el asamy mtkonsh zy  b3d aslun
			if (s[i] != s[i + 1])
			{
				cout << -1;
				return;
			}
		}
		mncntr = min(mncntr, cntr);
		s = s2;
		cntr = 0;
	}
	cout << mncntr;
}

void RecSol(const vector<deque<char>> &v, int& mncntr, int i, int n, int len, bool& cf)
{
	//base case 
	if (i == n || !cf)return; 

	vector<deque<char>> v2(v); 
	int cntr = 0; 
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < len; k++)
		{
			if (i != j && v2[i] != v2[j])
			{
				cntr++;
				char c = v2[j][0];
				v2[j].pop_front();
				v2[j].push_back(c);
			}
			else
				break;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{ // el case el t5ly mfesh possible solution hya en el asamy mtkonsh zy  b3d aslun
		if (v2[i] != v2[i + 1])
		{
			cf = false;
			return; 
		}
	}
	mncntr = min(mncntr, cntr);
	RecSol(v, mncntr, i + 1, n, len, cf);
	
}
int main()
{
	fast;
	int n; cin >> n;
	string s; cin >> s; 
	int len = s.length(); 
	vector<deque<char>>v(n, deque<char>(len));
		for (int i = 0; i < len; i++)
		{
			v[0][i] = s[i];
		}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < len; j++)
		{
			char c; cin >> c;
			v[i][j] = c;
		}
	}
	int mnC = INT_MAX;
	bool cf = true;
	RecSol(v, mnC, 0, n, len, cf); 
	if (cf)
		cout << mnC;
	else
		cout << -1; 
	return 0; 
}