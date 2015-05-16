#include <iostream>
#include <string>

using namespace std;

//判断在字符串长度为9，也就是最大数的长度的情况下是否仍在界内
bool isOutOfRange(string str,int startIndex,int endIndex,bool isPositive)
{
	if (endIndex - startIndex < 9)
		return false;
	else if (endIndex - startIndex == 9)//只可能为9
	{
		if (str[startIndex] > '0' && str[startIndex] < '2')
			return false;
		else if (str[startIndex] == '2')
		{
			if (str[startIndex + 1] >= '0' && str[startIndex + 1] < '1')
				return false;
			else if (str[startIndex + 1] == '1')
			{
				if (str[startIndex + 2] >= '0' && str[startIndex + 2] < '4')
					return false;
				else if (str[startIndex + 2] == '4')
				{
					if (str[startIndex + 3] >= '0' && str[startIndex + 3] < '7')
						return false;
					else if (str[startIndex + 3] == '7')
					{
						if (str[startIndex + 4] >= '0' && str[startIndex + 4] < '4')
							return false;
						else if (str[startIndex + 4] == '4')
						{
							if (str[startIndex + 5] >= '0' && str[startIndex + 5] < '8')
								return false;
							else if (str[startIndex + 5] == '8')
							{
								if (str[startIndex + 6] >= '0' && str[startIndex + 6] < '3')
									return false;
								else if (str[startIndex + 6] == '3')
								{
									if (str[startIndex + 7] >= '0' && str[startIndex + 7] < '6')
										return false;
									else if (str[startIndex + 7] == '6')
									{
										if (str[startIndex + 8] >= '0' && str[startIndex + 8] < '4')
											return false;
										else if (str[startIndex + 8] == '4')
										{
											if (isPositive)//2147483647
											{
												if (str[startIndex + 9] >= '0' && str[startIndex + 9] <= '7')
													return false;
												else
													return true;
											}
											else//-2147483648
											{
												if (str[startIndex + 9] >= '0' && str[startIndex + 9] <= '8')
													return false;
												else
													return true;
											}
										}
										else
											return true;
									}
									else
										return true;
								}
								else
									return true;
							}
							else
								return true;
						}
						else
							return true;
					}
					else
						return true;
				}
				else
					return true;
			}
			else
				return true;
		}
		else
			return true;
	}
}

int myAtoi(string str) 
{
	int result = 0;
	bool isPositive = true;//判断该数是否为正数

	//先找到第一个数字字符
	int firstNumericIndex = -1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i]<='9')
		{
			firstNumericIndex = i;
			break;
		}
	}

	//字符串中没有数字字符
	if (firstNumericIndex != -1)
	{
		//检查第一个数字字符前是否为负号
		if (firstNumericIndex - 1 >= 0 && (str[firstNumericIndex - 1] == '-'))
			isPositive = false;

		//判断之前是否存在非空格字符
		int symbolIndex = firstNumericIndex;
		if (!isPositive)
			symbolIndex--;
		else
		{
			if (firstNumericIndex-1>=0 && str[firstNumericIndex - 1] == '+')
				symbolIndex--;
		}

		bool canPerform = true;

		for (int i = symbolIndex - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
			{
				canPerform = false;
				break;
			}
		}

		if (canPerform)
		{
			//之后寻找字符串结尾的数字字符索引
			int lastNumbericIndex = firstNumericIndex;
			for (int i = firstNumericIndex + 1; i < str.size(); i++)
			{
				if (str[i] < '0' || str[i] > '9')
				{
					lastNumbericIndex = i - 1;
					break;
				}

				if (i == str.size() - 1)
					lastNumbericIndex = str.size() - 1;
			}

			//去除之前为0的字符
			for (int i = firstNumericIndex; i <= lastNumbericIndex; i++)
			{
				if (str[i] != '0')
				{
					firstNumericIndex = i;
					break;
				}

				if (i == lastNumbericIndex)//全是0
					firstNumericIndex = lastNumbericIndex;
			}


			int length = lastNumbericIndex - firstNumericIndex;

			//将firstNumericIndex和lastNumericIndex之间的字符转化为整数
			if (length > 9)
			{
				if (isPositive)
					result = INT_MAX;
				else
					result = INT_MIN;
			}
			else
			{
				if (isOutOfRange(str, firstNumericIndex, lastNumbericIndex, isPositive))
				{
					if (isPositive)
						result = INT_MAX;
					else
						result = INT_MIN;
				}
				else
				{
					int length = lastNumbericIndex - firstNumericIndex;

					for (int i = firstNumericIndex; i <= lastNumbericIndex; i++)
					{
						int powCnt = 0;
						int temp = str[i] - '0';
						if (temp != 0)
						{
							while (powCnt < length - (i - firstNumericIndex))
							{
								temp *= 10;
								powCnt++;
							}

							result += temp;
						}
					}

					if (!isPositive)
						result = -result;
				}
			}
		}
	}
		
	return result;
}

int main()
{
	cout << myAtoi("1095502006p8")<<endl;
	return 0;
}