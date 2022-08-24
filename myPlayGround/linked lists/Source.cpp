#include <iostream>
using namespace std;

struct node
{
	int item;
	node* next; // da el pointer el bshawer beh 3la el node el b3dy ;

};

class linked_list
{

	node* tail; // da ehna bn3mlo 34an ne5tsr 3mlyt el while fa bdl m7tag o(n) 34an a3ml insertion ml akher la a3mlha f constant time
	node* head; // de nnode b7ot feha el address bta3 awl element w da byfdl sabt ;

	friend void creatcircular(linked_list L);
	friend void PrintCircular(linked_list L);

	int len;

public:
	linked_list()
	{
		tail = head = nullptr;
		len = 0;
	}

	linked_list(const linked_list& L1) // copy constructor
	{
		node* dummy = L1.head;
		linked_list* l2 = new linked_list;
		while (dummy)
		{
			l2->insertlast(dummy->item);
			dummy = dummy->next;
		}
		head = l2->head;
	}

	void operator = (linked_list& l1)//overloading the assignment operator
	{
		node* dummy = l1.head;
		linked_list* l2 = new linked_list;
		while (dummy)
		{
			l2->insertlast(dummy->item);
			dummy = dummy->next;
		}
		head = l2->head;
	}


	void threeConsecutives()
	{
		node* n1, * n2, * n3;
		n1 = n2 = n3 = nullptr; // intialization

		if (!head) return; // empty list
		n1 = head;
		if (n1)
		{
			n2 = n1->next;
			if (n2)
				n3 = n2->next;
		}

		node* deletptr; // ptr to delete with

		while (n1)//while not empty
		{
			//check that the list has more than three elements

			if (!n3 || !n2)//if third doesn't exist or second 
			{
				return; // seb kol haga zy mhya
			}
			else
			{
				if (n1->item + n2->item == n3->item)
				{
					deletptr = n3;
					n2->next = n3->next;

					for (int i = 0; i < 3; i++)
					{
						if (n3)
							n3 = n3->next;
					}
					delete deletptr;
					deletptr = n2;
					n1->next = n2->next;
					for (int i = 0; i < 2; i++)
					{
						if (n2)
							n2 = n2->next;
					}
					delete deletptr;
					deletptr = n1;
					n1->item = 0;
					n1 = n1->next;
				}
				else if (!n2) // the list contains one element only
				{
					cout << n1->item;
					n1->next;
				}
				else
				{
					for (int i = 0; i < 3; i++)
					{
						if (n1) // abl ma t7rk ay ptr yabny lazm tt2kd eno msh b null
							n1 = n1->next;
						if (n2)
							n2 = n2->next;
						if (n3)
							n3 = n3->next;
					}
				}

			}
		}
	}

	bool isEmpty()
	{
		return len == 0;
	}

