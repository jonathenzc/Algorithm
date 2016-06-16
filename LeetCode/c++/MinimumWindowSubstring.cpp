#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
	if (t.size() == 0)
		return "";

	//对每个t中的字符构建映射
	unordered_map<char, int> map;
	for (auto tChar : t)
		map[tChar]++;
	
	int newStart = 0, start = 0;
	int min_length = INT_MAX, min_start = 0;
	int tCnt = t.size();

	while (start < s.size())
	{
		if (map[s[start]] > 0)
			tCnt--;

		map[s[start]]--;

		while(tCnt == 0) //全部找到
		{ 
			//记录最小的window，起始下标和window长度
			if (min_length > start - newStart + 1)
			{
				min_length = start - newStart + 1;
				min_start = newStart;
			}

			//寻找新的开始点
			map[s[newStart]]++;

			if (map[s[newStart]] > 0)
			{
				tCnt++;
			}

			newStart++;
		}

		start++;
	}

	if (min_start + min_length > s.size())
		return "";

	return s.substr(min_start,min_length);
}

int main()
{
	cout << minWindow("AEEBCDAF","ABC")<<endl;


	return 0;
}
