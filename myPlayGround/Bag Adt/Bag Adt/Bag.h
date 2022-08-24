#pragma once
#include <vector>
template <typename T>
class BagInterface 
{
public : 
	//3auz a7ot hena shwyt pure virtual functions 
	virtual int getCurrSize()  const = 0; 
	virtual bool isEmpty() const = 0;
	virtual bool add(const T  &item)  = 0;
	virtual	bool remove(const T &it)  = 0;
	virtual	void clear() = 0;
	virtual	int getFrequancyof( const T &it) const = 0; // btrg3 3dd tekrar 7aga mo3yna
	virtual bool Contains(const T &it) const = 0; // btshof el 7aga de mwgoda wla laa

};

