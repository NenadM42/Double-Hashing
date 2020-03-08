#include "HashTable.h"


ostream & operator<<(ostream & it, const HashTable & h)
{
	for (int i = 0; i < h.table_size; i++)
	{
		if (h.table_state[i] == h.FULL)
		{
			it << h.table[i].getInfo() << "\n";
		}
		else if (h.table_state[i] == h.HALF_FREE)
		{
			it << "DELETED\n";
		}
		else
		{
			it << "EMPTY\n";
		}
	}
	return it;
}

int HashTable::getNumberLength(int n)
{
	int cnt = 0;
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return cnt;
}

int HashTable::ConvertToDigits(const string & s)
{
	int res = 0;
	for (int i = 0; i < s.length(); i++)
	{
		res += s[i] * (i + 1);
	}
	return res;
}

void HashTable::hashFunctionBaseConversion(string key_str, int new_base, int table_size,int &key_ans)
{
	int key = ConvertToDigits(key_str);

	int number = 0;
	int cnt = 0;
	while (key > 0)
	{
		number += (key % 10) * pow(new_base, cnt++);
		key /= 10;
	}

	int res = 0;
	cnt = 0;
	int pom = table_size;
	while (pom > 0)
	{
		res += (number % 10) * pow(10, cnt++);
		pom /= 10;
	}
	key_ans = res % table_size;
}

string HashTable::findKey(string key)
{
	int key_num;
	hashFunctionBaseConversion(key, 13, table_size,key_num);
	int beg = key_num;
	int i = 0;
	bool visited[5050];
	memset(visited, 0, sizeof(visited));
	int cnt_vis = 0;
	while (true)
	{
		int next = address.getAdress(key_num, beg, ++i, table_size);
		if (table_state[key_num] == FULL and table[key_num].getKey() == key)
		{
				noSucces++;
				noSuccesAcces += i;
				return table[key_num].getInfo();
		}
		else if (table_state[key_num] == EMPTY)
		{
			noFailed++;noFailedAcces += i;
			return "0";
		}
		if (cnt_vis == table_size)
		{
			noFailed++;noFailedAcces += i;
			return "0";
		}

		if (visited[key_num] == 0)
		{
			visited[key_num] = 1;
			cnt_vis++;
		}
		key_num = next;
	}
}

bool HashTable::insertKey(string key, string info)
{//dk

	if (table_size == keyCount)
		return false;
	//if (findKey(key) != "0")
	//	return false;

	int key_num;
	hashFunctionBaseConversion(key, new_base, table_size,key_num);
	int beg = key_num;
	int i = 0;
	while (true)
	{
		int next = address.getAdress(key_num, beg, ++i, table_size);
		if (table_state[key_num] == EMPTY or table_state[key_num] == HALF_FREE)
		{
			keyCount++;
			table_state[key_num] = FULL;
			table[key_num].setInfo(info);
			table[key_num].setKey(key);
			return true;
		}
		key_num = next;
	}
}

bool HashTable::deleteKey(string key)
{
	if (findKey(key) == "0")
		return false;

	int key_num;
	hashFunctionBaseConversion(key, new_base, table_size,key_num);
	int beg = key_num;
	int s = 0;
	while (true)
	{
		int next = address.getAdress(key_num, beg, ++s, table_size);
		if (table_state[key_num] == FULL)
		{
			if (table[key_num].getKey() == key)
			{
				table_state[key_num] = HALF_FREE;
				keyCount--;
				return true;
			}
		}
		key_num = next;
	}
}

void HashTable::clear()
{
	for (int i = 0; i < table_size; i++)
	{
		table_state[i] = 2;
	}
}
