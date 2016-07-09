#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//方法1： O(n)超时
//int superPow(int a, vector<int>& b) {
//	int n = 1337;
//	int sum = 0;
//	for (int i = 0; i < b.size(); i++)
//		sum += b[i]*pow(10,b.size()-1-i);
//
//
//	//x*y % n = (x% n*y% n)% n;
//	//x*x % n = (x%n)^2 %n
//	int result=1;
//	for (int i = 0; i < sum; i++)
//	{
//		result = ((result%n)*(a%n)) % n;
//	}
//
//	return result;
//}

//方法2： a^k%n = ((a%n)^k)%n
int normalPow(int a, int k, int n)
{
	int result = 1, base = a;
	while (k > 0)
	{
		if (k & 1 == 1) //当前二进制位为1
			result = ((result%n)*(base%n)) % n; //result = (result*base) %n

		base = ((base%n)*(base%n)) % n; //base = (base*base)%n

		k = k >> 1;
	}

	return result;
}

int superPow(int a, vector<int>& b) {
	int n = 1337;

	//a^1234567%n = ( (a^1234560)%n * (a^7)%n ) %n 因为交换律//x*y % n = (x% n*y% n)% n;
	// (a^1234560)%n =  ((a^123456)%n)^10 % n

	int result = 1;
	for (int i = 0; i < b.size(); i++)
	{
		result = (normalPow(result,10,n)%n) * (normalPow(a,b[i],n)%n) % n;

	}


	return result;
}

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(0);
	v.push_back(0);

	cout << superPow(2147483647,v) << endl;

	return 0;
}