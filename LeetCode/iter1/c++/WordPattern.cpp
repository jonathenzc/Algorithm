#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//方法1：
//vector<string> splitStr(string str)
//{
//	vector<string> v;
//
//	int startIndex = 0;
//	while(startIndex < str.size())
//	{
//		int spaceIndex = str.find(" ",startIndex);
//		string subStr = str.substr(startIndex,spaceIndex-startIndex);
//		v.push_back(subStr);
//
//		startIndex = spaceIndex + 1;;
//	}
//
//	return v;
//}
//
//bool isVectorEqual(vector<int> a, vector<int> b)
//{
//	if (a.size() != b.size())
//		return false;
//
//	bool result = true;
//
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] != b[i])
//		{
//			result = false;
//			break;
//		}
//	}
//
//	return result;
//}
//
//bool wordPattern(string pattern, string str) {
//	//按空格划分
//	vector<string> strVec = splitStr(str + " ");
//
//	if (strVec.size() != pattern.size())
//		return false;
//
//	//构建模式中的字符与其位置的映射
//	unordered_map<char, vector<int>> patternMap;
//
//	for (int i = 0; i < pattern.size(); i++)
//		patternMap[pattern[i]].push_back(i);
//
//	//为字符串vector构建映射
//	unordered_map<string, vector<int>> strMap;
//	for (int i = 0; i < strVec.size(); i++)
//		strMap[strVec[i]].push_back(i);
//	
//	//遍历两个map
//	if (patternMap.size() != strMap.size())
//		return false;
//
//	bool result = true;
//
//	for (int i = 0; i < pattern.size(); i++)
//	{
//		if (!isVectorEqual(patternMap[pattern[i]], strMap[strVec[i]]))
//		{
//			result = false;
//			break;
//		}
//	}
//
//	return result;
//}

//方法2：
vector<string> splitStr(string str)
{
	vector<string> v;

	int startIndex = 0;
	while(startIndex < str.size())
	{
		int spaceIndex = str.find(" ",startIndex);
		string subStr = str.substr(startIndex,spaceIndex-startIndex);
		v.push_back(subStr);

		startIndex = spaceIndex + 1;;
	}

	return v;
}

bool wordPattern(string pattern, string str) {
	//按空格划分
	vector<string> strVec = splitStr(str + " ");

	if (strVec.size() != pattern.size())
		return false;

	//构建模式中的字符与待比较字符串的映射
	unordered_map<char, string> pattern2StrMap;
	//构建待比较字符串与模式中的字符的映射
	unordered_map<string, char> str2PatternMap;

	bool result = true;

	for (int i = 0; i < pattern.size(); i++)
	{
		//两边字符串均为被映射过
		if (pattern2StrMap[pattern[i]] == "" && str2PatternMap[strVec[i]] == 0)
		{
			pattern2StrMap[pattern[i]] = strVec[i];
			str2PatternMap[strVec[i]] = pattern[i];
		}
		else //两者中至少有一个被进行映射过
		{
			if (pattern2StrMap[pattern[i]] != strVec[i] || str2PatternMap[strVec[i]] != pattern[i]) //两边映射匹配不上
			{
				result = false;
				break;
			}
		}
	}

	return result;
}

void testPrint(string pattern, string str)
{
	if (wordPattern(pattern, str))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	testPrint("abba", "dog cat cat dog"); //true
	testPrint("abba", "dog cat cat fish"); //false
	testPrint("aaaa", "cat cat cat cat"); //true
	testPrint("abba", "dog dog dog dog"); //false

	return 0;
}