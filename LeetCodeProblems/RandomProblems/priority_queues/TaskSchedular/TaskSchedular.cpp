#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void printMap(map<char, pair<int, pair<int, priority_queue<int, vector<int>, greater<>>>>> &mp)
{
    for (auto item : mp)
    {
        cout << item.first << " : " << item.second.first << " : " << item.second.second.first << " : ";
        while (item.second.second.second.size())
        {
            cout << item.second.second.second.top() << " ";
            item.second.second.second.pop();
        }
        cout << endl;
    }
}
void incrementAllCharacters(map<char, pair<int, pair<int, priority_queue<int, vector<int>, greater<>>>>> &mp)
{
    for (auto &key : mp)
        key.second.first++;
}

void incrementAllCharactersExceptC(map<char, pair<int, pair<int, priority_queue<int, vector<int>, greater<>>>>> &mp, char c)
{
    for (auto &key : mp)
        if (key.first != c)
            key.second.first++;
}

int leastInterval(vector<char> &tasks, int n)
{
    //? First three steps in my algorithm
    // for all unique characters create a priority queue which carry the time stamps.
    map<char, pair<int, pair<int, priority_queue<int, vector<int>, greater<>>>>> mp;

    for (auto c : tasks)
    {
        auto finder = mp.find(c);
        if (finder != mp.end())
        {
            // we have found that item
            finder->second.second.first += n;
            finder->second.second.second.push(finder->second.second.first);
        }
        else
        {
            priority_queue<int, vector<int>, greater<>> pq;
            pq.push(0);
            mp[c] = {0, {0, pq}};
        }
    }

    int res = 0;
    //? while there is any element in any queue
    while (1)
    {
        bool noMoreElementsInAnyQueue = true;
        bool canProcess = false;
        // iterating over each key in the map
        for (auto &key : mp)
        {

            bool hasElementsInTheQueue = key.second.second.second.size();
            if (hasElementsInTheQueue)
                noMoreElementsInAnyQueue = false;
            int topOfTheQueue = key.second.second.second.top();
            int currentVal = key.second.first;
            if (hasElementsInTheQueue && (currentVal >= topOfTheQueue))
            {
                canProcess = true;
                noMoreElementsInAnyQueue = false;
                incrementAllCharactersExceptC(mp, key.first);
                key.second.second.second.pop();
                break;
            }
        }
        if (noMoreElementsInAnyQueue)
            break;
        if (!canProcess)
            incrementAllCharacters(mp);
        res++;
    }

    return res;
}

int main()
{
    DPSolver;
    //"A","A","A","A","A","A","B","C","D","E","F","G
    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int n = 2;
    cout << leastInterval(tasks, n) << endl;
    return 0;
}