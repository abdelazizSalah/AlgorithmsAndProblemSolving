//Accepted 
/*
explainations 
    i=1  f[i]=1

    i=2  f[i]=2=2!+0          0=2*(1-1)

    i=3  f[i]=9=3!+3          3=3*(2-1);

　　i=4  f[i]=56=4!+32        32=4*(9-1);

　　i=5   f[i]=395=5!+275     275=5*(56-1);

　　i=n : f[i]=n!+t           t=n*(f[n-1]-1);
*/
//#include <bits/stdc++.h>
//using namespace std; 
//#define fast ios_base ::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
//const int mx = (double)1e6 + 4; 
//const int mod = 998244353;
//using ll = long long; 
//int main() {
//	int n; cin >> n;
//	//preparing the factorials numbers till n
//	vector<ll> fact(mx); 
//	fact[1] = 1; 
//	for (int i = 2; i <= n; i++) {
//		fact[i] = (fact[i - 1] * i) % mod; 
//	}
//
//	//tabulation 
//	vector<ll> ans(mx);
//	// planting the seeds 
//	ans[1] = 1; 
//	ans[2] = 2;
//	
//	//applying the tabulations
//	for (int i = 3; i <= n; i++) {
//		ans[i] = (i * (ans[i -1] - 1) + fact[i] ) % mod; 
//	}
//
//	//printing the answer 
//	cout << ans[n]; 
//}