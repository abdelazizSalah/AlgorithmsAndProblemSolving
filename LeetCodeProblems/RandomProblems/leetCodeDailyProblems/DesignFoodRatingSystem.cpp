#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
/// Time limit exceeded. s
struct CustomCompare
{
    bool operator()(const std::pair<int, string> &p1, const std::pair<int, string> &p2) const
    {
        if (p1.first < p2.first)
            return true;
        else if (p1.first == p2.first)
        {
            if (p1.second > p2.second)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};
class FoodRatings
{
public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        this->n = foods.size();
        for (int i = 0; i < this->n; i++)
            this->food[foods[i]] = {cuisines[i], ratings[i]};
    }

    void changeRating(string food, int newRating)
    {
        this->food[food].second = newRating;
    }

    string highestRated(string cuisine)
    {

        priority_queue<pair<int, string>, vector<pair<int, string>>, CustomCompare> sameCusine;
        for (auto item : this->food)
        {
            if (item.second.first == cuisine)
                sameCusine.push({item.second.second, item.first});
        }
        return sameCusine.top().second;
    }

private:
    map<string, pair<string, int>> food;
    int n;
};