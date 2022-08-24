#include <bits/stdc++.h> // this is a library which contains all used libraries in problem solving
#include <iostream>
#include <set>
#include<map>
#include <deque>
#include <vector>
#include <utility>
#include <string>
#include<algorithm>
#define hash "####"
#define dot "...."
/////
using ll = long long;
#define ssssssss int 
/////
using namespace std;
int r1, r2, c1, c2, d1, d2;
bool check(int& a1, int& a2, int& a3, int& a4)
{
	return(a1 + a2 == r1 && a3 + a4 == r2 && a1 + a3 == c1 && a2 + a4 == c2 && a1 + a4 == d1 && a3 + a2 == d2);
}
int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}
void swap(int& x, int& y)
{
	int z = x;
	x = y;
	y = z;
}
bool check(vector <int>& v)
{
	int size = v.size();
	for (int i = 0; i < size - 1; i++)
	{
		if (v[i] == v[i + 1])
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); //el satr da fe hagat fl iostream library btbt2 ell code fa de bt5leh yeb2a asr3
	vector <int> c1;
	/* problem 101 die tower
		int n, x;
		cin >> n >> x;
		int low = 7 - x;
		bool extra = false;
		vector<int> sss;
		for (int i = 0; i < n; i++)
		{
			vector<int> v1(6, 0);
			v1[x - 1] = 1;
			int a, b;
			cin >> a >> b;
			v1[a - 1] = v1[b - 1] = 1;
			v1[7 - a - 1] = v1[7 - b - 1] = 1;
			for (int j = 0; j < 6; j++)
				if (v1[j] == 0)
					sss.push_back(j + 1);

			if (sss.size() > 2)
				extra = true;
			else
			{
				sss.clear();
				for (int s = 0; s < 6; s++)
				{
					if (v1[s] == 0)
					{
						x = s + 1;
						sss.push_back(x);
						break;
					}
				}
			}
			if (extra && sss.size() >= 3 && i != 1)
			{
				extra = false;
				bool cant = true;
				int lem = sss.size();
				int save;
				for (int i = 1; i < lem; i++)
				{
					for (int k = i + 1; k < lem; k++)
					{
						if (sss[k] == sss[i])
						{
							cant = false;
							save = k + 1;
							break;
						}
					}
					if (!cant)
						break;
				}
				if (cant)
				{
					cout << "NO";
					return 0;
				}
				else
				{
					sss.clear();
					sss.push_back(save);
				}
			}
		}
		if (sss.size() > 1)
			cout << "NO";
		else
			cout << "YES";*/ // my solution 
			//another solution
			/*int n, x, f1, f2;
			cin >> n >> x;
			while (n--)
			{
				cin >> f1 >> f2;
				if(x == f1 || f1 == 7 - x || f2 == x || f2 == 7 - x)
				{
					cout << "NO"; return 0;
				}
			}
			cout << "YES";
			return  0;*/
			//problem 102  Alyona and Numbers
			// time exceeded solution o(n^2)
			//int x, y , cntr = 0;
			//cin >> x >> y;

			//if (x < y)
			//	for (int i = 1; i <= x; i++)
			//	{
			//		for (int j = 1; j <= y; j++)
			//		{
			//			if (5 * j - i > y) // conducted formula
			//				break;
			//			else if(5 * j - i > 0)
			//				cntr++;
			//		}
			//	}
			//else
			//	for (int i = 1; i <= y; i++)
			//	{
			//		for (int j = 1; j <= x; j++)
			//		{
			//			if (5 * j - i > x) // conducted formula
			//				break;
			//			else if (5 * j - i > 0)
			//				cntr++;
			//		}
			//	}
			////cout << cntr; 
			//int x, y, a = 1 ,cntr = 0;
			//cin >> x >> y;
			//if (x < y)
			//{
			//	for (int i = 1; i <= x; i++)
			//	{
			//		if (i % 5 == 0)
			//			a++;
			//		for (int k = (5*a) - i; k <= y; k+= 5)
			//		{
			//			 if (k > 0)
			//				cntr++;
			//		}
			//	}
			//}
			//else
			//{
			//	for (int i = 1; i <= y; i++)
			//	{
			//		if (i % 5 == 0)
			//			a++;
			//		for (int k = (5 * a) - i; k <= x; k += 5)
			//		{
			//			if (k > 0)
			//				cntr++;
			//		}
			//	}
			////}
			//cout << cntr;
			// not my solution but briliant ***
			//long long x, y, a[5], b[5];
			//do
			//{
			//	cin >> x >> y;
			//	for (int i = 0; i < 5; i++)
			//		a[i] = b[i] = 0;
			//	for (int i = 1; i <= x; i++) {
			//		a[i % 5]++;
			//	}
			//	for (int i = 1; i <= y; i++) {
			//		b[i % 5]++;
			//	}
			//	cout << (a[0] * b[0] + a[1] * b[4] + a[2] * b[3] + a[3] * b[2] + a[4] * b[1]);
			//	return 0;
			//} while (x > 0);

			////problem 103 Mountain Scenery
			//vector<int> peaks;
			//int n, k, rised = 0;
			//vector<int> points;
			//cin >> n >> k;
			//for (int i = 0; i <= 2 * n; i++)
			//{
			//	int x;
			//	cin >> x;
			//	points.push_back(x);
			//}
			//for (int i = 1; i < 2 * n; i++)
			//{
			//	if (points[i] > points[i - 1] && points[i] > points[i + 1] && rised < k)
			//	{
			//		if (points[i] - 1 > points[i - 1] && points[i] - 1 > points[i + 1]) // to still be a peak 
			//		{
			//			points[i] --;
			//			rised++;
			//		}
			//	}
			//}
			//for (auto it : points)
			//	cout << it << ' ';

		//problem 104 Help Vasilisa the Wise 2
		//by using brute force method
		/*	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
			for (int x00 = 1; x00 < 10; x00++)
			{
				for (int x01 = 1; x01 < 10; x01++)
				{
					if (x00 == x01)continue;
					for (int x10 = 1; x10 < 10; x10++)
					{
						if (x00 == x10 || x10 == x01)continue;
						for (int x11 = 1; x11 < 10; x11++)
						{
							if (x11 == x00 || x11 == x01 || x11 == x10)continue;
							if (check(x00, x01, x10, x11))
							{
								cout << x00 << ' ' << x01 << endl << x10 << ' ' << x11;
								return 0;
							}
						}
					}
				}
			}
			cout << -1;*/
			////	//problem 105 Chewbacca and number
			////long long x;
			////cin >> x;
			////if(x == 9)
			////{
			////	cout << 9; return 0; 
			////}
			////deque <int> d1;
			////while (x)
			////{
			////	int c = x % 10;
			////	int t = 9 - c;
			////	if(t < c)
			////		d1.push_front(t);
			////	else
			////		d1.push_front(c);
			////
			////	x /= 10;
			////}
			////if (d1.front() == 0)
			////	d1[0] = 9;
			////
			////while (!d1.empty())
			////{
			////	cout << d1.front();
			////	d1.pop_front();
			////}
			////problem 106 Ksenia and Pan Scales
		////valid solution
		//vector<char>left, right;
		//string c1, c2;
		//cin >> c1;
		//int l1 = c1.length();
		//for (int i = 0; i < l1; i++)
		//{
		//	if (c1[i] != '|')
		//		left.push_back(c1[i]);
		//	else
		//	{
		//		i++;
		//		while (i != l1)
		//		{
		//			right.push_back(c1[i]);
		//			i++;
		//		}
		//	}
		//}

		//cin >> c2;
		//int l2 = c2.length();
		//for (int i = 0; i < l2; i++)
		//{
		//	if (left.size() < right.size())
		//		left.push_back(c2[i]);
		//	else
		//		right.push_back(c2[i]);
		//}

		//if (left.size() != right.size())
		//	cout << "Impossible";
		//else
		//{
		//	for (auto it : left)
		//		cout << it;
		//	cout << '|';
		//	for (auto it : right)
		//		cout << it;
		//}
	////	//problem 107 Launch of Collider
	////int n;
	////cin >> n;
	////vector<pair<char, int>> p;
	////vector <int> time;
	////string s;
	////cin >> s;
	////for (int i = 0; i < n; i++)//intializing the characters
	////	p.push_back({ s[i] , -1 });


	////for (int i = 0; i < n; i++)//intializing the positions
	////	cin >> p[i].second;

	////for (int i = 0; i < n - 1; i++)
	////	if (p[i].first == 'R' && p[i + 1].first == 'L')//this is the only way to collide from the right 
	////	{
	////		time.push_back((p[i + 1].second - p[i].second) / 2);
	////		i++;
	////	}

	////int min = -1;
	////int len = time.size();
	////if (len != 0)
	////{
	////	min = time[0];
	////	for (int i = 0; i < len; i++)//finding the minimum time
	////		if (time[i] < min)
	////			min = time[i];
	////}
	////cout << min;
	//////problem 108 Polo the Penguin and Segments
	////unsigned n, k, sum = 0;
	////cin >> n >> k;
	////
	////for (int i = 0; i < n; i++)
	////{
	////	int x, y;
	////	cin >> x >> y;
	////	sum += abs(y - x) + 1; // calculating the sum of points
	////}
	////n = 0; // number of added points
	////while (sum % k)//calculating number of added points
	////{
	////	sum++;
	////	n++;
	////}
	////cout << n;
//1 C Drazil and factorials
////long long n;
////cin >> n;
////cin >> n;
////int sum = 1;
//////multiset because it sort items automatically
////multiset<int> v1;
////while (n)
////{
////	int x = n%10;
////	n /= 10; 
////	switch (x)
////	{
////	case 2: v1.insert(2); break;
////	case 3: v1.insert(3); break;
////	case 4: v1.insert(3); v1.insert(2); v1.insert(2);  break;
////	case 5: v1.insert(5); break;
////	case 6: v1.insert(3); v1.insert(5);  break;
////	case 7: v1.insert(7); break;
////	case 8: v1.insert(2); v1.insert(2); v1.insert(2); v1.insert(7); break;
////	case 9: v1.insert(2); v1.insert(3); v1.insert(3); v1.insert(7);  break;
////	}
////}
////multiset <int> ::reverse_iterator it = v1.rbegin();
////while (it != v1.rend())
////{
////	cout << *it;
////	it++;
////}
	//problem 109 IQ TEST
	// first solution but not the best one 
////	string s1, s2, s3, s4;
////	cin >> s1 >> s2 >> s3 >> s4;
////	if (((s1 == s2) && (s1 == hash)) || ((s2 == s3) && (s2 == hash)) || ((s3 == s4) && (s3 == hash)))
////	{
////		cout << "YES";
////		return 0;
////	}
////	if (((s1 == s2) && (s1 == dot)) || ((s2 == s3) && (s2 == dot)) || ((s3 == s4) && (s3 == dot)))
////	{
////		cout << "YES";
////		return 0;
////	}
////
////	for (int i = 0; i < 3; i++)
////	{
////		if (s1[i] == '#')
////		{
////			if (s1[i + 1] == '#')
////			{
////				if (s2[i] == '#')
////				{
////					/*if (s2[i + 1] == '#')
////					{
////						cout << "NO";
////						return 0;
////					}
////					else
////					{
////						cout << "YES";
////						return 0;
////					}*/
////					cout << "YES";
////					return 0;
////				}
////				else
////				{
////					if (s2[i + 1] == '#')
////					{
////						cout << "YES";
////						return 0;
////					}
////				}
////			}
////			else
////			{
////				if (s2[i] == '#' && s2[i + 1] == '#')
////				{
////					cout << "YES"; 
////					return 0;
////				}
////				else if (s2[i] == '.' && s2[i + 1] == '.')
////				{
////					cout << "YES";
////					return 0;
////				}
////			}
////		}
////		else
////		{
////			if (s1[i + 1] == '.')
////			{
////				if (s2[i] == '.')
////				{
////					cout << "YES";
////					return 0;
////				}
////				else
////				{
////					if (s2[i + 1] == '.')
////					{
////						cout << "YES";
////						return 0;
////					}
////				}
////			}
////			else
////			{
////				if (s2[i] == '.' && s2[i + 1] == '.')
////				{
////					cout << "YES";
////					return 0;
////				}
////				else if (s2[i] == '#' && s2[i + 1] == '#')
////				{
////					cout << "YES";
////					return 0;
////				}
////			}
////		}
////	}
////	////////
////	for (int i = 0; i < 3; i++)
////	{
////		if (s2[i] == '#')
////		{
////			if (s2[i + 1] == '#')
////			{
////				if (s3[i] == '#')
////				{
////					cout << "YES";
////					return 0; 
////				}
////				else
////				{
////					if (s3[i + 1] == '#')
////					{
////						cout << "YES";
////						return 0;
////					}
////				}
////			}
////			else
////			{
////				if (s3[i] == '#' && s3[i + 1] == '#')
////				{
////					cout << "YES";
////					return 0;
////				}
////				else if (s3[i] == '.' && s3[i + 1] == '.')
////				{
////					cout << "YES";
////					return 0;
////				}
////			}
////		}
////		else
////		{
////			if (s2[i + 1] == '.')
////			{
////				if (s3[i] == '.')
////				{
////					cout << "YES";
////					return 0;
////				}
////				else
////				{
////					if (s3[i + 1] == '.')
////					{
////						cout << "YES";
////						return 0;
////					}
////				}
////			}
////			else
////			{
////				if (s3[i] == '.' && s3[i + 1] == '.')
////				{
////					cout << "YES";
////					return 0;
////				}
////				else if (s3[i] == '#' && s3[i + 1] == '#')
////				{
////					cout << "YES";
////					return 0;
////				}
////			}
////		}
////	}
////////////
////	for (int i = 0; i < 3; i++)
////	{
////		if (s3[i] == '#')
////		{
////			if (s3[i + 1] == '#')
////			{
////				if (s4[i] == '#')
////				{
////					cout << "YES";
////					return 0;
////				}
////				else
////				{
////					if (s4[i + 1] == '#')
////					{
////						cout << "YES";
////						return 0;
////					}
////				}
////			}
////			else
////			{
////				if (s4[i] == '#' && s4[i + 1] == '#')
////				{
////					cout << "YES";
////					return 0;
////				}
////				else if (s4[i] == '.' && s4[i + 1] == '.')
////				{
////					cout << "YES";
////					return 0;
////				}
////			}
////		}
////		else
////		{
////			if (s3[i + 1] == '.')
////			{
////				if (s4[i] == '.')
////				{
////					cout << "YES";
////					return 0;
////				}
////				else
////				{
////					if (s4[i + 1] == '.')
////					{
////						cout << "YES";
////						return 0;
////					}
////				}
////			}
////			else
////			{
////				if (s4[i] == '.' && s4[i + 1] == '.')
////				{
////					cout << "YES";
////					return 0;
////				}
////				else if (s4[i] == '#' && s4[i + 1] == '#')
////				{
////					cout << "YES";
////					return 0;
////				}
////			}
////		}
////	}
////
////	cout << "NO"; 
//problem 110 Yaroslav and Permutations
	////short n;
	////cin >> n;
	////vector<int> v1;
	//////reading the input
	////for (int i = 0; i < n; i++)
	////{
	////	int x;
	////	cin >> x;
	////	v1.push_back(x);
	////}
	////sort(v1.begin(), v1.end()); // sort the vector to easily count the repeations
	////int max2 = 1;
	//////find the largest sequence of number
	////for (int i = 0; i < n - 1; i++)
	////{
	////	int max = 1;
	////	while (i != n - 1 && v1[i] == v1[i + 1])
	////	{
	////		max++;
	////		i++;
	////	}
	////	if (max > max2)
	////		max2 = max;
	////}
	//////apply the rule 
	////(n >= max2 * 2 - 1) ? cout << "YES" : cout << "NO";

//problem 111 snow Footprint


//problem 112 Raising Bacteria
int x;
cin >> x;


	return 0;
}

/////
//// to test from a file not from the console
// #ifndef ONLINE_JUDGE
//	freopen(/*name of the file*/ , "rt" , stdin);
// #endif
////