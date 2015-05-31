#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) 
{
	if (needle.size() == 0)
		return 0;

	if (needle.size() > haystack.size())
		return -1;
	else
	{
		int needleIndexInHaystack = -1;
		int needleIndex = 0;

		bool isNeedleFound = false;

		for (int j = 0; j < haystack.size(); j++)
		{
			if (!isNeedleFound && haystack.size() - j < needle.size())//needle�Ĵ�С��ʣ�±ȽϵĴ�СҪ���򲻿��������������
			{
				needleIndexInHaystack = -1;
				break;
			}

			//�ҵ�neelde��haystack�еĵ�һ���ַ��±�
			if (!isNeedleFound)
			{
				if (haystack[j] == needle[needleIndex])
				{
					needleIndexInHaystack = j;
					isNeedleFound = true;
					needleIndex++;
				}
			}
			else
			{
				if (needleIndex < needle.size())
				{
					if (haystack[j] != needle[needleIndex])
					{
						j = needleIndexInHaystack;
						needleIndexInHaystack = -1;
						needleIndex = 0;//��haystack�м���Ѱ���Ƿ����
						isNeedleFound = false;
					}
					else
						needleIndex++;
				}
				else//�ҵ���ֱ������ѭ��
					break;

			}
		}

		return needleIndexInHaystack;
	}
}

int main()
{
	cout << strStr("fsda", "sdf") << " ";
	cout << strStr("fwrsdarew", "sda") << " ";
	cout << strStr("fsda", "fsda") << " ";
	cout<< strStr("fsda", "sda")<< " ";
	cout << strStr("mississippi", "issip") << " ";
	cout << strStr("mississippi", "issipi");

	return 0;
}