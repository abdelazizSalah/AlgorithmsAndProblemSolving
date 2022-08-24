#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0); 


void PrintDistances(const vector<pair<int,int>>& table) {
	int cntr = 0;
	//O(V)
	for (auto& it : table) {
		if (cntr == 0) { // as I work 1 based 
			cntr++;
			continue;
		}
		//no path from the source to the dest 
		if (it.first == INT_MAX)
			cout << "node number " << cntr++ << " is inreachable from the source.\n";
		else
			cout << "node number " << cntr++ << " is at distance "
			<< it.first << " and its parent is " << it.second << '\n';
	}
}
//solve it recursivly 
void BFSShortestPathesFounder(const vector<vector<int>>& G, queue<int>& Q, vector<bool>& grey, vector<bool>& black, vector<int>& Dists, int dists, int src) {
	//iterate over all neighbours 
	for (auto neigh : G[src]) {
		//check that this node is not in the Q and not Done 
		if (!grey[neigh] && !black[neigh]) {
			// insert it in the Q
			Q.push(neigh);

			//mark it in the grey 
			grey[neigh] = true;

			// count its distance 
			Dists[neigh] = dists + 1;
		}
	}

	//if not marked as finished 
	if (!black[src]) {
		//mark as finished 
		black[src] = true;

		//mark as not in the Q
		grey[src] = false;
	}

	if (Q.size()) {
		//get the first node in the Q
		int node = Q.front();
		Q.pop();

		//mark it out from the Q
		grey[node] = false;

		//apply the BFS on it 
		BFSShortestPathesFounder(G, Q, grey, black, Dists, Dists[node], node);
	}

}


void BFSShortestPathesFounderIterative(const vector<vector<int>>& G, vector<bool>& grey, vector<bool>& black, vector<int>& Dists, int src) {
	//creating the Q
	queue<int> Q;

	//inserting the first element in the Q; 
	Q.push(src);

	// mark it in the grey 
	grey[src] = true;

	//create lvl to count the distance
	int lvl = 0;

	while (Q.size()) {
		int sz = Q.size();
		lvl++;
		while (sz--) {
			//get the element in the front 
			int node = Q.front();
			// get it out from the Q
			Q.pop();
			//mark it out from the grey 
			grey[node] = false;

			//iterate over all its neighbours 
			for (auto neigh : G[node]) {
				//  check that it is not done and not in the Q
				if (!black[neigh] && !grey[neigh]) {
					// insert it in the Q
					Q.push(neigh);

					//mark it as in the Grey
					grey[neigh] = true;

					//count the Distance from the source
					Dists[neigh] = lvl;
				}
			}

			//mark it as finished 
			black[node] = true;
		}
	}
}

vector <int> BFS() {
	int n, e, src;
	cout << "Enter the number of Nodes: ";  cin >> n;
	cout << "Enter the number of Egdes: "; cin >> e;

	//1 based 
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < e; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		//for undirected 
		graph[v].push_back(u);
	}

	cout << "Enter the number of the source: ";
	cin >> src;
	// -1 represents that there is no such a path from the source
	vector<int> Dists(n + 1, -1);
	Dists[src] = 0;

	//utility DS
	vector<bool> grey(n + 1);
	vector<bool> black(n + 1);
	queue<int> Q;

	BFSShortestPathesFounderIterative(graph, grey, black, Dists, src);

	// printing all distances 
	for (auto dis : Dists)
		cout << dis << ' ';
	return Dists;
}


struct Graphnode {
	int parent;
	int dist;
};


void PrintTheGraph(const vector<vector<pair<int, Graphnode>>>& G) {
	int cntr = 1;
	while (cntr <= G.size()) {
		cout << "Node number: " << cntr << " has " << G[cntr].size() << " neighbours Which are: \n";
		for (auto node : G[cntr]) {
			cout << node.first << " and its parent is: " << node.second.parent
				<< " and its shortest Dist is: " << node.second.dist;
		}
		cntr++;
	}
}

