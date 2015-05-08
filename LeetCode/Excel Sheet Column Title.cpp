#include <iostream>
#include <string>

using namespace std;

string convertToTitle(int n)
{
	string s = "";

	if (n > 0)
	{
		string reversedS = "";
		while (n != 0)
		{
			reversedS += (n-1)%26+'A'; 
			n = (n - 1) / 26;
		}

		for (int i = reversedS.size()-1; i >=0; i--)
			s += reversedS[i];
	}

	return s;
}

int main()
{
	cout << convertToTitle(28)<<endl
		<<convertToTitle(10)<<endl
		<<convertToTitle(52)<<endl
		<<convertToTitle(53)<<endl;

	return 0;
}