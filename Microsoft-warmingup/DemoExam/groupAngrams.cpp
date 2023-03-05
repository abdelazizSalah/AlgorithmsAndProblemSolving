#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string str1, string str2)
{
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
        return false;

    // Sort both the strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare sorted strings
    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    if (n == 1)
    {
        return {{strs[0]}};
    }
    vector<vector<string>> result;
    // preproccessing step
    map<int, vector<string>> stringsOfSameSize;
    for (string s : strs)
    {
        stringsOfSameSize[s.size()].push_back(s);
    }
    map<string, bool> visited;
    int cntr = 0;
    for (auto s : stringsOfSameSize)
    {
        int n = s.second.size();
        for (int i = 0; i < n; i++)
        {
            if (!visited[s.second[i]])
            {
                visited[s.second[i]] = true;
                result.push_back({s.second[i]});
            }
            else
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (areAnagram(s.second[i], s.second[j]))
                {
                    visited[s.second[j]] = true;
                    result[cntr].push_back(s.second[j]);
                }
            }
            cntr++;
        }
    }

    return result;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    for (auto s : result)
    {
        for (auto i : s)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}