#include "supermarket.h"
int n = 0; //清除内存中商品数据（内部使用）
void chaoshi::Clear()
{
	shangpin* p;
	p = goods;
	while (p)
	{
		goods = p->next;
		delete p;
		p = goods;
	}
}

void chaoshi::add()       //管理员添加商品信息
{
	shangpin *p;
	double num, count;
	char name[20], address[30];
	int price;
	cout << "\n请输入新增商品信息：\n";
	cout << "商品代码:"; cin >> num;
	cout << "商品名称:"; cin >> name;
	cout << "商品产地:"; cin >> address;
	cout << "商品单价:"; cin >> price;
	cout << "该商品库存量:"; cin >> count;


	p = new shangpin(num, name, address, price, count);//创建新商品类结点
	p->next = NULL;
	if (goods == NULL)
	{
		goods = p;
		n++;
	}
	else
	{
		shangpin *p2 = goods;
		while (p2->next)
			p2 = p2->next;
		p2->next = p;
		n++;
	}

}


void chaoshi::shanchu()     //管理员删除商品信息
{
	char name[20];
	cout << "\n请输入要删除的商品名称:\n";
	cin >> name;
	//查找要删除的结点
	shangpin *p1, *p2;  p1 = goods;
	while (p1)
	{
		if (strcmp(p1->name, name) == 0) break;
		else
		{
			p2 = p1;
			p1 = p1->next;
		}

	}

	//删除结点
	if (p1 != NULL)                   //若找到结点，则删除
	{
		if (p1 == goods)             //若要删除的结点是第一个结点
		{
			goods = p1->next;
			delete p1;
			n--;
		}
		else                      //若要删除的结点是后续结点
		{
			p2->next = p1->next;
			delete p1;
			n--;
		}
		cout << "找到并删除\n";

	}
	else                        //未找到结点
		cout << "Sorry,未找到!\n";

}

//管理员修该商品信息
void chaoshi::xiugai()     //修改商品信息
{
	double num, count;
	char name[20], address[30];
	int price;
	cout << "\n修改商品，请输入要查的商品名称:";
	cin >> name; //查找要修改的结点
	shangpin *p1, *p2;  p1 = goods;

	while (p1)
	{
		if (strcmp(p1->name, name) == 0) break;
		else
		{
			p2 = p1;
			p1 = p1->next;
		}

	}
	//修改结点
	if (p1 != NULL)   //若找到结点
	{
		cout << endl;
		p1->Output();
		cout << endl;
		cout << "(1—商品代码，2—商品名称，3—产地，4—单价，5—该商品库存量，6—修改全部信息)" << endl;
		cout << "\n请选择要修改的信息:";
		int a;
		cin >> a;
		switch (a)
		{
		case 1:cout << "请输入新编码："; cin >> num;
			strcpy(name, p1->name); strcpy(address, p1->address); price = p1->price; count = p1->count; break;

		case 2:cout << "请输入新名称："; cin >> name;
			num = p1->num; strcpy(address, p1->address); price = p1->price; count = p1->count; break;

		case 3:cout << "请输入新产地："; cin >> address;
			num = p1->num; strcpy(name, p1->name); price = p1->price; count = p1->count; break;

		case 4:cout << "请输入新单价："; cin >> price;
			num = p1->num; strcpy(name, p1->name); strcpy(address, p1->address); count = p1->count; break;

		case 5:cout << "请输入新库存数据："; cin >> count;
			num = p1->num; strcpy(name, p1->name); strcpy(address, p1->address); price = p1->price; break;
		case 6:cout << "请输入新信息：\n";
			cout << "商品代码:";     cin >> num;
			cout << "商品名称:";     cin >> name;
			cout << "商品产地:";     cin >> address;
			cout << "商品单价:";     cin >> price;
			cout << "该商品库存量:"; cin >> count; break;

		}
		//创建新商品结点
		shangpin *p3;
		p3 = new shangpin(num, name, address, price, count);

		//员工结点替换到链表
		p3->next = p1->next;
		if (p1 == goods)  //若要替换的结点是第一个结点
			goods = p3;

		else          //若要替换的结点是后续结点
			p2->next = p3;
		delete p1;   //删除原来的商品结点
		cout << "修改成功!\n";

	}
	else  //未找到结点
		cout << "Sorry,未找到!\n";
}

