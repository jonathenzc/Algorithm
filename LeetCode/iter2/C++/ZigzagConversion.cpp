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
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;

		string convertedStr = "";

		int startIndex = 0;
		int diff = 2 * (numRows-1);
		int base = 0;
		while (startIndex < numRows)
		{
			int i = startIndex;
			int step = base;
			while (i < s.size())
			{
				convertedStr += s[i];
 
				step = diff - step;
				if (step == 0)
					step = diff;

				i += step;
			}

			base += 2;
			startIndex++;
		}

		return convertedStr;
	}
};

int main(void)
{
	Solution s;

	cout << s.convert("PAYPALISHIRING",3) << endl; //PAHNAPLSIIGYIR
	cout << s.convert("PAYPALISHIRING", 1) << endl; //PAHNAPLSIIGYIR

	return 0;
}