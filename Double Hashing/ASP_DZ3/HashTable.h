#pragma once

#include "Movie.h"
#include "DoubleHashing.h"

class HashTable
{
public:
	enum State{FULL,HALF_FREE,EMPTY};
private:

	int noSucces = 0;
	int noFailed = 0;
	
	int noSuccesAcces = 0;
	int noFailedAcces = 0;

	int getNumberLength(int n);
	int ConvertToDigits(const string &s);
	void hashFunctionBaseConversion(string key, int new_base, int table_size, int &key_ans);

	const int new_base = 13;
	const int table_size;
	Movie *table;
	int table_state[5005];

	int keyCount = 0;

	DoubleHashing address;

public:
	HashTable(const int &t_s) : table_size(t_s)
	{
		table = new Movie[table_size];
		for (int i = 0; i <= 5000; i++)
			table_state[i] = EMPTY;
	}

	~HashTable()
	{
		delete[] table;
	}

	string findKey(string key);

	bool insertKey(string key, string info);

	bool deleteKey(string key);

	int getKeyCount() const
	{
		return keyCount;
	}

	void clear();

	double fillRatio() const
	{
		return double(keyCount) / double(table_size);
	}

	friend ostream &operator<<(ostream &it, const HashTable &h);


	int avgAccesSucces()
	{
		if (noSucces == 0)
			return 0;
		return noSuccesAcces / noSucces;
	}

	void resetStatistics()
	{
		noFailed = 0;
		noSucces = 0;
		noFailedAcces = 0;
		noSuccesAcces = 0;
	}

	int avgAccesUnsucces()
	{
		if (noFailed == 0)
			return 0;
		return noFailedAcces / noFailed;
	}

	int avgAccessUnsuccessEst()
	{
		double alf = double(keyCount) / double(table_size);

		return (1 / (1 - alf));
	}

};