#include <bits/stdc++.h>
using namespace std;

#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

int countCharacters(vector<string> &words, string chars)
{
    DPSolver;
    int count = 0;
    map<char, int> mpOfChar;
    for (char c : chars)
        mpOfChar[c]++;
    for (string word : words)
    {
        map<char, int> mpOfCharForEachWord;
        bool canForm = true;
        for (char c : word)
        {
            if (!mpOfChar[c] || mpOfCharForEachWord[c] == mpOfChar[c])
            {
                canForm = false;
                break;
            }
            mpOfCharForEachWord[c]++;
        }
        if(canForm)
            count += word.size(); 
    }
    return count; 
}