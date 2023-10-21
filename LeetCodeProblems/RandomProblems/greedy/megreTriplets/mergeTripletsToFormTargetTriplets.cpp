// passed 58 out of 62 test cases!!!
#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool sameTriplet(vector<int> &t1, vector<int> &t2)
{
    for (int i = 0; i < 3; i++)
        if (t1[i] != t2[i])
            return false;
    return true;
}
bool validTriplet(const vector<int> &triplet, const vector<int> &trgt)
{
    bool exist = false;
    for (int i = 0; i < 3; i++)
        if (triplet[i] > trgt[i])
            return false;
        else if (triplet[i] == trgt[i])
            exist = true;
    return exist;
}

void applyOperation(vector<int> &putIn, vector<int> toBePlaced, const vector<int> &trgt, vector<bool> &vis)
{
    for (int i = 0; i < 3; i++)
    {
        putIn[i] = max(putIn[i], toBePlaced[i]);
        if (putIn[i] == trgt[i])
            vis[i] = true;
    }
}

bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
{
    int sz = triplets.size();
    if (sz == 1)
        return sameTriplet(triplets[0], target);

    int counter = 0;
    vector<bool> vis(3);
    vector<vector<int>> possibleVecs;
    for (auto triplet : triplets) // O(n)
        if (validTriplet(triplet, target))
            possibleVecs.push_back({triplet[0], triplet[1], triplet[2]});

    if (possibleVecs.empty())
        return false;
    sz = possibleVecs.size();
    if (sz == 1)
        return sameTriplet(possibleVecs[0], target);

    vector<int> container = possibleVecs[sz - 1];
    possibleVecs.pop_back();
    sz--;
    for (int i = 0; i < 3; i++)
        if (container[i] == target[i])
        {
            counter++;
            vis[i] = true;
        }
    if (counter == 3)
        return true;
    for (int i = 0; i < 3; i++)
        if (!vis[i])
        {
            for (int j = 0; j < sz; j++) // O(m) m = n - unuseful elements.
                if (possibleVecs[j][i] == target[i])
                {
                    //! 1. apply the operation
                    applyOperation(container, possibleVecs[j], target, vis);
                    //! 2. remove that list.
                    possibleVecs.erase(possibleVecs.begin() + j);
                    sz--;
                    //! 3. increment counter
                    counter++;
                    vis[i] = true;
                    break;
                }
            if (counter == 3)
                return true;
        }
    for (int i = 0; i < 3; i++)
        if (!vis[i])
            return false;
    return true;
}

int main()
{
    DPSolver;
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(4);
    v1.pop_back();
    cout << v1[0];

    return 0;
}