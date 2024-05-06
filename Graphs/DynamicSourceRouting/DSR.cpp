#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using ll = long long;
using namespace std;
// #pragma GCC optimize("O3", "unroll-loops")
/*
    Solve on this case: 
    7 7
    1 3
    3 4
    1 2
    2 5
    5 6
    4 6
    6 7
    1 7
*/


/// we can not solve it DFS. 
void DSR (const vector<vector<int>> &G , const int & dest, vector<bool>& vis, map<int,vector<int>>& memo, vector<int> currentPath, int src) {
    /// base cases;  
    if (src == dest)
        return ;

    if (!memo[src].empty()) { 
        /// then it must be in the memo 
        /// so we just need to take the minimum path
        /// minimizing on 2 factors. 
        /// 1. shorter length
        /// 2. smaller in lexographical order 
        
        /// this is because I do not insert the neighbour in the path before the call
     

        int prevPathLen = memo[src].size();  
        int currentPathLen = currentPath.size();  
        if (prevPathLen == currentPathLen) { 
            /// so we need to compare them lexographically
            vector<int> prevPath = memo[src]; 
            bool currentIsSmaller = lexicographical_compare(currentPath.begin(), currentPath.end(), prevPath.begin(), prevPath.end());
            if (currentIsSmaller) { 
                /// the current is smaller 
                memo[src] = currentPath; 
            } 
            // for (int i = 0 ; i < prevPathLen; i++) { 
            //     if (currentPath[i] < prevPath[i]){ // compare the ids of the nodes
            //         // currentPath.push_back(src);
            //         memo[src] = currentPath; 
            //         return; 
            //     } else if (prevPath[i] < currentPath[i]){ 
            //         return;
            //     }
            //     /// in case they are equal, just continue.
            // }
            // memo[src] = min(path, memo[src]); /// heya de el 3amla el mushkela, lw galak 7agat 11 w 15 w bta3, httl3 ghlt azun

        } else if (prevPathLen > currentPathLen + 1) { 
            currentPath.push_back(src); 
            memo[src] = currentPath ;
        }
        /// the previous path was shorter, so keep it.
        // return ;
    }

    /// mark the node as visited 
    vis[src] = true; 

    /// add the current node to the path
    currentPath.push_back(src);
    memo[src] = currentPath; 

    /// iterate over all the nieghbours; 
    for (int nei : G[src]) { 
        DSR(G, dest, vis, memo, currentPath, nei); 
    }
    // back tracking    
    vis[src] = false; 

}
vector<vector<int>> readingGraph() { 
    int noOfNodes, noOfEdges; 
    cin >> noOfNodes >>  noOfEdges; 
    /// working 1 based
    vector<vector<int>> G(noOfNodes+1); 
    for (int i = 0 ; i < noOfEdges; i ++) { 
        int src, dest; 
        cin >> src >> dest; 
        G[src].push_back(dest); 
        G[dest].push_back(src); 
    }
    return G; 
}
void printGraph(const vector<vector<int>>&G) { 
    int NoOfNodes = G.size(); 
    for (int i = 1; i < NoOfNodes ; i++){
        cout << "neighbours of the node number " << i << " are: {"; 
        for (int nei : G[i])
            cout << nei << ", "; 
        cout << "}\n"; 
    } 
}

void printResult(map<int,vector<int>> &memo, const int& numNodes){ 
    /*
        Iterate over the map, if the element does not exist in the map, print -1, else print the path. 
    */
   for( int i = 1; i < numNodes; i ++) { 
        if (memo[i].size())
            for (int num : memo[i])
                cout << num << ' ' ;  
        else 
            cout << "-1" ; 
        cout << '\n';  
   }
}


void BFS_RREQ(const vector<vector<int>>&G, const int &src, const int &dest,map<int,vector<int>> &memo){ 
    /// create an empty queue
    queue<int> Q; 
    Q.push(src); 
    
    /// create a bool vector with size = # of nodes. 
    vector<bool>vis(G.size()); 
    /// initialize the memo of the src with the src.
    memo[src] = {src}; 
    /// create a path variable 
    vector<int> path; 
    /// apply bfs
    while(Q.size()) { 
        /// extract the top node 
        int topNode = Q.front(); 
        Q.pop(); 
        /// mark as visited 
        vis[topNode] = true; 
        // /// if this node has a current path, so just get it, else, add
        //// if(memo[topNode].size())
        ////     path = memo[topNode]; 
        //// else 
        //     /// add the top node to the 
        /// get the path of the current node
        path = memo[topNode]; 

        /// iterate over all its neighbours
        for (int nei : G[topNode]) { 
            /// if nei is the dest, skip 
            if (nei == dest)
                continue;
            /// check if this neigbour was inserted in the memo before
            if (memo[nei].size()) { 
                path.push_back(nei); 
                /// check if the length of the current path < previous path 
                if (path.size() < memo[nei].size())
                    memo[nei] = path; 
                else if (path.size() == memo[nei].size()) { 
                    /// get the smallest lexographical vector
                    bool currentIsSmaller = lexicographical_compare(path.begin(), path.end(), memo[nei].begin(),memo[nei].end()); 
                    if (currentIsSmaller)
                        memo[nei] = path; 
                }
                path.pop_back(); 
            } else { 
                /// just append the neibour to the current path, and store it in the memo[nei]
                path.push_back(nei); 
                memo[nei] = path; 
                path.pop_back(); 
            }
            /// if not visited before, insert it in the Queue.
            if (!vis[nei])
                Q.push(nei); 
                vis[nei] = true; 
        }
    }
}

int main () { 
    DPSolver; 
    // 1. reading the graph in list format
    vector<vector<int>> G = readingGraph(); 
    // printGraph(G); 

    // 2. store the source and the destination
    int src, dest; 
    cin >> src >> dest; 

    /// 3. create a visited array to mark the previously visited nodes.
    vector<bool> vis (G.size()); 

    /// 4. create an empty string which contains the path 
    vector<int> path; 

    /// 5. create a map which contains the current path
    map<int, vector<int>> memo; 
    // memo[src] = vector<int>(); 

    /// 6. apply dfs from the source
    // DSR(G, dest, vis, memo, path, src);

    /// 6. apply bfs from the source 
    BFS_RREQ(G, src, dest, memo); 

    /// 7. print the result
    printResult(memo, G.size());   

    return 0; 
}