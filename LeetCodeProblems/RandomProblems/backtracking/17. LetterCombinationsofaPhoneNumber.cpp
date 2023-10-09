#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

map<char, vector<char>> mp = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}};

void backtracking(int i, string digits, string s, vector<string> &ans)
{
    // base cases
    if (i == digits.length())
    {
        if (s.length())
            ans.push_back(s);
        return;
    }

    for (auto chr : mp[digits[i]])
        backtracking(i + 1, digits, s + chr, ans);
}

vector<string> letterCombinations(string digits)
{
    DPSolver;
    // remove all ones
    digits.erase(remove(digits.begin(), digits.end(), '1'), digits.end()); // remove A from string
    vector<string> ans;
    backtracking(0, digits, "", ans);
    return ans;
}

int main()
{
    DPSolver;
    string digits = "12131";
    cout << digits;
    vector<string> ans = letterCombinations(digits);
    for (auto s : ans)
        cout << s << " ";
    cout << endl;

    return 0;
}