#pragma once
#include"Bag.h"
#include"Node.h"

template <typename T>
class LinkedListBag : public BagInterface <T>
{
	Node<T>* head;
	int itemCount; 
	Node<T>* getPtrTo(const T& it) const // de utility function brdo btdwrly 3la el item bta3y
	{ 
		Node<T>* DUMY = GetPtrToprev(it);
		if (DUMY)
			return DUMY->getnext();

		return nullptr;
	};
	Node<T>* GetPtrToprev(const T& it) const // de utility function brdo btdwrly 3la el item bta3y
	{
		Node<T>* dummy = head;
		for (size_t i = 0; i < itemCount; i++)
		{
			if (dummy->getitem() == it)
				return dummy;

			dummy = dummy->getnext()
		}
		return nullptr;
	}
	
	Node<T>* GetHead()
	{
		return head;
	}
public :

	LinkedListBag() {
		head = new Node <T>;
		itemCount = 1;
	}

	LinkedListBag(const LinkedListBag<T>& abag) // da copy constructor
	{
		int size = abag.getCurrSize();
		Node<T>* dummy = abag.GetHead();
		for (size_t i = 0; i < size; i++)
		{
			add(dummy->getitem());
			dummy = dummy->getnext();
		}
	}
	bool operator = (LinkedListBag<T>& abag)
	{
		int size = abag.getCurrSize();
		clear();
		int size = abag.getCurrSize();
		Node<T>* dummy = abag.GetHead();
		for (size_t i = 0; i < size; i++)
		{
			add(dummy->getitem());
			dummy = dummy->getnext();
		}
	}

	int getCurrSize()  const 
	{
		return itemCount;
	}
	bool isEmpty() const
	{
		return (itemCount == 0;
	}
	bool add(const T& it) 
	{
	//bema eny msh muhtam bl trteb fana mmkn a5leh y7ot ay element fl awl 34an ashal haga
			Node<T>* ptr = new Node<T>;
			if (ptr) // 34an mmkn myb2a4 fe mkan fl memory
			{
				ptr->setitem(it);
				ptr->setNext(head);
				head = ptr;
				itemCount++; 
				return true;
			}
			return false;
	} 
	bool remove(const T& it) 
	{
		//bema eny msh muhtm bl trteb brdo fana brdo 
		if (itemCount > 0)// lw msh empty
		{
			/*Node <T>* prev = GetPtrToprev(it);
			Node<T>* dummy = prev->getnext();
			if (dummy)
			{
				dummy = dummy->getnext();
				prev = prev->getnext();
				delete prev;
			}*/ // el klam da helw bs feh ashal meno 

			Node<T> * dummy = getPtrTo(it);
			if (dummy)
			{
				dummy->setitem(head->getitem());
				dummy = head->getnext();
				delete head;
				head = dummy;
				itemCount--;
				return true;
			}
			return false;
		}
	}
	void clear() 
	{
		Node<T>* dummy = head;
		while (head)
		{
			//hfdl ams7 fl head l7d ma afdeh
			head = head->getnext();
			delete dummy;
			dummy = head;
		}
	}
	int getFrequancyof(const T& it) const
	{
		int count = 0;
		Node<T>* dummy = head;
		while (dummy)
		{
			if (dummy->getitem() == it)
				count++;
		}
		return count;
	} // btrg3 3dd tekrar 7aga mo3yna

	bool Contains(const T& it) const
	{
		return (getPtrTo(it) != nullptr);
	} // btshof el 7aga de mwgoda wla laa


	~LinkedListBag()
	{
		clear();
	}
};

// ana wna b3ml linkedlist b5ls el functions bto3y w b3den bashof el special cases baa