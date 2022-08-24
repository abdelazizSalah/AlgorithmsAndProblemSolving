#include <iostream>
using namespace std;
// #include <bits/stdc++.h> used for memset lib
#include<string>
#include<math.h>
#include <vector>
#include <iomanip>
#include <deque>
#include <algorithm>
//for problem 16
//struct team
//{
//	int home; 
//	int away;
//};

struct Pair
{
	int number;
	int archenemies1, archenemies2;
	bool inteam;
};
int main()
{
	//HW solution
	//the problem is in this arr {1 , 2, ... , 100}
	//get the number of integers that are divisible by 2, 3 , 8 ,10?
	//the answer is 67

	//stright answer 
	//int arr[100];
	//int k = 1;
	//for (int i = 0; i < 100; i++)
	//	arr[i] = k++;

	//int counter = 0;

	//for (int i = 0; i < 100; i++)
	//	if (arr[i] % 2 == 0 || arr[i] % 3 == 0)
	//		counter++;


	//cout << counter;
	////another solution 
	////by using the discrete math inclusive exclusive method 
	//int cnt2 = 0, n = 100;
	//for (int i2 = 0; i2 < 2; i2++)// 3amlenha l7d el 2 bs aknha binary , enta keda bt5leh ye7sb l ms2la bdl ma kant o(n) htb2a o(1) :)))
	//	for (int i3 = 0; i3 < 2; i3++)
	//	{
	//		int d = 1, elementscounter = 0;
	//		if (i2) d *= 2, elementscounter++;
	//		if (i3) d *= 3, elementscounter++;

	//		if (elementscounter == 0) continue; // avoid 00 case 

	//		// only add the odd and subtract the even
	//		int sign = elementscounter % 2 == 1 ? 1 : -1;

	//		cnt2 += sign * n / d;
	//	}
	//cout << endl << cnt2;
	//	//Problem1
	//	//int friendsnumber, height; 
	//	//cin >> friendsnumber >> height; 
	//	//int minwid = 0;
	//
	//	//for (int i = 0; i < friendsnumber; i++)
	//	//{
	//	//	int personheight; 
	//	//	cin >> personheight;
	//	//	if (personheight > height)
	//	//		minwid += 2;
	//	//	else
	//	//		minwid++; 
	//	//}
	//	//cout << minwid; 
	//
	//	//problem 2 
	//	//int NoOfGames;
	//	//cin >> NoOfGames;
	//
	//	//int antonwon = 0;
	//	//int danikwon = 0;
	//
	//	//string arr; 
	//	//cin >> arr;
	//	////char* arr = new char[NoOfGames];
	//	////cin >> arr;
	//
	//	//for (int i = 0; i < NoOfGames; i++)
	//	//{
	//	//	if (arr[i] == 'A')
	//	//		antonwon++;
	//	//	else
	//	//		danikwon++;
	//	//}
	//
	//	//if (antonwon > danikwon)
	//	//	cout << "Anton";
	//	//else if (antonwon < danikwon)
	//	//	cout << "Danik";
	//	//else
	//	//	cout << "Friendship";
	//
	//	//problem3
	//	/*int Limak, Bob;
	//	cin >> Limak ;
	//	cin >> Bob;
	//	int years = 1;
	//	while ((Limak * 3) <= (Bob * 2))
	//	{
	//		years++;
	//		Limak = Limak * 3;
	//		Bob = Bob * 2;
	//	}
	//
	//	cout << years;*/
	//
	//
	//	//Problem4 
	//	/*int noOfProblems;
	//	cin >> noOfProblems;
	//
	//	int NoOFSolved = 0;
	//	for (int i = 0; i < noOfProblems; i++)
	//	{
	//		int P, V, T;
	//		cin >> P >> V >> T;
	//		if ((P && V) || (P && T) || (V && T))
	//			NoOFSolved++;
	//	}
	//	cout << NoOFSolved; */
	//
	//	//problem5
	//	/*int matrix[5][5];
	//	for (int row = 0; row < 5; row++)
	//		for (int col = 0; col < 5; col++)
	//		{
	//			int x;
	//			cin >> x;
	//			matrix[row][col] = x;
	//		}
	//
	//	int swap = 0;
	//	for (int row = 0; row < 5; row++)
	//		for (int col = 0; col < 5; col++)
	//		{
	//			if (matrix[row][col] == 1)
	//			{
	//				swap = (abs(3 - row - 1) + abs(3 - col - 1));
	//				cout << swap;
	//				return 0;
	//			}
	//		}*/
	//
	//
	//		//problem6
	//		//int colNo;
	//		//cin >> colNo;
	//		//int* arr = new int[colNo];
	//		////sorting problem 
	//		//for (int i = 0; i < colNo; i++)
	//		//{
	//		//	int x; 
	//		//	cin >> x;
	//		//	arr[i] = x;
	//		//}
	//
	//		//bool flag = false; 
	//
	//		////bubblesort
	//		//for (int i = 0; i < colNo; i++)
	//		//{
	//		//	flag = false;
	//		//	for (int j = 0; j < colNo - 1; j++)
	//		//	{
	//		//		if (arr[j] > arr[j + 1])
	//		//		{
	//		//			int swap = arr[j];
	//		//			arr[j] = arr[j + 1];
	//		//			arr[j + 1] = swap;
	//		//			flag = true;
	//		//		}
	//		//	}
	//		//	if (!flag) break;
	//		//}
	//
	//		//for (int i = 0; i < colNo; i++)
	//		//{
	//		//	cout << arr[i] << ' ';
	//		//}
	//		//delete [] arr;
	//
	//
	//	//problem 7
		//string s1, s2;
		//cin >> s1 >> s2;
		//int len = s1.length();
		//for (int i = 0; i < len; i++)
		//{
		////making all letters lower
		//	if (s1[i] < 97)
		//		s1[i] += 32;
		//	if (s2[i] < 97)
		//		s2[i] += 32;
		//}
		//if (s1 > s2)
		//	cout << 1;
		//else if (s1 < s2)
		//	cout << -1;
		//else cout << 0;
//another solution
//char s1[100], s2[100];
//		cin >> s1 >> s2;
//		if (_strcmpi(s1, s2) > 0) // de btkarn el letters w msh mohem el upper wl lower
//			cout << 1;
//		else if (_strcmpi(s1, s2) < 0)
//			cout << -1;
//		else
//			cout << 0;

	//	//problem 8
	//	//string s1;
	//	//cin >> s1; 
	//	//
	//	//int count = 0;
	//	//for (int i = 0; i < s1.length() - 1; i++)
	//	//{
	//	//	bool flag = true;
	//	//	for (int k = i + 1; k < s1.length(); k++)
	//	//	{
	//	//		if (s1[k] == s1[i])
	//	//		{
	//	//			flag = false;
	//	//			break;
	//	//		}
	//	//	}
	//	//	if (flag)
	//	//		count++; 
	//	//}
	//	//
	//	//if (count % 2 != 0) cout << "CHAT WITH HER!";
	//	//else cout << "IGNORE HIM!"; 
	//	//return 0;
	//
	//
	//	//problem 9 
	//string s1;
	//cin >> s1;
	//int len = s1.length();	
	//int up, low;
	//up = low = 0;
	//for (int i = 0; i < len; i++)
	//{
	//	if (s1[i] < 97)
	//		up++;
	//	else
	//		low++;
	//}
	//if(up > low)
	//for (int i = 0; i < len; i++)
	//{
	//	if(s1[i] > 96)
	//	s1[i] -= 32;
	//	cout << s1[i];
	//}
	//else 
	//for (int i = 0; i < len; i++)
	//{
	//	if (s1[i] <97)
	//		s1[i] += 32;
	//	cout << s1[i];
	//}
	//
	//problem 10
	//int size;
	//cin >> size;
	//int* arr = new int[size];
	//
	//for (int i = 0; i < size; i++)
	//{
	//	int x;
	//	cin >> x;
	//	arr[i] = x;
	//}
	//int groups = 0; 
	//for (int i = 0; i < size; i++)
	//{
	//	if (arr[i] != arr[i + 1])
	//		groups++; 
	//}
	//
	//cout << groups; 
	//delete [] arr;

	//problem 11
	//intialization
	//int cardsnumber; 
	//cin >> cardsnumber; 
	//int* cards = new int[cardsnumber];
	//int ser, dima; 
	//ser = dima = 0;
	//for (int i = 0; i < cardsnumber; i++)
	//{
	//	int x;
	//	cin >> x; 
	//	cards[i] = x;
	//}
	//int i = 0;
	//while(i < cardsnumber)// as long as there are some cards
	//{
	//	//sereja draws first
	//	if (cards[i] > cards[cardsnumber - 1])
	//	{//draws from left
	//		ser += cards[i];
	//		i++;
	//	}
	//	else
	//	{//draws from right
	//		ser += cards[cardsnumber - 1];
	//		cardsnumber--;
	//	}
	//	if (cardsnumber > 0 && cardsnumber > i) // if there are more cards then its  dima's turn
	//	{
	//		if (cards[i] > cards[cardsnumber - 1])
	//		{//draws left
	//			dima += cards[i];
	//			i++;
	//		}
	//		else
	//		{//draws right
	//			dima += cards[cardsnumber - 1];
	//			cardsnumber--;
	//		}
	//	}
	//}
	//
	//cout << ser << ' ' << dima;
	//delete[] cards; // free memory

	//problem 12
	//int noOFstones;
	//cin >> noOFstones;
	//string s1; 
	//cin >> s1;
	//int counter = 0;
	//for (int i = 0; i < noOFstones; i++)
	//{
	//	if (s1[i] == s1[i + 1])
	//		counter++;
	//}
	//cout << counter;

	//problem 13
	//int size;
	//cin >> size;
	//int* arr = new int[size];
	//for (int i = 0; i < size; i++)
	//{
	//	int x;
	//	cin >> x;
	//	arr[i] = x;
	//}
	//int counter = 0;
	//int free = 0;//number of free officers
	//for (int i = 0; i < size; i++)
	//{
	//	if (arr[i] > 0)
	//		free += arr[i];
	//	else
	//	{
	//		//if there are free officers hire one by one
	//		if (free > 0)
	//		{
	//			free--;
	//			continue; //one by one 
	//		}
	//		else
	//			counter++;
	//	}
	//}
	//cout << counter;
	//delete[] arr;//free memory

	/// <summary>
	/// day 2
	/// </summary>

	//problem 14
	//int* vals = new int[4];
	//for (int i = 0; i < 4; i++)
	//{
	//	//reading the first values 
	//	int x; 
	//	cin >> x; 
	//	vals[i] = x; 
	//}
	//
	//string s;
	//cin >> s;
	//int len = s.length();
	//int sumofcal = 0;
	//for (int i = 0; i <len ; i++)
	//{
	//	switch (s[i])
	//	{
	//	case '1': sumofcal += vals[0]; break;
	//	case '2': sumofcal += vals[1]; break;
	//	case '3': sumofcal += vals[2]; break;
	//	case '4': sumofcal += vals[3]; break;
	//	}
	//}
	//
	//cout << sumofcal;
	//delete[] vals;

	//problem 15
	// bnt wskhaaaaaa
//char* alphabets = new char[26]; // creat a space in the heap
//char ptr = 'a'; 
//for (int i = 0 ; i < 26; i++ , ptr++)
//{
//	alphabets[i] = ptr; // creating the circluar alphabet
//}
//
//int rotations = 0; 
//string name; 
//cin >> name; 
//int len = name.length();
//ptr = 'a';
//char dummy;//to be used as an indecator 
//for (int i = 0; i < len; i++)
//{
//	dummy = ptr;
//	int cw = 0;
//	int ccw = 0;
//	while (dummy != name[i])
//	{
//		//check for cw 
//		if (dummy == 'z')
//		{
//			dummy = 'a' - 1;
//			continue;
//		}
//		dummy++;
//		cw++;
//	}
//	dummy = ptr; // to start again from the same letter
//	while (dummy != name[i])
//	{
//		//check for ccw 
//		if (dummy== 'a')
//		{
//			dummy = 'z' + 1;
//			continue;
//		}
//		dummy--;
//		ccw++;
//	}
//
//	if (cw < ccw)//if cw is larger we need to rotate ccw
//	{
//		while (ptr != name[i])
//		{
//			//rotate cw 
//			if (ptr == 'z')
//			{
//				ptr = 'a' - 1;
//				continue;
//			}
//			ptr++;
//			rotations++;
//		}
//	}
//	else
//	{
//		while (ptr != name[i])
//		{
//			//rotate ccw 
//			if (ptr == 'a')
//			{
//				ptr = 'z' + 1;
//				continue;
//			}
//			ptr--;
//			rotations++;
//		}
//	}
//}
//cout << rotations; 
//delete[] alphabets; //free memory

//problem 16
//int numberOfTeams;
//cin >> numberOfTeams;
//team* teams = new team[numberOfTeams];//creating memory in the heap
//int counter = 0;
//for (int i = 0; i < numberOfTeams; i++)
//{
//	//intializing the struct
//	int h, a;
//	cin >> h;
//	teams[i].home = h; 
//	cin >> a; 
//	teams[i].away = a;
//}
//for (int i = 0; i < numberOfTeams; i++)
//{//iterating over the teams
//	for (int k = 0; k < numberOfTeams; k++)
//		if ((teams[i].home == teams[k].away)&& i!=k)
//			counter++;
//}
//cout << counter; 
//delete[] teams;//free the memory

//problem 17

//int* legs = new int[4];// creating memory in the heap
//for (int i = 0; i < 4; i++)
//{
//	//initializing
//	int x;
//	cin >> x;
//	legs[i] = x; 
//}
//int shoesnumber = 0;
//for (int i = 0; i < 4 ;i++)
//{
//	for (int k = i + 1; k < 4; k++)
//	{
//		if (legs[i] == legs[k])
//		{
//			shoesnumber++;
//			break;
//			//counting leg by leg
//		}
//	}
//
//}
//cout << shoesnumber; 
//delete[] legs;// free memory

//problem 18
//
//string moves;
//cin >> moves;
//string stones;
//cin >> stones;
//int counter = 1;
//int len = stones.length();
//for (int i = 0, k = 0; i < len; i++)
//{
//	if (moves[k] == stones[i])
//	{
//		k++; 
//		counter++;
//	}
//}
//cout << counter;

//problem 19
//int Y, W; 
//cin >> Y >>  W; 
//int max = Y > W ? Y : W;//find the largest between them 
//int chance = 0;
//for (int i = max; i < 7; i++)
//{
//	if (max < 7)
//		chance++;
//}
//
//switch (chance)
//{
//case 1: cout << "1/6"; break;
//case 2: cout << "1/3"; break;
//case 3:cout << "1/2"; break;
//case 4:cout << "2/3"; break;
//case 5:cout << "5/6"; break;
//case 6: cout << "1/1"; 
//}

//problem20
//int wiresnumber;
//cin >> wiresnumber;
//
//vector<int>* wires = new vector<int>[wiresnumber];//allocate memory in the heap
//
//for (int i = 0; i < wiresnumber; i++)
//{
//	//intialization
//	int size;
//	cin >> size;
//	for (int k = 0; k < size; k++)
//	{
//		wires[i].push_back(1);
//	}
//}
//
//int shoots;//number of shoots
//cin >> shoots;
//for (int i = 0; i < shoots; i++)
//{
//	int w, b; 
//	cin >> w >> b;
//	int size = wires[w - 1].size();
//	for (int l = 0; l < b - 1; l++) // left
//	{
//		if (w > 1)//if it is not on the first wire
//			wires[w - 2].push_back(1);
//	}
//
//	for (int i = b ; i <size ; i++) // right
//	{
//		if (w < wiresnumber)//if it is not on the last wire
//			wires[w].push_back(1);
//	}
//	wires[w - 1].clear(); // making all birds fly from the wire
//}
//
//for (int i = 0; i < wiresnumber; i++)
//{
//	cout << wires[i].size() << endl;
//}
//delete[] wires;

//problem 21
	/*int noOfOranges, maxSize, limit;
	cin >> noOfOranges >> maxSize >> limit;
	int refill = 0;
	int counter = 0;
	for (int i = 0; i < noOfOranges; i++)
	{
		int s;
		cin >> s;
		if (s > maxSize) continue;
		counter += s;
		if (counter > limit)
		{
			refill++;
			counter = 0;
		}
	}
	cout << refill;*/
	//another solution
		//bool cansqueeze = false; // to indicate wether there is any squeezable orange or not
		//vector<int> Oranges;
		//for (int i = 0; i < noOfOranges; i++)
		//{
		//	//intialization
		//	int x;
		//	cin >> x;
		//	if (!cansqueeze)
		//		if (x <= maxSize)
		//			cansqueeze = true;
		//	Oranges.push_back(x);
		//}
		//vector<int> ::iterator it = Oranges.begin();
		//int refill; // number of refilling
		//if (cansqueeze)
		//	refill = 0;
		//else
		//{
		//	//there are no squeezable oranges
		//	cout << 0;
		//	return 0;
		//}
		//int orangeCounter = 0;//number of squeezed oranges
		//for (int i = 0; it != Oranges.end(); it++, i++)
		//{
		//	if (*it > maxSize) continue; // if there is oversized oranges throw them away

		//	orangeCounter += Oranges[i];
		//	if (orangeCounter > limit)
		//	{
		//		refill++;
		//		orangeCounter = 0;
		//	}
		//}
		// 	   cout << refill; 
			//problem 22 
				//int mins, Cc, cakesNo, newovTime;
				//cin >> cakesNo >> mins >> Cc >> newovTime;
				//int repeatoven = ceil((float)cakesNo / Cc); // number of repetation without new oven
				//int cakes1st = (newovTime / mins) * Cc; // number of cakes that will be made during the building of the second oven 
				//int without = repeatoven * mins; // number of cakes without
				//int with;//number of cakes with
				//if (cakesNo - cakes1st > Cc)
				//	with = newovTime + ceil((((float)cakesNo - cakes1st) / (Cc))) * mins / 2;
				//else
				//	with = newovTime + ceil((((float)cakesNo - cakes1st) / (Cc))) * mins;
				//if (with < without)
				//	cout << "YES";
				//else cout << "NO";

				////problem 23
				//	char* s = new char[1000];
				//	char c;
				//	int len = 0;
				//	for (int i = 0; i < 1000; i++)
				//	{
				//		cin >> c;
				//		if (c == ' ' || c == ',' || c == '{') continue;
				//		else if (c != '}')
				//			s[len++] = c;
				//		else
				//			break;
				//	}//don't read unneccessary letters
				//	int counter = 0;
				//	for (int i = 0; i < len; i++)
				//	{
				//		bool notfound = true;
				//		for (int k = i + 1; k < len; k++)
				//			if (s[k] == s[i])
				//			{
				//				notfound = false;
				//				break;
				//			}
				//		if (notfound)
				//			counter++;
				//	}
				//	cout << counter;
				//	delete[] s;

				//problem 24 
				//int noofwords;
				//cin >> noofwords;
				//
				//for (int i = 0; i < noofwords; i++)
				//{
				//	string s;
				//	cin >> s; 
				//	if (s.length() > 10)
				//		cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
				//	else
				//		cout << s;
				//}

				////problem 25 
				//long long noOfPeople, icePacks; // for a very long int
				//cin >> noOfPeople >> icePacks; 
				//int distress = 0;
				//for (int i = 0; i < noOfPeople; i++)
				//{
				//	char sgn; 
				//	cin >> sgn;
				//	if (sgn == '+')
				//	{
				//		long long add; 
				//		cin >>add;
				//		icePacks += add;
				//	}
				//	else
				//	{
				//		long long take;
				//		cin >> take;
				//		if (take > icePacks)
				//			distress++;
				//		else
				//			icePacks -= take;
				//	}
				//}
				//cout << (icePacks) << ' ' << distress;
				//problem 26 
				//string s; 
				//cin >> s;
				//int len = s.length();
				//for (int i = 0; i < len; i++)
				//{
				//	bool swap = false;
				//	if (s[i] != '+')//selection sort
				//	{
				//		int index = i;
				//		for (int k = i + 1; k < len; k++)
				//		{
				//			if(s[k] != '+')
				//				if (s[k] < s[index])
				//				{
				//					index = k;
				//					swap = true;
				//				}
				//		}
				//		//swap
				//		if (swap)
				//		{
				//			char temp = s[i];
				//			s[i] = s[index];
				//			s[index] = temp;
				//		}
				//	}
				//}
				//
				//cout << s;

				//problem 27
				//int childrenNo;
				//cin >> childrenNo; 
				//
				//vector<int> prog;
				//vector<int> PE; 
				//vector<int> Math;
				//for (int i = 0; i < childrenNo; i++)
				//{
				//	//intialization
				//	int x;
				//	cin >> x;
				//	switch (x)
				//	{
				//	case 1: prog.push_back(i + 1); break; 
				//	case 2: Math.push_back(i + 1); break; 
				//	default: PE.push_back(i + 1); break; 
				//	}
				//}
				//
				//int counter = 0;
				//int progsize = prog.size();
				//int mathsize = Math.size(); 
				//int PEsize = PE.size();
				//
				////find the counter
				//if (progsize < mathsize)
				//{
				//	if (progsize < PEsize)
				//		counter = progsize;
				//	else
				//		counter = PEsize;
				//}
				//else if (mathsize < PEsize)
				//{
				//	counter = mathsize;
				//}
				//else
				//counter = PEsize;
				//cout << counter << endl;
				//
				//while (!prog.empty() && !Math.empty() && !PE.empty())//printing the teams
				//{
				//	cout << prog.back() << ' ' << Math.back() << ' ' << PE.back() << endl;
				//	prog.pop_back();
				//	Math.pop_back();
				//	PE.pop_back();
				//}

				//problem 28
				//int len , distinct;
				//cin >> len >> distinct; 
				//char a = 'a';
				//int counter = 0; 
				//for (int i = 0; i < len; i++)
				//{
				//	
				//	if (a != 'z' + 1 && counter < distinct)
				//	{
				//		cout << a;
				//	}
				//	else
				//	{
				//		a = 'a';
				//		cout << a;
				//		counter = 0;
				//	}
				//	a++;
				//	counter++;
				//}
	// problem 29
	//this problem will be solved by modulus
//double terminate;
//do
//{
//	cin >> terminate;
//	if (terminate == 0) break;
//	int size = terminate;
//	//int* arr = new int[(int)terminate]{ 0 }; // this is how we intailize a dynamic array without a loop
//	int arr[100000] = { 0 };
//
// 	for (int k = 1; k <= terminate ; k++)
//	{
//		if ((size) % k == 0)
//			if (arr[size - 1] == 0)
//				arr[size - 1] = 1;
//			else arr[size - 1] = 0;
//		//for (int i = 1; i <= terminate; i++)
//		//{
//		//	if (i % k == 0)
//		//		if (arr[i - 1] == 0)
//		//			arr[i - 1] = 1;
//		//		else arr[i - 1] = 0;
//		//	//O(n^2)
//		//}
//	}
//	if (arr[size - 1] == 0) cout << "no\n";
//	else
//		cout << "yes\n";
//} while (terminate != 0);

// another solution
/*unsigned int n;
while (cin >> n && n != 0)
{
	int sq = (int)sqrt(n);
	if (sq * sq == n)
		cout << "yes\n";
	else
		cout << "no\n";
}
	*/
	//problem 30
	// we can't solve it using numbers we must read strings and make the product concept
	//long long  x;
	//unsigned long long y;
	//while (cin >> x >> y)
	//{
	//	cout << x * y << endl;
	//}
	//string s1;
	//string s2;
	//while (cin >> s1)
	//{
	//	cin >> s2;
	//	reverse(s1.begin(), s1.end());// reverse the input to deal with it from right to left
	//	reverse(s2.begin(), s2.end());
	//	int result[600];//creat an array to carry the input
	//	memset(result, 0, sizeof(result));//intialize it with zeros
	//	for (int i = 0; i < s1.length(); i++)
	//	{
	//		for (int j = 0; j < s2.length(); j++)
	//		{
	//			result[i + j] += (s1[i] - '0') * (s2[j] - '0'); // this is how we convert the char to int
	//		}
	//	}
	//
	//	//loop to propagate the carry
	//	for (int i = 0; i < 600 - 1; i++)
	//	{
	//		result[i + 1] += result[i] / 10;
	//		result[i] %= 10;
	//	}
	//
	//	int i = 599; 
	//	while (i > 0 && result[i] == 0) i--; // loop to get the raid of the  unused places
	//
	//	//loop to print the result
	//	for (;i  >= 0; i--)
	//	{
	//		cout << result[i];
	//	}
	//	cout << endl;
	//}

	//Problem 31
//	//chess problem
	//int rows, cols, clr;

	//while (cin >> rows >> cols >> clr && rows != 0)
	//{
	//	int rem = clr == 1 ? 1 : 0;
	//	cout << ((rows - 7) * (cols - 7) + rem) / 2 << endl;
	//}

//problem 34
//int noOfFriends;
//while (cin >> noOfFriends && noOfFriends != 0)
//{
//	int* arr = new int[noOfFriends];
//	memset(arr, 0, noOfFriends);// intialize
//	for (int i = 0; i < noOfFriends; i++)
//	{
//		int x;
//		cin >> x;
//		arr[x - 1] = i + 1;
//	}
//	
//	//this is how we print without using a loop
//	copy(arr, arr + noOfFriends, ostream_iterator<int>(cout, " "));
//	delete[] arr;
//}

//problem 35
	//int noOfCities;
	//cin >> noOfCities;
	//int* arr = new int[noOfCities];
	////this is how we read without using loops
	////copy(istream_iterator<int>(cin), istream_iterator<int>(), arr);
	//for (int i = 0; i < noOfCities; i++)
	//{
	//	int x;
	//	cin >> x;
	//	arr[i] = x;
	//}

	//for (int i = 0; i < noOfCities; i++)
	//{
	//	//cout << min_element(arr, arr + noOfCities) << ' ' << max_element(arr, arr + noOfCities) << endl;
	//	long long maxx = -INT_MAX, minn = -maxx;
	//	/*
	//	for (int k = 0; k < noOfCities; k++)
	//	{
	//		if (k == i) continue;

	//		if (abs(arr[i] - arr[k]) < min)
	//			min = abs(arr[i] - arr[k]);

	//		if (abs(arr[i] - arr[k]) > max)
	//			max = abs(arr[i] - arr[k]);
	//	}*/

	//	maxx = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[noOfCities - 1]));

	//	if (i == 0)
	//		minn = abs(arr[i] - arr[i + 1]);
	//	else if (i == noOfCities - 1)
	//		minn = abs(arr[i] - arr[i - 1]);
	//	else
	//		minn = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));


	//	cout << minn << " " << maxx << endl;
	//}
	//delete[] arr;
//problem 36





	//PROBLEM 45
	//int noOfStudents, noOfPairOfArch;
	//cin >> noOfStudents >> noOfPairOfArch;
	//Pair* students = new Pair[noOfStudents];
	//for (int i = 0; i < noOfStudents; i++)
	//{
	//	//initialization
	//	students[i].number = i;
	//	students[i].archenemies1 = students[i].archenemies2 = -5;
	//	students[i].inteam = false;
	//}
	//for (int i = 0; i < noOfPairOfArch; i++)
	//{
	//	int x, y;
	//	cin >> x >> y;
	//	if (students[x - 1].archenemies1 == -5)
	//	{//intializing the archenemies
	//		students[x - 1].archenemies1 = y - 1;
	//		if (students[y - 1].archenemies1 == -5)
	//			students[y - 1].archenemies1 = x - 1;
	//		else
	//			students[y - 1].archenemies2 = x - 1;
	//	}
	//	else
	//	{
	//		students[x - 1].archenemies2 = y - 1;
	//		if (students[y - 1].archenemies1 == -5)
	//			students[y - 1].archenemies1 = x - 1;
	//		else
	//			students[y - 1].archenemies2 = x - 1;
	//	}
	//}

	//int bench = 0;
	//vector<int> team1;
	//vector<int> team2;

	//for (int i = 0; i < 2; i++)
	//{//teams formation
	//	if (i == 0)
	//	{
	//		team1.push_back(students[0].number);
	//		students[0].inteam = true;
	//		for (int k = 1; k < noOfStudents; k++)
	//		{
	//			bool notfound = true;
	//			for (int s = 0; s < team1.size(); s++)
	//			{
	//				if ((students[k].archenemies1 == team1[s] || students[k].archenemies2 == team1[s]) || students[k].inteam)
	//				{
	//					notfound = false;
	//					break;
	//				}
	//			}
	//			if (notfound)
	//			{
	//				team1.push_back(students[k].number);
	//				students[k].inteam = true;
	//				if (team1.size() >= noOfStudents / 2)
	//					break;
	//			}
	//		}
	//	}
	//	else
	//	{
	//		for (int l = 0; l < noOfStudents; l++)
	//		{
	//			if (!students[l].inteam)
	//			{
	//				students[l].inteam = true;
	//				team2.push_back(students[l].number);
	//				break;
	//			}
	//		}
	//		for (int k = 0; k < noOfStudents; k++)
	//		{
	//			bool notfound = true;
	//			for (int s = 0; s < team2.size(); s++)
	//			{
	//				if ((students[k].archenemies1 == team2[s] || students[k].archenemies2 == team2[s]) || students[k].inteam)
	//				{
	//					notfound = false;
	//					break;
	//				}
	//			}
	//			if (notfound)
	//			{
	//				team2.push_back(students[k].number);
	//				students[k].inteam = true;
	//			}
	//		}
	//	}
	//}

	//for (int i = 0; i < noOfStudents; i++)
	//{
	//	//number of students that are not in a team 
	//	if (!students[i].inteam)
	//		bench++;
	//}

	//if (team1.size() > team2.size()) // if the teams are not equal
	//{
	//	bench += team1.size() - team2.size();
	//}
	//else if (team1.size() < team2.size())
	//{
	//	bench += team2.size() - team1.size();
	//}

	//cout << bench;
	//delete[] students;
	return 0;
}