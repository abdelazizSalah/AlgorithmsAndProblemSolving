#include<bits/stdc++.h>
using namespace std; 
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)
int main()
{
	//map is best one for counting
	fast;

	int n; cin >> n;
	map<string, int > mp;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s; 
		mp[s] ++;
		if (mp[s] == 1)
			cout << "OK" << '\n';
		else
			cout << s << mp[s] - 1 << '\n';
	}
	return 0;


	return 0;
}