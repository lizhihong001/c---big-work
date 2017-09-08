#include "RAS.h"
/*
���ڹ�Կ��public key(n,e)�� ��num���ܺ������Ϊ num^e % n��
�������ÿ������㷨�����Ӷ��� o��e������Ϊ o��log2 e����
�����ݵ�˼���ǣ�a^b mod c = (a^2)^b / 2 mod c  bΪż��
				a^b mod c = a * (a^2)^b / 2 mod c  bΪ����
				��ָ�������۰��Դﵽ���͸��Ӷȵ�Ŀ��
*/
int RAS::Encrypt(int num)
{
	int n = 11413;
	int e = 7471;
	int res = 1;
	while (e > 0)
	{
		if (e % 2 == 1)
		{
			res = (res * num) % n;
		}
		e /= 2;
		num = (num * num) % n;
	}
	return res;
}
/*
����˽Կ��private key(n,d)�� ��num���ܺ������Ϊ num^d % n
*/
int RAS::Decrypt(int num)
{
	int n = 11413;
	int d = 6031;
	int res = 1;
	while (d > 0)
	{
		if (d % 2 == 1)
		{
			res = (res * num) % n;
		}
		d /= 2;
		num = (num * num) % n;
	}
	return res;
}
/*
�ǽ����ܺ�õ��ĳ��ַ������ܻ�ԭ�����ݵĺ���
*/
string RAS::DecryptStr(string str)
{
	CH temp[100];
	int len = str.length() / 5;
	int arr[100];
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			temp[i].ch[j] = str[5 * i + j];
		}
	}
	for (int i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i] += (temp[i].ch[j] - 48) * (int)(pow(10, 4 - j));
		}
	}
	char ans[100];
	int de[100];
	for (int i = 0; i < len; i++)
	{
		de[i] = Decrypt(arr[i]);
		ans[i] = de[i];
	}
	ans[len] = '\0';
	return ans;
}



/*
������Կ�Ĵ��룺
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
bool Is_Primenumber(int x)
{
	int cnt = 0;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			cnt++;
		}
	}
	if (cnt)
	{
		return 0;
	}
	else
		return 1;
}
bool Prime_EachOther(int number1, int number2)
{
	int cnt = 0;
	for (int i = 1; i < min(number1, number2); i++)
	{
		if (number1 % i == 0 && number2 % i == 0)
		{
			cnt++;
		}
	}
	if (cnt == 1)
		return 1;
	else
		return 0;
}
int main()
{
	int p, q, n, Euler, e, d;
	for (int i = 10; i <= 500; i++)
	{
		if (Is_Primenumber(i))
		{
			cout << i << "\t";
		}
	}
	cout << endl;
	cin >> p;
	for (int i = 2; i <= 500; i++)
	{
		if (Prime_EachOther(i, p))
		{
			cout << i << "\t";
		}
	}
	cout << endl;
	cin >> q;
	if (Prime_EachOther(p, q))
	{
		cout << "continue\n";
	}
	else
	{
		return 0;
	}
	n = p * q;
	Euler = (p - 1) * (q - 1);
	for (int i = 2; i < Euler; i++)
	{
		if (Prime_EachOther(i, Euler))
		{
			cout << i << "\t";
		}
	}
	cout << endl;
	cin >> e;
	for (int i = -20000; i <= 20000; i++)
	{
		for (int j = -20000; j <= 20000; j++)
		{
			if (e * i + Euler * j == 1)
			{
				cout << i << "\t";
			}
		}
	}
	cout << endl;
	cin >> d;
	cout << "piblic key = (" << n << "," << e << ")" << endl;
	cout << "pribate key = (" << n << ',' << d << ")" << endl;
}
*/