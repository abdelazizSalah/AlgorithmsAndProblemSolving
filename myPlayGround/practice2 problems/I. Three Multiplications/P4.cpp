#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)
using ll = long long; 
int main()
{
	fast;
	int n; cin >> n; 
	priority_queue<int> pq;
	for (int i = 0; i < n ; i++)
	{
		int x; cin >> x; 
		pq.push(x);
		if (i + 1< 3)
			cout << -1 << '\n';
		else
		{
			ll arr[3];
			ll sum = 1; 
			for (int j = 0; j < 3; j++)
			{
				arr[j] = pq.top();
				sum *= pq.top();
				pq.pop();
			}
			for (int j = 0; j < 3; j++)
				pq.push(arr[j]);

			cout << sum << '\n';
		}
	}
	return 0;
}