#include <iostream>
#include <vector>
#include <string>

using namespace std;

//������a-z���ַ���ת������������Ϊa-z���Ҳ��26λ��������32λҪС������һ��int�Ǵ������ô��������ġ�
int Str2Int(string s)
{
	int result = 0;

	for (int i = 0; i < s.size(); i++)
		result = result | (1 << (s[i]-'a'));//������ĸ������λ��

	return result;
}


int maxProduct(vector<string>& words) {
	vector<int> v;
	for (int i = 0; i < words.size(); i++)
		v.push_back(Str2Int(words[i]));

	int max = 0;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			//ͨ����λ�����ж������Ƿ���ͬ
			if ((v[i] & v[j]) == 0)  //��ͬ λ������Ҫ��������
			{
				int size = words[i].size() * words[j].size();
				if (size > max)
					max = size;
			}
		}
	}

	return max;
}

int main()
{
	vector<string> v;
	v.push_back("abcw");
	v.push_back("baz");
	v.push_back("foo");
	v.push_back("bar");
	v.push_back("xtfn");
	v.push_back("abcdef");

	cout << maxProduct(v);

	//int a = 26,
	//	b = 6,
	//	c;

	//c = a & b;
	//cout << c;
		

	return 0;
}