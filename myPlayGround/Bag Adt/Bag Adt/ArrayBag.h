#pragma once
#include "Bag.h"
#define Default_Capacity 50 
//da 3bara 3n template class by3ml inheritance mn template class tany
template <typename T>
class ArrayBag :
    public BagInterface <T>
{
private :
    T items[Default_Capacity]; 
    int itemCount;
    int getIndexOf(const T& target); // de 3bara 3n utility function bst5dmha ana 34an adwr 3la 7aga msln lakn el user 3omro ma hyst5dmha
public :
    ArrBag() {};

    getIndexOf(const T& target)
    {
            for (size_t i = 0; i < count; i++)
            {
                if (item[i] == it) // lazm == tb2a overloaded 
                {
                    return i;
                }
            }
            return -1;
    }

    int getCurrSize() const { return count; };

    bool isEmpty() const  { return(count == 0); }

    bool add(const T &it) 
    {
        if (count < Default_Capacity)
        {
            item[count++] = it;
            return true;
        }
        return false;
    }

    bool remove(const T& it) const 
    {
        int id = getIndexOf(it);
        if (id != -1)
        {
            //34an ana msh mohtm bl trteb fa msh h3ml shift ana 34an ashel l element hktb 3leh 34an da bag
            item[id] = item[count - 1];
            count--; // ana keda lw get a3ml add tany hy7sl overwrite 3la a5er element fa keda akny ms7to
        }
    }
    void clear()
    {
        count = 0; // 34an ana keda awl ma agy a3ml add tany hy7ot 3la awl element 5ales fa keda hy3ml overwrite 3la kol l elements , w da brdo 34an ana msh mohtm bl trteb w 34an 3mlto bl static
    }

    bool Contains(const T& it) const 
    {
        return (getIndexOf(it) != -1); // de tre2a ashal
    }

    int getFrequancyof(const T& it)
    {
        int c = 0;
        for (size_t i = 0; i < count; i++)
        {
            if (items[i] == it)
                c++;
        }
        return c;
    }
};

