#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<iterator>
#include"station.h"
#include<cstring>
#include<string>
using namespace std;
static char* wayfile = "d:\\way.txt";
static char* stationfile = "d:\\station.txt";
static int station_number_max;
static double infinite = 999;//表示无穷远

void eatline() //吃换行符
{
	while (cin.get() != '\n') continue;
}

void read_station()
{
	fstream finout;
	station temstation;
	finout.open(stationfile, ios_base::in | ios_base::binary);
	if (finout.is_open())
	{
		while (finout.read((char*)&temstation, sizeof temstation))
		{
			cout << left;
			cout << setw(3) << temstation.number << " : " << setw(35) << temstation.name << endl;
		}
		if (finout.eof())
		{
			finout.clear();
		}
		else
		{
			cerr << "Error in reading" << stationfile << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << stationfile << " could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	finout.close();
}

void add_station() 
{
	fstream finout(stationfile, ios_base::out | ios_base::app | ios_base::binary);
	station temstation;	
	cout << "Enter station name:" << endl;
	eatline();
	cin.get(temstation.name, 30);
	cout << "Now enter your station number:" << endl;
	cin >> temstation.number;
	finout.write((char*)&temstation, sizeof temstation) << flush;
	if (finout.fail())
	{
		cerr << "Erorr on attempted write" << endl;
		exit(EXIT_FAILURE);
	}
	finout.close();
}

void modify_station()
{
	cout << "Please enter the station name you want to modify:" << endl;
	string name;
	cin >> name;
	fstream finout;
	int i = 0;
	streampos place;
	finout.open(stationfile, ios_base::in | ios_base::out | ios_base::binary);
	station temstation;
	while (finout.read((char*)&temstation, sizeof temstation))
	{

		if (!strcmp(temstation.name,name.c_str()))
		{
			break;
		}
		i++;
	}
	place = i * sizeof temstation;
	cout << "Now enter your new station number:" << endl;
	cin >> temstation.number;
	cout << "Enter station name:" << endl;
	eatline();
	cin.get(temstation.name, 30);
	finout.seekp(place);
	finout.write((char*)&temstation, sizeof temstation) << flush;
	if (finout.fail())
	{
		cerr << "Erorr on attempted write" << endl;
		exit(EXIT_FAILURE);
	}
	finout.close();
}