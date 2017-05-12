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
	vector<string> fizzBuzz(int n) {
		int threeCnt = 0, fiveCnt = 0;

		for (int i = 1; i <= n; i++)
		{
			threeCnt++;
			fiveCnt++;

			if (threeCnt == 3 && fiveCnt == 5)
			{
				v.push_back("FizzBuzz");
				threeCnt = 0; fiveCnt = 0;
			}
			else if (threeCnt == 3)
			{
				v.push_back("Fizz");
				threeCnt = 0;
			}
			else if (fiveCnt == 5)
			{
				v.push_back("Buzz");
				fiveCnt = 0;
			}
			else
				v.push_back(int2str(i));
		}

		return v;
	}
private:
	vector<string> v;

	string int2str(int num)
	{
		stringstream ss;
		ss << num;
		string s;
		ss >> s;
		
		return s;
	}
};

int main(void)
{
	Solution s;

	vector<string> v = s.fizzBuzz(22);

	for (auto s : v)
		cout << s << endl;

	return 0;
}