#include <iostream>
#include <string>

using namespace std;

int strToInt(string s, int i,int j)
{
	int strInt = 0;

	for (int index = 0; index < j-i;index++)
	{
		if (s[index+i] != '0')
		{
			int powCnt = 0;
			int pow = s[index+i]-'0';
			while (powCnt<j-i-1-index)
			{
				pow *= 10;
				powCnt++;
			}

			strInt += pow;
		}
	}

	return strInt;
}

int *split(string s,int &size)
{
	int *versionList = new int[200];

	int dotIndex = 0;
	int lastDotIndex = 0;

	while (dotIndex != -1)
	{
		dotIndex = s.find('.', lastDotIndex);
		
		if (dotIndex == -1)
			versionList[size++] = strToInt(s, lastDotIndex, s.size());
		else
			versionList[size++] = strToInt(s, lastDotIndex, dotIndex);

		lastDotIndex = dotIndex + 1;
	}

	return versionList;
}

//题目假设了两个version字符串不为空且只包含.和数字
int compareVersion(string version1, string version2) 
{
	int version1Size = 0;
	int *version1Number = split(version1,version1Size);

	int version2Size = 0;
	int *version2Number = split(version2,version2Size);

	int smallerSize = version1Size;
	if (version2Size < smallerSize)
		smallerSize = version2Size;

	int result = 0;

	for (int i = 0; i < smallerSize; i++)
	{
		if (version1Number[i] > version2Number[i])
		{
			result = 1;
			break;
		}
		else if (version1Number[i] < version2Number[i])
		{
			result = -1;
			break;
		}
	}

	if (result == 0)
	{
		if (version1Size > version2Size)
		{
			for (int i = version2Size; i < version1Size; i++)
			{
				if (version1Number[i] != 0)
					result = 1;
			}
		}
		else if (version1Size < version2Size)
		{
			for (int i = version1Size; i < version2Size; i++)
			{
				if (version2Number[i] != 0)
					result = -1;
			}
		}
	}

	return result;
}

int main()
{
	//cout << compareVersion("01","1")<<endl;

	cout << compareVersion("19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000", "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000") << endl;

	return 0;
}