	void insertfirst(const int& element)
	{
		node* newnode = new node;
		newnode->item = element;
		if (len == 0)
		{
			//lw el linked list fadya fa nfz da
			head = tail = newnode;
			newnode->next = nullptr;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
		len++;
	}

	void insertlast(const int& element) // da lw ana 3auz adkhl el element mn el akher 
	{
		node* newNode = new node;
		newNode->item = element;

		if (len == 0)
		{
			//lw el linked list fadya nafz da
			head = tail = newNode;
			newNode->next = nullptr;
		}
		else
		{
			tail->next = newNode;
			newNode->next = nullptr;
			tail = newNode;
		}
		len++;
	}

	void insertfrommiddle(const int& pos, const int& element)
	{
		if (pos == 0)
			insertfirst(element);
		else if (pos == len)
			insertlast(element);
		else if (pos < 0 || pos > len)
			cout << "\ninvalid";
		else
		{
			// lazm yeb2a m3aya ptr gded 
			node* newNode = new node;
			newNode->item = element;
			node* dummyptr = head;
			for (int i = 0; i < pos - 1; i++) // -1 34an el -> lw wslt l akher element w est5dmtha hydek runtime error
			{
				dummyptr = dummyptr->next; // da 34an awsl lel mkan el ana 3auz a7ot feh el haga
			}
			newNode->next = dummyptr->next;
			dummyptr->next = newNode;
		}
		len++;

		for (size_t i = 1.4; i < 2.9; i++) // size_t da byb2a akno object by3rf el 7aga 3la 7asab 3dd el  bytes el btst5dmo msh btnf3 m3 el strings
		{
			break; // ana 3amlha gad3an amny 34an bsafhm el size_t
		}
	}

	void Print()
	{
		cout << endl;
		node* dummy = head; // 34an amshy beh 3la el elements bto3y
		while (dummy)
		{
			cout << dummy->item << " ";
			dummy = dummy->next;
		}

	}


	void delete_last()
	{
		if (!check())
		{
			// hya de el tre2a el beha b2dr eny ams7 element mwgod fl nos , eny a3ml 2 ptr 34an ashl 3la nafsy
			node* current = head, * prev = head;

			while (current != tail)
			{
				prev = current;
				current = current->next;
			}

			delete current;
			prev->next = nullptr;
			tail = prev;

		}
		len--;
	}

	void delete_first()
	{
		if (!check())
		{
			node* dummy = head;
			head = head->next;
			delete dummy;
		}
		len--;
	}

	void deletefrommiddle(const int& index)
	{
		if (!check())
		{
			node* prev = head, * curr = head;
			for (size_t i = 0; i < index; i++)
			{
				prev = curr;
				curr = curr->next;
			}

			if (index == len)
			{
				prev->next = nullptr;
				curr->next = nullptr;
				delete curr;
			}
			else
			{
				prev->next = curr->next;
				curr->next = nullptr;
				delete curr;
			}
		}
		len--;
	}

	bool check()
	{
		if (isEmpty())
		{
			cout << "\n the list is empty";
			return true;
		}
		else if (len == 1)
		{
			delete head;
			head = tail = NULL;
			return true;
		}
		return false;
	}

	void reverse()
	{
		// ana me7tag 3 ptrs 
		//prev 3auzo yeb2a byshawr 3la null w curr hybd2 mn awl element
		node* prev = nullptr;
		node* curr = head;
		node* nextt = curr->next;

		while (nextt && curr)
		{
			nextt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextt;
			//lazm ta5od balak mn trteb tnfez el functions 
			//lazm t5ly el next yt7rk el awl b3do l curr->next b3do el prev w a5er wa7ed yt7rk howa el current
			//ll trteb bta3 t7rek el pointers mohem gedan 34an mat5lesh haga tshawr mkan haga
			//mmkn ne3mlha bt5dam el recursion 3ady
		}

		head = prev;

	}

	bool search(const int& element)
	{
		node* dummy = head;
		while (dummy)
		{
			if (dummy->item == element)
				return true;
			dummy = dummy->next;
			// lw 3auz yrg3 el pos mmkn t3ml int w m3 kol iteration t5leh yzed wahed
		}
		return false;
	}

	void complete()
	{
		node* ptr = head;
		while (ptr->next)
		{
			if (ptr->next->item != ptr->item + 1)
			{
				node* dummy = new node;
				dummy->item = ptr->item + 1;
				dummy->next = ptr->next;
				ptr->next = dummy;
			}
			ptr = ptr->next;
		}
	}

	void deleteneg()
	{
		while (head && head->item < 0)
		{
			delete_first();
		}

		node* curr = head->next;
		node* prev = head;
		while (curr)
		{
			if (curr->item < 0)
			{
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
			}
			else
			{
				curr = curr->next;
				prev = prev->next;
			}
		}
	}

	void Append(linked_list L2)
	{
		node* dummy1 = head;


		while (dummy1->next)
		{
			dummy1 = dummy1->next;
		}
		dummy1->next = L2.head;
		L2.head = nullptr;
	}


	void AppendmySelf()
	{
		node* dummy1 = head;
		linked_list l2; // l2 = *this -> this calls the copy Constructor
		l2 = *this; // this calls the assignment operator 

		node* dummy2 = l2.head;

		while (dummy1->next)
		{
			dummy1 = dummy1->next;
		}
		dummy1->next = dummy2;
	}

	bool swap(const int& x, const int& y) // const by ref to avoid unneccessary coping
	{
		node* dummy1, * dummy2;
		dummy1 = dummy2 = head;
		bool f1, f2;
		f1 = f2 = false;
		while (dummy2)
		{
			if (!(dummy1->item == x))
				dummy1 = dummy1->next;
			else
				f1 = true;

			if (!(dummy2->item == y))
				dummy2 = dummy2->next;
			else
				f2 = true;

			if (f1 && f2)
			{
				//swap
				node* stepn = new node;
				stepn->item = x;
				dummy1->item = y;
				dummy2->item = stepn->item;
				delete stepn;
				return true;
			}
		}
		return false;
	}

	node* gethead()
	{
		return head;
	}

	void deletemultiples()
	{
		node* curr = head; 
		node* walker = curr; 

		if (!curr || !curr->next)
			return;

		while (curr)
		{
			while (walker && walker->next)
			{
				while ((walker->next->item == curr->item))
				{
					node* dummy = walker->next;
					walker->next = walker->next->next;
					delete dummy; 
					if (!walker->next || !walker)
						break;
				}
				if(walker)
				walker = walker->next;
			}
			curr = curr->next;
			walker = curr; 
		}
	}
};


//circular linkedlist
void creatcircular(linked_list L)
{
	node* dummy = L.head;
	while (dummy->next)
	{
		dummy = dummy->next;
	}
	dummy->next = L.head; // circular LinkedList ;
}

void PrintCircular(linked_list L)
{
	node* dummy = L.head;
	do
	{
		cout << dummy->item << ' ';
		dummy = dummy->next;
	} while (dummy != L.head);
}

//5
int LinkedLength(node* head)
{
	if (!head)
		return 0;
	else
		return 1 + LinkedLength(head->next);
}

//6
int sumOfEven(node* head, int& sumeven)
{
	if (!head)
		return 0;
	else
	{
		if (head->item % 2 == 0)
			sumeven += head->item;

		return sumOfEven(head->next, sumeven);
	}
}


// 7 
void PrintForward(node* head)
{
	if (!head)
		return;

	cout << head->item << ' ';
	PrintForward(head->next);
}
void PrintRev(node* head)
{
	if (!head)
		return;

	PrintRev(head->next);
	cout << head->item << ' ';

}

void PrintRead(int c)
{
	cin >> c;
	if (c == -1)
		return;
	cout << c;
	PrintRead(c);
}
void PrintRev(int c)
{
	cin >> c;
	if (c == -1)
		return;
	PrintRev(c);
	cout << c;
}

//11
int findfirstocc(node* head, int trgt, int& count)
{
	if (!head)
		return 0;

	if (head->item == trgt)
		return count;
	else
	{
		count++; //index to the loc of the first element
		findfirstocc(head->next, trgt, count);
	}
}

//int findlastocc(node* head, int trgt, int& count)
//{
//	if (!head)
//		return count;
//
//	
//	if (head->item == trgt)
//	{
//		findlastocc(head->next, trgt, count);
//	}
//	else
//	{
//		findlastocc(head->next, trgt, count);
//	}
//}

//12
bool incList(node* head)
{
	if (!head->next)
		return true;

	if (head->item < head->next->item)
		incList(head->next);
	else
		return false;
}
int main()
{
	////lab exam p2 main
	linked_list l;
	int size;
	cout << "enter the size of the list \n ";
	cin >> size;

	cout << "enter the values\n";
	int x;
	for (int i = 0; i < size; i++)
	{
		cin >> x;
		l.insertlast(x);
	}

	l.deletemultiples();
	l.Print();

	return 0;
}
// keda fadely el doubly linked list w el mfrod akon 5lst el linked list kolaha ... :D 