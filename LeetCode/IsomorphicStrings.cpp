#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t)
{
	//��������ַ������Ȳ��ȣ���ô���ǿ϶�����ͬ���ַ���
	if (s.size() != t.size())
		return false;
	else
	{
		map<char, char> m; //����s���ַ���t���ַ���ӳ���ϵ

		string mappingS = "";//����ӳ�����ַ���
		for (int i = 0; i < s.size(); i++)
		{
			if (m.find(s[i]) == m.end())//��ӳ���ϵ������
			{ 
				//Ѱ��ӳ���Ŀ���Ƿ��Ѿ��������ַ�ӳ�����
				map<char, char>::iterator iter;
				for (iter = m.begin(); iter != m.end(); iter++)
				{
					if (t[i] == iter->second)//�ַ���tΪӳ��Ŀ��
						return false;
				}

				m[s[i]] = t[i];//����ӳ���ϵ
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