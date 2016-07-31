#include <iostream>
#include <string>
#include <map>

using namespace std;

//int lengthOfLongestSubstring(string s) {
//	map<char, int> m; //记录之前字符串中字符出现的下标
//	int max = 0;
//	int i = 0;
//	int strSize = s.size();
//	int curSize = 0;
//	int newStart = 0;
//
//	while (i < strSize)
//	{
//		char ch = s[i];
//		if (m.find(ch) == m.end()) //之前没有记录过
//		{
//			curSize++;
//			m.insert(map<char, int>::value_type(ch, i));
//		}
//		else
//		{
//			if (curSize > max)
//				max = curSize;
//
//			if (m[ch] >= newStart)
//			{
//				newStart = m[ch];
//				curSize = i - newStart;
//			}
//			else
//				curSize = i - newStart;
//
//			m[ch] = i;
//		}
//
//		i++;
//	}
//
//	if (curSize > max)
//		max = curSize;
//
//	return max;
//}

//不用map，直接用数组来记录大小
int lengthOfLongestSubstring(string s) {
	int m[128];
	for (int i = 0; i<128; i++)
		m[i] = -1;

	int max = 0;
	int i = 0;
	int strSize = s.size();
	int curSize = 0;
	int newStart = 0;

	while (i < strSize)
	{
		int ch = s[i];
		if (m[ch]<0) //之前没有记录过
		{
			curSize++;
			m[ch] = i;
		}
		else
		{
			if (curSize > max)
				max = curSize;

			if (m[ch] >= newStart)
				newStart = m[ch];
				
			curSize = i - newStart;

			m[ch] = i;
		}

		i++;
	}

	if (curSize > max)
		max = curSize;

	return max;
}


int main()
{
	cout << lengthOfLongestSubstring("abcdefg") << endl;
	cout << lengthOfLongestSubstring("abcabcbb")<<endl;
	cout << lengthOfLongestSubstring("bbbbb") << endl;
	cout << lengthOfLongestSubstring("pwwkew") << endl;
	cout << lengthOfLongestSubstring("bbbbba") << endl;
	cout << lengthOfLongestSubstring("pwwkewww") << endl;
	cout << lengthOfLongestSubstring("abcdeeeee") << endl;
	cout << lengthOfLongestSubstring("a") << endl;
	cout << lengthOfLongestSubstring("") << endl;
	cout << lengthOfLongestSubstring("abba") << endl;
	cout << lengthOfLongestSubstring("abbacd") << endl;
	cout << lengthOfLongestSubstring("abbaabcd") << endl;
	cout << lengthOfLongestSubstring("zwnigfunjwz") << endl;
	

	return 0;
}