vector<vector<pair<int, int>>> ReadingTheGraph(int NumberOfNodes, int NumberOfEdges) {
	vector < vector<pair<int, int>>> G(NumberOfNodes + 1);
	cout << "Enter the edges in this form\nsource Destination weight \n";
	for (int i = 0; i < NumberOfEdges; i++) {
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({ v, w });
	}
	return G;
}


vector<pair<int, int>> InitializationSingleSource(int n, int src) {
	vector<pair<int, int>> table(n + 1, { INT_MAX, NULL });
	table[src].first = 0;
	return table;
}


bool thereIsAChange(const vector<pair<int, int>>& table, int src, int dest, int weight) {
	return table[src].first + weight < table[dest].first;
}
bool relax(vector<pair<int, int>>& table, int src, int dest, int weight) {
	if (thereIsAChange(table, src, dest, weight)) {
		if (table[src].first == INT_MAX)
			return false;
		table[dest].first = table[src].first + weight;
		table[dest].second = src;
		return true;
	}
	return false;
}


//complexity O(VE)
bool BellmanFordAlgo(vector<pair<int, int>>& table, const vector<vector<pair<int, int>>>& G, const int NumberOfEdges, const int src) {
	bool changed = false;
	//to make sure that you have tried all possible edges we iterate with the longest possible number of edges which is a chain  whose length is NumberOfEgdes - 1
	for (int i = 1; i < NumberOfEdges; i++) {
		changed = false; // to skip some use less iterations 
		//iterating over all the nodes in the graph
		for (int srcNode = 1; srcNode < G.size(); srcNode++) {
			//iterating over all its neighbours
			for (auto& node : G[srcNode]) {
				// if can relax changed will be true
				if (relax(table, srcNode, node.first, node.second))
					changed = true;
			}
		}
		// if no change happened so no need to continue 
		if (!changed)
			break;
	}

	if (!changed)
		return true;

	//we need to apply one more run to check wether there is a negativev cycles or not
	for (int srcNode = 1; srcNode < G.size(); srcNode++) {
		for (auto& node : G[srcNode]) {
			if (thereIsAChange(table, srcNode, node.first, node.second))
				return false;
		}
	}

	// if no negative cycles we should return true
	return true;
}


void BellmansFordCall() {
	int noOfNodes, noOfEdges, src;
	cout << "Enter the number of nodes: "; cin >> noOfNodes;
	cout << "Enter the number of edges: "; cin >> noOfEdges;
	cout << "Enter the number of the Source node: "; cin >> src;
	vector<vector<pair<int, int>>> G = ReadingTheGraph(noOfNodes, noOfEdges);
	vector<pair<int, int>> table = InitializationSingleSource(noOfNodes, src);

	bool res = BellmanFordAlgo(table, G, noOfEdges, src);

	int cntr = 1;
	if (!res) cout << "There is a negative Cycle!";
	else
		for (auto it : table) {
			if (it.first == INT_MAX) cout << '\n';
			else
				cout << "node number " << cntr++ << " is at distance "
				<< it.first << " and its parent is " << it.second << '\n';
		}
}

/*
	being dag means that there is no Cycles which means the negative edges will not form any -ve cycles
	being dag also means that we can topological sort them
	also we won't revisit any node again
*/
void topologicalSort(const vector<vector<pair<int, int>>>& G, int vrtx, vector<bool>& vis, stack<int>& myCont) {
	for (auto& node : G[vrtx]) {
		if (!vis[node.first]) {
			vis[node.first] = true;
			topologicalSort(G, node.first, vis, myCont);
			myCont.push(node.first);
		}
	}
}

