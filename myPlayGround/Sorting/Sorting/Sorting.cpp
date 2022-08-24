#include <iostream>
using namespace std;
template <class zuz>
//utility functions
void swapp(zuz& s1, zuz& s2);
void PrintList(int* arr, const int& size);

//heapsorting functions
void buildHeapacc(int* arr, int n);
void buildHeapdec(int* arr, int n);
void selectionDescendSort(int* list, const int& size);
void heapifyaccending(int* arr, int size, int parent);// de msh ht3ml build heap de htb2a function gowa el build heap
void heapifydeccending(int* arr, int size, int parent); // de msh ht3ml build heap de htb2a function gowa el build heap
void HeapSortingasc(int* arr, int n);
void HeapSortingdsc(int* arr, int n);

//selectionsort
void selectionAscendSort(int* list, const int& size);

//insertion sort
void insertionSortRec(int* arr, int size, int element);

//shell sort
//void ShellSort(int* Arr, int size , int step);

//bubble sort
void Bubble_sort(int* arr, int size); 


//Quick sort
//void QuickSort(int* arr , int size , int element); 
//void QuickkSoertAdelnsim(int arr[], int begin, int end);


//merge 
void MergeSorting(int *arr , int i , int j);
void merge(int* arr, int leftindx, int rightindx, int dividing);
int main()
{
	
	
	/*
	int arr[] = { 5 , 12 , 1 , 3 , 19 ,0 , -1,  };
	int size = sizeof(arr) / sizeof(arr[1]); 

	MergeSorting(arr, 0, size - 1);
	PrintList(arr, size);*/
	//insertionSortRec(arr, size, 0);
	//PrintList(arr, size);

	////selection sort
	//int arr[] = { 4 , 2, 1, 0 , 3, 10 }; 
	//int n = sizeof(arr) / sizeof(arr[0]); // de tr2a 34an tgeb beha el size bta3 ay array lw msh 3arfo enk te2sm 7gm el array 3la 7agm element wahed mno
	//selectionAscendSort(arr, n);
	//PrintList(arr, n); 

	//cout << endl;

	//selectionDescendSort(arr, 6); 
	//PrintList(arr, 6);

	//cout << endl;

	////heapsort
	/*int arr2[] = { 4 , 9 , 7 , 3 , 10 , 11 };
	int size = sizeof(arr2) / sizeof(arr2[1]);
	HeapSortingasc(arr2, size);
	HeapSortingdsc(arr2, size);
	return 0;*/
}


//need to think more about it

//void ShellSort(int* Arr, int size , int step)
//{
//	int step2 = step / 2;
//	int index1, index2, index3; 
//	//we need to creat step2 of arrays
//	int** arr = new int* [step2];
//	for (int i = 0; i < step2; i++)
//	{
//		arr[i] = new int[size];
//	}
//
//	//each one of them should contain the elements of the main array but with diffrent steps
//	for ( index3 = 0; index3 < step2; index3++)
//	{
//		for ( index2 = 0 ,  index1 = 0; index2 < step2; index2++ , index1 += step2)
//		{
//				*arr[index2] = Arr[index1];
//		}
//		insertionSortRec(arr[index3], index2, 0);
//	}
//
//	for ( index3 = 0; index3 < step2 ; index3++)
//	{
//		for (index2 = 0, index1 = 0; index2 < step2; index2++, index1 += step2)
//		{
//			Arr[index1] = *arr[index2] ;
//		}
//	}
//
//	ShellSort(Arr, size, step2); 
//
//	for (int i = 0; i < step2; i++)
//	{
//		delete arr[i]; 
//	}
//	delete[] arr;
//
//}

