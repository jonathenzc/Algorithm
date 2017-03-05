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
	int calculate(string s) {
		int ret = 0;
		int sign = 1;
		int curNum = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9') //数字
				curNum = 10 * curNum + (s[i] - '0');
			else
			{
				ret += sign*curNum;
				curNum = 0;

				if (s[i] == '+')
					sign = 1;
				else if (s[i] == '-')
					sign = -1;
				else if (s[i] == '(')
				{
					numV.push_back(ret);
					symbolV.push_back(sign);

					sign = 1;
					ret = 0;
				}
				else if (s[i] == ')')
				{
					ret = numV.back() +symbolV.back()*ret;

					numV.pop_back();
					symbolV.pop_back();
				}
			}
		}

		ret += sign*curNum;

		return ret;
	}
private:
	vector<int> numV;
	vector<int> symbolV;
};

int main(void)
{
	Solution ss;
	cout << ss.calculate("5-(4-3)+2") << endl;

	return 0;
}