

#include <bits/stdc++.h>
#define DPsolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct Node
{
    int distance;
    int parent;
    int ID;
};

int main()
{
    // create a priority queue to set the node with the minimum value at the front
    auto compareNode = [](const Node &a, const Node &b)
    {
        return a.distance > b.distance;
    };
    priority_queue<Node, vector<Node>, decltype(compareNode)> pq(compareNode);

    Node a;
    a.distance = 20;
    a.ID = 1;
    a.parent = NULL;

    Node b;
    b.distance = 5;
    b.ID = 2;
    b.parent = NULL;

    pq.push(a);
    pq.push(b);

    while (pq.size())
    {
        cout << pq.top().ID;
        pq.pop();
    }
}