#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int firstUniqChar(string s) {
	if (s.size() == 0)
		return -1;
	if (s.size() == 1)
		return 0;

	int index = 0;
	int indexMap[26]{0};
	indexMap[s[0] - 'a']++;

	for (int i = 1; i < s.size();i++)
	{
		indexMap[s[i] - 'a']++;

		if (index == -1)
		{
			if (indexMap[s[i] - 'a'] == 1)
				index = i;
		}
		else
		{
			if (s[index] == s[i])
			{
				do {
					index++;
				} while (index < i && indexMap[s[index] - 'a'] > 1);

				if (index >= i)
					index = -1;
			}
		}
	}

	return index;
}

int main()
{
	cout << firstUniqChar("leetcode")<<endl; //0
	cout << firstUniqChar("loveleetcode") << endl;//2
	cout << firstUniqChar("aabb") << endl; //-1
	cout << firstUniqChar("aa") << endl; //-1
	cout << firstUniqChar("aabbc") << endl; //4
	cout << firstUniqChar("abb") << endl; //0
	cout << firstUniqChar("abbbc") << endl; //0
	cout << firstUniqChar("abbbbba") << endl; //-1
	cout << firstUniqChar("aadadaad") << endl;//-1

	return 0;
}