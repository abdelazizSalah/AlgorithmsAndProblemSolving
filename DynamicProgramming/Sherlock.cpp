#include <bits/stdc++.h>    
using namespace std;
#define fast ios_base :: sync_with_stdio(0) ,cin.tie(0), cout.tie(0); 
using ll = long long;
using ull = unsigned long long;

//string product(string x, string y)
//{
//    if (x == "0" || y == "0") return"0";
//
//    vector<int>v(x.size() + y.size() + 1);
//    reverse(y.begin(), y.end());
//    reverse(x.begin(), x.end()); // 34an 3auz amshy 3lehom ml ymen lel shmal 
//
//    for (int i = 0; i < x.length(); i++) // multipling the two digits as string and storing there value in the vector without computing the carry
//        for (int j = 0; j < y.length(); j++)
//            v[i + j] += (x[i] - '0') * (y[j] - '0');
//
//    for (int i = 0; i < v.size() - 1; i++)
//    {
//        v[i + 1] += v[i] / 10;  // traversing the carry
//        v[i] %= 10; // getting the remainder
//    }
//
//    for (int i = v.size() - 1; i >= 0; i--)
//        if (v[i] == 0) v[i] = INT_MAX;
//        else break;
//
//
//    string s = "";
//    for (ll i = v.size() - 1; i >= 0; i--)
//    {
//        if (v[i] == INT_MAX) continue;
//        else s += to_string(v[i]);
//    }
//    return s;
//}
//
//string sum(string x, string y)
//{
//    int mx = max(x.length(), y.length());
//    vector<int>v(mx + 1);
//    //reverse(y.begin(), y.end());
//    //reverse(x.begin(), x.end()); // 34an 3auz amshy 3lehom ml ymen lel shmal 
//
//    int mn = min(x.length(), y.length());
//    for (int i = 0; i < mn; i++) // multipling the two digits as string and storing there value in the vector without computing the carry
//        v[i] += (x[x.length() - i - 1] - '0') + (y[y.length() - i - 1] - '0');
//
//
//    if (mn = x.length()) // h7ot ba2y el chars zy mhoma f el fadl
//        for (int i = mn; i < y.length(); i++)
//            v[i] += y[y.length() - i - 1] - '0';
//    else
//        for (int i = mn; i < x.length(); i++)
//            v[i] += x[x.length() - i - 1] - '0';
//
//
//
//    for (int i = 0; i < v.size() - 1; i++)
//    {
//        v[i + 1] += v[i] / 10;  // traversing the carry
//        v[i] %= 10; // getting the remainder
//    }
//
//    for (int i = v.size() - 1; i >= 0; i--)
//    {
//        if (v[i] == 0) v[i] = INT_MAX;
//        else break;
//    }
//
//    string s = "";
//    for (int i = v.size() - 1; i >= 0; i--)
//    {
//        if (v[i] == INT_MAX) continue;
//        else s += to_string(v[i]);
//    }
//    return s;
//}
//void fibModTabul() // tabulation .....
//{
//    int t1, t2, n; cin >> t1 >> t2 >> n;
//    vector<string>table(n + 1, "0");
//    table[0] = "0";
//    table[1] = to_string(t1);
//    table[2] = to_string(t2);
//
//    for (int i = 3; i <= n; i++)
//    {
//        string tt2 = product(table[i - 1], table[i - 1]); // t(i+1)^2
//        table[i] = sum(table[i - 2], tt2);
//    }
//
//    cout << table[n];
//}
//

//
int maxA(vector<int>& B, vector<int> A, int& mxim , int idx = 0)
{
	//base case
	if (A.size() == B.size())
	{
		int mx = INT_MIN;
		for (int i = 0; i < A.size() - 1; i++)
			mx = max(mx, abs(A[i] - A[i + 1]));

		mxim = max(mx, mxim);
		return mxim;
	}

	int mximum;
	for (int i = 0; i < B.size(); i++)
	{
		if (i + 1 <= B[i])
			A.push_back(i + 1); 
		mximum = maxA(B, A, mxim); 
	}
	return mxim;
}


void solve()
{
	int n; cin >> n;
	vector<int>B(n);
	for (int& x : B) cin >> x;
	vector<int>A;
	int mxx = INT_MIN;
	cout << maxA(B, A, mxx);

}
int main()
{
	fast;
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}