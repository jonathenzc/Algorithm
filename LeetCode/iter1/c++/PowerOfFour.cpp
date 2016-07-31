#include <iostream>
#include <string>

using namespace std;

bool isPowerOfFour(int num) {
	if (num <= 0)
		return false;
	else if (num == 1)
		return true;

	bool result = false;

	while (num > 1)
	{
		int digit = (num & 1);
		if (digit != 0)
			break;

		num = num >> 1;
		digit = (num & 1);

		if (digit != 0)
			break;
		
		num = num >> 1;
		digit = num & 1;
		if (num == 1 && digit == 1)
		{
			result = true;
			break;
		}
	}

	return result;
}

int main()
{
	if (isPowerOfFour(1))
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isPowerOfFour(0))
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isPowerOfFour(16))
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isPowerOfFour(17))
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isPowerOfFour(256))
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isPowerOfFour(257))
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isPowerOfFour(6))
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isPowerOfFour(12))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}