//Complexity O(V + E)
void DagShortestPath() {
	int noOfNodes, noOfEdges, src;
	cout << "Enter the number of nodes: "; cin >> noOfNodes;
	cout << "Enter the number of edges: "; cin >> noOfEdges;
	vector<vector<pair<int, int>>> G = ReadingTheGraph(noOfNodes, noOfEdges);
	vector<bool> vis(noOfNodes + 1);
	// topological sort the nodes 
	stack<int> topoOrder;
	//O(V)
	for (int i = 1; i <= noOfNodes; i++) {
		if (!vis[i]) {
			vis[i] = true;
			topologicalSort(G, i, vis, topoOrder); // O(V + E)
			topoOrder.push(i);
		}
	}

	// initialize the nodes as the routine 
	cout << "Enter the number of the Source node: "; cin >> src;

	//O(V)
	vector<pair<int, int>> table = InitializationSingleSource(noOfNodes, src);

	// iterate over them and relax the edges
	//O(V)
	while (topoOrder.size()) {
		for (auto& node : G[topoOrder.top()])
			relax(table, topoOrder.top(), node.first, node.second);
		topoOrder.pop();
	}

	int cntr = 0;
	//O(V)
	PrintDistances(table); 
}
/*
	it is the idea as the BFS except that we use a priority Queue instead of the normal Q
*/

void DijekstraAlgoIterative(const vector<vector<pair<int, int>>>& G, vector<pair<int, int>>& Table, vector<bool>& grey, vector<bool>& black, const pair<int, int> src) {
	//create the priority Q which we are going  to use in order to sort the nodes ascendingly according to their distances from the source 
	// the pair is the {distance and the node number}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	//insert the first node in the queue
	pq.push(src);
	//as long as the Q has nodes
	while (pq.size()) {
		//get all the elements in that level and iterate over them 
		int sz = pq.size();
		while (sz--) {
			// get the node with the least distance which is the second in the pair
			int node = pq.top().second;
			// get it out from the Q
			pq.pop();
			//mark it as not grey anymore
			grey[node] = false;
			//iterate over all its neighbours 
			for (auto& it : G[node]) {
				//relax all its edges 
				relax(Table, node, it.first, it.second);
				// if that neighbour has not been in the Q before or now then insert it
				if (!black[it.first] && !grey[it.first]) {
					pq.push({ Table[it.first].first , it.first });
					grey[it.first] = true;
				}
			}
			// mark this node as finished 
			black[node] = true;
		}
	}

	//this algorithm is the same as the BFS 
}


void DijekstraRec(const vector<vector<pair<int, int>>>& G, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> &pq ,vector<pair<int, int>>& Table, vector<bool>& grey, vector<bool>& black, const pair<int, int> src) {
	//iterate over all the neighbours 
	for (auto &node : G[src.second]) {
		relax(Table, src.second, node.first, node.second); 
		if (!black[node.first] && !grey[node.first]) {
			// b3ml push l el distance el ana b3ml sort beha 
			// w el tanya hwa rkm el node
			pq.push({Table[node.first].first, node.first});
			grey[node.first] = true;
		}
	}

	if (!black[src.second]) {
		grey[src.second] = false;
		black[src.second] = true;
	}

	while (pq.size()) {
		// get the minimum node 
		auto node = pq.top(); 
		pq.pop(); 
		//mark it out from the Q
		grey[node.second] = false;
		DijekstraRec(G, pq, Table, grey, black, node);
	}
}
void Dijekstra() {
	int noOfNodes, noOfEdges, src;
	cout << "Enter the number of nodes: "; cin >> noOfNodes;
	cout << "Enter the number of edges: "; cin >> noOfEdges;
	vector<vector<pair<int, int>>> G = ReadingTheGraph(noOfNodes, noOfEdges);

	//initialIze the source 
	cout << "Enter the number of the Source node: "; cin >> src;
	vector<pair<int, int>> table = InitializationSingleSource(noOfNodes, src);

	vector<bool> black(noOfNodes + 1);
	vector<bool> grey(noOfNodes + 1);
	//DijekstraAlgoIterative(G, table, grey, black, { 0 ,src });
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	DijekstraRec(G, pq, table, grey, black, { 0 ,src });

	PrintDistances(table); 
}
int main() {
	fast;
	Dijekstra();
	return 0;
}