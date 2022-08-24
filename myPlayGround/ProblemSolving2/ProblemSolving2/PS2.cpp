#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <utility>
#include <math.h>
using namespace std;
void factorsof(long long x, vector <int>& arr);
int main()
{
	// problem 38  Mahmoud and the longest uncommon


	////problem 39
	//bool vis[100001]{}; // this is an array to determine wether we have the number or not
	//int n, a;
	//cin >> n;
	//int target = n;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> a; //4 5 1 2 3 
	//	vis[a] = 1; //mark the number as visted
	//	if (a == target)
	//	{
	//		for (int k = a; k > 0; k--)
	//		{
	//			if (!vis[k])break;//lw el rkm da mgash lesa khlas e5rog ml loop
	//			else
	//			{
	//				cout << k << ' ';
	//				target = k - 1;
	//			}
	//		}
	//	}
	//	cout << "\n";
	//}
	////problem 40
	//vector <int> v1;
	//int n; 
	//cin >> n; 
	//for (int i = 0; i < n; i++)
	//{
	//	int x; 
	//	cin >> x; 
	//	v1.push_back(x);
	//}
	//int min = *min_element(v1.begin(), v1.end());
	//int max = *max_element(v1.begin(), v1.end());
	//int count = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	if ((v1[i] > min) && (v1[i] < max))
	//		count++;
	//}
	//cout << count;
	////problem 41
	/*int n;
	cin >> n;
	if (n < 26) cout << "NO";
	else
	{
		//map or sets or any container which has unique values
		map<char, char> m1;
		for (int i = 0; i < n; i++)
		{
			char c;
			cin >> c;
			if (c < 97)
				c += 32;
			m1[c] = c;
		}

		if (m1.size() == 26)
			cout << "YES";
		else
			cout << "NO";*/
			/*	set<char> s1;
				int n;
				cin >> n;
				if (n < 26)
					cout << "NO";
				else
				{
					for (int i = 0; i < n; i++)
					{
						char c;
						cin >> c;
						if (c < 97)
							c += 32;
						s1.insert(c);
					}
					if (s1.size() == 26)
						cout << "YES";
					else
						cout << "NO";
				}
			*/

			////this is the donkey work
			//int n;
			//cin >> n;
			//if (n < 26) cout << "NO";
			//else
			//{
			//	string S;
			//	cin >> S;
			//	for (int i = 0; i < n; i++)
			//	{
			//		//making all letters small
			//		if (S[i] < 97)
			//			S[i] += 32;
			//	}

			//	bool vis[26]{};
			//	for (int i = 0; i < n; i++)
			//	{
			//		switch (S[i])
			//		{
			//		case 'a': vis[0] = 1; break;
			//		case 'b': vis[1] = 1; break;
			//		case 'c': vis[2] = 1; break;
			//		case 'd': vis[3] = 1; break;
			//		case 'e': vis[4] = 1; break;
			//		case 'f': vis[5] = 1; break;
			//		case 'g': vis[6] = 1; break;
			//		case 'h': vis[7] = 1; break;
			//		case 'i': vis[8] = 1; break;
			//		case 'j': vis[9] = 1; break;
			//		case 'k': vis[10] = 1; break;
			//		case 'l': vis[11] = 1; break;
			//		case 'm': vis[12] = 1; break;
			//		case 'n': vis[13] = 1; break;
			//		case 'o': vis[14] = 1; break;
			//		case 'p': vis[15] = 1; break;
			//		case 'q': vis[16] = 1; break;
			//		case 'r': vis[17] = 1; break;
			//		case 's': vis[18] = 1; break;
			//		case 't': vis[19] = 1; break;
			//		case 'u': vis[20] = 1; break;
			//		case 'v': vis[21] = 1; break;
			//		case 'w': vis[22] = 1; break;
			//		case 'x': vis[23] = 1; break;
			//		case 'y': vis[24] = 1; break;
			//		case 'z': vis[25] = 1; break;
			//		}
			//	}
			//	for (int i = 0; i < n; i++)
			//	{
			//		if (vis[i] == 0)
			//		{
			//			cout << "NO"; return 0;
			//		}
			//	}
			//	cout << "YES";
			//}
			////problem  41
	/*int n;
	vector<int> v1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v1.push_back(x);
	}
	sort(v1.begin(), v1.end());
	reverse(v1.begin(), v1.end());
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += v1[i];

	int noOfCoins = 0;
	int mid2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (mid2 <= (sum / 2))
		{
			noOfCoins++;
			mid2 += v1[i];
		}
		else
			break;
	}
	cout << noOfCoins;*/

	//////PROBLEM 63 KEYBOARD	
	////vector<char> v1 = { 'q','w','e','r','t','y','u','i','o','p' };
	////vector<char> v2 = { 'a','s','d','f','g','h','j','k','l',';' };
	////vector<char> v3 = { 'z','x','c','v','b','n','m',',','.','/' };
	////vector<char> correct;
	////char c;
	////cin >> c;
	////string sent;
	////cin >> sent;
	////int len = sent.length();
	////if (c == 'R')
	////{
	////	for (int i = 0; i < len; i++)
	////	{
	////		auto it = find(v1.begin(), v1.end(), sent[i]);
	////		if (it != v1.end())
	////		{
	////			--it;
	////			char s = *it;
	////			correct.push_back(s);
	////		}
	////		else
	////		{
	////			it = find(v2.begin(), v2.end(), sent[i]);
	////			if (it != v2.end())
	////			{
	////				it--;
	////				char s = *it;
	////				correct.push_back(s);
	////			}
	////			else
	////			{
	////				it = find(v3.begin(), v3.end(), sent[i]);
	////				if (it != v3.end())
	////				{
	////					it--;
	////					char s = *it;
	////					correct.push_back(s);
	////				}
	////			}
	////		}
	////	}
	////}
	////else if (c == 'L')
	////{
	////	for (int i = 0; i < len; i++)
	////	{
	////		auto it = find(v1.begin(), v1.end(), sent[i]);
	////		if (it != v1.end())
	////		{
	////			it++;
	////			char s = *it;
	////			correct.push_back(s);
	////		}
	////		else
	////		{
	////			it = find(v2.begin(), v2.end(), sent[i]);
	////			if (it != v2.end())
	////			{
	////				it++;
	////				char s = *it;
	////				correct.push_back(s);
	////			}
	////			else
	////			{
	////				it = find(v3.begin(), v3.end(), sent[i]);
	////				if (it != v3.end())
	////				{
	////					it++;
	////					char s = *it;
	////					correct.push_back(s);
	////				}
	////			}
	////		}
	////	}
	////}
	////for (int i = 0; i < correct.size(); i++)
	////	cout << correct[i];
	//	///problem 75 Even Odds
	//	int size, pos;
	//	int num = 1;
	//	cin >> size >> pos;
	//	vector <long long> v1(size);
	//	//if even
	//	if (!(size % 2))
	//	{
	//		for (long long i = 0; i < size / 2; i++)
	//		{
	//			v1[i] = num;
	//			num += 2;
	//		}
	//		num = 2;
	//		for (long long i = size / 2; i < size; i++)
	//		{
	//			v1[i] = num;
	//			num += 2;
	//		}
	//		cout << v1[pos - 1];
	//	}
	//	else
	//	{
	//		for (long long i = 0; i < size / 2 + 1; i++)
	//		{
	//			v1[i] = num;
	//			num += 2;
	//		}
	//		num = 2;
	//		for (long long i = size / 2 + 1; i < size; i++)
	//		{
	//			v1[i] = num;
	//			num += 2;
	//		}
	//		cout << v1[pos - 1];
	//	}
	//
	//	////another solution
	//	//long long size, pos, i;
	//	//cin >> size >> pos;
	//	//bool odd = false;
	//	//if (size % 2)
	//	//	odd = true;
	//
	//	//if (odd)
	//	//{
	//	//	if (pos <= (size / 2) + 1)
	//	//	{
	//	//		i = 1;
	//	//		for (long long x = 1; x < pos; x++)
	//	//			i += 2;
	//	//		cout << i;
	//	//	}
	//	//	else
	//	//	{
	//	//		i = 0;
	//	//		for (long long x = size / 2 + 1; x < pos; x++)
	//	//			i += 2;
	//	//		cout << i;
	//	//	}
	//	//}
	//	//else
	//	//{
	//	//	if (pos <= (size / 2))
	//	//	{
	//	//		i = 1;
	//	//		for (long long x = 1; x < pos; x++)
	//	//			i += 2;
	//	//		cout << i;
	//	//	}
	//	//	else
	//	//	{
	//	//		i = 0;
	//	//		for (long long x = size / 2; x < pos; x++)
	//	//			i += 2;
	//	//		cout << i;
	//	//	}
	//	//}
	//////another solution
	////	long long size, pos, midpoint,num;
	////	cin >> size >> pos;
	////	//odd
	////	if (size % 2)
	////	{
	////		midpoint = (size / 2 + 1);
	////		if (pos > midpoint)
	////			num = (pos - size / 2 - 1) * 2;
	////		else
	////			num = (pos * 2) - 1;
	////		cout << num;
	////	}
	////	else // even
	////	{
	////		midpoint = size / 2;
	////		if (pos > midpoint)
	////			num = (pos - size / 2) * 2;
	////		else
	////			num = (pos * 2) - 1;
	////		cout << num;
	////	}

	//problem 76
	/*short lvls;
	cin >> lvls;
	set <int> passed;
	int x, y;
	for (int  k = 0; k < 2; k++)
	{
		cin >> x;
		for (int i = 0; i < x; i++)
		{
			cin >> y;
			passed.insert(y);
		}
	}
	for (int i = 1; i <= lvls; i++)
	{
		auto it = passed.find(i);
		if (it == passed.end())
		{
			cout << "Oh, my keyboard!";
			return 0;
		}
	}
	cout << "I become the guy.";*/

	//problem 77 is it rated?
	////short no;
	////cin >> no;
	////bool changed = false;
	////pair<int, int> teams[1000]; 
	////for (short i = 0; i < no; i++)
	////{
	////	int x;
	////	cin >> x;
	////	teams[i].first = x;
	////	cin >> x;
	////	teams[i].second = x;
	////	if (teams[i].first != teams[i].second)
	////		changed = true;
	////}
	////if (!changed)
	////{
	////	for (int i = 0; i < no; i++)
	////	{
	////		for (int k = i + 1; k < no; k++)
	////		{
	////			if (teams[k].first > teams[i].first)
	////			{
	////				cout << "unrated";
	////				return 0;

	////			}
	////		}
	////	}
	////	cout << "maybe";
	////	return 0;
	////}
	////else
	////	cout << "rated";
	////return 0;

	//problem 78 Olesya and Rodion
//int no, div;
//cin >> no >> div;
//long long x = pow(4 , no - 1);
//for (long long i = x; i < 10 * x; i++)
//	if (i % div == 0)
//	{
//		cout << i;
//		return 0;
//	}
//cout << -1;
//another solution

	/*int n, t; cin >> n >> t;
	string x = "\0";
	if (t == 10)
	{
		if (n == 1)
		{
			cout << -1;
			return 0;
		}
		else
		{
			while (n--)
			{
				x += '0';
			}
			x[0] = '1';
			cout << x;
			return 0;
		}
	}

	while (n--)
	{
		x += char(t + 48);
	}
	cout << x;*/

	//79 football
	////short n;
	////cin >> n;
	////pair<string, int> teams[100];
	////for (int i = 0; i < n; i++)
	////{
	////	cin >> teams[i].first;
	////	teams[i].second = 1;
	////}
	////for (int i = 0; i < n; i++)
	////{
	////	for (int k = i + 1; k < n; k++)
	////	{
	////		if (teams[i].first == teams[k].first)
	////		{
	////			teams[i].second++;
	////		}
	////	}
	////}
	////int max = teams[0].second;
	////int index = 0;
	////for (int i = 1; i < n; i++)
	////{
	////	if (max < teams[i].second)
	////	{
	////		max = teams[i].second;
	////		index = i;
	////	}
	////}
	////cout << teams[index].first;
	//poblem 80 Brain's Photos
	/*int x, y;
	cin >> x >> y;
	int len = x * y;
	char* color = new char[len];
	for (int i = 0; i < len; i++)
		cin >> color[i];

	for (int i = 0; i < len; i++)
	{
		if (color[i] == 'C' || color[i] == 'Y' || color[i] == 'M')
		{
			cout << "#Color";
			delete[] color;
			return 0;
		}
	}
	cout << "#Black&White";
	delete[] color;*/

	//////problem 81 Dubstep
	////string a;
	////string b = "WUB";
	////deque<char> c;
	////cin >> a;
	////int len = a.length();
	////for (int i = 0; i < len; i += 3)
	////{
	////	if ((a[i] == b[0]) && (a[i + 1] == b[1]) && (a[i + 2] == b[2]))
	////	{
	////		if (c.empty())
	////			continue;
	////		c.push_back(' ');
	////	}
	////	else
	////	{
	////		c.push_back(a[i]);
	////		i -= 2;
	////	}
	////}

	////len = c.size();
	////if (c[len - 1] == ' ')
	////{
	////	c.pop_back();
	////	len--;
	////}

	////for (int i = 0; i < len; i++)
	////{
	////	if (i != len - 1)
	////		if ((c[i] == c[i + 1])&&(c[i] == ' '))
	////			continue;
	////	cout << c[i];
	////}

////	// PROBLEM 82 Valera and X
////	int n;
////	cin >> n;
////	string* s = new string[n];
////	for (int i = 0; i < n; i++)
////		cin >> s[i];
////	char a = s[0][0]; //diagonall char
////	char b = s[0][1]; // the other char
////	int end = n;
////	if (a == b) // if the two chars are similar then end 
////	{
////		cout << "NO";
////		delete[]s;
////		return 0;
////	}
////	//itertate over every single char
////	for (int i = 0; i < n; i++)
////	{
////		for (int k = 0; k < n; k++)
////		{
//////diagonal chars are on [0][0] [0][4], [1][1] [1][3] , [2][2] , [3][1] [3][3] , [4][0] [4][4] so this is the condition
////			if ((i == k) || (k == end - 1))
////			{
////				if (s[i][k] != a)
////				{
////					cout << "NO";
////					delete[]s;
////					return 0;
////				}
////			}
////			else
////			{
////				if (s[i][k] != b) //if it was not a diagonal char then it should be the other char so if it is not then end
////				{
////					cout << "NO";
////					delete[]s;
////					return 0;
////				}
////			}
////		}
////		end--;
////	}
////	cout << "YES";
////	delete[]s;
///problem 83 Arpa’s hard exam and Mehrdad’s naive cheat
//according to the number theory 
////the power moves on a certain sequence which is 8 4 2 6
//long long n;
//cin >> n;
//int x = n % 4;
//if (n == 0)
//{
//	cout << 1;
//	return 0;
//}
//switch (x)
//{
//case 0: cout << 6; break;
//case 1: cout << 8; break;
//case 2: cout << 4; break;
//default: cout << 2; break;
//}

//problem 84 Calculating Function
// el tre2a de s7 bs hatedy time exceed 
//long long n; 
//cin >> n;
//long long sum = 0;
//for (int i = 1; i <= n; i++)
//	sum += pow(-1, i) * i;
//cout << sum;
//another solution
//logical solution -> think before write ;) ana el 7ltha mn gher videos
	//long long n;
	//cin >> n;
	//// if odd
	//if (n == 1)
	//	cout << -1;
	//else if (n % 2)
	//	cout << -(n / 2) - 1;
	//else
	//	cout << n / 2;
//problem 85 Theatre Square
//double n, m, a;
//cin >> n >> m >> a;
//long long x = (ceil(n / a)* ceil(m / a));
//cout << std::fixed << x; // fixed is used to remove the scientific notation

//problem 86 Anton and Polyhedrons
////int n; 
////cin >> n;
////vector <string> p1;
////for (int i = 0; i < n; i++)
////{
////	string s; 
////	cin >> s;
////	p1.push_back(s);
////}
////int sum = 0;
////for (auto it : p1)
////{
////	if (it == "Icosahedron")
////		sum += 20;
////	else if (it == "Dodecahedron")
////		sum += 12;
////	else if (it == "Octahedron")
////		sum += 8;
////	else if (it == "Cube")
////		sum += 6;
////	else
////		sum += 4;
////}
////cout << sum;
////problem 87 Panoramix's Prediction
////	vector <short> v1 = { 1 , 2 ,3 ,5 ,7,11,13,17 ,19 ,23 ,29 ,31 ,37 , 41 ,43 ,47 };
////	int n = 0, m = 0;
////	cin >> n >> m;
////	for (int i = 0; i < 17; i++)
////	{
////		if (v1[i] == m)
////		{
////			if (n == v1[i - 1])
////				cout << "YES";
////			else
////				cout << "NO";
////			return 0;
////		}
////	}
////	cout << "NO";
// problem 88 conterexample
// coprime -> the only common divisor is 1
//a < b < c && l <= a && c <= R
//long long a, b;
//cin >> a >> b;
//if (a % 2 != 0)
//a++;
//if (abs(b - a) < 2)
//	cout << -1;
//else
//cout << a << ' ' << a + 1 << ' ' << a + 2;

//////problem 100 good number
////	int n, k, cntr = 0;
////	cin >> n >> k;
////	for (int i = 0; i < n; i++)
////	{
////		int s;
////		bool found = true;
////		vector <int> arr(k + 1, 0);
////		cin >> s;
////		while (s)
////		{
////			int a = s % 10;
////			s /= 10;
////			if (a > k)
////				continue;
////			arr[a] = 1;
////		}
////		if (found)
////		{
////			for (int p = 0; p <= k; p++)
////				if (arr[p] != 1)
////				{
////					found = false;
////					break;
////				}
////
////			if (found)
////				cntr++;
////		}
////	}
////	cout << cntr;
//problem 101 Dice Tower 

return 0;

}
