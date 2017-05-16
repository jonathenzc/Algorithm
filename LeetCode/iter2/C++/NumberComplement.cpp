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
	int findComplement(int num) {
		string s = "";
		while (num > 0)
		{
			s += char((num & 1) ^ 1+'0');
			num >>= 1;
		}

		return binaryStr2int(s);
	}

private:
	int binaryStr2int(string s)
	{
		int bitSize = 0;
		int sum = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == '1')
				sum += powtwo(i);
		}

		return sum;
	}

	int powtwo(int size)
	{
		int cnt = 0;
		int ret = 1;
		while (cnt < size)
		{
			ret *= 2;
			cnt++;
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.findComplement(5) << endl;
	cout << s.findComplement(1) << endl;



	return 0;
}