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
			if (!isNeedleFound && haystack.size() - j < needle.size())//needle的大小比剩下比较的大小要长则不可能有这样的情况
			{
				needleIndexInHaystack = -1;
				break;
			}

			//找到neelde在haystack中的第一个字符下标
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
						needleIndex = 0;//在haystack中继续寻找是否存在
						isNeedleFound = false;
					}
					else
						needleIndex++;
				}
				else//找到了直接跳出循环
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