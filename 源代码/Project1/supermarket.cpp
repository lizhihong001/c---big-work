#include "supermarket.h"
int n = 0; //����ڴ�����Ʒ���ݣ��ڲ�ʹ�ã�
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

void chaoshi::add()       //����Ա�����Ʒ��Ϣ
{
	shangpin *p;
	double num, count;
	char name[20], address[30];
	int price;
	cout << "\n������������Ʒ��Ϣ��\n";
	cout << "��Ʒ����:"; cin >> num;
	cout << "��Ʒ����:"; cin >> name;
	cout << "��Ʒ����:"; cin >> address;
	cout << "��Ʒ����:"; cin >> price;
	cout << "����Ʒ�����:"; cin >> count;


	p = new shangpin(num, name, address, price, count);//��������Ʒ����
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


void chaoshi::shanchu()     //����Աɾ����Ʒ��Ϣ
{
	char name[20];
	cout << "\n������Ҫɾ������Ʒ����:\n";
	cin >> name;
	//����Ҫɾ���Ľ��
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

	//ɾ�����
	if (p1 != NULL)                   //���ҵ���㣬��ɾ��
	{
		if (p1 == goods)             //��Ҫɾ���Ľ���ǵ�һ�����
		{
			goods = p1->next;
			delete p1;
			n--;
		}
		else                      //��Ҫɾ���Ľ���Ǻ������
		{
			p2->next = p1->next;
			delete p1;
			n--;
		}
		cout << "�ҵ���ɾ��\n";

	}
	else                        //δ�ҵ����
		cout << "Sorry,δ�ҵ�!\n";

}

//����Ա�޸���Ʒ��Ϣ
void chaoshi::xiugai()     //�޸���Ʒ��Ϣ
{
	double num, count;
	char name[20], address[30];
	int price;
	cout << "\n�޸���Ʒ��������Ҫ�����Ʒ����:";
	cin >> name; //����Ҫ�޸ĵĽ��
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
	//�޸Ľ��
	if (p1 != NULL)   //���ҵ����
	{
		cout << endl;
		p1->Output();
		cout << endl;
		cout << "(1����Ʒ���룬2����Ʒ���ƣ�3�����أ�4�����ۣ�5������Ʒ�������6���޸�ȫ����Ϣ)" << endl;
		cout << "\n��ѡ��Ҫ�޸ĵ���Ϣ:";
		int a;
		cin >> a;
		switch (a)
		{
		case 1:cout << "�������±��룺"; cin >> num;
			strcpy(name, p1->name); strcpy(address, p1->address); price = p1->price; count = p1->count; break;

		case 2:cout << "�����������ƣ�"; cin >> name;
			num = p1->num; strcpy(address, p1->address); price = p1->price; count = p1->count; break;

		case 3:cout << "�������²��أ�"; cin >> address;
			num = p1->num; strcpy(name, p1->name); price = p1->price; count = p1->count; break;

		case 4:cout << "�������µ��ۣ�"; cin >> price;
			num = p1->num; strcpy(name, p1->name); strcpy(address, p1->address); count = p1->count; break;

		case 5:cout << "�������¿�����ݣ�"; cin >> count;
			num = p1->num; strcpy(name, p1->name); strcpy(address, p1->address); price = p1->price; break;
		case 6:cout << "����������Ϣ��\n";
			cout << "��Ʒ����:";     cin >> num;
			cout << "��Ʒ����:";     cin >> name;
			cout << "��Ʒ����:";     cin >> address;
			cout << "��Ʒ����:";     cin >> price;
			cout << "����Ʒ�����:"; cin >> count; break;

		}
		//��������Ʒ���
		shangpin *p3;
		p3 = new shangpin(num, name, address, price, count);

		//Ա������滻������
		p3->next = p1->next;
		if (p1 == goods)  //��Ҫ�滻�Ľ���ǵ�һ�����
			goods = p3;

		else          //��Ҫ�滻�Ľ���Ǻ������
			p2->next = p3;
		delete p1;   //ɾ��ԭ������Ʒ���
		cout << "�޸ĳɹ�!\n";

	}
	else  //δ�ҵ����
		cout << "Sorry,δ�ҵ�!\n";
}

//����Ա������Ʒ��Ϣ
void chaoshi::chazhao()               //��ѯ��Ʒ��Ϣ
{
	cout << "\n****��ѯ��Ʒ****\n";
	char name[20];
	cout << "\n������Ҫ��ѯ����Ʒ����:";
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

	if (p1 != NULL)          //���ҵ����
	{
		cout << "Ҫ��ѯ����Ϣ���£�\n";
		cout << "������Ʒ����:\t" << p1->num << "\t" << "������Ʒ����:\t" << p1->name << "\t\n";
		cout << "������Ʒ����:\t" << p1->address << "\t" << "������Ʒ����:\t" << p1->price << "\t\n";
		cout << "������Ʒ�����:\t" << p1->count << "\t";
		cout << endl;
	}
	else //δ�ҵ����
		cout << "\nSorry,δ�ҵ�������Ʒ!\n";
	infile.close();

}

//�������С����
void chaoshi::paixu()
{
	cout << "��������Ҫ������������ͣ� ";
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

//������Ʒ����
void chaoshi::buy()
{
	int i, sum, factly;
	cout << "\n****��Ʒ�Ĺ���****\n";
	char name[20];
	cout << "\n������Ҫ�������Ʒ����:\n";
	cin >> name;
	shangpin *p1 = goods;
	while (p1)
	{
		if (strcmp(p1->name, name) == 0) break;
		else p1 = p1->next;
	}

	if (p1 != NULL)          //���ҵ����
	{
		cout << "\n�㹺�����Ʒ����Ϊ:" << p1->name << "\t\n";
		cout << "������Ʒ�ĵ���Ϊ:" << p1->price << "\t\n";
	label:
		cout << "����Ҫ���������:";
		cin >> i; sum = p1->price*i;
		cout << "----------------------------------------------------" << endl;
		double h; h = (p1->count) - i;
		if (h<0) { cout << "������Ʒ����,�����ֻ�У�����:" << p1->count << endl; goto label; }
		cout << "��Ӧ�ø� " << sum << "Ԫ!" << endl;
		cout << "��ʵ�ʸ�(Ԫ): ";
		cin >> factly;
		cout << "Ӧ���һ���:" << factly - sum << "Ԫ!" << endl;//���㡣
		cout << "�����Ϊ" << h;  cout << endl;
		(p1->count) -= i;//�����
	}
	if (p1 == NULL) { cout << "û�и�����Ʒ" << endl; }
}

//ͳ�Ƴ���ĳ��Ʒ���������ܼ�Ǯ
void chaoshi::tongji()
{
	cout << "\n****��Ʒͳ��****\n";
	double Value = 0;
	char name[20];
	cout << "\n������Ҫͳ�Ƶ���Ʒ����:";
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
		cout << "������Ʒ�����:" << p1->count << endl;
		cout << "����Ʒ�ĵ�����:" << p1->price << endl;
		cout << "����Ʒ�ܼ�ֵ��:" << Value << endl;
	}

	else
		cout << "\nSorry,δ�ҵ�������Ʒ!\n";

}

//ͳ�Ƴ���������Ʒ���������ܼ�Ǯ
void chaoshi::zongti()
{
	cout << "\n****����������Ʒͳ��****\n";
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
		cout << "����������Ʒ��������:";
		cout << Amount;
		cout << "\n����������Ʒ�ܼ�ֵ��:";
		cout << Value;
		cout << endl;
	}
	else
		cout << "\nSorry,δ�ҵ�������Ʒ!\n";
}

