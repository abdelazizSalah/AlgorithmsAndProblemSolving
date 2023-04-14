#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, k, c[MAXN], dist[MAXN][MAXN], minDist[MAXN];
vector<int> adj[MAXN];

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    memset(dist[s], 0x3f, sizeof(dist[s]));
    dist[s][s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (int v : adj[u])
        {
            if (dist[s][v] > dist[s][u] + c[v])
            {
                dist[s][v] = dist[s][u] + c[v];
                pq.push({dist[s][v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        minDist[i] = *min_element(dist[i] + 1, dist[i] + n + 1);
    }
    sort(minDist + 1, minDist + n + 1);
    int ans = accumulate(c + 1, c + n + 1, 0);
    for (int i = 1; i <= k; i++)
    {
        if (minDist[i] == 0)
            break;
        ans -= minDist[i];
    }
    cout << ans << '\n';
    return 0;
}
