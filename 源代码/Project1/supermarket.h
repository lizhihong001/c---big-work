#pragma once
#include<iostream>
#include<fstream>
#include<cstdlib>   //exit(1)用的头文件
#include<cstring>
#include<iomanip>
#include <string>
using namespace std;
//====管理员的账号和密码都为123=====//

class shangpin
{
protected:
	char name[20];                //商品名称
	double num;                   //商品编码
	char address[30];             //商品产地
	int price;                    //商品单价
	double count;                 //商品库存量
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
		cout << "编号:" << num << "  名称:" << name << "  产地:" << address << "  单价:" << price << "  存货量:" << count << endl;
	}
	friend class chaoshi;

};


class chaoshi
{
private:
	shangpin *goods;          //商品表
	void Clear();             //清除内存中数据

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

	void add();                //增加商品
	void shanchu();            //删除商品
	void xiugai();             //修改商品
	void chazhao();            //查询商品
	void paixu();			  //商品排序
	void tongji();             //统计商品
	void buy();                //商品购买
	void baocun();             //基础数据存盘
	void zhuangru();           //基础数据装入
	void zongti();             //超市所有商品的数量和总价格

};
void guanliyuan();