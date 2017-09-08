#pragma once
#pragma once
#include <iostream>
#include <string>
#include "card.h"
class Manager  //管理员
{
public:
	Manager();
	bool check(string, string);   //管理员登陆
	card * p;
private:
	string ID;
	string passward;
};
const string line = "\r\n";       //换行符
const string tab = "\t";          //制表符
