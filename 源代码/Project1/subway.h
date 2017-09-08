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
	double distance_sum; //��ʱ����
	way tem_map[100][100];  //���·��ͼ
	way ori_map[100][100];
	int path_time[100][100];
	multimap<string, int> codes; //����վ�ź�վ�� �����������ж���
	multimap<int,string> match; 
	set<string>order; //վ������
	string name_order[100]; //վ������
public:
	subway();
	int getorder(string); //����վ���������
	double cost_count(double); //�������Ʊ�۸�
	void floyd(); //���·��
	void show_map(); //��ʾ��ͼ
	double show_fastest_way(string, string); //��ʾ���·������ Ʊ�� ���ؼ�Ǯ������
	void fastest_way(int, int); //�ݹ�
	void initialization(); //�ļ����������������
};
