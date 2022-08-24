#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)
int main()
{
	fast;
	int n; cin >> n;
	deque<int> shelf(n);
	for (auto& it : shelf) // storing for all books
		cin >> it;

	priority_queue<int> table;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		if (c == 'L' && shelf.size())
		{
			table.emplace(shelf.front());
			shelf.pop_front();
		}
		else if (c == 'R' && shelf.size())
		{
			table.emplace(shelf.back());
			shelf.pop_back();
		}
		else if (c == 'Q') // Q
		{
			if (table.size())
			{
				cout << table.top() << '\n';
				table.pop();
			}
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}