#include <iostream>

using namespace std;

//获取一半长度的整数转化成int，与另一半的整数进行比较
bool isPalindrome(int x) 
{
	if (x < 0 || (x!=0 && x%10==0))//负数不为回文数或者结尾为0且该数不为0整数的也不为回文
		return false;

	int halfInt = 0;

	while (halfInt < x)
	{
		halfInt *= 10;
		halfInt += x % 10;
		x = x / 10;
	}

	if (x == halfInt)
		return true;
	else
	{
		if (halfInt / 10 == x)//处理12321,在上面的情况下halfInt会变成123,而x会变成12
			return true;
		else
			return false;
	}
}

int main()
{
	if (isPalindrome(1))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}