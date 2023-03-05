/*
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.
*/
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    map<char, int> firstWord;
    for (char c : s)
        firstWord[c]++;

    for (char c : t)
        firstWord[c]--;

    for (auto k : firstWord)
        if (k.second > 0)
            return false;
    return true;
}