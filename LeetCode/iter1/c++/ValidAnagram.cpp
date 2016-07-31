#include <iostream>
#include <string>
#include <map>

using namespace std;

//bool isAnagram(string s, string t) {
//	if (s.size() != t.size())//大小不同的话，肯定不是anagram
//		return false;
//	
//	map<char, int> m;
//	//先对字符串s构建字典
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (m.find(s[i]) != m.end())
//			m[s[i]]++;
//		else
//			m.insert(map<char,int>::value_type(s[i],1));
//	}
//
//	//在t中寻找不在s中的字符，找到则返回false，全部遍历后返回true
//	for (int i = 0; i < t.size(); i++)
//	{
//		if (m.find(t[i]) != m.end())
//		{
//			if (m[t[i]] == 0)
//				return false;
//
//			m[t[i]]--;
//		}
//		else
//			return false;
//	}
//
//	return true;
//}

bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;

	int alphabat[26];
	for (int i = 0; i < 26; i++)
		alphabat[i] = 0;

	//用s来构建字典
	for (int i = 0; i < s.size(); i++)
		alphabat[s[i] - 'a']++;

	//在t中check是否在字典中
	for (int i = 0; i < t.size(); i++)
	{
		if (alphabat[t[i] - 'a'] == 0)
			return false;

		alphabat[t[i] - 'a']--;
	}

	return true;
}

int main()
{
	string s = "";
	string t = "f";
	
	if(isAnagram(s,t))
		cout<<"yes";
	else
		cout<<"No";
	
	return 0;
}