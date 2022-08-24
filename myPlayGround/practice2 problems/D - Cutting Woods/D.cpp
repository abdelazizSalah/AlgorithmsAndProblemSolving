#include<bits/stdc++.h>
#include <set>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)
int main()
{
	fast;
	int len; cin >> len; 
	set<int>cutspoints; 
	cutspoints.emplace(0);
	cutspoints.emplace(len);
	int Q; cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int opr, idx; cin >> opr >> idx; 
		if (opr == 1) // cut 
			cutspoints.emplace(idx);
		else // view
		{
			auto it = cutspoints.lower_bound(idx);
			int R = *it; 
			it--;
			int L = *it;
			cout << R - L << '\n';
		}
	} //ms2laa helwaaa fashkhhhhhhhhhhhhhhhhhhhhhhhhhh
	// el fekra enk t3rf el location bta3 el at3 w t3rf meno atwl length!!!!!!!!!!!!!!!
	return 0;
}