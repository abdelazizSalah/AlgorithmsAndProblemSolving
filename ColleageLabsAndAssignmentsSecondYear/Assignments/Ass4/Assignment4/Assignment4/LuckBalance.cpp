#include <bits/stdc++.h>
using namespace std; 
#define fast ios_base :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
using pq = priority_queue<int>; 
using ll = long long;
//accepted :)
void solve()
{
	int n, k; cin >> n >> k; 
	pq importnt; 
	ll sum = 0; 
	for (int i = 0; i < n; i++) // O(n)
	{
		int val, imp; cin >> val >> imp; 
		if (!imp) sum += val;
		else
			importnt.push(val); 
	}

	while (k--)//O(k)
	{
		if (importnt.size()) // check it is not empty
		{
			sum += importnt.top();
			importnt.pop();
		}
	}
	while (importnt.size()) //O(n - k)
	{
		sum -= importnt.top();
		importnt.pop();
	}
	cout << sum; 
} // linear time

int main()
{
	fast; 
	solve(); 
	return 0; 
}