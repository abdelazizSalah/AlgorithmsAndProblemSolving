class Solution
{
public:
    unordered_map<string, map<string, double>> arr;
    unordered_map<string, bool> visit;
    string start;
    double solve(string src, string des, bool &find)
    {
        /*auto it = arr[src].find(des);
        if (it != arr[src].end())
            return (*it).second;*/
        if (src == des)
        {
            find = true;
            return 1;
        }
        if (visit[src])
            return -1;
        visit[src] = 1;
        double out = -10;
        for (auto &ch : arr[src])
        {
            double cur = solve(ch.first, des, find) * ch.second;
            if (find)
            {
                out = cur;
                break;
            }
        }
        if (find)
            return arr[src][des] = out;
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int ne = equations.size();
        int nq = queries.size();

        set<string> symbols;
        for (int i = 0; i < ne; i++)
        {
            string a = equations[i][0], b = equations[i][1];
            double o = values[i];
            symbols.insert(a);
            symbols.insert(b);
            arr[a][b] = o;
            arr[b][a] = 1 / o;

            arr[a][a] = 1;
            arr[b][b] = 1;
        }
        int synb_num = symbols.size();
        vector<double> out(nq);
        for (int i = 0; i < nq; i++)
        {
            string a = queries[i][0], b = queries[i][1];

            if (symbols.find(a) == symbols.end() || symbols.find(b) == symbols.end())
                out[i] = -1;
            else if (a == b)
                out[i] = 1;
            else
            {
                start = a;
                bool find = 0;
                visit.clear();
                double ans = solve(a, b, find);
                if (find)
                    out[i] = ans;
                else
                    out[i] = -1;
            }
        }
        return out;
    }
};