/*
    @author: Abdelaziz Salah
    @date: 26/1/2024
    @brief: This file contains the implementation of the suffix array which takes complexity O(n log^2(n)).
*/
// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#define INT_MIN (-2147483647 - 1)
using namespace std;

int get_max_element(vector<pair<int, int>> &vec)
{
    int mx = INT_MIN;
    for (auto item : vec)
    {
        mx = max(mx, item.first);
        mx = max(mx, item.second);
    }
    return mx;
}

void radixSort(vector<pair<int, int>> &vec)
{
    // 1. get the max element
    int mxElement = get_max_element(vec);
    int sz = vec.size();
    vector<pair<int, int>> halvSortedVec;
    vector<pair<int, int>> sortedVec;
    // 2. create a buckets for each element
    vector<vector<pair<int, int>>> buckets(mxElement+1);

    // 3. insert each element in vec in its corresponding bucket using the second element as a key
    for (int i = 0; i < sz; i++)
        buckets[vec[i].second].push_back(vec[i]);

    // 4. insert the elements in their order in the halvSortedVec
    for (int i = 0; i <= mxElement; i++)
        for (auto item : buckets[i])
            halvSortedVec.push_back(item);

    // 5. set buckets to empty and repeat
    for (int i = 0; i <= mxElement; i++)
        buckets[i].clear();
    for (int i = 0; i < sz; i++)
        buckets[halvSortedVec[i].first].push_back(halvSortedVec[i]);

    // 6. insert the elements in their order in the sorted
    for (int i = 0; i <= mxElement; i++)
        for (auto item : buckets[i])
            sortedVec.push_back(item);

    vec = sortedVec;
}

vector<int> suffixArray(string s)
{
    // 1. append dollar sign
    s += '$';

    // 2. create two vectors
    //      2.1 one for the classes
    //      2.2 the other for the positions
    int sz = s.length();
    vector<int> classes(sz), positions(sz);

    // 3. apply the initial phase
    {
        // 3.1 define a vector which carry each character and its corresponding index
        vector<pair<char, int>> state(sz);
        for (int i = 0; i < sz; i++)
            state[i] = {s[i], i};

        // 3.2 sort that vector
        sort(state.begin(), state.end());

        // 3.3 append the positions
        for (int i = 0; i < sz; i++)
            positions[i] = state[i].second;

        // 3.4 assign the classes
        for (int i = 1; i < sz; i++)
            if (state[i].first == state[i - 1].first)
                classes[positions[i]] = classes[positions[i - 1]];
            else
                classes[positions[i]] = classes[positions[i - 1]] + 1;
    }

    // 4. initialize k = 0
    int k = 0;

    // 5. iterate while sz > 2^k
    while ((1 << k) < sz)
    {
        // 5.1 define a vector to represent 2^(k+1) into two halves 2^k | 2^k and to store the index with them
        vector<pair<pair<int, int>, int>> state(sz);
        for (int i = 0; i < sz; i++)
            state[i] = {{classes[i], classes[(i + (1 << k)) % sz]}, i};

        // 5.2 sort the state
        sort(state.begin(), state.end());

        // 5.3 store the new positions.
        for (int i = 0; i < sz; i++)
            positions[i] = state[i].second;

        // 5.4 assign the new classes
        for (int i = 1; i < sz; i++)
            if (state[i].first == state[i - 1].first)
                classes[positions[i]] = classes[positions[i - 1]];
            else
                classes[positions[i]] = classes[positions[i - 1]] + 1;

        // 5.5 increment k
        k++;
    }

    return positions;
}

int main()
{
    // string s;
    // cin >> s;
    // auto positions = suffixArray(s);
    // for (int p : positions)
    //     cout << p << ' ';

    vector<pair<int, int>> v = {{3, 2}, {2, 1}, {1, 3}, {0, 1}, {2, 0}, {3, 0}, {1, 2}, {3, 1}};
    radixSort(v);
    for (auto item : v)
        cout << item.first << ' ' << item.second << endl;

    return 0;
}