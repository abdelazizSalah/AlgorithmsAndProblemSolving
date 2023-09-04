#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

bool validSequence(string seq)
{
    stack<char> paranthesesStack;
    for (char c : seq)
    {
        if (c == '(')
            paranthesesStack.push(c);
        else
        {
            if (paranthesesStack.empty())
                return false;
            paranthesesStack.pop();
        }
    }
    return paranthesesStack.empty();
}

void generatePattern(vector<string> &res, string seq, int n)
{
    // base case
    if ((2 * n) == seq.size())
    {
        if (validSequence(seq))
            res.push_back(seq);

        return;
    }

    // seq + '('
    generatePattern(res, seq + '(', n);
    // seq + ')'
    generatePattern(res, seq + ')', n);
}

void solve(int n)
{
    vector<string> res;
    generatePattern(res, "", n);
    for (string s : res)
        cout << s << ' ';
    cout << '\n';
}

int main()
{
    DPSolver;
    // int n;
    // cin >> n;
    solve(1);
    solve(2);
    solve(3);
    return 0;
}