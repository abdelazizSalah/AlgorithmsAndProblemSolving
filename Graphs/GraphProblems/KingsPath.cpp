/**
* @author Abdelaziz Salah 
* 
* @rate 1800 
* 
* @Accepted from the first time
*/
//#include <bits/stdc++.h>
//using namespace std;
//// el fast de m3naha eno myhtmsh eno y3ml synchronization m3 7agat el c fbt5ly el reading asr3
//#define fast ios_base ::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
//// Complexity O(V + E) -> get the shortest path for all nodes from certain vertex
//void SSSPUsingBFSforList(map<pair<int, int>, vector<pair<int, int>>>& graph, queue<pair<int, int>>& Q, pair<int, int> src, map<pair<int, int>, bool>& grey, map<pair<int, int>, bool>& black, int dist, map<pair<int, int >, int>& Dists)
//{
//	//iterate over all its neighbours 
//	for (auto it : graph[src])
//		//if there is an egde and not visited before 
//		if (!grey[it] && !black[it])
//		{
//			//push it in the queue
//			Q.push(it);
//
//			//mark it as grey
//			grey[it] = true;
//
//			//count the dist
//			Dists[it] = dist;
//		}
//
//	//mark that vertex as finished 
//	if (!black[src])
//	{
//		grey[src] = false;
//		black[src] = true;
//	}
//
//	//iterate over the Q and get the next node 
//	while (Q.size())
//	{
//		//get the node which has the turn
//		auto node = Q.front();
//
//		//mark it out from the grey 
//		Q.pop();
//		grey[node] = false;
//
//		//call the BFS on it
//		SSSPUsingBFSforList(graph, Q, node, grey, black, Dists[node] + 1, Dists);
//	}
//}
//
//void isThereIsAPath(pair<int, int> src, pair<int, int> dest, map<pair<int, int>, vector<pair<int, int>>>& graph, queue<pair<int, int>>& Q, map<pair<int, int>, bool>& grey, map<pair<int, int>, bool>& black, int dist, map<pair<int, int>, int>& Dists)
//{
//	//set the distance from my self = 0
//	Dists[src] = 0;
//
//	//calling the single source shortest path
//	SSSPUsingBFSforList(graph, Q, src, grey, black, dist, Dists);
//
//	//if there is a path 
//	if (Dists[dest])
//		cout << Dists[dest]; // print it 
//	else
//		cout << -1; // there is no path
//}
//
////               u, d, l, r, lu, ld, ru, rd
//vector<int> Ydir{ 0, 0, -1, 1, -1, -1, 1, 1 };
//vector<int> Xdir{ -1, 1, 0, 0, -1, 1, -1, 1 };
//
//bool validDir(int x, int y)
//{
//	return x >= 0 && y >= 0 && x < 1e9 && y < 1e9;
//}
//
//int main()
//{
//	// reading the data
//	pair <int, int> src;
//	cin >> src.first >> src.second;
//
//	pair <int, int> dest;
//	cin >> dest.first >> dest.second;
//
//	//creating utility structures to help me
//	map<pair<int, int>, bool> availabeCells;
//	map<pair<int, int>, vector<pair<int, int>>>graph;
//	queue<pair<int, int>> Q;
//	map<pair<int, int>, bool>grey;
//	map<pair<int, int>, bool>black;
//	map<pair<int, int>, int> Dists;
//	int dist = 1;
//
//	//reading the number of segments
//	int n; cin >> n;
//
//	//creating the graph
//	while (n--)
//	{
//		int r; cin >> r;
//		int st, end; cin >> st >> end;
//		for (int i = st; i <= end; i++)
//		{
//			availabeCells[{r, i}] = true;
//			grey[{r, i}] = false;
//			black[{r, i}] = false;
//		}
//	}
//
//	//               u, d, l, r, lu, ld, ru, rd
//	//building the edges 
//	for (auto it : availabeCells)
//		if (it.second)
//			for (int i = 0; i < 8; i++) // iterating over the 8 directions
//			{
//				int xaxis = it.first.first + Xdir[i];
//				int yaxis = it.first.second + Ydir[i];
//				if (validDir(xaxis, yaxis) && availabeCells[{xaxis, yaxis}])
//					graph[it.first].push_back({ xaxis,yaxis });
//			}
//
//	isThereIsAPath(src, dest, graph, Q, grey, black, dist, Dists);
//}