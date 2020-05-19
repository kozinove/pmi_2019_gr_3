#pragma once
#include "Monom.h"




class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual Monom Next() = 0;
};
