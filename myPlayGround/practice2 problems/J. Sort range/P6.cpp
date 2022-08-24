#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)
using ll = long long;
int main()
{
    fast; 
    int t, n, len, pos, val;
    cin >> t;
    while (t--) {
        cin >> n >> len >> pos;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        for (int i = 0; i < len; ++i) {
            cin >> val;
            pq.push(val);
        }
        ans.push_back(pq.top());
        pq.pop();
        for (int i = len; i < n; ++i) {
            cin >> val;
            pq.push(val);
            ans.push_back(pq.top());
            pq.pop();
        }
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        cout << ans[pos - 1] << '\n';
    }

    return 0;
}