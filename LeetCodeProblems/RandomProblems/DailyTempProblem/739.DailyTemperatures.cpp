// ACCEPTED First Time :D
#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

vector<int> solve()
{
    stack<pair<int, int>> st;
    // vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    // vector<int> temps = {30, 40, 50, 60};
    // vector<int> temps = {30, 60, 90};
    vector<int> temps = {30, 70, 40, 50, 80, 60, 40, 50, 40};
    int sz = temps.size();
    if (sz == 1)
        return {0};
    vector<int> days(sz);
    // insert the last element in the temps.
    st.push({*(temps.end() - 1), sz - 1});

    // start iterating from the element before the last element
    for (int i = sz - 2; i >= 0; i--)
    {
        bool insertedFlag = false;
        int sum = 0;
        while (st.size())
        {
            if (st.top().first <= temps[i])
            {
                sum += days[st.top().second];
                st.pop();
            }
            else
            {
                insertedFlag = true;
                st.push({temps[i], i});
                days[i] = ++sum;
                break;
            }
        }
        if (!insertedFlag)
        {
            days[i] = 0;
            st.push({temps[i], i});
        }
    }

    for (int day : days)
        cout << day << ' ';
    return days;
}

int main()
{
    DPSolver;
    solve();
}