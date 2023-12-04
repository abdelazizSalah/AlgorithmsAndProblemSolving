#include <bits/stdc++.h>
using namespace std;

#define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

string largestGoodInteger(string num)
{
    DPSolver;
    bool can = false;
    int e = 1;
    int b = 0;
    int sz = num.size();
    int counter = 1;
    vector<bool> flags(10);
    while (e < sz)
    {
        if (num[e] == num[b])
        {
            if (++counter == 3)
            {
                flags[num[b] - '0'] = true;
                can = true;
            }
            e++;
        }
        else
        {
            b = e;
            e++;
            counter = 1;
        }
    }
    if (can)
    {
        for (int i = 9; i >= 0; i--)
        {
            if (flags[i])
            {
                string res = "";
                for (int j = 0; j < 3; j++)
                    res += '0' + i;
                return res;
            }
        }
    }
    return "";
}

int main()
{
    cout << largestGoodInteger("6777133339");
    return 0;
}