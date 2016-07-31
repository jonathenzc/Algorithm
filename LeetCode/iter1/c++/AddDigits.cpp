#include <iostream>

using namespace std;

//这里有一个性质：任何数mod 9等于这个数的位和
int addDigits(int num) 
{
	if (num == 0)
		return 0;
	
	int result = num % 9;
	if (result == 0)
		return 9;
	else
		return result;
}

int main()
{
	cout << addDigits(38) << endl
		<< addDigits(18) << endl
		<< addDigits(0) << endl
		<< addDigits(9) << endl;

	return 0;
}