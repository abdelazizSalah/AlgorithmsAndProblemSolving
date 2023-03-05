#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int sz = s.size();
    stack<char> st;
    for (int i = 0; i < sz; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (st.empty())
            {
                cout << "false";
                return;
            }
            else if (s[i] == ')' && st.top() == '(')

                st.pop();

            else if (s[i] == ']' && st.top() == '[')

                st.pop();

            else if (s[i] == '}' && st.top() == '{')

                st.pop();

            else
            {
                cout << "false";
                return;
            }
        }
    }
    cout << (st.empty() ? "true" : "false");
}

int main()
{
    solve();
    return 0;
}