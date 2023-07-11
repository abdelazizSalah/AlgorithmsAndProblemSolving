class Solution
{
public:
    void buidoubleGraph(const vector<vector<string>> &equations, const vector<double> &values, map<string, vector<pair<string, double>>> &G)
    {
        int noOfEdges = equations.size();
        for (int j = 0; j < noOfEdges; j++)
        {
            // add yourself if you were not here before.
            if (!G[equations[j][0]].size())
                G[equations[j][0]].push_back({equations[j][0], 1.0}); // A / A = 1
            if (!G[equations[j][1]].size())
                G[equations[j][1]].push_back({equations[j][1], 1.0});       // B / B = 1
            G[equations[j][0]].push_back({equations[j][1], values[j]});     // A / B
            G[equations[j][1]].push_back({equations[j][0], 1 / values[j]}); // B / A
        }
    }

    double roundToNdecimalPlaces(double num, int places)
    {
        double mult = 1.0;
        for (int i = 0; i < places; i++)
            mult *= 10.0;
        num = round(num * mult);
        num /= mult;
        return num;
    }
    map<string, double> dist;

    void initializeSource(string src, map<string, vector<pair<string, double>>> &G, map<string, double> &dist)
    {
        // iterate over all nodes in the graph
        for (auto node : G)
            dist[node.first] = INT_MAX;
        dist[src] = 1;
    }

    double getMax(double x1, double x2, double x3)
    {
        if (x1 > x2)
        {
            if (x1 > x3)
                return x1;
            else
                return x3;
        }
        else
        {
            // x2 > x1
            if (x2 > x3)
                return x2;
            else
                return x3;
        }
    }

    void dijekstra(map<string, vector<pair<string, double>>> &G, string src)
    {
        // lets build dijekstra using madabelo's Code.
        priority_queue<pair<double, string>, vector<pair<double, string>>, greater<>> pq;
        pq.push({1, src});
        while (pq.size())
        {
            double curent_cost = pq.top().first;
            string node = pq.top().second;
            pq.pop();
            if (curent_cost > dist[node])
                continue;
            for (auto nei : G[node])
            {
                // check for neighbour
                string next = nei.first;
                // double next_cost = getMax(roundToNdecimalPlaces(curent_cost * nei.second, 5),roundToNdecimalPlaces(curent_cost * nei.second, 4), roundToNdecimalPlaces(curent_cost * nei.second, 3));

                double next_cost = roundToNdecimalPlaces(curent_cost * nei.second, 7);
                if (next_cost < dist[next])
                {
                    pq.push({next_cost, next});
                    dist[next] = next_cost;
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        // building the map
        map<string, vector<pair<string, double>>> G;
        buidoubleGraph(equations, values, G);
        vector<double> res;
        for (auto q : queries)
        {
            if (G[q[0]].size() && G[q[1]].size()) // both exist in the graph
            {
                initializeSource(q[0], G, dist);
                dijekstra(G, q[0]);
                if (dist[q[1]] != INT_MAX)
                    res.push_back(dist[q[1]]);
                else
                    res.push_back(-1.00000);
            }
            else // does not exist so for sure -1
            {
                cout << "out";
                res.push_back(-1.00000);
            }
        }
        return res;
    }
};