#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// for the undirected graphs
void MatrixRepDirected(vector<vector<int>> &graph, int src, int dest, int weight)
{
	// if working 0 based and the src and dest are sent 1 based
	// comment them if we are working both 0 based
	src--;
	dest--;
	graph[src][dest] = graph[dest][src] = weight;
}

// for directed graphs
void MatrixRepUndirected(vector<vector<int>> &graph, int src, int dest, int weight)
{
	// if working 0 based and the src and dest are sent 1 based
	// comment them if we are working both 0 based
	src--;
	dest--;
	graph[src][dest] = weight;
}

void AdjListRepUnDirected(vector<vector<pair<int, int>>> &graph, int src, int dest, int w)
{
	graph[src - 1].push_back({dest, w});
	graph[dest - 1].push_back({src, w});
}

void AdjListRepDirected(vector<vector<pair<int, int>>> &graph, int src, int dest, int w)
{
	graph[src - 1].push_back({dest, w});
}

void PrintTheGraphAsMatrix(int N, const vector<vector<int>> &graph)
{
	// printing the graph as matrix
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << graph[i][j] << ' ';
		cout << endl;
	}
}

void PrintingTheGraphAsList(int &N, const vector<vector<pair<int, int>>> &AdjListGraph)
{

	// print the graph as a list
	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << ": ";

		// aw mmkn ne3mlhom hena brdo
		// el outdegrees homa el size bta3 el adj list
		// outDegrees[i] = AdjListGraph[i].size();
		for (auto it : AdjListGraph[i])
		{
			cout << "(" << it.first-- << ", " << it.second << "), ";
			// w el indegrees h3rfha mn gowa
			// InDegrees[it.first] ++;
		}
		cout << '\n';
	}
}

void PrintingTheOutDegreesAndInDegrees(int &N, const vector<int> &outDegrees, const vector<int> &InDegrees)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Out degrees of " << i + 1 << " is " << outDegrees[i];
		cout << "In degrees of " << i + 1 << " is " << InDegrees[i];
		cout << '\n';
	}
}

void matrixRep2()
{
	cout << "enter the number of nodes in the graph: ";
	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1));

	cout << "enter the number of edges: ";
	int edges;
	cin >> edges;
	for (int i = 0; i < edges; i++)
	{
		int u, v;
		cin >> u >> v;
		// directed 1 based unweighter
		graph[u][v] = 1;

		// undirected
		graph[v][u] = 1;
	}

	PrintTheGraphAsMatrix(n + 1, graph);
}

void ListRep()
{
	cout << "enter the number of nodes in the graph: ";
	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1);

	cout << "enter the number of edges: ";
	int edges;
	cin >> edges;
	for (int i = 0; i < edges; i++)
	{
		int u, v;
		cin >> u >> v;
		// directed 1 based unweighter
		graph[u].push_back(v);

		// undirected
		graph[v].push_back(v);
	}

	for (auto it : graph)
	{
		for (auto it2 : it)
			cout << it2 << ' ';
		cout << '\n';
	}
}

int main()
{
	//{
	//	int N; cin >> N;
	//	vector<int> outDegrees(N); /// number of edges coming out from certain node
	//	vector<int> InDegrees(N); /// number of edges coming into certain node
	//
	//	// creating the graph for matrix
	//	vector<vector<int>> graph(N, vector<int>(N));
	//
	//	// for list         node + weight
	//	vector < vector<pair<int, int >>> AdjListGraph(N);
	//
	//	// reading the data
	//	for (int i = 0; i < (N * (N - 1)); i++) // with Directed we loop till N * N -1 , while with undirected we loop till N * (N - 1) / 2 -> for complete graph
	//	{
	//		int src, dest, w;
	//		cin >> src >> dest >> w;
	//		MatrixRepUndirected(graph, src, dest, w);
	//		AdjListRepDirected(AdjListGraph, src, dest, w);
	//
	//		// mmkn n3ml el outdegree hena w el indegree hena brdu
	//
	//		// src has a new out edge
	//		++outDegrees[src];
	//		// the dest has a new in edge
	//		++InDegrees[dest];
	//	}

	ListRep();
	// cout << N;
	return 0;
}