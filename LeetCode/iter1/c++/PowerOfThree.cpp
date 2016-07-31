#include <iostream>

using namespace std;

bool isPowerOfThree(int n) 
{
	return (n > 0 && 1162261467 % n == 0); //1162261467是3^19,20次就超过int的范围了。
}

int main()
{
	if (isPowerOfThree(89))
		cout << "yes";
	else
		cout << "no";

	return 0;
}