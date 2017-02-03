#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		//先为magazine构建一个字典映射
		vector<int> dict(26,0);
		for (char ch : magazine)
			dict[ch - 'a']++;

		//遍历ransomNote，比照字符是否都在dict中出现
		for (char ch : ransomNote)
		{
			if (dict[ch - 'a'] == 0)
				return false;

			dict[ch - 'a']--;
		}

		return true;
	}
};

void testPrint(string ransomNote,string magazine)
{
	Solution s;
	
	if (s.canConstruct(ransomNote,magazine))
		cout << ransomNote <<" can be constructed by "<<magazine<<endl;
	else
		cout << ransomNote << " can't be constructed by " << magazine << endl;
}

int main(void)
{
	testPrint("","a");
	testPrint("a","b");
	testPrint("aa","ab");
	testPrint("aa","aab");

	return 0;
}