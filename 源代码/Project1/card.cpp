#include "card.h"
#include <iostream>
#include <iomanip>
using namespace std;
double card::TicketIncome = 0;
card::card(string a, string b)
{
	ID = a;
	password = b;
	money = 0;
	freeze = 0;
	discount = 1;
	times = 0;
	type = "NormalCard";
	cout << "card created  successfully!\n\n";
}
card::card(string a, string b, string c, double m, bool f, double d, int t)
{
	ID = a;
	password = b;
	type = c;
	money = m;
	freeze = f;
	discount = d;
	times = t;
}
void card::rechargr(int x)   //充值
{
	money += x;
	cout << "rechargr successfully!" << endl;
	cout << "remind " << money << "yuan" << endl;
}
void card::BuyTicket(double ticketmoney, int amount)    //买票
{
	if (freeze)
	{
		cout << "this card has been freezen!";
		return;
	}
	else
	{
		if (times >= 15)
		{
			discount = 0.6;
		}
		double cost = ticketmoney * discount * amount;
		if (money - cost >= 0)
		{
			money -= cost;
			cout << "unit price is " << setprecision(2) << std::fixed << ticketmoney << endl;
			cout << "amount is " << amount << endl;
			cout << "discount is " << setprecision(2) << std::fixed << discount << endl;
			cout << "total price is " << setprecision(2) << std::fixed << cost << endl;
			cout << "remind money is " << setprecision(2) << std::fixed << money << endl;
			cout << "ticket has been bought!\n";
			times++;
			TicketIncome += cost;
		}
		else
		{
			cout << "not suffcient funds!\n";
			return;
		}
	}
}
void card::consumer(double cost)    //其他消费
{
	if (freeze)
	{
		cout << "this card has been freezen!" << endl;
		return;
	}
	else
	{
		if (money - cost >= 0)
		{
			money -= cost;
			cout << "consumer successfully";
		}
		else
		{
			cout << "not suffcient funds!\n";
			return;
		}
	}
}
bool card::CheckID(string id)      //用户名检测
{
	if (id == ID)
		return 1;
	else
		return 0;
}
bool card::CheckPassword(string pw)    //密码检测
{
	if (pw == password)
		return 1;
	else
		return 0;
}
void card::ShowMap()     //查询地图
{

}
double card::Inquiremoney()    //查询余额
{
	return money;
}
void card::ReportTheLoss()     //挂失
{
	freeze = 1;
	cout << "this card has been reported the lost" << endl;
}
void card::SeverFrozen()      //解除挂失
{
	freeze = 0;
	cout << "This card has been serered frozen" << endl;
}
void card::RevisePassword(string newpassword)   //修改密码
{
	if (freeze)
	{
		cout << "this card has been freezen!\n";
		return;
	}
	else
		password = newpassword;
	cout << "revise password successfully!" << endl;
}
void card::SetTicketMoney(double x)        //设置票务收入
{
	TicketIncome = x;
}
double card::GetTicketIncome()
{
	return TicketIncome;
}
void card::ShowIncome()          //查询收入
{
	cout << "Income = " << TicketIncome << endl;
}
string card::GetID()
{
	return ID;
}
string card::GetPW()
{
	return password;
}
string card::GetType()
{
	return type;
}
double card::GetMoney()
{
	return money;
}
bool card::GetFreeze()
{
	return freeze;
}
double card::GetDiscount()
{
	return discount;
}
int card::GetTimes()
{
	return times;
}
void card::showinfo()    //展示信息
{
	cout << "ID: 	" << ID << endl;
	cout << "password: 	" << password << endl;
	cout << "type: 	" << type << endl;
	cout << "money:		" << money << endl;
	cout << "using times in this month is " << times << endl;
	if (freeze)
	{
		cout << "condition:  has been frozen" << endl;
	}
	else
	{
		cout << "condition:  normally" << endl;
	}
	cout << endl;
}

StudentCard::StudentCard(string a, string b, string c, double m, bool f, double d, int t)
{
	ID = a;
	password = b;
	type = c;
	money = m;
	freeze = f;
	discount = d;
	times = t;
}
void StudentCard::BuyTicket(double ticketmoney, int amount)    //买票
{
	if (freeze)
	{
		cout << "this card has been freezen!\n";
		return;
	}
	else
	{
		double cost = ticketmoney * discount * amount;
		if (money >= cost)
		{
			money -= cost;
			cout << "unit price is " <<  setprecision(2) << std::fixed << ticketmoney << endl;
			cout << "amount is " << amount << endl;
			cout << "discount is " << setprecision(2) << std::fixed << discount << endl;
			cout << "total price is " << setprecision(2) << std::fixed << cost << endl;
			cout << "remind money is " << setprecision(2) << std::fixed << money << endl;
			cout << "ticket has been bought!\n";
			TicketIncome += cost;
			times++;
			return;
		}
		else
		{
			cout << "not suffcient funds\n";
			return;
		}
	}
}

ElderCard::ElderCard(string a, string b, string c, double m, bool f, double d, int t)
{
	ID = a;
	password = b;
	type = c;
	money = m;
	freeze = f;
	discount = d;
	times = t;
}
void ElderCard::BuyTicket(double ticketmoney, int amount)   //买票
{
	if (freeze)
	{
		cout << "this card has been freezen\n";
		return;
	}
	else
	{
		double cost = ticketmoney * discount * amount;
		if (money >= cost)
		{
			money -= cost;
			cout << "unit price is " << setprecision(2) << std::fixed << ticketmoney << endl;
			cout << "amount is " << amount << endl;
			cout << "discount is " << setprecision(2) << std::fixed << discount << endl;
			cout << "total price is " << setprecision(2) << std::fixed << cost << endl;
			cout << "remind money is " << setprecision(2) << std::fixed << money << endl;
			cout << "ticket has been bought!\n";
			TicketIncome += cost;
			times++;
			return;
		}
		else
		{
			cout << "not suffcient funds\n";
			return;
		}
	}
}