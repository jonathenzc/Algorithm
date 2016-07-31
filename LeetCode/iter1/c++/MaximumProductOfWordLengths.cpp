#include <iostream>
#include <vector>
#include <string>

using namespace std;

//将带有a-z的字符串转换成整数，因为a-z最多也就26位的数，比32位要小，所以一个int是存的下这么大的整数的。
int Str2Int(string s)
{
	int result = 0;

	for (int i = 0; i < s.size(); i++)
		result = result | (1 << (s[i]-'a'));//左移字母个数个位置

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
			//通过按位与来判断两数是否相同
			if ((v[i] & v[j]) == 0)  //不同 位运算需要运用括号
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