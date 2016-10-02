#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int longestPalindrome(string s) {
	unordered_map<char, int> map;

	for (char ch : s)
		map[ch]++;

	bool isOddFound = false;
	int length = 0;
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		if (iter->second & 1 == 1) //odd
		{
			length += iter->second - 1;
			isOddFound = true;
		}
		else
			length += iter->second;
	}

	if(isOddFound)
		length += 1;

	return length;
}


int main()
{
	cout << longestPalindrome("abccccdd")<<endl;
	cout << longestPalindrome("abccccdddeeeee") << endl;
	cout << longestPalindrome("abcdefg") << endl;

	return 0;

}