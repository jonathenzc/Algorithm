#include <iostream>

using namespace std;

bool isPowerOfThree(int n) 
{
	return (n > 0 && 1162261467 % n == 0); //1162261467��3^19,20�ξͳ���int�ķ�Χ�ˡ�
}

int main()
{
	if (isPowerOfThree(89))
		cout << "yes";
	else
		cout << "no";

	return 0;
}