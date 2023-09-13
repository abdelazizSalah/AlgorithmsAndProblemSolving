#include <bits/stdc++.h>
using namespace std;
class TimeMap
{
public:
    TimeMap()
    {
        timeMap = map<string, vector<pair<int, string>>>();
    }

    void set(string key, string value, int timestamp)
    {
        auto ptr = timeMap.find(key);
        if (ptr != timeMap.end())
            ptr->second.push_back({timestamp, value});
        else
        {
            timeMap[key].push_back({0, ""}); // initialize all inserted elements with empty element.
            timeMap[key].push_back({timestamp, value});
        }
    }

    string get(string key, int timestamp)
    {
        return BS(timeMap[key], timestamp);
    }

private:
    map<string, vector<pair<int, string>>> timeMap;
    string BS(vector<pair<int, string>> &list, int trgtTime)
    {
        int sz = list.size();
        if (sz == 1)
            return list[0].second;
        int bgn = 0;
        int end = sz - 1;
        int mid = (end + bgn) / 2;
        string lessThanTrgt;
        while (end > bgn)
        {
            if (list[mid].first > trgtTime)
                end = mid;
            else if (list[mid].first < trgtTime)
            {
                bgn = mid + 1;
                lessThanTrgt = list[mid].second;
            }
            else
                return list[mid].second;
            mid = (end + bgn) / 2;
        }
        if (mid >= 0 && mid < sz)
            if (list[mid].first == trgtTime)
                return list[mid].second;
            else if (list[mid].first < trgtTime)
                lessThanTrgt = list[mid].second;

        return lessThanTrgt;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
int main()
{
    TimeMap tm = TimeMap();
    tm.set("foo", "bar", 1);
    cout << tm.get("foo", 1) << '\n';
    cout << tm.get("foo", 3) << '\n';
    tm.set("foo", "bar2", 4);
    cout << tm.get("foo", 4) << '\n';
    cout << tm.get("foo", 5) << '\n';
    return 0;
}