#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) 
{
	bool result = false;

	while (n % 2 == 0 && n != 0)
		n = n / 2;

	if (n == 1)
		result = true;

	return result;
}

int main()
{
	if (isPowerOfTwo(0))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}