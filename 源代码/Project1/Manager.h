#pragma once
#pragma once
#include <iostream>
#include <string>
#include "card.h"
class Manager  //����Ա
{
public:
	Manager();
	bool check(string, string);   //����Ա��½
	card * p;
private:
	string ID;
	string passward;
};
const string line = "\r\n";       //���з�
const string tab = "\t";          //�Ʊ��
