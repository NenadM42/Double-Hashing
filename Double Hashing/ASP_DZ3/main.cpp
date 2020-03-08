#include "HashTable.h"

#include <iostream>
#include<fstream>


void print()
{
	string s = "------------";
	cout << s << endl;
	cout << "1 - Find Key" << endl;
	cout << "2 - Insert Key" << endl;
	cout << "3 - Delete Key" << endl;
	cout << "4 - Clear" << endl;
	cout << "5 - Reset Statistics" << endl;
	cout << "6 - Average Success Acces" << endl;
	cout << "7 - Average Unsuccess Access" << endl;
	cout << "8 - Fill Ratio" << endl;
	cout << "9 - Get Key Count" << endl;
	cout << "10 - Print Table" << endl;
	cout << "11 - Get Table Size" << endl;
	cout << "12 - Average EST unsuccesfull" << endl;
	cout << s << endl;
}

int main()
{
	const int N = 5011;
	HashTable H(N);

	ifstream file;
	file.open("tmdb_movies.csv");
	string key, info, lan;
	getline(file, info);

	while (!file.eof())
	{
		getline(file, lan, ',');
		getline(file, key, ',');
		//cout << line << " ";

		getline(file, info);


		info = lan + "," + key + "," + info;

		H.insertKey(key, info);
		//cout << info << endl;
	}

	ifstream file2;
	file2.open("movies_search_1.txt");
	int cnt = 0;

	while (true)
	{
		cout << endl;
		print();
		cout << endl;
		string s, i, o;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Ime filma:\n"; 
			cin >> s;
			cout << H.findKey(s);
			break;
		case 2:
			cout << "Ime filma i opis:\n";
			cin >> i;
			getchar();
			getline(cin,o);
			H.insertKey(i, o);
			break;
		case 3:
			cout << "Ime filma:\n";
			cin >> s;
			H.deleteKey(s);
			break;
		case 4:
			H.clear();
			break;
		case 5:
			H.resetStatistics();
			break;
		case 6:
			cout << H.avgAccesSucces();
			break;
		case 7:
			cout << H.avgAccesUnsucces();
			break;
		case 8:
			cout << H.fillRatio();
			break;
		case 9:
			cout << H.getKeyCount();
			break;
		case 10:
			cout << H;
			break;
		case 11:
			cout << H.getKeyCount();
			break;
		case 12:
			cout << H.avgAccessUnsuccessEst() << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}