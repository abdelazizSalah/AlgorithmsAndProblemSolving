#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int distance;
    int parent;
    int ID;
};

int main()
{
    auto compareNode = [](const Node &a, const Node &b)
    {
        // apply ur logic
        return a.distance > b.distance;
    };

    priority_queue<Node, vector<Node>, decltype(compareNode)> pq(compareNode);
    Node a;
    a.distance = 10;

    Node b;
    b.distance = 7;

    pq.push(a);
    pq.push(b);

    while (pq.size())
    {
        cout << pq.top().distance;
        pq.pop();
    }
    return 0;
}