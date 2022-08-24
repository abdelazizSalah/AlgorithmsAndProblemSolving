#pragma once
#include "Events.h"
class Formulation :
    public Events
{
    char type; 
    int TrgtLoc;
    int Significance;
    int Time; 
public :
    Formulation(char t, int TL, int Sgnfcns, int T , int id, int ED);
    void Excute() const;
    int getTargetLoc() const;
    void SetTargetLoc(int &TL);
    int getSignificance() const;
    void SetSignificance(int &S);
    int getTime() const;
    void setTime(int& T);
    char getType()const;
    void setType(char &T);
    ~Formulation();
    //copyConstructor and Assignment operator must be made
};

