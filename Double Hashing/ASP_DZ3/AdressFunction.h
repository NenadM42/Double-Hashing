#pragma once

#include <string>

using namespace::std;

class AdressFunction
{
public:
	AdressFunction();
	virtual ~AdressFunction();

	virtual int getAdress(long long k, long long a, long long i, long long size) const = 0;
};

