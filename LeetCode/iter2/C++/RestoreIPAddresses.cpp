#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		if (s.size() <= 12 && s.size() >= 4) {
			string target = "";

			helper(0, 0, target, s);
		}

		return v;
	}
private:
	vector<string> v;

	bool validNumber(string s, int start, int end)
	{
		if (end > s.size())
			return false;

		int sum = 0;
		int len = end - start;
		
		if (len == 1)
			sum = s[start] - '0';
		else if (len == 2)
			sum = 10 * (s[start] - '0') + (s[start + 1] - '0');
		else if (len == 3)
			sum = 100 * (s[start] - '0') + 10 * (s[start + 1] - '0') + (s[start + 2]-'0');

		if (len == 1 && (sum >= 0 && sum <= 9))
			return true;
		else if (len == 2 && (sum >= 10 && sum <= 99))
			return true;
		else if (len == 3 && (sum >= 100 && sum <= 255))
			return true;
		else
			return false;
	}

	void helper(int start, int cnt, string target,string s) {
		if (cnt == 4 && start >= s.size()) {
			target.pop_back();

			v.push_back(target);
		}
		else
		{
			for (int i = 1; i <= 3; i++)
			{
				if (validNumber(s, start, start+i)) {
					string tmpS = target;
					for (int j = 0; j < i; j++)
						tmpS += s[start+j];

					tmpS += '.';
					helper(start+i,cnt+1,tmpS, s);
				}
			}
		}

	}
};

int main()
{
	Solution s;

	vector<string> v = s.restoreIpAddresses("25525511135");

	for (string str : v)
		cout << str << endl;

	return 0;
}