#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isUgly(int num) {
	if (num <= 0)
		return false;
	
	bool ret = true;

	while (num > 1)
	{
		if (num % 2 == 0)
			num /= 2;
		else if (num % 3 == 0)
			num /= 3;
		else if (num % 5 == 0)
			num /= 5;
		else
		{
			ret = false;
			break;
		}
	}

	return ret;
}

void testPrint(int n)
{
	if (isUgly(n))
		cout << n<<" Ugly\n";
	else
		cout << n<<" Not Ugly\n";
}

int main()
{
	for (int i = 0; i < 41; i++)
		testPrint(i);
	


	return 0;
}