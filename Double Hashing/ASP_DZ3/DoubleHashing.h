#pragma once
#include "AdressFunction.h"
class DoubleHashing :
	public AdressFunction
{
public:
	DoubleHashing();
	~DoubleHashing();

	// Inherited via AdressFunction
	virtual int getAdress(long long k, long long a, long long i, long long size) const override;
};

