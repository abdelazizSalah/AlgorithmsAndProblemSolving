#include "LinkedQueue.h"
#include"../1-Stacks/ArrayStack.h"
#include <iostream>		//To use C++ console I/O functionality
//, we need to include iostream which contains necessary declarations.
using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"


/*
Function: removeFirstPostitive
	A function the removes the first non-zero items in a queue
	The function stops either because a zero-item is encounted or queue becomes empty
*/
template <typename T>
void removeFirstPostitive(LinkedQueue<T>& Q)
{
	T x;
	while (Q.peek(x))	//Have a look first before dequeuing it
		if (x <= 0)
			return;
		else
			Q.dequeue(x);
}

//A function that prints queue contents
template <typename T>
void PrintQueue(LinkedQueue<T> Q)
{
	T K;
	cout << "\nQueue contents: ";
	while (Q.dequeue(K))
		cout << K << " ";
	cout << endl;
}

//A function that prints queue contents
template <typename T>
bool ReplaceAll(LinkedQueue<T>& Source, T value, T newValue)	//Soruce is passe by ref
{
	LinkedQueue<T> tempQ;	//a temp queue is needed
	T x;
	bool found = false;
	while (Source.dequeue(x))
	{
		if (x == value)		//repalce the value if found
		{
			tempQ.enqueue(newValue);
			found = true;
		}
		else
			tempQ.enqueue(x);
	}

	//After the above loop, stack "Source" is empty
	//Restore Source stack again
	while (tempQ.dequeue(x))
		Source.enqueue(x);

	return found;
}

//A function that returns the sum of an integer queue
int QueueSum(LinkedQueue<int> Q)
{
	int s = 0;
	int x;
	while (Q.dequeue(x))
		s += x;
	return s;
}


//lab exam problem 1:s
void SumOutSideIn(LinkedQueue <int> Q1)
{
	// takes queue and should and the rear and the head 
	LinkedQueue <int> Q2;
	int Qsize = 0;
	//i need to determine the size of the queue
	while (!Q1.isEmpty())
	{
		int x;
		Q1.dequeue(x);
		Q2.enqueue(x);
		Qsize++;
	} // now Q1 is empty i won't use it again

	

	//stack to add the elements in 
	ArrayStack<int> S1(Qsize / 2); // the stack should be half the size of the queue

	ArrayStack<int> S2(Qsize / 2); //stack to print the output from
	for (int i = 0; i < Qsize / 2; i++) // iterates to add the elements in the stack
	{
		int x;
		if (Q2.dequeue(x)); //remove it from the queue and add it to the stack
		S1.push(x);
	}

	int oddelement = 0;
	if (Qsize % 2 != 0) //if odd store the middle element alone
	{
		if (Q2.dequeue(oddelement)); //remove it from the queue and add it to the stack
		S1.push(oddelement);
	}

	for (int i = 0; i < Qsize / 2; i++) // loop to calc the sum and stores it in the stack
	{
		int x, y;
		int sum = 0;
		if (Q2.dequeue(x) && S1.pop(y))
		{
			sum = x + y;
			S2.push(sum);
		}
	}

	while (!S2.isEmpty()) // loop for printing the output
	{
		int x; 
		S2.pop(x); 
		cout << x << ' ';
	}

	if (Qsize % 2 != 0)//if odd print it last
		cout << oddelement;
}

//This is the program starting point.
int main()
{

	LinkedQueue <int> Q1; 
	int size_of_queue = 0; 
	cout << "enter the size of the queue\n"; 
	cin >> size_of_queue; 
	for (int i = 0; i < size_of_queue; i++)
	{
		int x; 
		cin >> x; 
		Q1.enqueue(x); 
	}
	SumOutSideIn(Q1); 















	////Declare a queue of integers named "queue1"
	//LinkedQueue<int> queue1;
	//int x, n;

	//cout << "\nEnter no. of values to enqueue:";
	//cin >> n;

	////Test the 1st stack by pushing n values then poping
	//cout << "Filling queue 1:" << endl;
	//cout << "Enqueuing "<<n<<" values:" << endl;

	//cout<<"Please Enter the "<<n<<" values to enqueue in queue1 :";
	//for(int i = 0; i < n; i++)
	//{
	//	cin>>x;
	//	queue1.enqueue(x); //pushing x to stack2
	//}

	//PrintQueue(queue1);
	//cout<<"\nSum of queue items = "<<QueueSum(queue1);

	//int a, b;
	//cout << "\nEnter a value to replace:";
	//cin >> a;
	//cout << "\nEnter the new value:";
	//cin >> b;

	//bool isFound = ReplaceAll(queue1, a, b);
	//if (isFound)
	//	cout << "\nValue replaced";
	//else
	//	cout << "\nValue not found";
	//PrintQueue(queue1);


	//cout << "\nRemoving first +ve items:";
	//removeFirstPostitive(queue1);

	//cout << "After removal: ";	
	//PrintQueue(queue1);
	//
	//cout<<endl;

	//Write code to test empty case and to test peekFront function

		//Declare a queue of integers named "queue1"
	//LinkedQueue<int> queue1;
	//int x, n;

	//cout << "\nEnter no. of values to enqueue:";
	//cin >> n;
	//cout << "Please Enter the " << n << " values to enqueue in queue1 :";
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> x;
	//	queue1.enqueue(x); //pushing x to stack2
	//}

	//int first, sec ;
	//for (size_t i = 0; i < n / 2 + 1; i++)
	//{
	//	queue1.dequeue(first);
	//	queue1.peek(sec);
	//	if (first != sec)
	//	{
	//		queue1.enqueue(first);
	//	}
	//	else
	//	{
	//		queue1.dequeue(sec);
	//		queue1.enqueue(first);
	//	}
	//}
	//PrintQueue(queue1);
	//


	return 0;
 }

