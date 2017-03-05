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
	int romanToInt(string s) {
		vector<int> v(26, 0);
		v['I' - 'A'] = 1;
		v['V' - 'A'] = 5;
		v['X' - 'A'] = 10;
		v['L' - 'A'] = 50;
		v['C' - 'A'] = 100;
		v['D' - 'A'] = 500;
		v['M' - 'A'] = 1000;

		int ret = 0;
		
		int i = 0;
		while(i < s.size())
		{
			if (i + 1 < s.size() && v[s[i] - 'A'] < v[s[i + 1] - 'A']) {
				ret += v[s[i + 1] - 'A'] - v[s[i] - 'A'];
				i++;
			}
			else
				ret += v[s[i] - 'A'];

			i++;
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.romanToInt("MMMCMXCIX") << endl;
	cout << s.romanToInt("I") << endl;
	cout << s.romanToInt("II") << endl;
	cout << s.romanToInt("III") << endl;
	cout << s.romanToInt("IV") << endl;
	cout << s.romanToInt("MDCCCLXXXVIII") << endl;

	return 0;
}