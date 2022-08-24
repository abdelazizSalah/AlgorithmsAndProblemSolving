#pragma once 
template <class T>
class ListInterface
{
public:
	virtual	bool IsEmpty() const = 0;
	virtual	int getLen() const = 0;
	virtual	bool insert(const T& IT, int pos) = 0;
	virtual	bool remove(const int& pos) = 0; // de btms7 mkan mo3yn
	virtual	bool remove(const T& it) = 0; // de btms7 element mo3yn
	virtual	void clear() = 0;
	virtual	T getEntery(const int& pos) const = 0;
	virtual	T replace(const int& pos, const T& it) = 0;
	//mtnsash t5lehom virtual ybny
};
