#include <iostream>

using namespace std;

int getSum(int a, int b) {
	
	int addDigit = a&b; //进位是多少
	int noAddDigit = a^b; //没有进位的基础值

	if (addDigit != 0) //仍有进位
		return getSum(noAddDigit, addDigit << 1);
	else
		return noAddDigit;
}

int main()
{
	cout << getSum(4,3)<<endl;
	cout << getSum(4, 30) << endl;
	cout << getSum(5, 9) << endl;
	cout << getSum(1, 0) << endl;
	cout << getSum(1, 1) << endl;
	cout << getSum(4, -3) << endl;
	cout << getSum(1, -1) << endl;
	cout << getSum(1, -10) << endl;
	cout << getSum(40, -90) << endl;
	return 0;
}