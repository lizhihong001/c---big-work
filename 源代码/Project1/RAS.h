#pragma once
#include <string>
using namespace std;
/*
int Encrypt(int);     //RAS�����ּ���
int Decrypt(int);     //RAS�����ֽ���
string DecryptStr(string);  //RAS���ַ�������
*/
struct CH                    //�������ܵ���ʱ�ṹ
{
	char ch[5];
};
class RAS
{
public:
	RAS() {};
	int Encrypt(int);
	int Decrypt(int);
	string DecryptStr(string);
private:
};

