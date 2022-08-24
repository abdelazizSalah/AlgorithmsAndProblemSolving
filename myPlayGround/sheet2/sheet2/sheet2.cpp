#include <iostream>
using namespace std;

void completeArr(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	int sizeofnewarr = max - arr[0];
	int* newarr = nullptr;
	newarr = new int[sizeofnewarr];
	int start = newarr[0] = arr[0];

	for (int i = 1; i < sizeofnewarr+1; i++)
	{
		newarr[i] = ++start;
	}

	for (int i = 0; i < sizeofnewarr+1; i++)
	{
		if (newarr)
			cout << newarr[i] << ' ';
	}
}




int main()
{
	int arr[5] = { 4  , 6 , 9 , 11 , 13 }; 
	completeArr(arr, 5); 

	return 0;
}