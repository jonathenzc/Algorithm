#include <iostream>
#include <vector>


using namespace std;

//方法1：用牛顿迭代法求出平方根
//const float EPS = 0.01;
//double sqrt(double x) {
//	if (x == 0) return 0;
//	double result = x; /*Use double to avoid possible overflow*/
//	double lastValue;
//	do {
//		lastValue = result;
//		result = result / 2.0f + x / 2.0f / result;
//	} while (abs(result - lastValue) > EPS);
//	return result;
//}
//
//bool isPerfectSquare(int num) {
//	int squareRoot = sqrt(num);
//
//	if (squareRoot*squareRoot == num)
//		return true;
//	else
//		return false;
//}

//方法2：数学方法n^2 = 1+3+5+...+(2n-1) = (1+2n-1)*n/2
bool isPerfectSquare(int num) {
	if (num < 0)
		return false;

	if (num <= 1)
		return true;

	int i = 1;

	while (num > 0)
	{
		num -= i;
		i += 2;
	}

	if (num == 0)
		return true;
	else
		return false;
}

void testPrint(int num)
{
	if (isPerfectSquare(num))
		cout << "Yes\n";
	else
		cout << "No\n";
}

//void testPrint(vector<int> v)
//{
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i] << " ";
//
//	cout << endl;
//}

int main()
{
	testPrint(16);
	testPrint(4);
	testPrint(9);
	testPrint(2);
	testPrint(19);
	testPrint(256);
	testPrint(255);

	return 0;
}