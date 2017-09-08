#pragma once
#include <iostream>
#include <string>
using namespace std;
class card
{
public:
	card() {};
	card(string a, string b);
	card(string a, string b, string c, double m, bool f, double d, int t);
	void rechargr(int);  //充值
	virtual void BuyTicket(double, int);    //买票
	void consumer(double);    //其他消费
	bool CheckID(string);      //用户名检测
	bool CheckPassword(string);   //密码检测
	void ShowMap();     //查询地图
	double Inquiremoney();    //查询余额
	void ReportTheLoss();     //挂失
	void SeverFrozen();      //解除挂失
	void RevisePassword(string);   //修改密码
	void SetTicketMoney(double);        //设置票务收入
	void ShowIncome();          //查询收入
	double GetTicketIncome();
	string GetID();
	string GetPW();
	string GetType();
	double GetMoney();
	bool GetFreeze();
	double GetDiscount();
	int GetTimes();
	void showinfo();    //展示信息
	card * next;
protected:
	string ID, password, type;
	double money;
	bool freeze;
	double discount;
	int times;
	static double TicketIncome;
};
class StudentCard : public card
{
public:
	StudentCard() {};
	StudentCard(string a, string b) : card(a, b)
	{
		discount = 0.5;
		type = "StudentCard";
	}
	StudentCard(string, string, string, double, bool, double, int);
	~StudentCard();
	void BuyTicket(double, int);    //买票
};
class ElderCard : public card
{
public:
	ElderCard() {};
	ElderCard(string a, string b) : card(a, b)
	{
		type = "ElderCard";
		discount = 0;
	}
	ElderCard(string a, string b, string c, double m, bool f, double d, int t);
	~ElderCard();
	void BuyTicket(double, int);   //买票
private:
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~