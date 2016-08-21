#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double calOper(double a,double b, int k)
{
	if (k == 1)
		return a + b;
	else if (k == 2)
		return a - b;
	else if (k == 3)
		return a*b;
	else if (k == 4)
	{
		if (b != 0)
			return a / b;
	}
	else if (k == 5)
		return b-a;
	else if (k == 6)
	{
		if (a != 0)
			return b / a;
	}

	return 0;
}

bool try24(int a[],int i, int j, int k)
{
	//(((a#b)#c)#d)
	if (calOper(calOper(calOper(a[0], a[1], i), a[2], j), a[3], k) == 24)
		return true;

	//((a#b)#(c#d))
	if (calOper(calOper(a[0], a[1], i), calOper(a[2], a[3], j), k) == 24)
		return true;

	return false;
}


bool canGet24(int a[])
{
	bool ret = false;

	//枚举数的排列
	do {
		//枚举符号
		for (int i = 1; i <= 6 && !ret; i++)
		{
			for (int j = 1; j <= 6 && !ret; j++)
			{
				for (int k = 1; k <= 6 && !ret; k++)
				{
					if (try24(a, i, j, k))
						ret = true;
				}
			}
		}


	} while (next_permutation(a, a + 4) && !ret);

	return ret;
}

int main()
{
	int arrayCnt;
	cin >> arrayCnt;
	int a[4];

	for (int i = 1; i <= arrayCnt; i++)
	{
		cin >> a[0] >> a[1] >> a[2] >> a[3];

		sort(a,a+4);

		if (canGet24(a))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}