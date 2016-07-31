#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	if (x < y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}

	while (y != 0)
	{
		int tmp = y;
		y = x % y;
		x = tmp;
	}

	return x;
}

bool canMeasureWater(int x, int y, int z) {
	if (z < 0)
		return false;
	
	if (z == 0)
		return true;

	if (z > x + y)
		return false;

	//贝祖定理 d = ax+by,d = gcd(x,y)，即x和y取整数，我们总能构造出一对a和b使得他们符合gcd(x,y)
	int gcdNum = gcd(x,y);

	return z%gcdNum == 0;
}

void testPrint(int x, int y, int z)
{
	if (canMeasureWater(x,y,z))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	testPrint(2,7,4);
	testPrint(2,6,4);
	testPrint(2, 6, 5);
	testPrint(3, 5, 4);
	testPrint(34, 5, 16);
	testPrint(34, 5, 6);
	testPrint(34, 5, 14);

	//cout << gcd(12,8)<<endl;
	//cout << gcd(12, 36)<<endl;
	//cout << gcd(36, 48) << endl;
	//cout << gcd(5, 9) << endl;
	return 0;
}