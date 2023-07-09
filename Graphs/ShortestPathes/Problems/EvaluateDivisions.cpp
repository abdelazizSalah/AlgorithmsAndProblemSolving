#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ld = long double;
void readingInput(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int noOfEquations, noOfQueries;
    cin >> noOfEquations >> noOfQueries;
    equations = vector<vector<string>>(noOfEquations);
    queries = vector<vector<string>>(noOfQueries);
    values = vector<double>(noOfEquations);
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
                    if (first[i] == second[j] && first.size() > 1 && second.size() > 1)
                        first.erase(i--, 1), second.erase(j--, 1), mnSize--, len2--;
            eq[0] = first;
            eq[1] = second;
        }
        else
        {
            mnSize = len2;
            for (int i = 0; i < mnSize; i++)
                for (int j = 0; j < len1; j++)
                    if (first[j] == second[i] && first.size() > 1 && second.size() > 1)
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

void printGraph(const vector<vector<double>> &G)
{
    for (auto node : G)
    {
        for (auto val : node)
            cout << val << ' ';
        cout << '\n';
    }
}

map<string, int> alphaNum;
void buildGraph(const vector<vector<string>> &equations, const vector<double> &values, vector<vector<double>> &G)
{

    G = vector<vector<double>>(26, vector<double>(26));
    // building the graph in matrix form.
    int noOfEdges = equations.size();
    for (int j = 0; j < noOfEdges; j++)
    {
        // directed under condition
        G[alphaNum[equations[j][0]]][alphaNum[equations[j][1]]] = values[j];     // A / B
        G[alphaNum[equations[j][1]]][alphaNum[equations[j][0]]] = 1 / values[j]; // B / A
        G[alphaNum[equations[j][0]]][alphaNum[equations[j][0]]] = 1;             // A/A
        G[alphaNum[equations[j][1]]][alphaNum[equations[j][1]]] = 1;             // B/B
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

vector<ld> dist(26, INT_MAX);
void dijekstra(const vector<vector<double>> &G, int src)
{
    dist = vector<ld>(26, INT_MAX);
    vector<int> parent(26, -1);
    // lets build dijekstra using madabelo's Code.
    dist[src] = 1;
    parent[src] = -1;
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<>> pq;
    pq.push({1, src});
    while (pq.size())
    {
        ld curent_cost = pq.top().first;
        ld node = pq.top().second;
        pq.pop();
        if (curent_cost > dist[node])
            continue;
        for (int x = 0; x < 26; x++)
        {
            // check for neighbour
            if (G[node][x] > 0)
            {
                int next = x;
                ld next_cost = roundToNdecimalPlaces(curent_cost * G[node][x], 3);
                if (next_cost < dist[next])
                {
                    pq.push({next_cost, next});
                    parent[next] = node;
                    dist[next] = next_cost;
                }
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
    int i = 0;
    for (char a = 'a'; a <= 'z'; a++)
        alphaNum[string(1, a)] = i++;
    vector<vector<string>> equations = {{"a", "b"}};
    vector<double> values = {0.5};
    vector<vector<double>> G;
    vector<vector<string>> queries = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};
    preprocessing(equations, queries);
    buildGraph(equations, values, G);
    for (auto q : queries)
    {
        if (G[alphaNum[q[0]]][alphaNum[q[0]]])
        {
            dijekstra(G, alphaNum[q[0]]);
            if (dist[alphaNum[q[1]]] != INT_MAX)
                cout << dist[alphaNum[q[1]]] << ' ';
            else
                cout << -1.00000 << ' ';
        }
        else // does not exist so for sure -1
            cout << -1.00000 << ' ';
    }
}