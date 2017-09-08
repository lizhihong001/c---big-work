#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<iterator>
#include"way.h"
#include<string>
using namespace std;
static char* wayfile = "d:\\way.txt";
static char* stationfile = "d:\\station.txt";
static int station_number_max;
static double infinite = 999;//表示无穷远

void eatline();//吃换行符

void read_way()
{
	fstream finout;
	way temway;
	finout.open(wayfile, ios_base::in | ios_base::binary);
	if (finout.is_open())
	{
		while (finout.read((char*)&temway, sizeof temway))
		{
			cout << left;
			cout << setw(35)<<temway.pre << " -> " << setw(35) <<temway.post << '\t' << setw(8)<<temway.distance << "km" << '\t' <<setw(3)<< temway.time << "min" << endl;
		}
		if (finout.eof())
		{
			finout.clear();
		}
		else
		{
			cerr << "Error in reading" << wayfile << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << wayfile << " could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	finout.close();
}
void add_way()
{
	fstream finout(wayfile, ios_base::out | ios_base::app | ios_base::binary);
	way temway;
	cout << "Now enter your station name:" << endl;
	cout << "One side is:" << endl;
	eatline();
	cin.get(temway.pre, 30);
	cout << "The other side is:" << endl;
	eatline();
	cin.get(temway.post, 30);
	cout << "Enter the distance:" << endl;
	cin >> temway.distance;
	cout << "Enter the time:" << endl;
	cin >> temway.time;
	finout.write((char*)&temway, sizeof temway) << flush;
	if (finout.fail())
	{
		cerr << "Erorr on attempted write" << endl;
		exit(EXIT_FAILURE);
	}
	finout.close();
}
void modify_way()
{
	string start, end;
	cout << "Please enter two station names at two sides of the way you want to modify:" << endl;
	cout << "One side:" << endl;
	cin >> start;
	cout << "The other side:" << endl;
	cin >> end;
	fstream finout;
	int i = 0;
	streampos place;
	finout.open(wayfile, ios_base::in | ios_base::out | ios_base::binary);
	way temway;
	while (finout.read((char*)&temway, sizeof temway))
	{
		if ((temway.pre == start&&temway.post == end) || (temway.pre == end&&temway.post == start))
		{
			break;
		}
		i++;
	}
	place = i * sizeof temway;
	cout << "Now enter your new way name:" << endl;
	cout << "One side is:" << endl;
	eatline();
	cin.get(temway.pre, 30);
	cout << "The other side is:" << endl;
	eatline();
	cin.get(temway.post, 30);
	cout << "Enter the distance:" << endl;
	cin >> temway.distance;
	cout << "Enter the time" << endl;
	cin >> temway.time;
	finout.seekp(place);
	finout.write((char*)&temway, sizeof temway) << flush;
	if (finout.fail())
	{
		cerr << "Erorr on attempted write" << endl;
		exit(EXIT_FAILURE);
	}
	finout.close();
}