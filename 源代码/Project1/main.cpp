#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "card.h"
#include "Manager.h"
#include "RAS.h"
#include "supermarket.h"
#include <iterator>
#include "station.h"
#include "subway.h"
#include <map>
#include <set>
#include <cstring>
const char* wayfile = "d:\\way.txt";
const char* stationfile = "d:\\station.txt";
const int station_number_max = 100;//总车站数
const double infinite = 999;//表示无穷远
using namespace std;
fstream file;			//绑定文件
void AddFront(card * &h, card * &t)   //插入链表
{
	t->next = h;
	h = t;
}
int main()
{
	subway GuangZhou;
	string start, end;
	GuangZhou.initialization();
	GuangZhou.floyd();
	RAS ras;
	int total = 0; 
	card * head = NULL;
	card * thismember = NULL;
	card * FileIn = NULL;
	string a, b, c;
	double m, d, ticketincome;
	bool f;
	int t;
	char begin[100];
	file.open("C:\\Users\\gxy1997nh\\Desktop\\info.txt", ios::in | ios::binary);
	if (!file)
	{
		cerr << "failed\n";
		system("pause");
		abort();
	}
	file >> begin;              
	if (begin == "\0")
	{
		FileIn->SetTicketMoney(0);
	}
	else
	{
		ticketincome = atoi(begin);
		FileIn->SetTicketMoney(ticketincome);
	}
	while (file >> a >> b >> c >> m >> f >> d >> t)
	{
		b = ras.DecryptStr(b);
		if (c == "NormalCard")
		{
			FileIn = new card(a, b, c, m, f, d, t);
			AddFront(head, FileIn);
			total++;
		}
		if (c == "StudentCard")
		{
			FileIn = new StudentCard(a, b, c, m, f, d, t);
			AddFront(head, FileIn);
			total++;
		}
		if (c == "ElderCard")
		{
			FileIn = new ElderCard(a, b, c, m, f, d, t);
			AddFront(head, FileIn);
			total++;
		}
	}
	file.close();
Main:	char choice;
	cout << "*****************************************\n";
	cout << "*" << "\tlog in please tap              *\n";              
	cout << "*" << "\tregister please tap 2          *\n";
	cout << "*" << "\tlog in manager please tap 3    *\n";
	cout << "*" << "\tsupermarket service tap 4      *\n";
	cout << "*" << "\texit please tap 0              *\n";
	cout << "*****************************************\n";
	cin >> choice;
	if (choice == '1')          
	{
		string id, password;
		bool checkid = 0, checkpassword = 0;
LogInMode	:	cout << "please input your id and password\n";     //登录模块
		cin >> id;
		cin >> password;
		card * find = head;
		while (find)
		{
			if (find->CheckID(id))
			{
				checkid = 1;
				if (find->CheckPassword(password))
				{
					checkpassword = 1;
					cout << "log in successfully\n";
					thismember = find;
					break;
				}
				else
				{
					cout << "wrong password please input again\n";
					goto LogInMode;
				}
			}
			else
				find = find->next;
		}
		if (checkid == 0)
		{
			cout << "not such a member please input again\n";
			goto LogInMode;
		}
		if (checkid && checkpassword)
		{
		B:	cout << "*******************************************\n";
			cout << "*" << "\trechargr please tap 1            *\n";
			cout << "*" << "\tbuy ticket please tap2           *\n";
			cout << "*" << "\tinquire map please tap 3         *\n";
			cout << "*" << "\tinquire money please tap 4       *\n";
			cout << "*" << "\tcall for lost please tap 5       *\n";
			cout << "*" << "\trevise password please tap 6     *\n";
			cout << "*" << "\tfinish operate please tap 0      *\n";
			cout << "*******************************************\n";

		//    用户操作部分
			char op;
			cin >> op;
			if (op == '1')      //充值
			{
				int x;
				cout << "please input the money you will rechargr\n";
				cin >> x;
				thismember->rechargr(x);
				goto B;
			}
			else if (op == '2')    //买票
			{
				int amount;
				double cost;
				cout << "Please input your start and end\n";
				cin >> start >> end;
				cout << "How many tickets do you want to buy\n";
				cin >> amount;
				cost = GuangZhou.show_fastest_way(start, end);
				thismember->BuyTicket(cost, amount);
				goto B;
			}
			else if (op == '3')    //查询地图
			{
				GuangZhou.show_map();
				goto B;
			}
			else if (op == '4')    //查询余额
			{
				cout << "remind " << thismember->Inquiremoney() << endl;
				goto B;
			}
			else if (op == '5')    //挂失
			{
				thismember->ReportTheLoss();
				goto B;
			}
			else if (op == '6')    //修改密码
			{
				string old, newpw;
			E:	cout << "please input your old password" << endl;
				cin >> old;
				if (thismember->CheckPassword(old))
				{
					cout << "please input your new password\n";
					cin >> newpw;
					thismember->RevisePassword(newpw);
					goto B;
				}
				else
				{
					cout << "old password input error, please input again\n";
					goto E;
				}
			}
			else if (op == '0')    //返回上一界面
			{
				thismember = NULL;
				goto Main;
			}
			else
				goto B;
		}
	}
	else if (choice == '2')    //注册模块
	{
	ModeRegister:
		string id, password;
		char type;
		card * ptr = head;
		card * find = head;
		cout << "please input your id" << endl;
		cin >> id;
		if (total == 0)
		{

		}
		else
		{
			while (ptr)
			{
				if (ptr->CheckID(id))
				{
					cout << "Sorry,this ID has been registered, please input again\n";   //用户名已被使用
					goto ModeRegister;
				}
				else
					ptr = ptr->next;
			}
		}
		cout << "please input your password\n";
		cin >> password;
		cout << "***********************************\n";
		cout << "*" <<"\tnormal card please tap 1  *\n";
		cout << "*" <<"\tStudentCard please tap 2  *\n";
		cout << "*" <<"\tElderCard please tap 3    *\n";
		cout << "***********************************\n";
		cin >> type;
		if (type == '1')
		{
			ptr = new card(id, password);
			total++;
			AddFront(head, ptr);
		}
		else if (type == '2')
		{
			ptr = new StudentCard(id, password);
			total++;
			AddFront(head, ptr);
		}
		else if (type == '3')
		{
			ptr = new ElderCard(id, password);
			total++;
			AddFront(head, ptr);
		}
		goto Main;
	}
	else if (choice == '3')       //管理员登陆模块
	{
		Manager MGR;
		card * temp;
		string str1, str2;
ManagerMode	 :  cout << "please input manager's id and password\n";
		cin >> str1 >> str2;
		if (MGR.check(str1, str2))
		{
			cout << "log in successfully!\n";
		I:  cout << "*******************************************************\n";
			cout << "*" << "\tshow all information please tap 1            *\n";
			cout << "*" << "\toperate to the pointed member please tap2    *\n";
			cout << "*" << "\tinquire income please tap 3                  *\n";
			cout << "*" << "\tshow map data please tap 4                   *\n";
			cout << "*" << "\tadd a new data please tap 5                  *\n";
			cout << "*" << "\tmodify data please tap 6                     *\n";
			cout << "*" << "\tgo back please tap                           *\n";
			cout << "*******************************************************\n";
			//管理员操作模块
			char op;
			cin >> op;
			if (op == '1')     //总览所有客户信息
			{
				MGR.p = head;
				while (MGR.p)
				{
					MGR.p->showinfo();
					MGR.p = MGR.p->next;
				}
				goto I;
			}
			else if (op == '2')     //对具体客户的操作
			{
				bool check = 0;
				string id;
			F:	cout << "please input the id\n";
				cin >> id;
				temp = head;
				while (temp)
				{
					if (temp->CheckID(id))
					{
						check = 1;
						MGR.p = temp;
						break;
					}
					temp = temp->next;
				}
				if (!check)
				{
					cout << "no such a member, please input  again\n";
					goto F;
				}
				else
				{
				H:	cout << "inquire information please tap 1\nreport the lost please tap 2\n sever the lost please tap 3\n revise password please tap 4\n go back please  tap 0\n";
					char mission;
					cin >> mission;
					if (mission == '1')     //查询客户信息
					{
						MGR.p->showinfo();
						goto H;
					}
					else if (mission == '2')    //人工挂失
					{
						MGR.p->ReportTheLoss();
						goto H;
					}
					else if (mission == '3')    //解除挂失
					{
						MGR.p->SeverFrozen();
						goto H;
					}
					else if (mission == '4')    //人工修改密码
					{
						string newpassw;
						cout << "please input the new password\n";
						cin >> newpassw;
						MGR.p->RevisePassword(newpassw);
						goto H;
					}
					else			 //返回
					{
						goto I;
					}
				}
			}
			else if (op == '3')     //查询收入
			{
				MGR.p->ShowIncome();
				goto I;
			}
			else if (op == '4')
			{
				char ch;
				cout << "show map please tap 1\nshow station please tap 2\ngoback please tap 0\n";
				cin >> ch;
				if (ch == '1')
				{
					read_way();
				}
				else if (ch == '2')
				{
					read_station();
				}
				else
				{
					goto I;
				}
				goto I;
			}
			else if (op == '5')
			{
				char ch;
				cout << "add map please tap 1\nadd station please tap 2\ngoback please tap 0\n";
				cin >> ch;
				if (ch == '1')
				{
					add_way();
				}
				else if (ch == '2')
				{
					add_station();
				}
				else
				{
					goto I;
				}
				goto I;
			}
			else if (op == '6')
			{
				char ch;
				cout << "modify map please tap 1\nmodify station please tap 2\ngoback please tap 0\n";
				cin >> ch;
				if (ch == '1')
				{
					modify_station();
				}
				else if (ch == '2')
				{
					modify_station();
				}
				else
				{
					goto I;
				}
				goto I;
			}
			if (op == '0')   //返回
			{
				temp = NULL;
				goto Main;
			}
			else
			{
				goto I;
			}
		}
		else
		{
			cout << "input error , please input again" << endl;
			goto ManagerMode;
		}
	}
	else if (choice == '4')
	{
		char c;
		chaoshi a;
		int i;
	la:  //返回上一层标签
		cout << "            //-----欢迎进入超市管理系统-----//\n";
		cout << "            //---------请选择您的身份-------//\n";
		cout << "            //-----------1.管理员-----------//\n";
		cout << "            //-----------2.用户者-----------//\n";
		cout << "            //---------- 3.退出系统---------//\n";
		cout << "请选择：";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			guanliyuan();
			do {
				cout << "\n****管理员操作功能表****\n";
				cout << "    1—增加商品\n";
				cout << "    2—删除商品\n";
				cout << "    3—修改商品\n";
				cout << "    4—查询商品\n";
				cout << "    5—对商品进行排序\n";
				cout << "    6—统计商品信息(存货量)\n";
				cout << "    7—购买商品\n";
				cout << "    8—统计超市所有商品的总数量和总价值\n";
				cout << "    9—返回上一层\n";
				cout << "请选择（1—9）:";
				cin >> c;
				switch (c)
				{
				case '1': system("cls");
					a.add();
					a.baocun(); break;

				case '2': system("cls");
					a.zhuangru();
					a.shanchu();
					a.baocun(); break;

				case '3': system("cls");
					a.zhuangru();
					a.xiugai();
					a.baocun(); break;

				case '4': system("cls");
					a.zhuangru();
					a.chazhao(); break;

				case '5': system("cls");
					a.zhuangru();
					a.paixu(); break;

				case '6': system("cls");
					a.zhuangru();
					a.tongji(); break;

				case '7': system("cls");
					a.zhuangru();
					a.buy(); break;

				case '8': system("cls");
					a.zhuangru();
					a.zongti(); break;
				case '9':system("cls"); goto la;
				}
			} while (c != 10);
		}break;
		case 2: {cout << "\n****用户者操作功能表****\n";
		cha:  //查询标签
			system("cls");
			a.zhuangru();
			a.chazhao();
			cout << "\n是否要继续查询[Y/N]:";
			char xuan; cin >> xuan;
			if (xuan == 'y' || xuan == 'Y') goto cha;
			else break;
		}break;
		case 3: goto Main;
		}
		goto Main;
	}
	else if (choice == '0')     //结束程序
	{
		cout << "Thanks for using\n";
		file.open("C:\\Users\\gxy1997nh\\Desktop\\info.txt", ios::trunc | ios::out);
		card* Write = head;
		ticketincome = Write->GetTicketIncome();
		file << ticketincome << line;
		while (Write)
		{
			a = Write->GetID();
			b = Write->GetPW();
			c = Write->GetType();
			m = Write->GetMoney();
			f = Write->GetFreeze();
			d = Write->GetDiscount();
			t = Write->GetTimes();
			file << a << tab;
			int len = b.length();
			int arr[1000];
			for (int i = 0; i < len; i++)
			{
				arr[i] = ras.Encrypt(b[i]);

				if (arr[i] < 10)
				{
					file << "0000" << arr[i];
				}
				else if (arr[i] < 100)
				{
					file << "000" << arr[i];
				}
				else if (arr[i] < 1000)
				{
					file << "00" << arr[i];
				}
				else if (arr[i] < 10000) 
				{
					file << "0" << arr[i];
				}
				else
				{
					file << arr[i];
				}
			}
			file << tab;
			file << c << tab << m << tab << f << tab << d << tab << t << line;
			Write = Write->next;
		}
		system("pause");
		file.close();
	}
	else
	{
		goto Main;
	}
}