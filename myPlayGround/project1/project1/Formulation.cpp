#include "Formulation.h"

Formulation::Formulation(char t, int TL, int Sgnfcns, int T , int id , int ED):Events(id , ED) ,type(t) , TrgtLoc(TL), Significance(Sgnfcns),Time(T)
{ 

}

void Formulation::Excute() const
{
	//TODO
}

int Formulation::getTargetLoc()const
{
	return TrgtLoc;
}

void Formulation::SetTargetLoc(int& TL)
{
	TL >= 0 ? TrgtLoc = TL : TrgtLoc = 0; 
}

int Formulation::getSignificance()const
{
	return Significance;
}

void Formulation::SetSignificance(int& S)
{
	S >= 0 ? Significance = S : S = 0;
}

int Formulation::getTime()const
{
	return Time;
}

void Formulation::setTime(int &T)
{
	T >= 0 ? Time - T : Time = 0;
}

char Formulation::getType()const
{
	return type;
}

void Formulation::setType(char& T)
{
	type = T;
}

Formulation::~Formulation()
{
	//?
}

