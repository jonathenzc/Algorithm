#include <iostream>
#include <math.h>

using namespace std;

//对num消除n的因数
int degrade(int num,int n)
{
	while (num % n == 0)
		num = num / n;

	return num;
}

bool isUgly(int num) {
	if (num <= 0)
		return false;

	//如果一个数符合题意，那么该数可以表示成2^l * 3^m * 5^n
	//消除2的因数
	num = degrade(num, 2);

	//消除3的因数
	num = degrade(num, 3);

	//消除5的因数
	num = degrade(num, 5);

	//如果结果不为1的话，就不是ugly数
	if (num != 1)
		return false;
	else
		return true;
}

int main()
{
	if (isUgly(6)) //Yes
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(8)) //Yes
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(14)) //No
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(1)) //Yes
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(17)) //No
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(28)) //No
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}