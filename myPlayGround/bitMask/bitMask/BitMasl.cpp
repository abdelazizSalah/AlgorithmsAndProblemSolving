#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using ll = long long;
int main()
{
	fast;
	deque<int> v{ 1 ,1 ,2 ,2,3, 3,4 , 5 ,6 , 6 ,7 , 8 , 9 ,9 };
	// this is how we can detect the unique value in a redundant set of integers
	while (v.size())
		if (v.size() > 1 && !(v[0] ^ v[1]))
			for (int i = 0; i < 2; i++)
			{
				v.pop_front();
			}
		else
		{
			cerr << v[0] << '\n';
			v.pop_front();
		}
	//this is how to determine wethere a number is even or odd without using modulos operator :)
	ll x;
	cin >> x;
	if (x & 1)cerr << "odd"; // faster than % and better
	else
		cerr << "even";

	//max digits for int is 10 while max digits for ll is 19
	cin >> x;
	ll numberofdigits = to_string(x).length(); // this is how we can calculate the number of digits easliy without loops
	cerr << numberofdigits;

	//how to calculate the number of set bits
	int a = 5, b = 7;
	int res = a ^ b;
	int counter = 0;
	while (res > 0)
	{
		if (res & 1)
			counter++;

		//to use the shifters you must store them in a lvalue
		res = res >> 1; // divide it by 2 every time
		///
		/// 5=> 101
		/// 7=> 111
		/// ^-------
		///     010
		/// &     1=> 0
		/// --------
		///      01
		/// &     1 => 1
		/// -------
		///       0
		/// &     1=> 0
	}
	cerr << '\n' << counter;

	//if you want to remove the last set bit
	int s = 13; 
	int z = s & (s - 1); // this removes the last set bit

	//if you want to swap a and b use xor swapping it is the best method
	int l = 12; 
	int k = 6;
	l = l ^ k; // 12 ^ 6
	k = k ^ l; //6 ^ 12 ^ 6
	l = l ^ k; //12 ^ 6 ^ 12 !!!! to7faaaaaa
	cerr<<'\n' << l << ' ' << k;


	exit(0); // this terminate the program
	return 0;
}