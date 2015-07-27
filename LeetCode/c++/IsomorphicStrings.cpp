#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t)
{
	//如果两个字符串长度不等，那么他们肯定不是同构字符串
	if (s.size() != t.size())
		return false;
	else
	{
		map<char, char> m; //储存s中字符与t中字符的映射关系

		string mappingS = "";//经过映射后的字符串
		for (int i = 0; i < s.size(); i++)
		{
			if (m.find(s[i]) == m.end())//该映射关系不存在
			{ 
				//寻找映射的目标是否已经被其他字符映射过了
				map<char, char>::iterator iter;
				for (iter = m.begin(); iter != m.end(); iter++)
				{
					if (t[i] == iter->second)//字符串t为映射目标
						return false;
				}

				m[s[i]] = t[i];//建立映射关系
			}

			mappingS += m[s[i]];
		}

		if (mappingS == t)
			return true;
		else
			return false;
	}
}

//bool isIsomorphic(string s1, string s2)
//{
//	int* m = new int[512];
//	for (int i = 0; i < s1.length(); i++) {
//		if (m[s1[i]] != m[s2[i] + 256]) return false;
//		m[s1[i]] = m[s2[i] + 256] = i + 1;
//	}
//	return true;
//}

int main()
{
	if (isIsomorphic("aa", "ab"))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}