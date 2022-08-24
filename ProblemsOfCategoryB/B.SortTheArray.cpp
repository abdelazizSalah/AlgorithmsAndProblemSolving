//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0) 
//
//void solve()
//{
//	// reading the data
//	int n; cin >> n; 
//	vector<int> arr(n); 
//	for (int& i : arr) cin >> i; 
//
//	// setting utility vars 
//	bool up = true; 
//	int s = 0; 
//	int e = s; 
//	// iterating over the array
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (arr[i + 1] < arr[i] && up)
//		{
//			up = false; // we started to be down 
//			s = i; 
//		}
//
//		if (arr[i + 1] > arr[i] && !up)
//		{
//			// we raised again 
//			e = i; 
//			up = true; 
//			break; 
//		}
//	}
//	if (!up) // if the array is sorted descendingly
//		e = n -1; 
//
//	//sort that part of the arr
//	sort(arr.begin() + s, arr.begin() + e+1); 
//
//	if (is_sorted(arr.begin(), arr.end()))
//		cout  << "yes\n"<< s + 1 << ' ' << e + 1;
//	else
//		cout << "no"; 
//
//}
//
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}