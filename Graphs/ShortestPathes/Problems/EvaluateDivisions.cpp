#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ld = long double;
void readingInput(vector<vector<string>> &equations, vector<ld> &values, vector<vector<string>> &queries)
{
    int noOfEquations, noOfQueries;
    cin >> noOfEquations >> noOfQueries;
    equations = vector<vector<string>>(noOfEquations);
    queries = vector<vector<string>>(noOfQueries);
    values = vector<ld>(noOfEquations);
    for (auto &vec : equations)
        cin >> vec[0] >> vec[1];
    for (auto &vec : queries)
        cin >> vec[0] >> vec[1];
    for (auto &vec : values)
        cin >> vec;
}

void removeCommonChars(vector<vector<string>> &equations)
{
    // iterate over the equations and the queries, and check if they have common char in num and den remove them.
    for (auto &eq : equations)
    {
        string first = eq[0];
        string second = eq[1];

        int len1 = eq[0].size();
        int len2 = eq[1].size();
        int mnSize = INT_MAX;
        if (len1 < len2)
        {
            // first string is shorter
            mnSize = len1;
            for (int i = 0; i < mnSize; i++)
                for (int j = 0; j < len2; j++)
                    if (first[i] == second[j])
                        first.erase(i--, 1), second.erase(j--, 1), mnSize--, len2--;
            eq[0] = first;
            eq[1] = second;
        }
        else
        {
            mnSize = len2;
            for (int i = 0; i < mnSize; i++)
                for (int j = 0; j < len1; j++)
                    if (first[j] == second[i])
                        first.erase(j--, 1), second.erase(i--, 1), mnSize--, len1--;

            eq[0] = first;
            eq[1] = second;
        }
    }
}

void preprocessing(vector<vector<string>> &equations, vector<vector<string>> &queries)
{
    removeCommonChars(equations);
    removeCommonChars(queries);

    //? TODO: cover the case of abc/xyz
}

void printGraph(map<string, vector<pair<string, ld>>> &G)
{
    for (auto node : G)
    {
        cout << "neighbours of " << node.first << " are: \n";
        for (auto nei : G[node.first])
            cout << nei.first << ' ' << nei.second << " ----- ";
        cout << endl;
    }
}

map<string, int> alphaNum;
void buildGraph(const vector<vector<string>> &equations, const vector<ld> &values, map<string, vector<pair<string, ld>>> &G)
{
    // G = vector<vector<ld>>(27, vector<ld>(27));
    // building the graph in matrix form.
    // cout << G["ahmed"][0].first;
    int noOfEdges = equations.size();
    for (int j = 0; j < noOfEdges; j++)
    {
        // add yourself if you were not here before.
        if (!G[equations[j][0]].size())
            G[equations[j][0]].push_back({equations[j][0], 1}); // A / A = 1
        if (!G[equations[j][1]].size())
            G[equations[j][1]].push_back({equations[j][1], 1});         // B / B = 1
        G[equations[j][0]].push_back({equations[j][1], values[j]});     // A / B
        G[equations[j][1]].push_back({equations[j][0], 1 / values[j]}); // B / A
    }
    printGraph(G);
}

ld roundToNdecimalPlaces(ld num, int places)
{
    int mult = 1;
    for (int i = 0; i < places; i++)
        mult *= 10;
    num = round(num * mult);
    num /= mult;
    return num;
}

void initializeSource(string src, map<string, vector<pair<string, ld>>> &G, map<string, ld> &dist)
{
    // iterate over all nodes in the graph
    for (auto node : G)
    {
        dist[node.first] = INT_MAX;
    }
    dist[src] = 1;
}

map<string, ld> dist;
void dijekstra(map<string, vector<pair<string, ld>>> &G, string src)
{
    // initializing the distances;
    // map<string, ld> dist;
    // lets build dijekstra using madabelo's Code.
    priority_queue<pair<ld, string>, vector<pair<ld, string>>, greater<>> pq;
    pq.push({1, src});
    while (pq.size())
    {
        ld curent_cost = pq.top().first;
        string node = pq.top().second;
        pq.pop();
        if (curent_cost > dist[node])
            continue;
        for (auto nei : G[node])
        {
            // check for neighbour
            string next = nei.first;
            ld next_cost = roundToNdecimalPlaces(curent_cost * nei.second, 5);
            if (next_cost < dist[next])
            {
                pq.push({next_cost, next});
                dist[next] = next_cost;
            }
        }
    }
}

/*

equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0]
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
*/

int main()
{
    // building the map
    vector<vector<string>> equations = {{"a", "aa"}};
    vector<ld> values = {0.5};
    map<string, vector<pair<string, ld>>> G;
    buildGraph(equations, values, G);
    vector<vector<string>> queries = {{"a", "aa"}, {"aa", "aa"}};
    // // preprocessing(equations, queries);
    for (auto q : queries)
    {
        if (G[q[0]].size() && G[q[1]].size()) // both exist in the graph
        {
            initializeSource(q[0], G, dist);
            dijekstra(G, q[0]);
            if (dist[q[1]] != INT_MAX)
                cout << dist[q[1]] << ' ';
            else
                cout << -1.00000 << ' ';
        }
        else // does not exist so for sure -1
            cout << -1.00000 << ' ';
    }
}