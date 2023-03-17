#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return (gcd(b, a % b));
}
// // faster solution
// void solve()
// {
//     int n;cin>>n;
//     long long a[n+10],sum[n+10]={0};
//     long long ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];sum[i]=sum[i-1]+a[i];
//     }
//     for(int i=1;i<n;i++)
//     {
//         ans=max(ans, __gcd(sum[i],sum[n]-sum[i]));
//     }
//     cout<<ans<<endl;
//  
// }

ll solve()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    for (ll &a : A)
        cin >> a;
    ll sumAll = accumulate(A.begin(), A.end(), (ll)0); // lazm n3ml (ll) 34an ye3ml accumlate fe ll msh int
    ll incrementSum = 0;
    vector<ll> B(n);
    for (ll i = 0; i < n - 1; i++)
    {
        sumAll -= A[i];
        incrementSum += A[i];
        B[i] = gcd(incrementSum, sumAll);
    }
    return *max_element(B.begin(), B.end());
}

int main()
{
    DPSOLVER;
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << '\n';

    return 0;
}