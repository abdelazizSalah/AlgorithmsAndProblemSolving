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
#define INT_MIN (-2147483647 - 1);
using namespace std;


void countSort (vector<int>&positions,const vector<int>& classes) {
    // 1. extract the size 
    int sz = positions.size(); 

    // 2. create count vector
    vector<int> count(sz); 

    // 3. iterate over each class, and increment its count 
    for (int c : classes)
        count [c] ++; 

    // 4. create a vector for indicies
    vector<int> indicies(sz); 

    // 5. fill the indicies using the previous index + its count
    for (int i = 1; i < sz; i++ )
        indicies[i] = indicies[i-1] + count[i-1];  

    // 6. create a vector to represent the new positions. 
    vector<int> newPositions(sz);

    // 7. iteratre over each position in the given positions vector 
    for (int pos : positions) {
        // 7.1 extract the class of this position
        int cls = classes[pos]; 

        // 7.2 assign the new position 
        newPositions[indicies[cls]] = pos; 
        
        // 7.3 increment the index of that class
        indicies[cls]++; 
    }

    // 8. assign the position to the newPositions
    positions = newPositions; 
}

vector<int> buildSuffixArray(string &s)
{
    // 1. append $ to s
    s += '$';

    // 2. extract the sz of s
    int sz = s.length();

    // 3. create two vectors
    vector<int> classes(sz);
    vector<int> positions(sz);

    // 4. initial phase
    {
        // 4.1 define a vector of pairs
        vector<pair<char, int>> state(sz);

        // 4.2 fill the states
        for (int i = 0; i < sz; i++)
            state[i] = {s[i], i};

        // 4.3 sort the state
        sort(state.begin(), state.end());

        // 4.4 assign positions;
        for (int i = 0; i < sz; i++)
            positions[i] = state[i].second;

        // 4.5 assign classes
        for (int i = 1; i < sz; i++)
            // if both characters are the same
            if (state[i].first == state[i-1].first)
                classes[positions[i]] = classes[positions[i - 1]];
            else
                classes[positions[i]] = classes[positions[i - 1]] + 1;
    }

    // 5. define k
    int k = 0;

    // 6. do the log n iterations
    while ((1 << k) < sz)
    {
        // 6.1 append the right part sorted, to be able to use the most optimized suffix method and only one sorting iteration. 
        int shiftAmount = (1 << k);
        for (int i = 0; i < sz; i++)
            positions[i] = (positions[i] + sz - shiftAmount) % sz;

        // 6.2 apply count sort
        countSort(positions, classes); 

        // 6.3 define a new vector for classes
        vector<int> newClasses(sz); 

        // 6.4 iterate and assign the classes 
        for (int i = 1; i < sz; i++){
            // 6.4.1 define new two pairs 
            pair<int,int> prev = {
                classes[positions[i-1]], 
                classes[(positions[i-1] + shiftAmount) % sz]
            };
            pair<int,int> curr = {
                classes[positions[i]], 
                classes[(positions[i] + shiftAmount) % sz]
            };

            // 6.4.2 compare them, if equal
            if (prev == curr)
                newClasses[positions[i]] =
                 newClasses[positions[i-1]];
            else 
                newClasses[positions[i]] =
                 newClasses[positions[i-1]] + 1;
        } 

        // 6.5 assign classes to new Classes 
        classes = newClasses; 

        // 6.6 increment k
        k++; 
    }

    // 7. return positions
    return positions; 
}

int main()
{
    string s;
    cin >> s;
    auto positions = buildSuffixArray(s);
    for (int p : positions)
        cout << p << ' ';

    return 0;
}