#include <bits/stdc++.h>
using namespace std;
#define fast ios_base :: sync_with_stdio(0),cin.tie(0), cout.tie(0);

//result  index
bool check(char* operations , vector<int> arr3 ,int i, int res , int n)  // if we have 5 integers and we want to do any possible operations to find the res = 23 ;
{
	if (i == n)
		return res == 27;
	bool ans = false;

	operations[i - 1] = '+';
	ans |= check(operations , arr3 , i + 1, res + arr3[i],n); // fe awl loop ha7awl agm3 kol el elements 
	if (ans) return true;

	operations[i - 1] = '-';
	ans |= check(operations , arr3 ,i + 1, res - arr3[i], n);// b3d keda hagm3hom kolohom w htr7 akher element w b3dha hatr7hom kolohom m3ada akher 2 w hakaza
	if (ans) return true;

	operations[i - 1] = '*';
	ans |= check(operations , arr3 , i + 1, res * arr3[i] , n);//ha7awl adrbhom kolohom f b3d 
	 // keda ana edrt awsl l all possible combinations
	return ans;
}
void solve()
{
	vector<int> arr(5);
	char op[4]; // 34an akhleha 1 based 
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end()); // must be sorted to make all permutations
	do
	{ // if found any possible way
		if (check(op, arr, 1, arr[0], 5))
		{
			cout << "Possible";
			return ;
		}
	} while (next_permutation(arr.begin(), arr.end()));
	//if not found
	cout << "Impossible";
}
int main()
{
	fast;
	solve();
	return 0;
}


int partition(vector<int>& v, int b, int e)
{
	int idx = b;
	while (idx < e) // ma asl el idx hwa el byzed y3ny fa tbe3y
	{
		if (v[e] < v[b])
			swap(v[++idx], v[e]); // b3ml swap lel element el b3d el idx
		else
			e--;
	}
	swap(v[idx], v[b]); // b3ml swap l awl element w el element el w2f 3ndo el idx
	return idx;
}
void QuickSort(vector<int>& v, int b, int e)
{
	if (b >= e)return;
	int pvtidx = partition(v, b, e);
	QuickSort(v, b, pvtidx - 1);
	QuickSort(v, pvtidx + 1, e);
}

void merge(vector<int>& v, int b1, int e1, int b2, int e2)
{
	vector<int> tmp(v.size());
	int beg = b1; int idx = b1;

	while (b1 <= e1 && b2 <= e2)
	{
		if (v[b1] < v[b2])
			tmp[idx++] = v[b1++];
		else
			tmp[idx++] = v[b2++];
	}

	while (b1 <= e1)
		tmp[idx++] = v[b1++];

	while (b2 <= e2)
		tmp[idx++] = v[b2++];

	for (int i = beg; i < idx; i++)
	{
		v[i] = tmp[i];
	}
}
void mergeSort(vector<int>& v, int b, int e)
{
	if (b >= e)
		return;
	int m = b + (e - b) / 2;
	mergeSort(v, b, m);
	mergeSort(v, m + 1, e);
	merge(v, b, m, m + 1, e);
}
