//#include <bits/stdc++.h>
//using namespace std;
//
///// <summary>
///// //////////////
///// DFS is good for counting the number of components 
///// 
///// also good for finding a path between a node and another one 
///// 
///// it can compute the Graph minimum spanning tree 
///// 
///// and it can detect wethere there are any cycles in the graph or not
///// 
///// can help in the topological sort 
///// 
///// and it can find the bridges and articulation points 
//
//// complexity O(V^2) -> O(V + E)
//void DFSForMatRep(vector<vector<int>>& graph, vector<bool>& vis, int vertex) {
//
//	for (int i = 0; i < graph[vertex].size(); i++)
//		// keda ana b3ml el traversal depending 3la asghar rakam el awl, 1 ,2  ,3 ,4 ,5 and so on. 
//		if (graph[vertex][i] == 1) // depth first -> go into it
//			// if it is a neighbour -> check that it is not visited before
//			if (!vis[i])
//			{
//				cout << i + 1 << ' ';
//				vis[i] = true;
//				DFSForMatRep(graph, vis, i);
//			}
//}
//
//void PrintingTheGraphAsMatrix(const vector<vector<int>>& graph, const int& N)
//{
//	//printing the graph
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//			cout << graph[i][j] << ' ';
//		cout << '\n';
//	}
//}
//
//void CreatingTheDFSAsMAtrix(vector<vector<int>>& graph, int N, vector <bool>& vis)
//{
//	/// b3ml iteration 3la kol el nodes w ashof el lesa mtzarsh bzoro
//	for (int i = 0; i < N; i++)
//		if (!vis[i])
//		{
//			vis[i] = true;
//			cout << i + 1 << ' ';
//			DFSForMatRep(graph, vis, i);
//		}
//}
//
//
//// printing the small value always first 
//// complexity O(V + E) -> better for sparse graphs 
//void DFSForListRep(vector<vector<int>>& graph, int vertex, vector <bool>& vis)
//{
//	for (int i = 0; i < graph[vertex].size(); i++)
//		if (!vis[graph[vertex][i]])
//		{
//			vis[graph[vertex][i]] = true;
//			//cout << graph[vertex][i] + 1 << ' ';
//			DFSForListRep(graph, graph[vertex][i], vis);
//		}
//}
//
//void CreatingDFSAsList(vector<vector<int>>& graph, int N, vector <bool>& vis)
//{
//	// b3dy 3la kol el nodes wl lesa m4 vis bzorha
//	for (int i = 0; i < N; i++)
//		if (!vis[i])
//		{
//			vis[i] = true;
//			cout << i + 1 << ' ';
//			DFSForListRep(graph, i, vis);
//		}
//}
//
//
//int NumberOfConnectedComponentsusingMat(vector<vector<int>>& graph, int N, vector<bool>& vis)
//{
//	int cntr = 0;
//	for (int i = 0; i < N; i++)
//		if (!vis[i])
//		{
//			cntr++;
//			DFSForMatRep(graph, vis, i);
//		}
//	return cntr;
//}
//
//// we have here a problem 
//int NumberOfConnectedComponentsusingList(vector<vector<int>>& graph, int N, vector<bool>& vis)
//{
//	int cntr = 0;
//	for (int i = 0; i < N; i++)
//		if (!vis[i])
//		{
//			cntr++;
//			DFSForListRep(graph, i, vis);
//		}
//	return cntr;
//}
//
///// <summary>
///// /
///// </summary>
///// <returns></returns>
///// 
///// 
///// BFS Algo
//void BFSForMatrix(vector<vector<int>>& graph, queue<int>& Q, int vrtx, int N, vector<bool>& grey, vector<bool>& black)
//{
//	//PrintingTheGraphAsMatrix(graph, N); 
//	for (int i = 0; i < N; i++)
//		if (graph[vrtx][i]) // if there is a connection
//			if (!grey[i] && !black[i]) // if this node is not visited before and not in the queue
//			{
//				Q.push(i);
//				grey[i] = true; // mark that it is inside the queue
//			}
//
//	if (!black[vrtx]) // if not visited before
//	{
//		black[vrtx] = true; //finished
//		cout << vrtx + 1 << " ";
//	}
//	if (Q.size())
//	{
//		int vx = Q.front();
//		Q.pop();
//		grey[vrtx] = false; // out from the queue
//		BFSForMatrix(graph, Q, vx, N, grey, black);
//	}
//}
//
//void BFSCallForMat(vector<vector<int>>& graph, vector<bool>& black, vector<bool>& grey, int N)
//{
//	queue<int> Q;
//	for (int i = 0; i < N; i++)
//		if (!black[i]) // act as black 
//			BFSForMatrix(graph, Q, i, N, grey, black);
//}
//
//
////bfs in the iterative version -> list rep
//void bfs(int n, const vector<vector<int>>& graph, vector<bool>& vis)
//{
//	queue<int> Q;
//	int lvl = 0;
//	Q.push(n);
//	while (Q.size())
//	{
//		int sz = Q.size();
//		while (sz--)
//		{
//			int node = Q.front();
//			Q.pop();
//			for (auto g : graph[node])
//			{
//				if (!vis[g])
//				{
//					Q.push(g);
//					vis[g] = true;
//				}
//			}
//		}
//
//		lvl++;
//	}
//}
//
//// grey is for the Queue check
//void BFSForList(vector<vector<int>>& graph, queue<int>& Q, int vrtx, vector<bool>& grey, vector<bool>& black)
//{
//	// iterate over all neighbours and put them in the queue
//	for (int i = 0; i < graph[vrtx].size(); i++)
//		if (!black[graph[vrtx][i]] && !grey[graph[vrtx][i]]) // not in the queue and not done
//		{
//			// insert it into the queue
//			Q.push(graph[vrtx][i]);
//
//			// mark that it is inside the queue
//			grey[graph[vrtx][i]] = true;
//		}
//
//	// after inserting all neighbours print the vertex 
//	if (!black[vrtx])
//	{
//		black[vrtx] = true;
//		cout << vrtx + 1 << ' ';
//	}
//
//	while (Q.size())
//	{
//		// get the first element from the queue
//		int vx = Q.front();
//
//		//get the element out from the queue
//		Q.pop();
//
//		// mark it out from the queue
//		grey[vx] = false;
//
//		//send it to the bfs
//		BFSForList(graph, Q, vx, grey, black);
//	}
//}
//
//// Complexity O(V + E) -> get the shortest path for all nodes from certain vertex
//void SSSPUsingBFSforList(vector<vector<int>>& graph, queue<int>& Q, int vrtx, int N, vector<bool>& grey, vector<bool>& black, int dist, vector<int>& Dists)
//{
//	for (int i = 0; i < graph[vrtx].size(); i++)
//		if (!black[graph[vrtx][i]] && !grey[graph[vrtx][i]]) // not in the queue and not done
//		{
//			// insert it into the queue
//			Q.push(graph[vrtx][i]);
//
//			// mark that it is inside the queue
//			grey[graph[vrtx][i]] = true;
//
//			//set the dist 
//			Dists[graph[vrtx][i]] = dist;
//		}
//
//	// after inserting all neighbours print the vertex 
//	if (!black[vrtx])
//	{
//		black[vrtx] = true;
//		cout << vrtx + 1 << ' ';
//	}
//
//	while (Q.size())
//	{
//		// get the first element from the queue
//		int vx = Q.front();
//
//		// get the element out from the queue
//		Q.pop();
//
//		// mark it out from the queue
//		grey[vx] = false;
//
//		// send it to the bfs 
//		SSSPUsingBFSforList(graph, Q, vx, N, grey, black, Dists[vx] + 1, Dists);
//	}
//}
//
//// Complexity O(V + E)
//void SSSPUsingBFSAndMat(vector<vector<int>>& graph, queue<int>& Q, int vrtx, int N, vector<bool>& grey, vector<bool>& black, int dist, vector<int>& Dists)
//{
//	for (int i = 0; i < N; i++)
//		if (graph[vrtx][i]) // if there is a relation 
//			if (!black[i] && !grey[i]) // not in the queue and not done
//			{
//				// insert it into the queue
//				Q.push(i);
//
//				// mark that it is inside the queue
//				grey[i] = true;
//
//				//set the dist 
//				Dists[i] = dist;
//			}
//
//	// after inserting all neighbours print the vertex 
//	if (!black[vrtx])
//	{
//		black[vrtx] = true;
//		cout << vrtx + 1 << ' ';
//	}
//
//	while (Q.size())
//	{
//		// get the first element from the queue
//		int vx = Q.front();
//
//		// get the element out from the queue
//		Q.pop();
//
//		// mark it out from the queue
//		grey[vx] = false;
//
//		// send it to the bfs 
//		SSSPUsingBFSAndMat(graph, Q, vx, N, grey, black, Dists[vx] + 1, Dists);
//	}
//}
//
//bool isThereIsAPath(int src, int dest, vector<vector<int>>& graph, queue<int>& Q, int vrtx, int N, vector<bool>& grey, vector<bool>& black, int dist, vector<int>& Dists)
//{
//	Dists[src] = 0; // mark the distance from the vertex = 0
//	SSSPUsingBFSAndMat(graph, Q, src, N, grey, black, 1, Dists);
//	return Dists[dest] == -1 ? false : true;
//}
//
//int main()
//{
//	int N; cin >> N;
//	vector<vector<int>> graph(N, vector<int>(N));
//	vector<vector<int>> graphList(N);
//	int viscntr = 0;
//
//	// reading the data of the graph and creating the matrix -> undirected 
//	int numberOfPairs; cin >> numberOfPairs;
//	for (int i = 0; i < numberOfPairs; i++)
//	{
//
//		int x, y; cin >> x >> y;
//
//		//for representing it as a matrix
//		graph[--x][--y] = 1;
//		graph[y][x] = 1;
//
//		// for representing it as a list
//		graphList[x].push_back(y);
//		graphList[y].push_back(x);
//	}
//
//	//visited arrays
//	vector<bool>vis(N); // act as grey for BFS
//	vector<bool>visList(N); // act as Black for BFS
//
//	//CreatingTheDFSAsMAtrix(graph, N, vis);
//	//CreatingDFSAsList(graphList, N, vis);
//	//cout << "\nThe number of Components = " << NumberOfConnectedComponentsusingMat(graph, N, vis);
//	//cout << "\nThe number of Components = " << NumberOfConnectedComponentsusingList(graphList, N, vis);
//	//BFSCallForMat(graph, visList, vis, N); 
//	queue<int> Q;
//
//	// vector to carry all the distances, initializing it by -1 to find if there is no path between certian nodes
//	vector<int>Dists(N, -1);
//	//BFSForList(graphList, Q, 1, N, vis, visList); 
//	//SSSPUsingBFS(graphList, Q, 1, N, vis, visList, 1, Dists);
//
//	//Dists[3] = 0; // mark the distance from the vertex = 0
//	//SSSPUsingBFSAndMat(graph, Q, 3, N, vis, visList, 1, Dists); 
//	//for (int i = 1; i <= N; i++)
//	//	cout << "\ndist from 2 to : " << i << " " << Dists[i - 1];
//
//	//cout << boolalpha << isThereIsAPath(3, 6, graph, Q, 3, N, vis, visList, 1, Dists); 
//
//
//	return 0;
//}
//
//
////with arrays instead of vectors 
//
//// mat rep
//int graph[100][100];
//bool vis[100];
//const int N = 100;
//void DFSMat(int node)
//{
//	if (!vis[node])
//	{
//		vis[node] = true;
//		for (int i = 0; i < N; i++)
//			if (graph[node][i]) // there is a egde between them 
//				DFSMat(graph[node][i]);
//	}
//}
//
//void DFSList(int node)
//{
//	if (!vis[node])
//	{
//		vis[node] = true;
//		for (auto u : graph[node]) // iterating over the neighbours of that node
//			DFSList(u);
//	}
//}
//
//void BFSListIterative(int node)
//{
//	queue<int> Q;
//	Q.push(node);
//	vis[node] = true;
//	int lvl = 0;
//	while (Q.size())
//	{
//		int sz = Q.size();
//		while (sz--)
//		{
//			int n = Q.front();
//			Q.pop();
//			for (auto u : graph[n])
//				if (!vis[u])
//				{
//					Q.push(u);
//					vis[u];
//				}
//		}
//		lvl++;
//	}
//}
//
//void BFSMatrixIterative(int node)
//{
//	queue<int> Q;
//	Q.push(node);
//	vis[node] = true;
//	int lvl = 0;
//	while (Q.size())
//	{
//		int sz = Q.size();
//		while (sz--)
//		{
//			int n = Q.front();
//			Q.pop();
//			for (int i = 0; i < N; i++)
//			{
//				if (graph[n][i])
//				{
//					Q.push(graph[n][i]);
//					vis[graph[n][i]];
//				}
//			}
//		}
//		lvl++;
//	}
//}
//
//
//bool grey[100]; 
//bool black[100]; 
//queue<int> Q; 
//
//void BFSListRec(int node)
//{
//	// iterating over all neighbours
//	for (auto g : graph[node])
//		if (!grey[g] && !black[g]) // not finished and not in the queue
//		{
//			grey[g] = true; 
//			Q.push(g); 
//		}
//
//	// mark that you have finished this node
//	if (!black[node])
//		black[node] = true; 
//
//	
//	// iterating over the elements in the Queue and work on the first element of them
//	while (Q.size())
//	{
//		// get the node which has next turn
//		int nextNode = Q.front();
//
//		// get it out from the queue
//		Q.pop(); 
//
//		//mark as it has get out
//		grey[nextNode] = false; 
//
//		//send it to the BFS
//		BFSListRec(nextNode); 
//	}
//}
//
//// unweighted
//void BFSMatRec(int node)
//{
//	// iterating over all neighbours
//	for (int i = 0 ;i < N ; i++)
//		if (!grey[i] && !black[i] && graph[node][i]) // not finished and not in the queue
//		{
//			grey[i] = true;
//			Q.push(i);
//		}
//
//	// mark that you have finished this node
//	if (!black[node])
//		black[node] = true;
//
//
//	// iterating over the elements in the Queue and work on the first element of them
//	while (Q.size())
//	{
//		// get the node which has next turn
//		int nextNode = Q.front();
//
//		// get it out from the queue
//		Q.pop();
//
//		//mark as it has get out
//		grey[nextNode] = false;
//
//		//send it to the BFS
//		BFSMatRec(nextNode);
//	}
//}