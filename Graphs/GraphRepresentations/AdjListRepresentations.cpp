#include <bits/stdc++.h>
using namespace std;

// for the undirected graphs
void creatingMatrixRepresentationForTheGraph(vector<vector<int>> &graph, int src, int dest, int weight)
{
	// if working 0 based and the src and dest are sent 1 based
	// comment them if we are working both 0 based
	src--;
	dest--;
	graph[src][dest] = graph[dest][src] = weight;
}

// for directed graphs 
void creatingMatrixRepresentationForTheGraphDirected(vector<vector<int>>& graph, int src, int dest, int weight)
{
	// if working 0 based and the src and dest are sent 1 based
	// comment them if we are working both 0 based
	src--;
	dest--;
	graph[src][dest] = weight;
}

int main()
{
	int N; cin >> N;
	// creating the graph
	vector<vector<int>> graph(N, vector<int>(N));

	// reading the data
	for (int i = 0; i < (N * (N-1)) ; i++) // with Directed we loop till N * N -1 , while with undirected we loop till N * (N - 1) / 2
	{
		int src, dest, w;
		cin >> src >> dest >> w;
		creatingMatrixRepresentationForTheGraphDirected(graph, src, dest, w);

	}

	//cout << N;
	// printing the graph
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << graph[i][j] << ' ';
		cout << endl;
	}
	return 0;
}