#include <bits/stdc++.h>
using namespace std;

void printingTheDistances(const vector<pair<int,int>> &Dists,int src) {
	int cntr = 1;
	for (auto D : Dists) {
		if (D.first == INT_MAX)
			D.first = -1;
		cout << "\nThe Distance of node " << cntr << " from the node " << src << " is " << D.first;
		cout << "\nand the parent of the node " << cntr << " is " << D.second + 1;
		cntr++;
	}

}
vector<pair<int,int>> initializeSourceNode(int size, int source) {
	// zero based
	// first is the distance the second is the parent 
	vector<pair<int, int>> Dists(size, { INT_MAX , NULL});

	Dists[source - 1] = {0, NULL};

	return Dists;
}

bool relax(int src, int dest, int weight, vector<pair<int,int>> & Dists) {
	int srcDist = Dists[src].first; 
	int destDist = Dists[dest].first; 
	if (srcDist + weight < destDist && srcDist != INT_MAX) {
		Dists[dest].first = srcDist + weight; 
		Dists[dest].second = src;
		return true; 
	}

	return false; 
}

vector<vector<pair<int,int>>> ReadingTheGraph(int & src, int & noOfEdges, int& noOfNodes) {
	cout << "Enter number of nodes: "; 
	cin >> noOfNodes;
	cout << "Enter number of Edges: "; 
	cin >> noOfEdges;
	cout << "Directed (Y/N): ";
	char c; cin >> c;
	cout << "Enter the number of the source node: ";
	cin >> src;
	bool directed; 	if (c == 'Y' || c == 'y')
		directed = true;
	else
		directed = false;

	//zero based 
	cout << "Enter the edges between the nodes in this form\n"; 
	cout << "Src dest weight\n"; 
	vector<vector<pair<int, int>>> G(noOfNodes); 
	for (int i = 0; i < noOfEdges; i++) {
		int u, v, w; cin >> u >> v >> w; 
		u--; v--;
		G[u].push_back({ v , w }); 
		if(!directed)
			G[v].push_back({ u , w }); 
	}

	return G;
}
bool BellmansFord() {
	//read the graph 
	int src, noOfEdges, noOfNodes; 
	vector<vector<pair<int, int>>> G = ReadingTheGraph(src, noOfEdges, noOfNodes);
	//initialize the source 
	vector<pair<int,int>> Dists = initializeSourceNode(noOfNodes, src); 
	// iterate over all the edges - 1 
	//relax all of them 
	for (int i = 0; i < noOfEdges - 1; i++) {
		for (int j = 0; j < noOfNodes; j++) {
			for (auto node : G[j])
				relax(j, node.first, node.second, Dists);
		}
	}

	// iterate another time 
		//check if there are any changes 
			// if yes then return that there are negative cycles 
	for (int j = 0; j < noOfNodes; j++) {
		for (auto node : G[j])
			if (relax(j, node.first, node.second, Dists))
				return false;
	}
	// else return the Dists 
	printingTheDistances(Dists,src);
	return true;
}

void diAlgo(const vector<vector<pair<int, int>>>& G, vector<pair<int, int>>& Dists,  pair<int, int> src, vector<bool>& black, vector<bool>& grey) {
	priority_queue <pair<int, int>> pq;
	pq.push(src);
	grey[src.second] = true; 
	while (pq.size()) {
		int sz = pq.size(); 
		while (sz--) {
			int srcNode = pq.top().second;
			pq.pop(); 
			grey[srcNode] = false;
			for (auto& node : G[srcNode]) {
				int destNode = node.first; 
				int edgeWeight= node.second; 
				relax(srcNode, destNode, edgeWeight, Dists); 
				if (!grey[destNode] && !black[destNode]) {
					pq.push({ Dists[destNode].first, destNode }); 
					grey[destNode] = true; 
				}
			}
			black[srcNode] = true; 
		}
	}

}

void Dijekstra() {
	//read the graph 
	int src, noOfEdges, noOfNodes;
	vector<vector<pair<int, int>>> G = ReadingTheGraph(src, noOfEdges, noOfNodes);
	//initialize the source 
	vector<pair<int, int>> Dists = initializeSourceNode(noOfNodes, src);
	// iterate over all the edges - 1 
	//relax all of them 
	for (int i = 0; i < noOfEdges - 1; i++) {
		for (int j = 0; j < noOfNodes; j++) {
			for (auto node : G[j])
				relax(j, node.first, node.second, Dists);
		}
	}

	vector<bool> grey(noOfNodes);
	vector<bool> black(noOfNodes);
	diAlgo(G, Dists, { 0,src }, black, grey);
	printingTheDistances(Dists, src);
}

int main() {
	Dijekstra();
}