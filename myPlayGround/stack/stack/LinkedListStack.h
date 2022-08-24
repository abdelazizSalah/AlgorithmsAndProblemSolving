#pragma once
#include"arraystack.h"
template <class t>
struct Node
{
	Node* next;
	t item;
};
template <class t>
class LinkedListStack : public stackinterface<t>
{
	Node* top; // ma ana msh me7tag gher eny ashawr 3ala akher element ana d5lto w khlas
public:
	virtual bool IsEmpty() const
	{
		return (top == nullptr);
	}
	virtual bool push(const t& item)
	{
		if (top == nullptr)
		{
			top = new Node<t>;
			top->item = item;
			top->next = nullptr;
			return true;
		}
		Node<t>* dummy = new Node<t>;
		if (dummy) // lw 3rf ye3ml new allocation
		{
			dummy->item = item;
			dummy->next = top;
			top = dummy;
			return true;
		}
		return false;

	}
	virtual bool pop(t& item)  // ba2t el item by reference 34an ana abl ma ashel el item da 3uz a3rf howa shal eh bzbt bs mmkn m3mlsh kda 3ady
	{
		if (top) // check that the stack is not empty
		{
			Node <t>* dummy;
			dummy = top;
			item = top->item;
			top = top->next;
			delete dummy;
			return true;
		}
		return false;

	}
	virtual t peek() const
	{
		return t->item;
	}

	 
};