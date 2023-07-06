#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define f(i, m) for (int i = 0; i < m; i++)
vector<vector<pair<int, ll>>> g; // list rep
vector<ll> dist;
vector<int> par;
int n, m;

void test_case()
{
    cin >> n >> m;
    g = vector<vector<pair<int, ll>>>(n + 1); // 1 based
    dist = vector<ll>(n + 1, 1e17);
    par = vector<int>(n + 1, -1);
    f(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}
void dijkstra(int src)
{
    dist[src] = 0;
    par[src] = -1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        ll curent_cost = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if (curent_cost > dist[node])
            continue;
        for (auto x : g[node])
        {
            int next = x.first;
            ll next_cost = curent_cost + x.second;
            if (next_cost < dist[next])
            {
                pq.push({next_cost, next});
                par[next] = node;
                dist[next] = next_cost;
            }
        }
    }
}
void path(int node)
{
    if (par[node] != -1)
        path(par[node]);
    cout << node << " ";
}

int main()
{
    test_case();
    dijkstra(1);
    if (dist[n] != 1e17)
        path(n);
    else
        cout << -1;
}