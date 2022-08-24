#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <chrono> 
#include <thread>
#include <algorithm>
using namespace std::chrono;
using namespace std;
#define now chrono::high_resolution_clock::now(); 
#define dur duration_cast<nanoseconds>(end - start) / 1000000.0f;

int hashFunction(string s)
{
	int pos;
	switch (s.length())
	{
	case 1: pos = 39 * int(s[0]);  break;
	case 2:  pos = 39 * int(s[0]) + 392 * int(s[1]); break;
	case 3:  pos = 39 * int(s[0]) + 392 * int(s[1]) + 393 * int(s[2]); break;
	default:
		pos = 39 * int(s[0]) + 392 * int(s[1]) + 393 * int(s[2]) + 394 * int(s[3]);
	}
	return pos % 24000;
}
int main()
{
	vector<string>A(20000);
	vector<string> H(24000, "");
	ifstream file("words20k.txt");
	string s;
	int i = 0;
	while (file >> s)// Read the words one by one into a string vector A.
		A[i++] = s;

	// coping the data using hash function and linear proping
	i ^= i; // i=0  
	auto start = now;
	while (i != A.size())
	{
		int pos = hashFunction(A[i]);
		while (H[pos] != "" && H[pos] != "$") // liner probing
		{
			pos++; 
			pos %= 24000;
		}
		H[pos] = A[i++];
		if (!(i%500)) // calculating average time for insertion in each quartile 
		{
			// instead of making switch case for each 500 i used numbers to represent each 500
			//number 1 -> 1st 500 
			//number 2- > 2nd 500 and so on
			auto end = now;
			auto duration = dur; 
			cout<<"500 number " << (i/500) << " takes average time -> "<< duration.count() / 500 <<"ms\n"; 
			start = now;
		}
	}

	cout << "\nfor elements from 14000 to 14999 in the text file: ";
	i ^= i; // i = 0 ;
	int probnum = 0; 
	int totprobs = 0;
	vector<int> probes(1000); // vector to track number of probes
	while (i != 1000 )
	{
		//Search for elements
		int pos = hashFunction(A[i + 14000]);
		while (H[pos] != A[i + 14000]) // not found here 
		{
			if (H[pos] == "") break; 
			probnum++;
			pos++;
			totprobs++; 
			pos %= 24000; 
		}
		if (H[pos] == "") continue;
		probes[i] = probnum; 
		probnum ^= probnum; // probnum = 0 
		
		// delete 
		H[pos] = "$"; // my mark of deletion
		i++;
	}

	//min , max & avg num of probes
	auto pair = minmax_element(probes.begin(), probes.end()); 
	cout << "\nmin number of Probes = " << *pair.first << "\nmax number of probes = " << *pair.second ;
	cout << "\naverage number of Probes = " << totprobs / probes.size() ;

	return 0;
}