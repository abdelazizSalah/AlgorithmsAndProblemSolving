#include <bits/stdc++.h>
using namespace std;

pair<int, bool> binary_search(const vector<int> &vec, int key)
{
    int low = 0, high = vec.size() - 1;
    while (low <= high)
    {
        int mid = floor((high + low) / 2);
        if (vec[mid] == key)
            return {mid, true};
        else if (vec[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, false};
}

int main()
{
    vector<int> vec = {5, 32, 6, 3, 7, 8, 3, 1, 0, -43, -23, -13};
    sort(vec.begin(), vec.end());
    int key = 8;
    pair<int, bool> result = binary_search(vec, key);
    if (result.second)
        cout << "Found at index " << result.first << endl;
    else
        cout << "Not found" << endl;
}