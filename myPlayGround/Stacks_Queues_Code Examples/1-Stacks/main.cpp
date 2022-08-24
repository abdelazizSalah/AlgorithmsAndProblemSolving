
#include "ArrayStack.h"	
#include <iostream>		//To use C++ console I/O functionality
//, we need to include iostream which contains necessary declarations.
using namespace std;	//This statement enables us to use classes and objects in the standard C++ library
						//without prefixing them with "std::"

// This caod has 1 checkpoint [CheckPoint 1]
//Follow the provided instructions at each check point

//This is the program starting point.
int main()
{
	////Declare a Stack of integers named "S" and with max size = 10 elements
	//ArrayStack<int> S(10);

	//int i,x,n;

	//cout<<"\nEnter no. of values to push into stack:";
	//cin>>n;

	////Test the 1st stack by pushing n values then poping
	//cout << "Testing stack S......" << endl;
	//cout << "Pushing "<<n<<" values into S:" << endl;

	//cout<<"Please Enter the "<<n<<" values to push in S :";
	//for(i = 0; i < n; i++)
	//{	 
	//	cin>>x;
	//	S.push(x); //pushing x to S
	//}

	///*cout << endl<<"Popping: ";*/

	////while(S.pop(x))		//as long as pop returns true, so x contains a valid value		
	////	cout << x << " ";

	///// ==> [CheckPoint 1]
	////After 1st run, comment the above while loop and uncomment the while loop below

	//if(S.peek(x))		//as long as peek returns true, so x contains a valid value		
	//	cout << x; // blash fol7 baaa2


	//
	//cout<<endl;

	//cout<<"Testing function isEmpty ==> is S Empty?? ==> "<<boolalpha<<S.isEmpty();
	//cout<<endl;

	cout << "enter the number of elements you want t push in the stack: ";
	int size;
	cin >> size;
	ArrayStack<int> s(size);
	cout << "\n enter the values you want to store: ";
	int element;
	for (size_t i = 0; i < size; i++)
	{
		cin >> element;
		s.push(element);
	}
	int* arr = new int[size / 2];
	int even;
	if (size % 2 == 0)
	{
		even = 0;
	}
	else
		even = 1;

	for (int i = even; i < size / 2; i++)
	{
		int x, y;
		s.pop(x);
		s.pop(y);
		arr[i] = x + y;
	}

	for (int  i = size/2; i > 0 ; i--)
	{
		s.push(arr[i]);
	}

	
	return 0;
}

