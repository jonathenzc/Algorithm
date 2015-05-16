#include <iostream>
#include <string>

using namespace std;

//�ж����ַ�������Ϊ9��Ҳ����������ĳ��ȵ�������Ƿ����ڽ���
bool isOutOfRange(string str,int startIndex,int endIndex,bool isPositive)
{
	if (endIndex - startIndex < 9)
		return false;
	else if (endIndex - startIndex == 9)//ֻ����Ϊ9
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
	bool isPositive = true;//�жϸ����Ƿ�Ϊ����

	//���ҵ���һ�������ַ�
	int firstNumericIndex = -1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i]<='9')
		{
			firstNumericIndex = i;
			break;
		}
	}

	//�ַ�����û�������ַ�
	if (firstNumericIndex != -1)
	{
		//����һ�������ַ�ǰ�Ƿ�Ϊ����
		if (firstNumericIndex - 1 >= 0 && (str[firstNumericIndex - 1] == '-'))
			isPositive = false;

		//�ж�֮ǰ�Ƿ���ڷǿո��ַ�
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
			//֮��Ѱ���ַ�����β�������ַ�����
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

			//ȥ��֮ǰΪ0���ַ�
			for (int i = firstNumericIndex; i <= lastNumbericIndex; i++)
			{
				if (str[i] != '0')
				{
					firstNumericIndex = i;
					break;
				}

				if (i == lastNumbericIndex)//ȫ��0
					firstNumericIndex = lastNumbericIndex;
			}


			int length = lastNumbericIndex - firstNumericIndex;

			//��firstNumericIndex��lastNumericIndex֮����ַ�ת��Ϊ����
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