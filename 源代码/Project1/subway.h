#pragma once
#include<map>
#include<set>
#include<string>
#include"way.h"
#include<iostream>
using namespace std;
class subway
{
private:
	int i, j, k, x, y, size;
	double distance_sum; //临时变量
	way tem_map[100][100];  //最短路的图
	way ori_map[100][100];
	int path_time[100][100];
	multimap<string, int> codes; //关联站号和站名 （用来换乘判定）
	multimap<int,string> match; 
	set<string>order; //站名排序
	string name_order[100]; //站名排序
public:
	subway();
	int getorder(string); //输入站名返回序号
	double cost_count(double); //计算地铁票价格
	void floyd(); //最短路径
	void show_map(); //显示地图
	double show_fastest_way(string, string); //显示最短路的名字 票价 返回价钱！！！
	void fastest_way(int, int); //递归
	void initialization(); //文件处理完后读入矩阵中
};
