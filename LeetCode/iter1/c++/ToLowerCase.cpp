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
	string toLowerCase(string str) {
		for (int i = 0; i < str.length();i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] = (str[i] - 'A' + 'a');
			}
		}
		return str;
	}
};

int main(void)
{
	Solution s;
	cout << s.toLowerCase("Hello") << endl
		<< s.toLowerCase("here") << endl
		<< s.toLowerCase("LOVELY") << endl;

	return 0;
}