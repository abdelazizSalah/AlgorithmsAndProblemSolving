#pragma once
template <class T>
class Node
{
private  :
	T item;
	Node <T>* next;
public :
	Node() {}
	T getitem() { return item };
	Node<T> * getnext() { return next; }
	void setitem(T IT) { item = IT; }
	void  setNext(Node<T>* n) { next = n; }
};