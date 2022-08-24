// { Driver Code Starts
#include <iostream>	
#include <vector>
using namespace std;

void add_to_vector(vector<int>& A, int x);


void sort_vector_asc(vector<int>& A);


void reverse_vector(vector<int>& A);

int size_of_vector(vector<int>& A);

void sort_vector_desc(vector<int>& A);

void print_vector(vector<int>& A);

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		vector<int> A;
		int q;
		cin >> q;
		while (q--)
		{
			char c;
			cin >> c;
			if (c == 'a')
			{
				int x;
				cin >> x;
				add_to_vector(A, x);
			}
			if (c == 'b')
			{
				sort_vector_asc(A);
			}
			if (c == 'c')
			{
				reverse_vector(A);
			}
			if (c == 'd')
			{
				cout << size_of_vector(A) << " ";
			}
			if (c == 'e')
			{
				print_vector(A);

			}
			if (c == 'f')
			{
				sort_vector_desc(A);
			}

		}
		cout << endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete below methods*/

/*inserts an element x at
the back of the vector A */
void add_to_vector(vector<int>& A, int x)
{
	//Your code here
	A.push_back(x);
}

/*sort the vector A in ascending order*/
void sort_vector_asc(vector<int>& A)
{
	//Your code here
	int size = A.size();
	for (int i = 0; i < size; i++)
	{
		bool swap = false;
		for (int j = 0; j < size - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				int swap = A[j];
				A[j] = A[j + 1];
				A[j + 1] = swap;
				swap = true;
			}
		}
		if (!swap)
			break;
	}
}

/*reverses the vector A*/
void reverse_vector(vector<int>& A)
{
	//Your code here
	int size = A.size();
	for (int i = 0; i < size; i++)
	{
		int swap = A[size - 1];
		A[size - 1] = A[i];
		A[i] = swap;

		size--;
	}
}

/*returns the size of the vector  A */
int size_of_vector(vector<int>& A)
{
	//Your code here
	return A.size();
}

/*sorts the vector A in descending order*/
void sort_vector_desc(vector<int>& A)
{
	//Your code here
	int size = A.size();

	for (int i = 0; i < size; i++)
	{
		int index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (A[j] > A[index])
				index = j;
		}
		int swap = A[index];
		A[index] = A[i];
		A[i] = swap;
	}
}

/*prints space separated
elements of vector A*/
void print_vector(vector<int>& A)
{
	//Your code here
	for (auto it : A)
		cout << it << ' ';
}