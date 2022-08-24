#pragma once
#include"stackinterface.h"
#define maxsize 100
template <class t > 
class arraystack : public stackinterface<t>
{
	t* arr;
	int top; 
public :

	arraystack()
	{
		arr = new int [maxsize]; 
		top = -1;
	}
	virtual bool IsEmpty() const
	{
		return (top == -1);
	}

	virtual bool push(const t& item)
	{
		if (top > maxsize)
			return false;
		arr[++top] = item; 
		return ture;
	}
	virtual bool pop(t& item) // ba2t el item by reference 34an ana abl ma ashel el item da 3uz a3rf howa shal eh bzbt bs mmkn m3mlsh kda 3ady
	{
		if (top == -1)
			return false;
		item = arr[top--];
		return true;
	}
	
	virtual t peek() const
	{
		return arr[top];
	}

	virtual ~arraystack()
	{
		delete[] arr;
	}
};
