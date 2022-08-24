#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)
using ll = long long;
int main()
{
	fast;
	map<int, string> mp; // speed , string
	int n; 
	cin >> n; 
	while (n--)
	{
		string arr[4] = { "Hussien" , "Atef" , "Karemo" , "Ezzat" };
		for (int i = 0; i < 4; i++)
		{
			int x; cin >> x;
			mp[x] = arr[i];
		}
		auto it = mp.rbegin();
		cout << it->second;
		it++; 
		cout << ' ' << it->second << '\n';
	}
	//try the priority queue solution
	return 0;
}