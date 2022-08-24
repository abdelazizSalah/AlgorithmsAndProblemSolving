#include <iostream>
using namespace std;

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void selectionSort(int* arr, const int& size)
{//o(n^2)
	int imin = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[imin] > arr[j])
				imin = j;
		}
		swap(arr[i], arr[imin]);
	}
}

void reheapup(int* heap, int newNode)
{
	int parent;

	if (newNode)
	{
		parent = (newNode - 1) / 2;
		if (heap[newNode] > heap[parent]) // if child > parent 
		{
			swap(heap[parent], heap[newNode]);
			reheapup(heap, parent);
		}
	}
}

void reheapDown(int* heap, int root, int last)
{
	int leftkey, rightkey, largeChildKey, largeChildIndex;

	if ((root * 2 + 1) <= last)
	{//there is at least one child
		leftkey = heap[root * 2 + 1];
		if ((root * 2 + 2) <= last)
			rightkey = heap[root * 2 + 2];
		else
			rightkey = -1;
		//determine  which child is larger
		if (leftkey > rightkey)
		{
			largeChildKey = leftkey;
			largeChildIndex = root * 2 + 1;
		}//if leftkey > 
		else
		{
			largeChildKey = rightkey;
			largeChildIndex = root * 2 + 2;
		}
		//test if root > largersubtree
		if (heap[root] < heap[largeChildIndex])
		{
			swap(heap[root], heap[largeChildIndex]);
			reheapDown(heap, largeChildIndex, last);
		}
	}
}
void heapSort(int arr[], int last)
{//o(nlogn)
	int sorted;

	for (int walker = 0; walker <= last; walker++)
		reheapup(arr, walker);

	sorted = last;

	while (sorted > 0)
	{
		swap(arr[0], arr[sorted]);
		sorted--;
		reheapDown(arr, 0, sorted);
	}
}

void insertionSort(int* arr, const int& size)
{ // o(n^2)
	for (int i = 0; i < size; i++)
		for (int j = i; j > 0; j--)
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
}

void shellSort(int arr[], int last)
{ // o(n^(6/5) or n^(7/6))
	int incre, walker, hold;

	incre = last / 2;
	while (incre != 0)
	{
		for (int curr = 0; curr < last; curr++)
		{
			hold = arr[curr];
			walker = curr - incre;
			while (walker >= 0 && hold < arr[walker])
			{
				arr[walker + incre] = arr[walker];
				walker = walker - incre;
			}
			arr[walker + incre] = hold;
		}
		incre /= 2;
	}
	return;
}


void bubbleSort(int arr[], int size)
{//o(n^2)
	for (int i = 0; i < size; i++)
	{
		bool flag = true;
		for (int j = 0; j < size; j++)
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]); // sahla bghba2
				flag = false;
			}
		if (flag) // 34an lw m7slsh ay swaping yeb2a mfesh da3y eny akml 34an 5las keda sorted 
			break;
	}
}
void PrintList(int* arr, const int& size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
}

int calcInversions(int* arr, const int& size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			if (arr[i] > arr[j])
				count++;
		}
	return count;
}

bool BinarySearch(int* arr, const int& last, const int& target, int& location)
{
	int begin = 0;
	int mid = 0;
	int end = last;
	while (begin < last)
	{
		mid = (begin + end) / 2;
		if (target < arr[mid])
			end = mid - 1;//look in the lower half
		else if (target > arr[mid])
			begin = mid + 1;// look in the upper half
		else
			begin = end + 1; //found force end
	}

	location = mid;
	if (target == arr[mid])
		return true;
	else
		return false;
}

int BinSearchRec(int arr[], int beg, int end, int target)
{
	if (beg > end)
		return -1;
	int mid = (beg + end) / 2;
	if (arr[mid] == target) return mid;
	else if (arr[mid] > target) return BinSearchRec(arr, beg, mid - 1, target);
	else return BinSearchRec(arr, mid + 1, end, target);
}
int main()
{
	int arr[] = { 8 , 4, 2, 1 , 0 , 15 };

	int sortedarr[] = { 1 , 3, 5, 6, 7, 8 };
	int loc = 0;
	if (BinarySearch(sortedarr, 5, 7, loc)) cout << "the target number has been found at the index: " << (loc + 1) << endl;

	cout << BinSearchRec(sortedarr, 0, 5, 7) + 1;

	int size = sizeof(arr) / sizeof(arr[1]); // smart method to determine the size
	cout << calcInversions(arr, size) << endl;//calc inversions

	///all type of sorting except el quick 34an mb7bosh
	selectionSort(arr, 6);// gamaaaaaal
	PrintList(arr, 6);
	cout << endl;

	heapSort(arr, 5);// gamaaaaaal
	PrintList(arr, 6);
	cout << endl;

	insertionSort(arr, 6);// gamaaaaaal
	PrintList(arr, 6);
	cout << endl;

	shellSort(arr, 6);// gamaaaaaal
	PrintList(arr, 6);
	cout << endl;

	bubbleSort(arr, 6);// gamaaaaaal
	PrintList(arr, 6);

	return 0;
}