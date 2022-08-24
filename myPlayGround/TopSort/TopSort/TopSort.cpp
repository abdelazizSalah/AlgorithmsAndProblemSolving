#include<bits/stdc++.h>
using namespace std; 
#define fast ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)	
stack<int> STOP; 

void DFS_Visit(vector<vector<int>>& Graph, vector<pair<int, pair<int , int>>>& whiteGreyAndBlack, int x, int time)
{
	time += 1; 
	//set from white to grey
	whiteGreyAndBlack[x].first = 0;
	whiteGreyAndBlack[x].second.first = 1; // set grey
	for (auto& v : Graph[x])// neighbours of X
		if (whiteGreyAndBlack[x].first)// if white
			DFS_Visit(Graph, whiteGreyAndBlack, v, time);
	whiteGreyAndBlack[x].second.first = 0;
	whiteGreyAndBlack[x].second.second = 1; // set black
	STOP.push(x);
}

void DFS(vector<vector<int>>& Graph, vector<pair<int,pair<int, int>>>& WhiteGreyAndBlack)
{
	// all white
	for (auto& u : WhiteGreyAndBlack)
		u.first = 1;

	int time = 0;
	for (auto& it : Graph)
		for (auto& it2 : it) // homa dol el adjacent
			if (WhiteGreyAndBlack[it2].first) // white
				DFS_Visit(Graph, WhiteGreyAndBlack, it2, time);
}
void solve()
{
	int n; cin >> n; 
	vector<vector<int>> graph(n);
	vector<pair<int,pair<int,int>>>vis(n);// white grey black
	for (int i = 0; i < n; i++)
	{
		int pre1, pre2; cin >> pre1 >> pre2;
		if (pre1 != -1)
			graph[pre1].push_back(i);
		if (pre2 != -1)
			graph[pre2].push_back(i);
	}
	//reading graph
	for (auto& it : graph)
	{
		for (auto& it2 : it)
			cout << it2 << ' ';
		cout << '\n';
	}
	DFS(graph, vis);

	while (STOP.size())
	{
		cout << STOP.top() << ' ';
		STOP.pop(); 
	}
}

int main()
{
	fast;
	solve(); 
	return 0;
}