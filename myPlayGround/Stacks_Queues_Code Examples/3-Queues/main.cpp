
#include "LinkedQueue.h"
#include <iostream>		//To use C++ console I/O functionality
						//, we need to include iostream which contains necessary declarations.

using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"
//This is the program starting point.
int main()
{


	//Declare a queue of integers named "Q"
	LinkedQueue<int> Q;
	int x;

	//Test the queue by enqueue 6, 7, 8, 9 and 10 then dequeue them.
	cout << "Testing Q:" << endl;
	cout << "inserting 5 values into Q:" << endl;

	cout<<"Please Enter the 5 values to enqueue in queue1 :";
	for(int i = 0; i < 5; i++)
	{
		cin>>x;
		Q.enqueue(x); //pushing x to stack2
	}

	cout << "Testing dequeue operation:\n ";

	while(Q.dequeue(x))
		cout << x << " ";

	cout<<endl;

	//Write code to test empty case and to test peekFront function
	return 0;
}
  
