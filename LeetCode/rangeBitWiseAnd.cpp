#include <iostream>
#include <string>

using namespace std;

//将正整数转成二进制
string intToBinary(int num)
{
	string s = "";

	while (num != 0)
	{
		s += num % 2 + '0';
		num = num / 2;
	}

	return s;
}

int rangeBitWiseAnd(int m,int n)
{
	string mStr = intToBinary(m);
	string nStr = intToBinary(n);

	if (mStr.size() != nStr.size())
		return 0;
	else
	{
		//记录两个字符串上一个相同坐标的下标索引
		//找到第一个不同的下标索引后立即返回，记录上一个下标相同的下标
		int lastEqualPos = mStr.size() - 1;
		for (int i = mStr.size() - 2; i >= 0; i--)
		{
			if (mStr[i] != nStr[i])
				break;
			else
			{
				if (mStr[i] == '1')
					lastEqualPos = i;
			}
		}

		//
		int wiseAndResult=0;

		for (int i = lastEqualPos; i < mStr.size(); i++)
		{
			//根据字符串中的位置得出该位置的二次幂，比如i为2，就是2^2
			//这里其实用math里面的pow就可以了
			if (mStr[i] == '1')
			{
				int cnt = 0;
				int power = 1;//二次方的结果
				while (cnt < i)
				{
					power *= 2;
					cnt++;
				}

				wiseAndResult += power;
			}
		}

		return wiseAndResult;
	}
}

int main()
{
	cout << rangeBitWiseAnd(2,2)<<endl;

	return 0;
}