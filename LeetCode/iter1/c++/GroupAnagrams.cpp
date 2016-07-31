#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector < vector<string>> resultV;
	if (strs.size() == 0)
		return resultV;

	//用大小为26的质数数组来作为hash的基
	int prime[26] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 };

	//键为字符prime的乘积，值为返回结果的下标
	unordered_map<int, int> strMap;

	int groupCnt = 0; //当前有多少组

	for (int i = 0; i < strs.size(); i++)
	{
		string s = strs[i];
		int hashKey = 1; //以乘积作为hash的键
		//使用字符串中字符在prime数组中所对应的质数，进行乘积来得到一个hash值。
		for (int s_i = 0; s_i < s.size(); s_i++)
			hashKey *= prime[s[s_i] - 'a'];

		if (strMap.find(hashKey) == strMap.end())
		{
			strMap[hashKey] = groupCnt;
			vector<string> v;
			v.push_back(s);
			resultV.push_back(v);

			groupCnt++;
		}
		else
		{
			int groupIndex = strMap[hashKey];
			resultV[groupIndex].push_back(s);
		}
	}

	return resultV;
}

void testPrint(vector<string> v)
{
	vector<vector<string>> groupV = groupAnagrams(v);
	for (int i = 0; i < groupV.size(); i++)
	{
		for (int j = 0; j < groupV[i].size(); j++)
		{
			cout << groupV[i][j] << " ";
		}

		cout << endl;
	}
}

int main()
{
	vector<string> v;
	v.push_back("aabcd");
	v.push_back("abacd");
	v.push_back("abbcd");
	v.push_back("abcbd");
	v.push_back("abcdd");
	v.push_back("abccd");

	testPrint(v);

	cout << endl;

	vector<string> v1;
	v1.push_back("eat");
	v1.push_back("tea");
	v1.push_back("tan");
	v1.push_back("ate");
	v1.push_back("nat");
	v1.push_back("bat");

	testPrint(v1);

	cout << endl;

	vector<string> v2;
	v2.push_back("cab");
	v2.push_back("tin");
	v2.push_back("pew");
	v2.push_back("duh");
	v2.push_back("may");
	v2.push_back("ill");
	v2.push_back("buy");
	v2.push_back("bar");
	v2.push_back("max");
	v2.push_back("doc");

	testPrint(v2);

	return 0;
}
