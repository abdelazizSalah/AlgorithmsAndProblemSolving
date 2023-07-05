#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e11;
const int maxn = 1e5 + 10;
int n, m;
vector<int> v[maxn];
vector<int> peso[maxn];
int dist[maxn];
int vim[maxn];
set<pair<int, int>> s;

void dijkstra(int u)
{
    for (int i = 1; i <= n; i++)
        dist[i] = 100000000000LL;
    dist[u] = 0;
    vim[u] = u;
    for (int i = 1; i <= n; i++)
        s.insert({dist[i], i});
    while (!s.empty())
    {
        int x = s.begin()->second;
        s.erase(s.begin());
        for (int i = 0; i < v[x].size(); i++)
        {
            int viz = v[x][i];
            int p = peso[x][i];
            if (dist[x] + p < dist[viz])
            {
                s.erase({dist[viz], viz});
                dist[viz] = dist[x] + p;
                s.insert({dist[viz], viz});
                vim[viz] = x;
            }
        }
    }
}
main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, p;
        scanf("%lld%lld%lld", &a, &b, &p);
        v[a].push_back(b);
        peso[a].push_back(p);
        v[b].push_back(a);
        peso[b].push_back(p);
    }
    dijkstra(1);
    vector<int> resp;
    if (dist[n] == 100000000000LL)
        cout << "-1" << endl;
    else
    {
        while (true)
        {
            if (vim[n] == n)
            {
                resp.push_back(n);
                break;
            }
            else
            {
                resp.push_back(n);
                n = vim[n];
            }
        }
        for (int i = (int)resp.size() - 1; i >= 0; --i)
            cout << resp[i] << " ";
        cout << endl;
    }

    return 0;
}
