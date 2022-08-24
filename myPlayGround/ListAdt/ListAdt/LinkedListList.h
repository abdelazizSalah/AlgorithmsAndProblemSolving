#pragma once
#include"ArrList.h"

template <class T>
struct Node
{
	T item;
	Node* next;
};

template <typename T >
class LinkedListList :public ListInterface<T>
{
private:
	Node <T>* head;
	int count;
	Node <T>* getPtrto(const int& pos) // de utility function
	{
		return (getPtrtoprev(pos)->next);

	}
	Node <T>* getPtrtoprev(const int& pos) // de utility function
	{
		if (!IsEmpty() && pos < count && pos > 0)
		{
			Node<T>* dummy = head;
			for (size_t i = 1; i < pos - 1; i++)
			{
				dummy = dummy->next;
			}
			return dummy;
		}
	}
	Node<T>* getHead()
	{
		return head;
	}
public:
	LinkedListList()
	{
		count = 0;
	}

	LinkedListList(const LinkedListList <T>& L2)
	{
		Node<T>* dummy = L2.getHead();
		int i = 0;
		while (dummy)
		{
			insert(L2.getEntery(i), i);
			i++;
			dummy = dummy->next;
		}
	}

	bool operator = (const LinkedListList <T>& L2)
	{
		clear();
		Node<T>* dummy = L2.getHead();
		int i = 0;
		while (dummy)
		{
			insert(L2.getEntery(i), i);
			i++;
			dummy = dummy->next;
		}
	}
	virtual	bool IsEmpty() const
	{
		return (count == 0);
	}

	virtual	int getLen() const
	{
		return count;
	}

	virtual	bool insert(const T& IT, const int &pos)
	{	//---------------------------------------------------------------------------------------------------------------
		//ka3da sabta fl insertion in middle lazm ageb el node el abl el mkan el ana 3auz adkhl feh el node el gdeda	|
		//  w nfs el kalam fl delete in middle lazm ageb el node le abl el ana 3auz adkhl feha							|
		//---------------------------------------------------------------------------------------------------------------
		// lazm lw had5l haga adkhlha bl trteb 
		//ha7tag 2 ptrs 
		if (pos > 0 && pos <=  count + 1 )
		{
			
			Node<T>* curr = new Node <T>;
			curr->item = IT;

			if (pos == 1)
			{
				curr->next = head;
				head = curr;
				count++;
				return true;
			}
			else
			{
				Node<T>* prev = getPtrtoprev(pos);
				curr->next = prev->next;
				prev->next = curr->next;
				count++;
				return true;
			}
		}
		return false;
	}

	virtual	bool remove(const int& pos)  // de btms7 mkan mo3yn
	{

		if (!IsEmpty() && pos < count && pos > 0)
		{

			Node<T>* curr = getPtrto(pos);;
			if (pos == 1)
			{
				head = head->next;
				delete curr;
				count--;
				return true;
			}
			else
			{
				Node<T>* prev = getPtrtoprev(pos);
				prev->next = curr->next;
				delete curr;
				count--;
			}
		}
		else return false;
	}

	virtual	bool remove(const T& it)  // de btms7 element mo3yn
	{
		if (!IsEmpty() && pos < count && pos > 0)
		{
			bool found = false;
			Node<T>* curr = head;
			int i = 1;
			while (curr)
			{
				if (curr->item == it)
				{
					remove(i);
					count--;
					found = true;
				}
				i++;
				curr = curr->next;
			}
			return found;
		}
	}

	virtual	void clear()
	{
		if (!IsEmpty())
		{
			/*Node <T>* dummy;
			dummy = head;
			while (head)
			{
				head = head->next;
				delete dummy;
				dummy = head;
			}*/ // el 7l da tmam bss fe ashal enk t3ml keda
			remove(1);
		}
	}

	virtual	T getEntery(const int& pos) const
	{
		if (!IsEmpty() && pos < count && pos > 0)
		{
			Node<T>* dummy = getPtrto(pos);
			return dummy->item; 
		}
	}

	virtual	T replace(const int& pos, const T& it)
	{
		if (!IsEmpty() && pos < count && pos > 0)
		{
			Node<T>* dummy = getPtrto(pos);
			Node<T>* dummy2 = dummy; // 34an ana 3auz arg3 el element da 
			dummy->item = it;
			return dummy2;
		}
	}

	virtual ~LinkedListList()
	{
		clear();
	}
};
 //done :)