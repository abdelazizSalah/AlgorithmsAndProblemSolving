#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

map<pair<int, string>, int> memo;
int dpSolution(const string &s, int idx, string ans)
{
    // make it efficient
    auto it = memo.find({idx, ans});
    if (it != memo.end())
        return it->second;
    // make it work
    // define base cases
    if (ans[0] == '0' || (ans[0] > '2' && ans.size() == 2) || (ans[0] == '2' && ans.size() == 2 && ans[1] > '6'))
    {
        memo[{idx, ans}] = 0;
        return 0;
    }
    if (idx == s.size() - 1)
    {
        memo[{idx, ans}] = 1;
        return 1;
    }

    // recursive calls
    int ansWithOneChar = 0, ansWithTwoChars = 0;
    if (idx + 1 < s.size())
    {
        string temp = to_string(s[idx + 1] - '0');
        if (ans.size() == 1)
        {
            ansWithOneChar = dpSolution(s, idx + 1, temp);
            ansWithTwoChars = dpSolution(s, idx + 1, ans + temp);
        }
        else
            ansWithOneChar = dpSolution(s, idx + 1, temp);
    }

    memo[{idx, ans}] = ansWithOneChar + ansWithTwoChars;
    return ansWithOneChar + ansWithTwoChars;
}

int numDecodings(string s)
{
    return dpSolution(s, 0, to_string(s[0] - '0'));
}

int main()
{
    DPSOLVER;
    cout << numDecodings("2264");
}