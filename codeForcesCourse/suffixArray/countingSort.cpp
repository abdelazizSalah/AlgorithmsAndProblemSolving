#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#define INT_MIN (-2147483647 - 1)
using namespace std;

void countingSort(int minRange, int maxRange, vector<int> &unsortedElements)
{
    // create a vector with the length of the given range.
    int totalSize = abs(minRange) + abs(maxRange) + 1;
    vector<int> count(totalSize);

    // increment the counter of each element.
    for (int element : unsortedElements)
        count[element]++;

    // determine the indicies
    vector<int> indicies(totalSize);
    for (int i = 1; i < totalSize; i++)
        indicies[i] = indicies[i - 1] + count[i];

    // now lets sort the vector
    int sz = unsortedElements.size();
    vector<int> sortedVec(sz);
    for (int i = 0; i < sz; i++)
    {
        int index = indicies[unsortedElements[i]]--;
        sortedVec[--index] = unsortedElements[i];
    }

    unsortedElements = sortedVec;
}

int main()
{
    vector<int> v = {1, 4, 1, 2, 7, 5, 2};
    countingSort(*min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()), v);
    for (int i : v)
        cout << i << ' ';
    return 0;
}
