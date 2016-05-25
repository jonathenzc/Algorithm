#include <iostream>
#include <string>

using namespace std;

string getPermutation(int n, int k) {
	if (n == 1)
		return "1";
	
	if (n == 2)
	{
		if (k == 1)
			return "12";
		else if (k == 2)
			return "21";
	}

	int *numUsed = new int[n+1]; //表示数字是否被使用过
	for (int i = 1; i <= n; i++)
		numUsed[i] = 0;

	int factorial = n;
	for (int i = n-1; i >= 1; i--)
		factorial *= i;

	//代替n和k
	int num = n;
	int replaceK = k; 

	string result = "";
	int ith = -1;

	while (num != 1)
	{
		factorial /= num;

		ith = replaceK / factorial;

		replaceK = replaceK % factorial;

		if (replaceK != 0)
			ith += 1;
		else
			replaceK = factorial;

		//找出第ith的数
		int index = 0;
		char ch ;
		for (int i = 1; i <= n; i++)
		{
			if (numUsed[i] == 0)
			{
				index++;
				if (index == ith)
				{
					ch = i + '0';
					numUsed[i] = 1; //被选中
					break;
				}
			}
		}

		result += ch;

		num--;
	}

	//找出最后一个数
	for (int i = 1; i <= n; i++)
	{
		if (numUsed[i] == 0)
		{
			result += (i + '0');
			break;
		}
	}

	return result;
}

int main()
{
	//for (int i = 1; i < 25;i++)
		cout<<getPermutation(9,206490)<<endl;

	return 0;
}