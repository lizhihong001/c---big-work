#pragma once
struct way
{
	char pre[30];
	char post[30];
	double distance;
	double time;
};
void read_way();
void add_way();
void modify_way();