//donneeee
void MergeSorting(int* arr, int left, int right)
{
	if (left < right)
	{
		int m = left + (right - left) / 2;

		MergeSorting(arr, left, m); 
		MergeSorting(arr, m + 1, right);

		merge(arr, left, right, m);
	} 

}
void merge(int* arr, int leftindx, int rightindx, int dividing)//dividing = left - (right - 1)/2
{
	int i, j, k; 
	int size1 = dividing - leftindx + 1; //first sub array	from 1 to m
	int size2 = rightindx - dividing; //from m to the end
	int* Left = new int[size1];
	int* right = new int[size2];

	for ( i = 0; i < size1; i++)
	{
		Left[i] = arr[leftindx + i];
	}
	for ( j = 0; j < size2; j++)
	{
		right[j] = arr[dividing + 1 + j];
	}

	i = j = 0;
	k = leftindx;

	while (i < size1 && j < size2)
	{
		if (Left[i] <= right[j])
		{
			arr[k] = Left[i]; 
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < size1)
	{
		arr[k] = Left[i];
		i++; 
		k++;
	}

	while (j < size2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}

int partitionadelnsim(int arr[], int begin, int end)
{
	int i = begin; 
	int j = end;

	int piclov = i; 
	while (true)
	{
		while (arr[piclov] <= arr[j] && piclov != j)
			j--;

		if (piclov == j)
			break;
		else if (arr[piclov] > arr[j])
		{
			swap(arr[j], arr[piclov]);
			piclov = j;
		}

		while (arr[piclov] >= arr[i] && piclov != i) i++;

		if (piclov == i) break;
		else if (arr[piclov] < arr[i])
		{
			swap(arr[piclov], arr[i]);
			return piclov; 
		}
	}
}

void QuickkSoertAdelnsim(int arr[], int begin, int end)
{
	if (begin < end)
	{
		int piv = partitionadelnsim(arr, begin, end);
		QuickkSoertAdelnsim(arr, begin, piv - 1);
		QuickkSoertAdelnsim(arr, piv + 1, end);

	}
}

void QuickSort(int* arr, int size, int element)
{

	//de tre2t el mo7dra na2sha bs el stoping condition
	//int *Lptr = &arr[1]; 
	//int *Rptr = &arr[size - 1]; 

	//for (int i = 0; i < size; i++)
	//{

	//	if (Lptr > Rptr)
	//	{
	//		swapp(*Rptr, arr[0]);
	//		break;
	//	}

	//	if (*Rptr < arr[0] && *Lptr > arr[0])
	//	{
	//		swap(*Rptr, *Lptr);
	//		Lptr += 1;
	//		Rptr -= 1;
	//		continue;
	//	} 

	//	if (*Lptr < arr[0])
	//		Lptr += 1;
	//	
	//	if (*Rptr > arr[0])
	//		Rptr -= 1;
	//	
	//}

	QuickSort(arr, size, arr[0]);

}

void Bubble_sort(int* arr, int size)
{//O(n^2)->worst ----- O(n)->best

	//mn momyzat el bubble enha btgblk el max aw el min mn awl iteration fa btb2a helwa lw btsearch
	//meza tanya enk mmkn t3ml sorting fe loop 1 w el data tb2a khlas sorted 
	for (int t = 0; t < size; t++)
	{
		bool swaped = false;
		for (int j = 0; j < size - t - 1 ; j++) // el size - t - 1 de 3an a7ot wall w akhleh may3mlsh comparisons m3 el hagat el sorted aslun
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swaped = true;
			}
		}
		if (!swaped) break; //lw el data 7slha sorting msh hayb2a leha lazma eny akml ba2y el iterations
	}


}


void insertionSortRec(int* arr, int size, int element)
{//O(n^2) worst case , m3rof 3n el tre2a de enha btb2a helwa lw el list d5laly sorted aslun
	if (size <= 0 || element == size)
		return;

	if (arr[element] < arr[element - 1])
	{
		swapp(arr[element], arr[element - 1]);
		insertionSortRec(arr, size, element - 1);
	}
	else
		insertionSortRec(arr, size, element + 1);
}


void HeapSortingasc(int* arr, int n) // O(nlogn) 
{
	buildHeapacc(arr, n);
	for (int i = n - 1; i > 0; i--)
	{
		swapp(arr[i], arr[0]);
		heapifyaccending(arr, i, 0);
	}
	PrintList(arr, n);
}

void HeapSortingdsc(int* arr, int n)
{//O(nlogn)
	buildHeapdec(arr, n);
	for (int i = n - 1; i > 0; i--)
	{
		swapp(arr[i], arr[0]);
		heapifydeccending(arr, i, 0);
	}
	PrintList(arr, n);
}