//���ݴ���
void chaoshi::baocun()
{
	cout << "�Ƿ񱣴棿[Y/N]";
	char a;
	cin >> a;
	if (a == 'n')return;
	if (a == 'y' || a == 'Y')
	{
		ofstream outfile("C:\\Users\\gxy1997nh\\Desktop\\supermarket.txt", ios::out);
		if (!outfile) { cerr << "û�и��ļ�!"; exit(1); }
		shangpin* p; p = goods;
		while (p)
		{
			outfile << "��Ʒ����\t\t" << p->num << endl;
			outfile << "��Ʒ����\t\t" << p->name << endl;
			outfile << "��Ʒ����\t\t" << p->address << endl;
			outfile << "��Ʒ����\t\t" << p->price << endl;
			outfile << "����Ʒ�����\t" << p->count << endl;
			cout << endl;
			p = p->next;
		}
		outfile.close();
		cout << "��������ݵı���\n";
	}

}


//����װ��
void chaoshi::zhuangru()
{
	shangpin *p = goods;
	ifstream infile("C:\\Users\\gxy1997nh\\Desktop\\supermarket.txt");  //��һ����Ϣ
	infile >> p->num >> p->name >> p->address >> p->price >> p->count;
	while (infile.good())
	{
		//������Ʒ���
		p = new shangpin(p->num, p->name, p->address, p->price, p->count);
		p->next = NULL;    //��Ʒ������

		if (goods)       //���Ѵ��ڽ��
		{
			shangpin*p2; p2 = goods;
			while (p2->next)  //����β���
				p2 = p2->next;
			p2->next = p;     //����
		}
		else             //���
			goods = p;     //����
						   //����һ����Ϣ
		infile >> p->num >> p->name >> p->address >> p->price >> p->count;
	}
	cout << "\n��Ʒ�����Ѿ�װ��\n";
}

//����Ա��½����
void guanliyuan()
{
	int c, d;
	int a = 123;
	int b = 123;
label:
	cout << "\n���������Ա���˺�:";
	cin >> c; cout << endl;
	cout << "���������Ա������:";
	cin >> d; cout << endl;
	if (a == c&&b == d) { system("cls"); cout << "======�ɹ���½,��ӭ:" << a << "����Ա=====" << endl; }
	else { cout << "�������,����������" << endl; goto label; }
}