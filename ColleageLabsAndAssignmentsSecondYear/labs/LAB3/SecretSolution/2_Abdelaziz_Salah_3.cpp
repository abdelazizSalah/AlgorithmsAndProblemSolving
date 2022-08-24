#include <unordered_map> 
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Helper function
void preprocess(string& str) {
    // Removing punctuation
    for (int i = 0, len = str.size(); i < len; i++)
    {
        // Check whether parsing character is punctuation or not 
        if (ispunct(str[i]))
        {
            str.erase(i--, 1);
            len = str.size();
        }
    }

    // Converting to lower case
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Helper function
vector<string> readFile() {
    ifstream f("two-cities.txt"); //taking file as inputstream

    string file;

    if (f) {
        ostringstream ss;
        ss << f.rdbuf(); // reading data
        file = ss.str();

        // Removes punctuation and converts to lower case
        preprocess(file);

        // Split into tokens on space
        istringstream iss(file);
        vector<string> tokens{ istream_iterator<string>{iss},
                          istream_iterator<string>{} };

        return tokens;
    }

    vector<string> empty;
    return empty;
}

// TODO: IMPLEMENT THIS FUNCTION
bool cmp (pair<int , string>a , pair<int , string>b)
{
    return a.first > b.first;
}
string findSecret(vector<string> tokens) {
    // Hint: you can use std::unordered_map and std::sort
    unordered_map<string, int> mp; // same as the map but not ordered
    auto it = tokens.begin();
    while (it != tokens.end())
    {
        mp[*it] ++;
        it++;
    }

    vector<pair<int, string>>v1 ; // this converts the map into vector of pairs
   for (auto it : mp)
        v1.push_back({ it.second , it.first });

    sort(v1.begin(), v1.end(), cmp);
    string result;
    vector<int> idx = { 11, 23, 22, 43, 3, 47 };
    for (int i = 0; i < 6; i++)
    {
        result += v1[idx[i] -1 ].second; 
        if (i != 5)
            result += ' '; 
    } 
    return result;
}

int main() {

    vector<string> tokens = readFile();

    cout << findSecret(tokens) << endl;
    return 0;
}
