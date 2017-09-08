#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<iterator>
#include"subway.h"
#include"station.h"
#include<string>
#include<cstring>
using namespace std;
static char* wayfile = "d:\\way.txt";
static char* stationfile = "d:\\station.txt";
static int station_number_max;
static double infinite = 999;//表示无穷远
subway::subway()
{

	i = j = k = x = y = size = 0;
	distance_sum = 0;
	
	for (i = 0; i < 100; i++)
		name_order[i] = '\0';
	
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
		{
			path_time[i][j] = j;
			
			tem_map[i][j].time = tem_map[i][j].time = infinite;
			if (i == j)
				tem_map[i][j].distance = tem_map[i][j].distance = 0;
			else
				tem_map[i][j].distance = tem_map[i][j].distance = infinite;
			ori_map[i][j].pre[0] = ori_map[i][j].pre[0] = ori_map[i][j].post[0] = ori_map[i][j].post[0] = '\0';
		}
}
void subway::show_map()
{
	int tem;
	map<int, string>::iterator it;
	cout << right;
	for (tem=1,it = match.begin(); it != match.end(); it++)
	{
		if ((*it).first > (tem)*100)
		{
			cout << endl << endl;
			cout << tem << " 号线： ";
			tem++;
		}
		cout << (*it).second << "   ";
	}
	cout << endl;
}
void subway::initialization()
 {
	way temway;
	station temstation;
	//map codes, map match和 set order的初始化
	fstream finout;
	finout.open(stationfile, ios_base::in | ios_base::binary);
	set<string>::iterator it;
	if (finout.is_open())
	{
		while (finout.read((char*)&temstation, sizeof temstation))
		{
			codes.emplace(temstation.name, temstation.number);
			order.emplace(temstation.name);
			match.emplace(temstation.number, temstation.name);
		}
	}
	else
	{
		cerr << wayfile << " could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	finout.close();
	//size初始化
	size = order.size();
	//排序数组初始化
	for (it = order.begin(), i = 0; it != order.end(); ++it, i++)
	{
		
		name_order[i]=*it;
	}
	
	//矩阵读取文件
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			strcpy_s(ori_map[i][j].pre, name_order[i].c_str());
			strcpy_s(ori_map[i][j].pre, name_order[i].c_str());
			strcpy_s(ori_map[i][j].post, name_order[j].c_str());
			strcpy_s(ori_map[i][j].post, name_order[j].c_str());
		}
	}

	finout.open(wayfile, ios_base::in | ios_base::out | ios_base::binary);
	if (finout.is_open())
	{
		while (finout.read((char*)&temway, sizeof temway))
		{
			x = getorder(temway.pre);
			y = getorder(temway.post);
			ori_map[x][y].distance = tem_map[x][y].distance = ori_map[y][x].distance = tem_map[y][x].distance = temway.distance;
			ori_map[x][y].time = tem_map[x][y].time = ori_map[y][x].time = tem_map[y][x].time = temway.time;
		}
	}
	else
	{
		cerr << wayfile << " could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	finout.close();
}
int subway::getorder(string name)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (name == name_order[i]) break;
	}
	return i;
}
double subway::cost_count(double distance)
{
	double tem_sum = 4;
	if (distance > 4)
		if (distance <= 12) tem_sum += (distance - 4) / 4;
		else if (distance <= 24) tem_sum += (distance - 12) / 6;
		else tem_sum += (distance - 24) / 8;
		return tem_sum;
}
void subway::floyd()
{
	double tem_dis = 0, tem_time = 0;
	for (k = 0; k < size; k++)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				tem_time = tem_map[i][k].time + tem_map[k][j].time;
				if (tem_time < tem_map[i][j].time)
				{
					tem_map[i][j].time = tem_time;
					path_time[i][j] = path_time[i][k];
				}
			}
		}
	}
}
double subway::show_fastest_way(string start, string end)
{
	distance_sum = 0;
	double cost_tem = 0;
	int start_ = getorder(start);
	int end_ = getorder(end);
	cout << name_order[start_];
	fastest_way(start_, end_);
	cost_tem = cost_count(distance_sum);
	cout << '\t' << cost_tem << "yuan" << endl;
	return cost_tem;
}
void subway::fastest_way(int start, int end)
{
	if (path_time[start][end] == end)
	{
		cout << "->" << name_order[end];
		distance_sum += ori_map[start][end].distance;
		return;
	}
	fastest_way(start, path_time[start][end]);
	fastest_way(path_time[start][end], end);
	return;
}