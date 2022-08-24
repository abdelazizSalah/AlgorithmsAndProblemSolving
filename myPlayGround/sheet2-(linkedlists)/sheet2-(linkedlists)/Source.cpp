#include <iostream>
using namespace std;

struct node
{
	int item;
	node* next;
};


int LLtraverse_and_count(node* &head)
{
	node* ptr = head;
	int count = 0;
	
	while (ptr)
	{
		//to count the negative items
		if (ptr->item < 0)
			count++;

		ptr = ptr->next;
	}
	return count;
}

int Atraverse_And_count(int*& arr, int n)
{
	int* ptr = arr;
	int count = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (ptr[i] < 0)
			count++;
	}
	return count;
}

int minvalLL(node*& head)
{
	int min = head->item;
	node* ptr = head->next;

	while (ptr)
	{
		//to find the min
		if (ptr->item < min)
			min = ptr->item;

		//the ptr must transverse
		ptr = ptr->next;
	}

	return min;
}

int minvalArr(int* arr, int size)
{
	int* ptr = arr;
	int min = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

void printarr(int* l, int size, int* p, int size2)
{

	cout << "\n{";
		for (int i = 0; i < size2; i++)
	{
		cout << l[p[i] - 1]; 
	}
		cout << "}";

}

void printLL(node* N1, node* N2)
{
	cout << endl;
	node* ptr2 = N2;
	while (ptr2)
	{
		node* ptr = N1; // 34an kol mara akhleh yebd2 ml awl khales // bs khud balk keda el complexity bta3tk O(n^2)
		for (int i = 0; i < ptr2->item - 1; i++)
		{
			if(ptr)
			ptr = ptr->next;
		}
		if(ptr)
		cout << ptr->item << " "; 
		ptr2 = ptr2->next;
	}
}

void print(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
void completearr(int* arr, int size)
{
	int min = arr[0];
	int max = arr[size];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		else if (arr[i] > max)
			max = arr[i];
	}
	int count = max - min + 1;
	int* arr2 = new int [count];
	//// first element equal to the first element
	//arr2[0] = arr[0];
	////last element equal to the last element
	//arr2[count] = arr[size];
	for(int i = 0; i < count; i++)
	{
		arr2[i] = min++;
	}

	print(arr2, count);

	//de tmam fadly baa a3mlha bl linked list
}


int main()
{
	/*int arr[6] = { 1 , 2, 3, 4, 5 ,6 };
	int arr2[3] = { 4 , 1 , 6 }; 
	printarr(arr, 6, arr2, 3);*/

	int arr3[4] = { 1 , 4, 5, 7 }; 
	completearr(arr3, 4);

	//node n1;
	//node n2;
	//node n3;
	//node* head = &n1;
	//head-> item= 5;
	//n1.item = 7; 
	//n1.next = &n2;
	//n2.item = 0;
	//n2.next = &n3;
	//n3.item = 10;
	//n3.next = nullptr;

	//node n11;
	//node n22;
	//node n33;
	//node* head2 = &n11;
	//n11.item = 1;
	//n11.next = &n22;
	//n22.item = 2;
	//n22.next = &n33;
	//n33.item = 3;
	//n33.next = nullptr;


	//printLL(head, head2);

	return 0;
}