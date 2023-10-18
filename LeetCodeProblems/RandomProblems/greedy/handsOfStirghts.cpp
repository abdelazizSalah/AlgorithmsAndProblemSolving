#include <bits/stdc++.h>
using namespace std;
#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    DPSolver;
    // we can not formate n groups each of group size.
    if (hand.size() % groupSize != 0)
        return false;

    // create a map of int and pq ascendingly
    map<int, priority_queue<int, vector<int>, greater<>>> mp;

    // sort elements
    sort(hand.begin(), hand.end());

    // create a vis vector
    int sz = hand.size();
    vector<bool> vis(sz);

    // iterate over hand vector and insert its elements in the mp
    for (int i = 0; i < sz; i++)
        mp[hand[i]].push(i);

    for (int i = 0; i < sz; i++)
    {
        // if this card is not taken into a group before.
        if (!vis[i])
        {
            for (int count = 0; count < groupSize; count++)
            {
                int currentCard = hand[i] + count;
                if (count == groupSize - 1)
                {

                    vis[mp[currentCard].top()] = true;
                    mp[currentCard].pop();
                    break;
                }
                // if there is no consecutive card in the hand, return false;
                if (mp[currentCard + 1].empty())
                    return false;
                else
                {
                    vis[mp[currentCard].top()] = true;
                    mp[currentCard].pop();
                }
            }
        }
    }

    // make sure that we have taken all the cards in a group
    for (bool visitor : vis)
        if (!visitor)
            return false;
    return true;
}

int main()
{
    DPSolver;
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int gsize = 3;
    cout << boolalpha << isNStraightHand(hand, gsize);
    return 0;
}