#include <iostream>
#include <string>
#include <map>

using namespace std; 

//建立罗马数字和阿拉伯数字的映射
int romanToInt(string s) 
{
	map<char, int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	
	//如果值小的数字在右边表示加；在左边表示减
	int result = 0;
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (m[s[i]] >= m[s[i + 1]]) //大于等于比右边的数，用加
			result += m[s[i]];
		else
			result -= m[s[i]];
	}

	//处理s[s.size()-1]的情况,结尾的数字肯定是加上去的
	result += m[s[s.size() - 1]];

	return result;
}

int main()
{

	return 0;
}