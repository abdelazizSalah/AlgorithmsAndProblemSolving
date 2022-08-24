#include <bits/stdc++.h>   

using namespace std;
#define fast ios_base::sync_with_stdio(0),  cin.tie(0) , cout.tie(0); 
using ll = long long;

void solve()
{
    //read data 
    int n; cin >> n;
    multimap<int, int, greater<>> table; // time table 
    vector<int> ddl(n);

    // reading deadlines
    for (int i = 0; i < n; i++)
        cin >> ddl[i];

    //mapping deadlines with their penalities
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        table.insert({ x, ddl[i] });
    }

    vector<int> ans(n + 1); // to sort elements inside it
    auto it = table.begin();
    ll penality = 0;
    for (int i = 0; i < n ; i++)
    {
        bool placed = false;  // to determine wether we have placed the element or we need to take it as penality
        int j = it->second; // -1 to work 0 from index
        if (ans[j] == 0)
        {
            ans[j] = it->first;
            placed = true;
        } // if the index is not empty try to place in any previous positions sth like hashTabels
        else
        {
            while (j > 1) // check all positions 
            {
                j--;
                if (ans[j] < it->first) // if found empty place
                {
                    ans[j] = it->first;
                    placed = true;
                    break;
                }
            }
            if (!placed)
                penality += it->first;
        }
        it++;
    }
    cout << penality;
}

int main()
{
    fast;
    solve();
    return 0;
}