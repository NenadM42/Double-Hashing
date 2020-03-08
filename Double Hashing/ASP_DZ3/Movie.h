#pragma once

#include <string>
#include <iostream>

using namespace std;

class Movie
{
private:

	string original_language;
	string original_title;
	string realease_date;
	long long revenue;
	int runtime;
	string info;
	string key;


public:

	Movie() = default;
	
	Movie(const string &i) : info(i)
	{

	}
	
	Movie(const string &o_l, const string &o_t, const string &r_d,
		const long long &rev, const int runt) : original_language(o_l), original_title(o_t),
		realease_date(r_d), revenue(rev), runtime(runt)
	{}
	

	~Movie()
	{

	}

	void setKey(const string &s)
	{
		key = s;
	}

	void setInfo(const string &s)
	{
		info = s;
	}

	string getKey() const
	{
		return key;
	}

	string getInfo() const
	{
		return info;
	}

};

