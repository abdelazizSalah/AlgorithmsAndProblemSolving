#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using ll = long long;
using namespace std;
// #pragma GCC optimize("O3", "unroll-loops")

void DSR (const vector<vector<int>> &G , const int & dest, vector<bool>& vis, map<int,vector<int>>& memo, vector<int> currentPath, int src) {
    /// base cases;  
    if (src == dest)
        return ;
    if (vis[src]) { 
        /// then it must be in the memo 
        /// so we just need to take the minimum path
        /// minimizing on 2 factors. 
        /// 1. shorter length
        /// 2. smaller in lexographical order 
        
        /// this is because I do not insert the neighbour in the path before the call
        currentPath.push_back(src); 

        int prevPathLen = memo[src].size();  
        int currentPathLen = currentPath.size();  
        if (prevPathLen == currentPathLen) { 
            /// so we need to compare them lexographically
            vector<int> prevPath = memo[src]; 
            bool prevIsSmaller = lexicographical_compare(prevPath.begin(), prevPath.end(), currentPath.begin(), currentPath.end());
            if (!prevIsSmaller) { 
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

        } else if (prevPathLen > currentPathLen) { 
            memo[src] = currentPath ;
        }
        /// the previous path was shorter, so keep it.
        return ;
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


int main () { 
    vector<int> v1 = {11, 20, 3}; 
    vector<int> v2 = {1, 20, 3};
    cout <<  lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
    // DPSolver; 
    // // 1. reading the graph in list format
    // vector<vector<int>> G = readingGraph(); 
    // // printGraph(G); 

    // // 2. store the source and the destination
    // int src, dest; 
    // cin >> src >> dest; 

    // /// 3. create a visited array to mark the previously visited nodes.
    // vector<bool> vis (G.size()); 

    // /// 4. create an empty string which contains the path 
    // vector<int> path; 

    // /// 5. create a map which contains the current path
    // map<int, vector<int>> memo; 
    // // memo[src] = vector<int>(); 

    // /// 6. apply dfs from the source
    // DSR(G, dest, vis, memo, path, src);

    // /// 7. print the result
    // printResult(memo, G.size());   

    return 0; 
}