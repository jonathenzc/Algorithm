#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

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

bool isVectorEqual(vector<int> a, vector<int> b)
{
	if (a.size() != b.size())
		return false;

	bool result = true;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			result = false;
			break;
		}
	}

	return result;
}

bool wordPattern(string pattern, string str) {
	//按空格划分
	vector<string> strVec = splitStr(str + " ");

	if (strVec.size() != pattern.size())
		return false;

	//构建模式中的字符与其位置的映射
	unordered_map<char, vector<int>> patternMap;

	for (int i = 0; i < pattern.size(); i++)
		patternMap[pattern[i]].push_back(i);

	//为字符串vector构建映射
	unordered_map<string, vector<int>> strMap;
	for (int i = 0; i < strVec.size(); i++)
		strMap[strVec[i]].push_back(i);
	
	//遍历两个map
	if (patternMap.size() != strMap.size())
		return false;

	bool result = true;

	for (int i = 0; i < pattern.size(); i++)
	{
		if (!isVectorEqual(patternMap[pattern[i]], strMap[strVec[i]]))
		{
			result = false;
			break;
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