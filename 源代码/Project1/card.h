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
	void rechargr(int);  //��ֵ
	virtual void BuyTicket(double, int);    //��Ʊ
	void consumer(double);    //��������
	bool CheckID(string);      //�û������
	bool CheckPassword(string);   //������
	void ShowMap();     //��ѯ��ͼ
	double Inquiremoney();    //��ѯ���
	void ReportTheLoss();     //��ʧ
	void SeverFrozen();      //�����ʧ
	void RevisePassword(string);   //�޸�����
	void SetTicketMoney(double);        //����Ʊ������
	void ShowIncome();          //��ѯ����
	double GetTicketIncome();
	string GetID();
	string GetPW();
	string GetType();
	double GetMoney();
	bool GetFreeze();
	double GetDiscount();
	int GetTimes();
	void showinfo();    //չʾ��Ϣ
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
	void BuyTicket(double, int);    //��Ʊ
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
	void BuyTicket(double, int);   //��Ʊ
private:
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~