void buildHeapacc(int* arr, int n)
{//O(nlogn)
	for (int i = (n / 2) - 1; i >= 0; i--)//(n/2) - 1 -> to get the level before the last
	{
		heapifyaccending(arr, n, i); // we moves on the tree level by level 
	}
}

void buildHeapdec(int* arr, int n)
{//O(nlogn)
	for (int i = (n / 2) - 1; i >= 0; i--)//(n/2) - 1 -> to get the level before the last
	{
		heapifydeccending(arr, n, i); // we moves on the tree level by level 
	}
}

void heapifyaccending(int* arr, int size, int parent) // de msh ht3ml build heap de htb2a function gowa el build heap
{//O(logn)
	int leftchild = (2 * parent) + 1;
	int rightchild = (2 * parent) + 2;
	int max = parent;

	if (leftchild < size)
	{
		if (arr[leftchild] > arr[parent])
		{
			if (rightchild < size)
			{
				if (arr[leftchild] > arr[rightchild])
					max = leftchild;
				else
					max = rightchild;
			}
			else
				max = leftchild; // for descending reverse and find the min
		}
		else if (rightchild < size)
		{
			if (arr[rightchild] > arr[parent])
				max = rightchild;
		}

		if (max != parent)
		{
			swapp(arr[parent], arr[max]);
			heapifyaccending(arr, size, max);  // recursive function
		}

	}
}

void heapifydeccending(int* arr, int size, int parent) // de msh ht3ml build heap de htb2a function gowa el build heap
{//O(logn)
	int leftchild = (2 * parent) + 1;
	int rightchild = (2 * parent) + 2;
	int min = parent;

	if (leftchild < size)
	{
		if (arr[leftchild] < arr[parent])
		{
			if (rightchild < size)
			{
				if (arr[leftchild] < arr[rightchild])
					min = leftchild;
				else
					min = rightchild;
			}
			else
				min = leftchild; // for descending reverse and find the min
		}
		else if (rightchild < size)
		{
			if (arr[rightchild] < arr[parent])
				min = rightchild;
		}

		if (min != parent)
		{
			swapp(arr[parent], arr[min]);
			heapifydeccending(arr, size, min);  // recursive function
		}

	}
}
void PrintList(int* arr, const int& size)
{//O(n)
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}

}

template <class zuz>
void swapp(zuz& s1, zuz& s2)
{//O(1)
	zuz temp = s1;
	s1 = s2;
	s2 = temp;
}


void selectionAscendSort(int* list, const int& size) // O(n^2)
{
	// 4 2 1 0 3 10
	int i, j;
	int index;
	int swap = 0;
	bool swaped = false;
	for (i = 0; i < size; i++)
	{
		int min = list[i];
		swaped = false;
		for (j = i + 1; j < size; j++)
		{
			if (list[j] < min)
			{
				min = list[j];
				index = j;
				swaped = true;
			}
		}
		if (swaped)
		{
			swapp(list[i], list[index]);
		}
	}
	//yeb2a el logic hena eny akny bdwr 3la el min bs 3la el size bta3 el loop kolo w kol ma bla2y el min
	//da bro7 a7oto fe awl element w b3den khlas keda bkml
}

//same logic with only diffrenet condition
void selectionDescendSort(int* list, const int& size)
{//O(n^2)
	// 4 2 1 0 3 10
	int i, j;
	int index;
	bool swaped = false;
	for (i = 0; i < size; i++)
	{
		int max = list[i];
		swaped = false;
		for (j = i + 1; j < size; j++)
		{
			if (list[j] > max)
			{
				max = list[j];
				index = j;
				swaped = true;
			}
			/*	swap = list[i];
				list[i] = list[index];
				list[index] = swap;*/
		}
		if (swaped) // momken astghna 3n el kalam da 3n tre2 eny a3ml kda
		{
			swapp(list[i], list[index]);
		}
	}
	//yeb2a el logic hena eny akny bdwr 3la el max bs 3la el size bta3 el loop kolo w kol ma bla2y el max
	//da bro7 a7oto fe awl element w b3den khlas keda bkml
}

