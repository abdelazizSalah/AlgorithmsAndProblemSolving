#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100005;
const int INF = 1e9;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];
bool visited[MAXN];

int prim(int start, int n)
{
    memset(dist, INF, sizeof(dist));
    memset(visited, false, sizeof(visited));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    int totalWeight = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        totalWeight += dist[u];

        for (auto &[v, w] : adj[u])
        {
            if (!visited[v] && w < dist[v])
            {
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }

    return totalWeight;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int mstWeight = prim(0, n);
    cout << mstWeight << endl;

    return 0;
}
