#include <iostream>
using namespace std;

template<class Z> 
int sequentialSearch(Z* arr, int begin, int last, Z target); 

template<class Z>
int sequentialrecSearch(Z* arr, int begin, int last, Z target);


template <class T> 
T binarySearch(T* arr, int begin, int last, T target);

template <typename T>
int binarySearchiterative(T* arr, int begin, int last, T target); 

int main()
{


	return 0; 
}
 
template<class Z>
int sequentialSearch(Z* arr, int begin, int last, Z target)
{ // returns the index of the target in the list
	for (int i = 0; i < last; i++)
	{
		if (arr[i] == target) return i; 
	}
	return -1; 
}

template<class Z>
int sequentialrecSearch(Z* arr, int begin, int last, Z target)
{
	if (begin > last) return -1;  // not found  in the whole array
	if (arr[begin] == target) return begin; // found
	else return sequentialrecSearch(arr, begin + 1, last, target); // not found in this iteration
}

template<class T> // mtnsash eny lazm a7ot de haa
int binarySearch(T* arr, int begin, int last, T target)
{
	// de function btrg3ly el index bta3 el element elly ana bdwr 3leh
	// fekret el BinarySearch hya eny kol mara b2sm el el iterations bt3ty 3la 2 
	//fa m3 kol iterations ana brmy nos el size bta3y
	//hn3mlha recursive 
	if (last < begin) return -1; 

	int mid = (last - begin) / 2; 
	if (arr[mid] == target) return mid;
	else if (arr[mid] < target) return binarySearch(arr, begin, mid - 1, target);
	else (arr[mid] > target) return binarySearch(arr, mid + 1, last, target); 

	return T();
}


template <typename T> 
int binarySearchiterative(T* arr, int begin, int last, T target)
{
	while (last > begin)
	{
		int mid = (last + begin) / 2;
		if (arr[mid] == target) return mid; // found 
		else if (arr[mid] > target) last = mid; // if mid > target , place the last to the mid
		else if (arr[mid] < target) begin = mid; // if m < target , place the begin to the mid
		else return -1; // not found 
	} // complexity o(logn) 
}