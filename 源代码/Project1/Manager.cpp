#include "Manager.h"
Manager::Manager()
{
	ID = "gxy1997nh";
	passward = "syxka";
};
bool Manager::check(string a, string b)
{
	if (a == ID && b == passward)
	{
		return 1;
	}
	else
		return 0;
}
