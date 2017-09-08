#pragma once
#include<iostream>
#include<fstream>
#include<cstdlib>   //exit(1)�õ�ͷ�ļ�
#include<cstring>
#include<iomanip>
#include <string>
using namespace std;
//====����Ա���˺ź����붼Ϊ123=====//

class shangpin
{
protected:
	char name[20];                //��Ʒ����
	double num;                   //��Ʒ����
	char address[30];             //��Ʒ����
	int price;                    //��Ʒ����
	double count;                 //��Ʒ�����
	shangpin *next;

public:
	shangpin(double num, char*name, char*address, int price, double count)
	{
		this->num = num;
		strcpy(this->name, name);
		strcpy(this->address, address);
		this->price = price;
		this->count = count;
	}

	void Output()
	{
		cout << "���:" << num << "  ����:" << name << "  ����:" << address << "  ����:" << price << "  �����:" << count << endl;
	}
	friend class chaoshi;

};


class chaoshi
{
private:
	shangpin *goods;          //��Ʒ��
	void Clear();             //����ڴ�������

public:
	chaoshi()
	{
		goods = NULL;
	}

	~chaoshi()
	{
		shangpin*p;
		p = goods;
		while (p)
		{
			p = p->next;
			delete goods;
			goods = p;
		}
		goods = NULL;
	}

	void add();                //������Ʒ
	void shanchu();            //ɾ����Ʒ
	void xiugai();             //�޸���Ʒ
	void chazhao();            //��ѯ��Ʒ
	void paixu();			  //��Ʒ����
	void tongji();             //ͳ����Ʒ
	void buy();                //��Ʒ����
	void baocun();             //�������ݴ���
	void zhuangru();           //��������װ��
	void zongti();             //����������Ʒ���������ܼ۸�

};
void guanliyuan();