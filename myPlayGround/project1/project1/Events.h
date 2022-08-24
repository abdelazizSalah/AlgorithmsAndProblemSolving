#pragma once
class Events // base class 
{
	int ID; 
	int EventDay;
	//MarsStation* MSptr; el mfrod yt7t 
public :
	Events(int id, int Ed) : ID(id), EventDay(Ed) {};
	virtual void  Excute() const = 0 ;
	~Events() { /*???*/ };

};

