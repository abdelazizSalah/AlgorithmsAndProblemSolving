#include <iostream>
using namespace std;

template <class t>
class Node
{
	t item;
	Node<t>* left;
	Node<t>* right;
public:
	Node(t item, Node<t>* l = nullptr, Node<t>* r = nullptr) :left(l), right(r)
	{
		this->item = item;
	}
	void setitem(t item)
	{
		this->item = item;
	}
	t getitem() const
	{
		return this->item;
	}
	void setLeft(Node<t>* l)
	{
		left = l;
	}
	Node<t>* getleft() const
	{
		return left;
	}
	void setRight(Node<t>* r)
	{
		right = r;
	}
	Node <t>* getRight() const
	{
		return right;
	}
};

template <typename t >
class BinTree
{
	Node<t> * root;
	//utility functions are always private functions 
	int RecCount(Node <t>* subTreePtr)
	{
		if (!subTreePtr) return 0;

		return 1 + RecCount(subTreePtr->getleft()) + RecCount(subTreePtr->getRight());
	}

	int RecSum(Node <t>* subtreeptr )
	{
		if (subtreeptr == nullptr) return 0;

		return subtreeptr->getitem() + RecSum(subtreeptr->getleft()) + RecSum(subtreeptr->getRight());
	}

public :
	BinTree(Node<t>* r = nullptr) : root(r)
	{
	}

	int CountNodes()
	{
		return  RecCount(root);
	}

	int CountSum(Node <t>* subtreeptr)
	{
		return RecSum(subtreeptr);
	}



};

int main()
{
	

	return 0;
}