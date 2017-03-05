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
	//方法1：取余
	//vector<string> fizzBuzz(int n) {

	//	for (int i = 1; i <= n; i++)
	//	{
	//		if (i % 15 == 0)
	//			v.push_back("FizzBuzz");
	//		else if (i % 5 == 0)
	//			v.push_back("Buzz");
	//		else if (i % 3 == 0)
	//			v.push_back("Fizz");
	//		else
	//			v.push_back(int2str(i));
	//	}

	//	return v;
	//}

	//方法2：计步长
	vector<string> fizzBuzz(int n) {

		int step3 = 1, step5 = 1;

		for (int i = 1; i <= n; i++)
		{
			if (step3 == 3 && step5 == 5)
			{
				step3 = 1;
				step5 = 1;
				v.push_back("FizzBuzz");
			}
			else if (step5 == 5)
			{
				step5 = 1;
				step3++;
				v.push_back("Buzz");
			}
			else if (step3 == 3)
			{
				step3 = 1;
				step5++;
				v.push_back("Fizz");
			}
			else 
			{
				step3++;
				step5++;
				v.push_back(int2str(i));
			}

		}

		return v;
	}
private:
	vector<string> v;

	string int2str(int n)
	{
		stringstream ss;
		ss << n;
		string s;
		ss >> s;

		return s;
	}
};

void testPrint(vector<string> v)
{
	for (auto s : v)
		cout << s << endl;
}

int main(void)
{
	Solution s;
	
	vector<string> v = s.fizzBuzz(15);

	testPrint(v);

	return 0;
}