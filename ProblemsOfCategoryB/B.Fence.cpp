//#pragma once
//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0) 
//using ll = long long; 
//
//void prefixSum(vector<ll>& v, int size)
//{
//	for (int i = 1; i <= size; i++)
//		v[i] += v[i - 1];
//}
//
//void solve()
//{
//	//reading the data
//	int n, k; cin >> n >> k; 
//	vector<int> v(n); 
//	vector<ll>psum(n); 
//
//	for (auto& it : v)
//		cin >> it; 
//
//	//setting the initial element
//	psum[0] = v[0];  
//
//	//before the k we de normal prefix sum
//	for (int i = 1; i < k; i++)
//		psum[i] = psum[i - 1] + v[i];
//
//	ll min = psum[k-1], idx = k - 1; 
//
//	//after the k we add a new element and subtract the oldest element
//	for (int i = k; i < n; i++)
//	{
//		psum[i] = psum[i - 1] + v[i] - v[i - k]; 
//
//		//storing the index of the minimum value
//		if (psum[i] < min)
//		{
//			min = psum[i]; 
//			idx = i; 
//		}
//	}
//
//	//i work 0 based and also i should subtract 1 from the k so total i need to subtract 2
//	if (k != 1)
//		cout << (idx + 1) - (k - 1);
//	else
//		cout << idx + 1; 
//	
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}