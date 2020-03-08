#include "DoubleHashing.h"



DoubleHashing::DoubleHashing()
{
}


DoubleHashing::~DoubleHashing()
{
}

int DoubleHashing::getAdress(long long k, long long a, long long i, long long size) const
{
	int q = 1;
	int p = size - 2;
	return (a + i*(q + (k % p)))%size;
}
