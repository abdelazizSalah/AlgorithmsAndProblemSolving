#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

struct node
{
	short color = 1;//0 black , 1 white , 2 grey
	int idx;
	//node* next;
	node* parent = nullptr;
	node* tail;
	int s; // start time
	int f; //finish time
	node(int idx)
	{
		this->idx = idx;
	}

};

void get_tail(node*& head)
{
	if (head->tail)
		while (head->tail)
			head = head->tail;
}

void print_graph(vector<node*>& graph)
{
	for (auto it : graph)
	{
		auto dum = it;
		while (dum->tail)
		{
			cout << dum->idx << '-';
			dum = dum->tail;
		}
		cout << dum->idx << '\n';
	}
}
stack<int> TSort;

void DFS_VISIT(vector<node*>& graph, node*& vertex, int& time)
{
	time += 1;
	vertex->s = time; // set start time
	vertex->color = 2; // set color to grey
	auto dum = vertex;
	while (dum)
	{
		dum = dum->tail;
		if (dum) // not null
		{
			if (dum->color == 1) // white
			{
				dum->parent = vertex;
				DFS_VISIT(graph, dum, time);
			}
		}
	}
	vertex->color = 0; // color black
	vertex->f = ++time;
	TSort.push(vertex->idx);
}

void DFS(vector<node*>& graph)
{
	int time = 0;
	for (auto& u : graph)
		if (u->color == 1)
			DFS_VISIT(graph, u, time);
}
void solve()
{
	//reading input
	int n; cin >> n;
	vector<node*> graph(n);
	for (int i = 0; i < n; i++)
	{
		graph[i] = new node(i);
		graph[i]->tail = nullptr;
	}


	for (int i = 0; i < n; i++)
	{
		int pre1, pre2; cin >> pre1 >> pre2;
		node* dum;
		if (pre1 != -1)
		{
			dum = graph[pre1];
			get_tail(dum);
			dum->tail = new node(i);
			dum->tail->tail = nullptr;
			//dum = graph[pre1];
			//get_tail(dum);
			//dum->tail = new node(graph[i]->idx);
			//dum->tail->tail = nullptr;
		}
		if (pre2 != -1)
		{
			dum = graph[pre2];
			get_tail(dum);
			dum->tail = new node(i);
			dum->tail->tail = nullptr;
			//dum= graph[pre2];
			//get_tail(dum);
			//dum->tail =new node(graph[i]->idx);
			//dum->tail->tail = nullptr;
		}
	}
	print_graph(graph);
	/*
	DFS(graph);
	while (TSort.size())
	{
		cout << TSort.top();
		TSort.pop();
	}
	return;*/
	//print_graph(graph); 
}

int main()
{
	fast;
	solve();
	return 0;
}