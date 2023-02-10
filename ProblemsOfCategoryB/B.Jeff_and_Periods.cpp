/// Accepted first time :). I'm so happy :D
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void solve()
{
    int noOfElements;
    cin >> noOfElements;
    int largestVal = -1;
    vector<int> values(noOfElements);
    for (int &val : values) // O(n) n is the number of elements
    {
        cin >> val;
        largestVal = max(largestVal, val);
    }
    vector<pair<int, int>> items(largestVal + 1, {-1, -1}); // {index, difference}
    for (int index = 0; index < noOfElements; index++)      // O(n) n is the number of elements
    {
        // if it is the first time we see this value
        // save its index in the first, and put 0 in the second
        int val = values[index];
        if (items[val].first == -1)
        {
            items[val].first = index;
            items[val].second = 0;
        }
        else
        {
            // if this is the second time to see this value
            // save the difference between the current index and the previous index in the second
            // and save the new index in the first
            if (items[val].second == 0)
            {
                items[val].second = index - items[val].first;
                items[val].first = index;
            }
            else
            {
                // if this is not the second time we need to check if the difference between the current index and
                // the previous index equals to the difference we saved in the second
                // if it was equal then we just need to update the first position with the current index
                if (index - items[val].first == items[val].second)
                {
                    items[val].first = index;
                }
                else
                {
                    // else this means that this is not a valid X
                    // so we need to decrement the number of possible values
                    // and mark the first of this as -2
                    items[val].first = -2;
                    items[val].second = -2;
                }
            }
        }
    }
    // iterating to print the result
    queue<pair<int, int>> q;
    for (int i = 0; i < items.size(); i++) // O(s) s is the largest value in the vector.
        if (items[i].first >= 0)
            q.push({i, items[i].second});

    // printing the result
    cout << q.size() << '\n';
    while (!q.empty()) /// O(m) m is the number of valid X
    {
        cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }
} // O(n + s + m) = O(n) as n is the largest value.

int main()
{
    fast;
    solve();
    return 0;
}