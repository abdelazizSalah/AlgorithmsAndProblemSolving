#pragma once
template <class t>
class stackinterface
{
	virtual bool IsEmpty() const = 0;
	virtual bool push(const t &item) = 0;
	virtual bool pop(t& item) = 0; // ba2t el item by reference 34an ana abl ma ashel el item da 3uz a3rf howa shal eh bzbt bs mmkn m3mlsh kda 3ady
	virtual t peek() const = 0 // de ana bab2a 3auz a3rf menha el element el on top 
};
