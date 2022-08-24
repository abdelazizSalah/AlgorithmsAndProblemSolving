#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
vector<vector<int>> graph;
vector<bool> vis;

stack<int> TopSort;

void DFS_visit(int x)
{
	vis[x] = 1;
	for (auto& it : graph[x]) // neighbours
		if (!vis[it])
			DFS_visit(it);
	TopSort.push(x);
}

void DFS();

void solve()
{
	int n; cin >> n;
	vis = vector<bool>(n);
	graph = vector<vector<int>>(n); // to determine the size 
	//reading graph
	for (int i = 0; i < n; i++)
	{
		int pre1, pre2; cin >> pre1 >> pre2;
		if (pre1 != -1)
			graph[pre1].push_back(i);

		if (pre2 != -1)
			graph[pre2].push_back(i);
	}
	DFS();
	while (TopSort.size())
	{
		cout << TopSort.top() << ' ';
		TopSort.pop();
	}
}

int main()
{
	fast;
	int t = 1;
	//cin >> t
	//while(t--)
	solve();
	return 0;
}

void DFS()
{
	for (int i = 0; i < graph.size(); i++)
		if (!vis[i])
			DFS();
}
