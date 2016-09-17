#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		
		for (int i = 0; i < s.size(); i++) {

			vector<string> curV;
			
			if (isPalindrome(s, 0, i))
			{
				curV.push_back(s.substr(0,i+1));
				helper(0, i, curV, s);
				curV.pop_back();
			}
		}

		return v;
	}
private:
	vector<vector<string>> v;

	void helper(int start,int end, vector<string> curV, string s) {
		if (end == s.size() - 1)
			v.push_back(curV);
		else {
			for (int i = end+1; i < s.size(); i++) {

				if (isPalindrome(s, end+1, i))
				{
					curV.push_back(s.substr(end+1, i-end));
					helper(0, i, curV, s);
					curV.pop_back();
				}
			}
		}
	}

	bool isPalindrome(string s,int start,int end)
	{
		bool ret = true;
		while (start < end) {
			if (s[start] != s[end]) {
				ret = false;
				break;
			}

			start++;
			end--;
		}

		return ret;
	}
};

int main()
{
	Solution s;
	string str = "aab";
	vector<vector<string>> v = s.partition(str);

	for (auto tmpV : v) {
		for (auto tmpS : tmpV)
			cout << tmpS << " ";

		cout << endl;
	}

	return 0;
}