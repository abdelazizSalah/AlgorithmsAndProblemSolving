#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;
using ll = long long;
#define now chrono::high_resolution_clock::now(); 
#define dur duration_cast<nanoseconds>(end - start) / 1000000.0f;

void  swapp(int& x, int &y) // faster than normal swap
{
	x ^= y;
	y ^= x;
	x ^= y;
}
void SelectionSort(vector<int>& v)
{
	ll size = v.size();
	for (int i = 0; i < size - 1; i++)
	{
		int min = v[i]; // min element
		int idx = i; // indx of the min element
		for (int j = i; j < size; j++)
		{
			if (v[j] < min) // find the index of the minimum element
			{
				min = v[j];
				idx = j;
			}
		}
		swapp(v[i], v[idx]);
	}
}

void insertionSort(vector<int>& v, int b, int e)
{
	ll size = v.size();
	for (int i = b + 1; i < e + 1; i++)
		if (v[i] < v[i - 1])
		{
			int j = i;
			while (j > b && v[j] < v[j - 1])
				if (v[j] < v[j - 1])
				{
					swapp(v[j], v[j - 1]);
					j--;
				}
		}
}

//not used but thought of 
void merge(vector<int>& v, int s1, int e1, int s2, int e2)
{
	int ind = s1, beg = s1; // beg da 34an a3rf ana bad2 mn fen kol mra 
	vector<int> tmp(v.size()); // da el vector el byb2a zyada m3aya 34an kol mra a7ot feh el elements bto3y
	while (s1 <= e1 && s2 <= e2) // toul ma fe elements fl 2 vectors
	{
		//bshof men asghar w a7oto fl tmp arr
		if (v[s1] > v[s2])
			tmp[ind++] = v[s2++];
		else
			tmp[ind++] = v[s1++];
	}

	// lw lesa fadel elements fe ay wahed ml 2 vectors b7oto fl temp 
	while (s2 <= e2)
		tmp[ind++] = v[s2++];
	while (s1 <= e1)
		tmp[ind++] = v[s1++];

	// bn2l el elements ml temp lel original array
	for (int i = beg; i < ind; i++)
		v[i] = tmp[i]; // i+beg 34an m3mlsh overwite 3la haga mwgoda 
}

void MergeSort(vector <int>& v, int b, int e)
{
	if (b >= e)
		return;
	int m = b + (e - b) / 2;
	MergeSort(v, b, m); // partition of the left part
	MergeSort(v, m + 1, e); //partition of the right part
	merge(v, b, m, m + 1, e); // merging
}

//MergeSort
void MergeLec(vector<int>& v, const int& b, const int& m, const int& e)
{
	int LS = m - b + 1; // left vect size
	int RS = e - m; // right vect size
	vector<int> left(LS + 1); // left vector
	vector<int> right(RS + 1); // right vector

	for (int i = 0; i < LS; i++) // insert the left elements
		left[i] = v[b + i];
	for (int i = 0; i < LS; i++) // insert the right elements
		right[i] = v[m + 1 + i];

	//infinity at the end
	left[LS] = INT_MAX;
	right[RS] = INT_MAX;

	//sorting 
	int i = 0, j = 0;
	for (int k = b; k <= e; k++)
	{
		if (left[i] <= right[j])
			v[k] = left[i++];
		else
			v[k] = right[j++];
	}
}

void MergesortLec(vector <int>& v, int b, int e)
{
	if (b < e)
	{
		int m = floor(b + (e - b) / 2); // mid
		MergesortLec(v, b, m);
		MergesortLec(v, m + 1, e);
		MergeLec(v, b, m, e);
	}
}

//QuickSort
int partition(vector<int>& v, int s, int e)
{
	int idx = s; // pvt idx
	while (idx < e)//toul mana mwsltsh lel end aw m7slsh overlapping kml
	{
		if (v[e] < v[s])
			swap(v[++idx], v[e]);
		else
			e--;
	}
	swap(v[s], v[idx]);
	return idx;
}

void QuickSort(vector<int>& v, int b, int e)
{
	if (b >= e)
		return;
	int pvtidx = partition(v, b, e);
	QuickSort(v, b, pvtidx - 1);
	QuickSort(v, pvtidx + 1, e);
}

// not used but thought of.
void QuickSortHyb(vector<int>& v, int b, int e, int act)
{
	if (e - b < act / 1000) // partial quickSort
		return;
	int pvtidx = partition(v, b, e);
	QuickSortHyb(v, b, pvtidx - 1, act);
	QuickSortHyb(v, pvtidx + 1, e, act);
}

void HypridSort(vector<int>& v, const int& b, const int& e)
{
	if (is_sorted(v.begin() + b, v.end() - b))return;
	if (e - b > 60) // partial quickSort
	{
		int pvtidx = partition(v, b, e);
		HypridSort(v, b, pvtidx - 1);
		HypridSort(v, pvtidx + 1, e);
	}
	else
		insertionSort(v, b, e);
}

int main(int argc, char* argv[])
{
	vector<int>* v = new vector<int>; // est5dmt el dynamic 34an lama bst5dm el static msh 3arf leh by3ml el size bta3 el vector automatic w bybwz l bernamg
	ifstream fin(argv[2]); // data
	ofstream fout(argv[3]); // output 
	ofstream ftime(argv[4]); // time
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			int x;
			fin >> x;
			v->push_back(x); // de 34an hwa by7ot element zyada fl akher bsbb eof fa ana bshelo
		}
		v->pop_back();
		fin.close();
	}
	int slc = stoi(argv[1]);  // the integer of the selector 
	switch (slc)
	{
	case 0: {
		auto start = now; 
		SelectionSort(*v);
		auto end = now;
		auto duration = dur;
		ftime << "Selection duration: " << duration.count() << "ms\n";
		cout << "Selection duration: " << duration.count()<< "ms\n";
		break;
	}
	case 1:
	{
		auto start = now;
		insertionSort(*v, 0, v->size() - 1);
		auto end = now;
		auto duration = dur;
		ftime << "Insertion duration: " << duration.count()<< "ms\n";
		cout << "Insertion duration: " << duration.count()<< "ms\n";
		break;
	}
	case 2:
	{
		auto start = now;
		MergesortLec(*v, 0, v->size() - 1);
		auto end = now;
		auto duration = dur;
		ftime << "Merge duration: " << duration.count()<< "ms\n";
		cout << "Merge duration: " << duration.count()<< "ms\n";
		break;
	}
	case 3:
	{
		auto start = now;
		QuickSort(*v, 0, v->size() - 1);
		auto end = now;
		auto duration = dur;
		ftime << "Quick duration: " << duration.count()<< "ms\n";
		cout << "Quick duration: " << duration.count()<< "ms\n";
		break;
	}
	default:
	{
		auto start = now;
		HypridSort(*v, 0, v->size() - 1);
		auto end = now;
		auto duration = dur;
		ftime << "hyprid duration: " << duration.count()<< "ms\n";
		cout << "hyprid duration: " << duration.count()<< "ms\n";
	}
	}
	ftime.close(); // close time file 
	if (fout.is_open())
	{
		for (auto it = v->begin(); it != v->end(); it++)
			fout << *it << '\n';
		fout.close();
	}
	return 0;
}

