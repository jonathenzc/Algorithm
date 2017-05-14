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
	string convertToBase7(int num) {
		if (num == 0)
			return "0";

		string s = "";
		bool isNegative = false;

		if (num < 0)
		{
			num = -num;
			isNegative = true;
		}

		while (num > 0)
		{
			s = char((num % 7)+'0')+s; 
			num = num / 7;
		}

		if (isNegative)
			s = "-" + s;

		return s;
	}
};

int main(void)
{
	Solution s;
	cout << s.convertToBase7(10) << endl;
	cout << s.convertToBase7(-10) << endl;
	cout << s.convertToBase7(100) << endl;
	cout << s.convertToBase7(-100) << endl;

	return 0;
}