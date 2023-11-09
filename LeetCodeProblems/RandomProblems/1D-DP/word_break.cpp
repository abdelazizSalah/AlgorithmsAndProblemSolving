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
        char *leftPart;
        char *rightPart;
        s.copy(leftPart, pos, 0);
        s.copy(rightPart, s.length() - pos - t.length() - 1, pos + t.length());
        cout << string(leftPart) << ' ' << string(rightPart) << '\n';
    }

    return 0;
}

map<string, bool> memo;
bool wordBreak(string s, std::vector<std::string> &wordDict)
{
    //! make it efficient.
    auto it = memo.find(s);
    if (it != memo.end())
        return it->second;

    //! make it work
    // define basecases.
    if (s == "")
        return true;

    for (auto word : wordDict)
    {
        // search for the position of this word in the string.
        size_t pos = s.find(word);

        // this is because the same word may exist in multiple locations.
        while (pos != string::npos)
        {
            // this is a copy of the main string to be able to erase the founded string from its location without affecting the main string.
            char *leftPart;
            char *rightPart;
            s.copy(leftPart, pos, 0);
            s.copy(rightPart, s.length() - pos - word.length(), pos);

            bool wordIsCreated1 = wordBreak(std::string(leftPart), wordDict);
            bool wordIsCreated2 = wordBreak(std::string(rightPart), wordDict);
            if (wordIsCreated1 && wordIsCreated2)
                return true;
            // now we need to look for another occurence of the same word.
            pos = s.find(word, pos + word.size());
        }
    }
    // this means that we could not formate the string.
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
    // cout << boolalpha << wordBreak(s, wordDict);
    test();
    return -1;
}