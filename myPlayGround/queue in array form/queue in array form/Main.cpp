#include <iostream>
using namespace std;
#include <cassert>
template <class T>
class Queue
{
	int rear;
	int front;
	T* arr;
	int count;
	int MaxSize;
public:

	Queue(int& Ms)
	{
		MaxSize = Ms > 0 ? Ms : 100;
		count = 0;
		front = 0; //34an ana ha3mlo circular kda kda
		rear = MaxSize - 1; // 34an yshawr 3la akher element
		arr = new T[MaxSize];
	}

	//copyConstructor
	Queue(const Queue<T>& Q1)
	{
		T dummy;
		Queue<T> Q2;
		arr = new T[Q1.getSize()];
		while (Q1.dequeue(dummy))
		{
			enqueue(dummy);
			Q2.enqueue(dummy); // 34an arg3 el queue el aslya bt3ty zy ma hya m2srsh feha
		}
		while (Q2.dequeue(dummy))
			Q1.enqueue(dummy);
	}

	//operator overloading
	void operator = (Queue <T>& Q1)
	{
		Clear();
		T dummy;
		Queue<T> Q2;

		if (MaxSize != Q1.getMaxSize())
		{
			delete[] arr;
			arr = new T[Q1.getMaxSize()];
		}

		while (Q1.dequeue(dummy))
		{
			enqueue(dummy);
			Q2.enqueue(dummy); // 34an arg3 el queue el aslya bt3ty zy ma hya m2srsh feha
		}
		while (Q2.dequeue(dummy))
			Q1.enqueue(dummy);
	}

	//bool Search(const T& item)
	//{
	//	T dummy;
	//	while (dequeue(dummy))
	//		if (item == dummy)
	//			return true;
	//	return false;
	//}

	int Search(const T& item )
	{
		if (IsEmpty())
			return -1; 
		
		int pos = -1;
		for (int i = front; i != rear; i = (i + 1) % MaxSize)
		{
			if (arr[i] == item)
			{
				pos = i;
				break;
			}
		}
		if (item == arr[rear])
			return rear;
		return pos;
	}
	bool IsEmpty()
	{
		return (count == 0);
	}

	bool IsFull()
	{
		return (count == MaxSize); // fe tre2a tanya best5dam el rear wl front 
	}

	bool enqueue(T& item)
	{
		if (!IsFull())
		{
			rear = (rear + 1) % MaxSize; // keda howa  hay3mlha circular
			arr[rear] = item;
			count++;
			return true;
		}
		else
			return false;

	}

	bool dequeue(T& item)
	{
		if (!IsEmpty())
		{
			item = arr[front];
			front = (front + 1) % MaxSize;
			count--;

			return true;
		}
		else
			return false;
	}

	T getfront()
	{
		assert(!IsEmpty()); // de 3bara 3n function btst2bl bool w lw el func false bygblk hwa false leh w fe anhy satr w bytl3lk el error
		return arr[front];
	}

	T getrear()
	{
		assert(!IsEmpty()); // de 3bara 3n function btst2bl bool w lw el func false bygblk hwa false leh w fe anhy satr w bytl3lk el error
		return arr[rear];
	}

	int getCount()
	{
		return count;
	}

	int getMaxSize()
	{
		return MaxSize;
	}
	void Clear()
	{
		T dummy;
		while (!IsEmpty())
			dequeue(dummy);
	}

	void PrintQueue()
	{
		/*if (IsEmpty())
			return;
		int x;
		while (dequeue(x))
		{
			cout << x << ' ';
		}*/ // el klam da msh s7 34an nta keda btfdy el queue kolaha
		if (IsEmpty())
			return;
		for (int i = front; i != rear ; i = (i + 1) % MaxSize)
		{
			cout << arr[i] << ' ';
		}
		cout << arr[rear];
	}

	~Queue()
	{
		Clear();
	}
};

int main()
{
	int N;
	cout << "\n enter the size of the queue: ";
	cin >> N;
	Queue<int> Q1(N);
	cout << "\n enter the element in the queue: ";
	for
		(int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		Q1.enqueue(x);
	}

	/*cout << "\n dequeueing the queue: ";
	for (int i = 0; i < N; i++)
	{
		int x; 
		Q1.dequeue(x);
		cout << x << ' ';
	}*/

	N = Q1.Search(5);
	cout << N + 1; // if 0  y3ny msh mwgod
	Q1.PrintQueue();
	return 0;
}