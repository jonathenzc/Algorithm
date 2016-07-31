#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool isPal(string& s, int start, int end)  //start and end refer to index;
{
	bool result = true;

	while (start < end)
	{
		if (s[start] != s[end])
		{
			result = false;
			break;
		}

		start++;
		end--;
	}

	return result;
}

vector<vector<int>> palindromePairs(vector<string>& words)
{
	vector<vector<int>> resultV;

	if (words.size() == 0)
		return resultV;

	unordered_map<string, int> map; //记录每个单词的下标
	for (int i = 0; i < words.size(); i++)
		map[words[i]] = i;

	for (int i = 0; i < words.size(); i++)
	{
		string s = words[i];

		reverse(s.begin(),s.end());

		for (int l = 0; l <= s.size(); l++)
		{
			if (isPal(s, 0, l - 1))//作为前缀，先保证反转后的s中0到l-i为回文
			{
				string restStr = s.substr(l);
				if (map.count(restStr))
				{
					int restStrIndex = map[restStr];
					if (restStrIndex != i)
					{
						vector<int> tmpV;
						tmpV.push_back(i);
						tmpV.push_back(restStrIndex);
						resultV.push_back(tmpV);
					}
				}
			}

			if (isPal(s, l, s.size()-1)) //作为后缀
			{
				string restStr = s.substr(0,l);
				if (map.count(restStr) && l != s.size()) //因为如果数组中abcd和dcba都出现，那么""abcd和abcd""都会做一次，所以只需要在长度上限制一下
				{
					int restStrIndex = map[restStr];
					if (restStrIndex != i)
					{
						vector<int> tmpV;
						tmpV.push_back(restStrIndex);
						tmpV.push_back(i);
						resultV.push_back(tmpV);
					}
				}
			}
		}
	}


	return resultV;
}

void testPrint(vector<string> v)
{
	vector<vector<int>> resultV = palindromePairs(v);

	for (int i = 0; i < resultV.size(); i++)
	{
		vector<int> v = resultV[i];
		cout << "[";
		for (int j = 0; j < v.size(); j++)
			cout << v[j] << " ";
		cout << "]\n";
	}

	cout << "\n";
}

int main()
{
	vector<string> v;
	v.push_back("bat");
	v.push_back("tab");
	v.push_back("cat");

	testPrint(v);


	vector<string> v1;
	v1.push_back("abcd");
	v1.push_back("dcba");
	v1.push_back("lls");
	v1.push_back("s");
	v1.push_back("sssll");

	testPrint(v1);


	vector<string> v2;
	v2.push_back("a");
	v2.push_back("aa");
	v2.push_back("aaa");

	testPrint(v2);

	return 0;
}