#pragma once
#include "Events.h"
class Cancelation :
    public Events
{
public : 
    Cancelation(int id, int ED);
    void Excute() const;
    ~Cancelation();
    //bs keda a3tkd ?
};

