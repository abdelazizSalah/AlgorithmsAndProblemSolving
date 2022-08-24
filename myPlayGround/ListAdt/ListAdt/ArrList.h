#pragma once
#include "ListAdtInterface.h"
#include <iostream>
using namespace std;
#define Default_Size 100


template < class T >
class ArrList : public ListInterface<T>
{
private:
	// talama ana f list yeb2a m3ndesh pos 0 34an bdl ma kol ma a2ol ana h7ot fe pos - 1 laa ana h7ot fl pos3a toul 
	T items[Default_Size + 1];
	int count;
public:
	ArrList()
	{
		count = 0;
	}

	ArrList(const ArrList<T>& A)
	{
		// copy constructor 
		for (size_t i = 1; i < A.getLen(); i++)
		{
			insert(A.getEntery(i));
		}
	}
	virtual	bool IsEmpty()
	{
		return (count == 0);
	}

	virtual	int getLen() const
	{
		return count;
	}

	virtual	bool insert(const T& IT, int pos)
	{
		if (count > Default_Size || IsEmpty())
			return false;

		//ana 3auz a3ml insert fe mkan mo3yn fl array fa da m7tag eny a3ml loops 34an b3d ma a7ot el element a shift 
		if (pos <= count)
		{
			for (size_t i = count; i >= pos; i--)
				items[i + 1] = items[i];

			items[pos] = IT;
			count++;
			return true;
		}
		else
		{
			//fl lec el case de el mfrod ytl3 feha flase  , bs ana 7abeb a3mlha keda aktur 
			// lw el pos akbr mn el count fa ana h2ol lel bny adam da eny 34an akhly el list sorted fana msh h7oto fl pos da w h7oto 3nd akher element
			cout << "\n to keep the list sorted i will put the item at the end of the list";
			items[count + 1] = IT;
			count++;
			return true;
		}
	}

	//
	// lw 3mlt double slash w t7thom double slash w b3d keda dost enter htla2eh by3ml comments lw7do
	//

	virtual	bool remove(const int& pos)  // de btms7 mkan mo3yn
	{
		if (IsEmpty() || pos > Default_Size)
			return false;

		//34an te3ml remove w t shift fanta hatms7 el element el awl w b3den t shift , aw msh lazm tms7o enta mmkn t overwrite 3leh
		for (size_t i = pos; i < count; i++)
			items[i] = items[i + 1];

		count--;
		return true;
	}

	virtual	bool remove(const T& it)  // de btms7 element mo3yn
	{
		bool found = false;
		//lazm adwr 3la el element el awl w ageb el index bta3o b3den a3ml el remove
		for (size_t i = 0; i < count; i++)
		{
			if (items[i] == it)
			{
				remove(i); // keda ana hams7 kol l items el lehom nfs el value 3ady
				found = true;
			}
		}
		return found;
	}

	virtual	void clear()
	{
		count = 0;
	}

	virtual	T getEntery(const int& pos) const
	{
		if (pos < count)
			return items[pos];
	}

	virtual	T replace(const int& pos, const T& it) // 3auz arg3 el old item
	{
		if (pos < count || !IsEmpty())
		{
			T oldItem = item[pos] 
			items[pos] = it;
			return oldItem;
		}
	}

	//keda el arrlist khelst.
};
