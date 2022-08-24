#include<iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std; 
using ll = long long; // using is similar to #define
//#include <bits/stdc++.h> library which contains all libraries
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); //el satr da fe hagat fl iostream library btbt2 ell code fa de bt5leh yeb2a asr3

	//el capacity msh btdrb fe 2 , btdrb fe 1.5 bs
	vector<int> v4(5 ,10);
	cout << v4.capacity() << endl;
	v4.push_back(1);
	cout << v4.capacity();
	//resize msh btms7 el elements el zyada ...
	//34an ams7hom bst5dm function esmha shrink to fit
	vector<int>::iterator it = v4.begin();
	for (; it != v4.end(); it++)
		cout << *it << ' ';

	cout << endl; 
	vector <int> ::reverse_iterator it2 = v4.rbegin();
	for (; it2 != v4.rend(); it2++)
		cout << *it2 << ' ';

	//random access iterator
	//da iterator a2dr adelo el address w hwa yro7 3leh 3toul
	auto it3 = v4.begin() + 3;
	cout << *it3; // msh kol el data structures btsupport el no3 da
	
	return 0;
}