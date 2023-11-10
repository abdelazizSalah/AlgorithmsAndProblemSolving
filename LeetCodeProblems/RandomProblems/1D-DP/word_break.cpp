#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int test()
{
    string s = "abctabctabctabc";
    string t = "abc";
    size_t pos = s.find(t);
    cout << s << '\n';
    while (pos != string::npos)
    {
        string leftPart;
        string rightPart;
        leftPart = s.substr(0, pos);
        rightPart = s.substr(pos + t.length(), s.length() - pos - t.length());
        cout << string(leftPart) << ' ' << string(rightPart) << '\n';
    }

    return 0;
}

// Correct logic, but it is too expensive.
// map<string, bool> memo2;
// bool wordBreak2(string s, std::vector<std::string> &wordDict)
// {
//     //! make it efficient.
//     auto it = memo.find(s);
//     if (it != memo.end())
//         return it->second;

//     //! make it work
//     // define basecases.
//     if (s == "")
//         return true;

//     for (auto word : wordDict)
//     {
//         // search for the position of this word in the string.
//         size_t pos = s.find(word);

//         // this is because the same word may exist in multiple locations.
//         while (pos != string::npos)
//         {
//             // this is a copy of the main string to be able to erase the founded string from its location without affecting the main string.
//             string leftPart;
//             string rightPart;
//             leftPart = s.substr(0, pos);
//             rightPart = s.substr(pos + word.length(), s.length() - pos - word.length());
//             bool wordIsCreated1 = wordBreak(std::string(leftPart), wordDict);
//             bool wordIsCreated2 = wordBreak(std::string(rightPart), wordDict);
//             if (wordIsCreated1 && wordIsCreated2)
//                 return true;
//             // now we need to look for another occurence of the same word.
//             pos = s.find(word, pos + word.size());
//         }
//     }
//     // this means that we could not formate the string.
//     return false;
// }
map<int, bool> memo;
bool wordBreak(string s, std::vector<std::string> &wordDict, int idx = 0)
{
    //! make it efficient.
    auto it = memo.find(idx);
    if (it != memo.end())
        return it->second;

    //! make it work
    // define basecases.
    if (idx == s.length())
        return true;

    for (auto word : wordDict)
    {
        // search for the position of this word in the string.
        size_t pos = s.find(word, idx);

        if (pos == idx)
            if (wordBreak(s, wordDict, idx + word.length()))
                return true;
    }
    // this means that we could not formate the string.
    memo[idx] = false;
    return false;
}

int main()
{
    DPSolver;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    // string s = "applepenapple";
    // vector<string> wordDict = {"apple", "pen"};
    // string s = "catsandog";
    // vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << boolalpha << wordBreak(s, wordDict, 0);
    // test();
    return 0;
}