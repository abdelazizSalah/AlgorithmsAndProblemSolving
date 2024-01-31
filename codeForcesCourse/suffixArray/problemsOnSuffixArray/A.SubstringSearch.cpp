#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
void countingSort(vector<int> &positions, vector<int> &classes)
{
    int n = positions.size();
    vector<int> count(n);
    for (int c : classes)
        count[c]++;

    /*
        hena bn3d feh kam element fe el position i-1, w ana bd2t el position i-1 mn fen, 34an a2dr a2ol el position bta3 i hybd2 mn fen

        look at the counting sort file.
    */
    vector<int> indicies(n);
    for (int i = 1; i < n; i++)
        indicies[i] = indicies[i - 1] + count[i - 1]; // ana keda fhmtk :D

    vector<int> newPositions(n);
    for (int position : positions)
    {
        int clas = classes[position];
        newPositions[indicies[clas]] = position;
        indicies[clas]++;
    }
    positions = newPositions;
}

vector<int> suffixArray(string &s)
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
        // 5.1 the transition k -> k+1
        for (int i = 0; i < sz; i++)
            positions[i] = (positions[i] + sz - (1 << k)) % sz; // +sz to avoid negatives, %sz to be cyclic.

        // 5.2 sort the state
        countingSort(positions, classes); // 2nlgn

        // 5.3 update classes
        vector<int> newClasses(sz);
        newClasses[positions[0]] = 0;
        for (int i = 1; i < sz; i++)
        {
            pair<int, int> prev = {classes[positions[i - 1]], classes[(positions[i - 1] + (1 << k)) % sz]};
            pair<int, int> current = {classes[positions[i]], classes[(positions[i] + (1 << k)) % sz]};
            if (prev == current)
                newClasses[positions[i]] = newClasses[positions[i - 1]];
            else
                newClasses[positions[i]] = newClasses[positions[i - 1]] + 1;
        }
        // 5.4 assign new classes to the global classes.
        classes = newClasses;

        // 5.5 increment k
        k++;
    }

    return positions;
}

int compareStrings(string s, string q, int startingIdxForS, int numberOfChars)
{
    int targetIdx = 0;
    int sLen = s.length(); 
    for (int i = startingIdxForS; i < startingIdxForS + numberOfChars; i++)
    {
        if (s[i%sLen] > q[targetIdx])
            return -1;
        else if (s[i%sLen] < q[targetIdx])
            return 1;
        targetIdx++;
    }
    return 0;
}

bool subStringExist(const vector<int> &positions, string s, string q)
{
    // we should look at the length of q
    int len = q.length();

    // apply binary search
    int bgn = 0;
    int end = s.length();
    int md = (bgn + end) / 2;
    while (bgn < end) // lgn * |P|
    {
        int compare = compareStrings(s, q, positions[md], len);
        if (compare == 0)
            return true; // found
        else if (compare == 1)
            // larger
            bgn = md + 1;
        else
            end = md;

        md = (bgn + end) / 2;
    }
    if (md < s.length() && md > 0)
        if (compareStrings(s, q, positions[md], len) == 0)
            return true;
    return false;
}

int main()
{
    DPSolver;
    string s;
    cin >> s;
    // build the suffix array
    vector<int> positions = suffixArray(s);

    // reading the queries.
    int q;
    cin >> q;
    while (q--) // O(q -> 3 * 10^(5))
    {
        string query;
        cin >> query;
        // call the function
        if (subStringExist(positions, s, query))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}