//管理员查找商品信息
void chaoshi::chazhao()               //查询商品信息
{
	cout << "\n****查询商品****\n";
	char name[20];
	cout << "\n请输入要查询的商品名称:";
	cin >> name;
	cout << endl;
	ifstream infile("C:\\Users\\gxy1997nh\\Desktop\\supermarket.txt", ios::in);
	if (!infile)
	{
		cerr << "failed\n";
		abort();
	}
	shangpin *p1 = goods;
	while (p1)
	{
		if (strcmp(p1->name, name) == 0) break;
		else p1 = p1->next;
	}

	if (p1 != NULL)          //若找到结点
	{
		cout << "要查询的信息如下：\n";
		cout << "该类商品代码:\t" << p1->num << "\t" << "该类商品名称:\t" << p1->name << "\t\n";
		cout << "该类商品产地:\t" << p1->address << "\t" << "该类商品单价:\t" << p1->price << "\t\n";
		cout << "该类商品库存量:\t" << p1->count << "\t";
		cout << endl;
	}
	else //未找到结点
		cout << "\nSorry,未找到该类商品!\n";
	infile.close();

}

//按编码大小排序
void chaoshi::paixu()
{
	cout << "请输入你要排序的数据类型： ";
	char leixin;
	cin >> leixin;
	shangpin *L; L = goods;
	shangpin *p, *q;
	int jiage;
	double temp, cangku;
	char names[30], dizhi[40];
	if (leixin == 'n')
	{
		for (p = L->next; p != NULL; p = p->next)
		{
			for (q = p->next; q != NULL; q = q->next)
			{
				if (p->num >= q->num)
				{
					strcpy(names, p->name);
					strcpy(p->name, q->name);
					strcpy(q->name, names);

					temp = p->num;
					p->num = q->num;
					q->num = temp;

					strcpy(dizhi, p->address);
					strcpy(p->address, q->address);
					strcpy(q->address, dizhi);

					jiage = p->price;
					p->price = q->price;
					q->price = jiage;

					cangku = p->count;
					p->count = q->count;
					q->count = cangku;
				}
			}

		}
		baocun();
	}
	if (leixin == 'j')
	{
		for (p = L->next; p != NULL; p = p->next)
		{
			for (q = p->next; q != NULL; q = q->next)
			{
				if (p->price >= q->price)
				{
					strcpy(names, p->name);
					strcpy(p->name, q->name);
					strcpy(q->name, names);

					temp = p->price;
					p->price = q->price;
					q->price = temp;

					strcpy(dizhi, p->address);
					strcpy(p->address, q->address);
					strcpy(q->address, dizhi);

					jiage = p->num;
					p->num = q->num;
					q->num = jiage;

					cangku = p->count;
					p->count = q->count;
					q->count = cangku;
				}
			}

		}
		baocun();

	}
}

//购买商品操作
void chaoshi::buy()
{
	int i, sum, factly;
	cout << "\n****商品的购买****\n";
	char name[20];
	cout << "\n请输入要购买的商品名称:\n";
	cin >> name;
	shangpin *p1 = goods;
	while (p1)
	{
		if (strcmp(p1->name, name) == 0) break;
		else p1 = p1->next;
	}

	if (p1 != NULL)          //若找到结点
	{
		cout << "\n你购买的商品名称为:" << p1->name << "\t\n";
		cout << "该类商品的单价为:" << p1->price << "\t\n";
	label:
		cout << "输入要购买的数量:";
		cin >> i; sum = p1->price*i;
		cout << "----------------------------------------------------" << endl;
		double h; h = (p1->count) - i;
		if (h<0) { cout << "该类商品不足,库存量只有（件）:" << p1->count << endl; goto label; }
		cout << "你应该付 " << sum << "元!" << endl;
		cout << "你实际付(元): ";
		cin >> factly;
		cout << "应该找回你:" << factly - sum << "元!" << endl;//找零。
		cout << "库存量为" << h;  cout << endl;
		(p1->count) -= i;//库存量
	}
	if (p1 == NULL) { cout << "没有该类商品" << endl; }
}

