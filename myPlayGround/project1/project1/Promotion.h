#pragma once
#include "Events.h"
class Promotion :
    public Events
{
public :
    Promotion(int id, int ED);
    void Excute() const;
    ~Promotion() {/*??*/ };
};

