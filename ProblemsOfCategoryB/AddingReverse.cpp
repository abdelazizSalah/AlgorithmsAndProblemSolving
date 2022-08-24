//#include <bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0) , cin.tie(0),cout.tie(0); 
//using ll = long long;
//
//void solve()
//{
//	//read the strings 
//	string a, b; cin >> a >> b; 
//
//	//reverse them 
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//
//	//put the larger in a always
//	if (a.length() < b.length())
//		swap(a, b);  
//
//	//set carry flag into false 
//	bool carry = false; 
//
//	//define empty Queue as result
//	queue<int> result; 
//
//	//intiate reverse iterators 
//	int alen = a.length(); 
//	int blen = b.length(); 
//	auto aIt = a.rbegin();
//	auto bIt = b.rbegin(); 
//
//	//iterating over the smaller size 
//	while (blen > 0)
//	{
//		int res = 0; 
//		alen--; 
//		blen--; 
//
//		if (carry) {
//			carry = false;
//			res++; 
//		}
//		
//		res += (*aIt - '0') + (*bIt - '0'); 
//		
//		if (res > 9)
//		{
//			carry = true;
//			result.push(res % 10);
//		}
//		else
//			result.push(res); 
//
//		// increment the iterator
//		aIt++; bIt++; 
//	}
//
//	//iterating over the remaining digits 
//	while (alen--)
//	{
//		int res = 0; 
//		if (carry)
//		{
//			res++; 
//			carry = false; 
//		}
//
//		res += *aIt - '0'; 
//
//		if (res > 9)
//		{
//			carry = true;
//			result.push(res % 10);
//		}
//		else
//			result.push(res);
//
//	}
//
//	//if there is a remaining carry insert it in the end 
//	if (carry)
//		result.push(1); 
//
//	//removing the leading zeros 
//	while (result.front() == 0)
//		result.pop(); 
//
//	//printing the output
//	while (result.size())
//	{
//		cout << result.front();
//		result.pop(); 
//	}
//
//	cout << '\n'; 
//}
//
//int main()
//{
//	fast;
//	int n; cin >> n;
//	while (n--)
//		solve();
//	return 0;
//}