//统计超市某商品总数量和总价钱
void chaoshi::tongji()
{
	cout << "\n****商品统计****\n";
	double Value = 0;
	char name[20];
	cout << "\n请输入要统计的商品名称:";
	cin >> name;
	shangpin *p1;
	p1 = goods;
	while (p1)
	{
		if (strcmp(p1->name, name) == 0) break;
		else p1 = p1->next;
	}

	if (p1)
	{
		Value += p1->count*p1->price;
		cout << "该类商品库存量:" << p1->count << endl;
		cout << "该商品的单价是:" << p1->price << endl;
		cout << "该商品总价值是:" << Value << endl;
	}

	else
		cout << "\nSorry,未找到该类商品!\n";

}

//统计超市所有商品总数量和总价钱
void chaoshi::zongti()
{
	cout << "\n****超市所有商品统计****\n";
	double Amount = 0, Value = 0;
	shangpin *p1;
	p1 = goods;
	if (p1)
	{
		while (p1)
		{
			Amount += p1->count;
			Value += p1->count*p1->price;
			p1 = p1->next;
		}
		cout << endl;
		cout << "超市所有商品总数量是:";
		cout << Amount;
		cout << "\n超市所有商品总价值是:";
		cout << Value;
		cout << endl;
	}
	else
		cout << "\nSorry,未找到该类商品!\n";
}

//数据存盘
void chaoshi::baocun()
{
	cout << "是否保存？[Y/N]";
	char a;
	cin >> a;
	if (a == 'n')return;
	if (a == 'y' || a == 'Y')
	{
		ofstream outfile("C:\\Users\\gxy1997nh\\Desktop\\supermarket.txt", ios::out);
		if (!outfile) { cerr << "没有该文件!"; exit(1); }
		shangpin* p; p = goods;
		while (p)
		{
			outfile << "商品代码\t\t" << p->num << endl;
			outfile << "商品名称\t\t" << p->name << endl;
			outfile << "商品产地\t\t" << p->address << endl;
			outfile << "商品单价\t\t" << p->price << endl;
			outfile << "该商品库存量\t" << p->count << endl;
			cout << endl;
			p = p->next;
		}
		outfile.close();
		cout << "已完成数据的保存\n";
	}

}


//数据装入
void chaoshi::zhuangru()
{
	shangpin *p = goods;
	ifstream infile("C:\\Users\\gxy1997nh\\Desktop\\supermarket.txt");  //读一条信息
	infile >> p->num >> p->name >> p->address >> p->price >> p->count;
	while (infile.good())
	{
		//创建商品结点
		p = new shangpin(p->num, p->name, p->address, p->price, p->count);
		p->next = NULL;    //商品结点加入

		if (goods)       //若已存在结点
		{
			shangpin*p2; p2 = goods;
			while (p2->next)  //查找尾结点
				p2 = p2->next;
			p2->next = p;     //连接
		}
		else             //表空
			goods = p;     //连接
						   //读下一条信息
		infile >> p->num >> p->name >> p->address >> p->price >> p->count;
	}
	cout << "\n商品数据已经装入\n";
}

//管理员登陆函数
void guanliyuan()
{
	int c, d;
	int a = 123;
	int b = 123;
label:
	cout << "\n请输入管理员的账号:";
	cin >> c; cout << endl;
	cout << "请输入管理员的密码:";
	cin >> d; cout << endl;
	if (a == c&&b == d) { system("cls"); cout << "======成功登陆,欢迎:" << a << "管理员=====" << endl; }
	else { cout << "密码错误,请重新输入" << endl; goto label; }
}