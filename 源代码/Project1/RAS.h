#pragma once
#include <string>
using namespace std;
/*
int Encrypt(int);     //RAS对数字加密
int Decrypt(int);     //RAS对数字解密
string DecryptStr(string);  //RAS对字符串解密
*/
struct CH                    //辅助解密的临时结构
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

