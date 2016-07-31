#include <iostream>
#include <string>
#include <map>

using namespace std; 

//�����������ֺͰ��������ֵ�ӳ��
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
	
	//���ֵС���������ұ߱�ʾ�ӣ�����߱�ʾ��
	int result = 0;
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (m[s[i]] >= m[s[i + 1]]) //���ڵ��ڱ��ұߵ������ü�
			result += m[s[i]];
		else
			result -= m[s[i]];
	}

	//����s[s.size()-1]�����,��β�����ֿ϶��Ǽ���ȥ��
	result += m[s[s.size() - 1]];

	return result;
}

int main()
{

	return 0;
}