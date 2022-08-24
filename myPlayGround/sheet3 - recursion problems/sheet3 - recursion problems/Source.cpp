#include <iostream>
using namespace std;

template <class T >
struct Node
{
	T item;
	Node <T>* next;
};
int sumseries(int n)
{
	//3auzha recursion
	if (n < 2)
		return 1;
	else
		return n + sumseries(n - 1);
	//done 
}

double sumser(const int& n)
{
	if (n == 1)
		return 1;
	else
		return (1.0 / n + sumser(n - 1));
}

int sumarr(int* Arr, const int& size)
{
	if (size == 1) // de lazm teb2a 1 34an mgm34 awl element mrten
		return Arr[0];
	else
		return Arr[size - 1] + sumarr(Arr, size - 1);
}

int frequancy(int* arr, const int& size, const int& val)
{
	if (size < 1)
		return 0;
	else
	{
		if (arr[size - 1] == val)
			return 1 + frequancy(arr, size - 1, val);
		frequancy(arr, size - 1, val);
	}

}

template <typename T>
int linkedlen(Node<T>* head)
{
	if (!head)
		return 0;
	else
	{
		head = head->next;
		return 1 + linkedlen(head);
	}
}

template <typename T >
int evenlinked(Node<T>* head)
{
	if (!head)
		return 0;
	else
	{
		if (head->item % 2 == 0)
		{
			head = head->next;
			return 1 + evenlinked(head);
		}
		else
		{
			head = head->next;
			return evenlinked(head);
		}

	}
}

template <class T>
void printfor(Node<T>* head)
{
	if (!head)
		return;
	cout << head->item << " ";
	printfor(head->next); // to make it print back we will change the order
}
template <class T>
void printback(Node<T>* head)
{
	if (!head)
		return;

	printback(head->next);
	cout << head->item << " ";
}

void printuserreversed(int n = 0)
{
	cin >> n;
	if (n == 0)
		return;
	printuserreversed(n);
	cout << n << " ";
}

void printuserfor (int n = 0)
{
	cin >> n;
	if (n == 0)
		return;
	cout << n << " ";
	printuserfor(n);
}

int LastOcc(int* arr, int size , int val )
{
	if (size == 0)
		return -1;

	if (arr[size] == val)
		return size;
	else
		LastOcc(arr, size - 1, val);

}
int FirstOcc(int* arr, int size, int val, int i = 0)
{
	if (i == size)
		return -1; // not found
	if (arr[i] == val)
		return i;
	else
		return FirstOcc(arr, size, val, ++i); // mt3mlhash i++ 34an hydek runtime error ebn7ram
}

//template <typename T >
//void invert(Node <T>* (head) = nullptr , Node <T>** dummy = nullptr, Node <T>** nex =nullptr)
//{
//	if (!head->item)
//		return;
//
//	head->next = dummy;
//	dummy = head;
//	head = nex;
//	if (nex)
//	nex = nex->next;
//	invert(head, dummy, nex);
//	//need to be modified
//}

template < typename T> 
bool incresingLinked(Node<T>* head)
{
	if (!head->next)
		return true;
	if (head->item < head->next->item)
		incresingLinked(head->next);
	else
		return false;
}

void dec2bin(int n)
{
	if (n == 0)
		return;
	dec2bin(n / 2);
	cout << n % 2;
}

void printpyramid(char ch)
{
	//	3AUZ ENO YDEK 7RF FA TRSM HRM BEH 
	// 				   a
	//				  ABA
	//				 ABCBA
	//				ABCDCBA
	//w hakaza
	for (char c = ch , j = 0 ; c >= 'A' ; c-- , j++ )
	{
		int spaces = c - 'A';
		for (int i = 0; i < spaces; i++)
		{
			//ana hena lazm a7dd 3dd el spaces el awl 
			cout << " ";
		}
		char let = 'A' + j; //	kol mara me7tag azwd el 7rf 1 w ana aslun bade2 mn el A
		for (char i = 'A'; i <= let; i++)
		{
			cout << i; // toul ma el let asghr ml A BT3TY 3auzo ytb3 
			//forward part
		}
		for ( char i = let - 1; i >= 'A' ;  i--)
		{
			cout << i; //da el backward part
		}
		cout << endl;//kol mara lazm y3ml line gded

		//keda complexity O(N^2)
	}

}




int main()
{
	int Arr[6] = { 1 , 2 , 3  , 1 , 1,  6 };
	Node<int> *hptr;
	Node<int> head;
	head.item = 2;
	Node <int> n2;
	n2.item = 7;
	head.next = &n2;
	Node <int> n3;
	n3.item = 6;
	n2.next = &n3;
	n3.next = nullptr;
	printfor(&head);
	cout << endl;
	hptr = &head;
	//invert(hptr, &n3.next, &head.next);
	cout << hptr->item;
	
	return 0;
}