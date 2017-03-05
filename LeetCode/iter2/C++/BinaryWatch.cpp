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
	vector<string> readBinaryWatch(int num) {
		vector<int> oneCntV(60,0);

		//构建0到59中数为二进制的容器
		for (int i = 0; i < 60; i++)
		{
			int oneCnt = 0;
			int tmpI = i;
			while (tmpI > 0)
			{
				oneCnt += (tmpI &1);
				tmpI = tmpI >> 1;
			}

			oneCntV[i] = oneCnt;
		}

		for (int hour = 0; hour < 12; hour++)
		{
			for (int minute = 0; minute < 60; minute++)
			{
				if (oneCntV[hour] + oneCntV[minute] == num)
				{
					string hourStr = int2str(hour);
					string minuteStr = int2str(minute);
					
					//组合字符串
					string retStr = "";

					retStr += hourStr+":";

					if (minute >= 0 && minute < 10)
						retStr += "0";

					retStr += minuteStr;
					
					retV.push_back(retStr);
				}
			}
		}

		return retV;
	}

private:
	vector<string> retV;

	string int2str(int num)
	{
		stringstream ss;
		ss << num;
		string s;
		ss >> s;

		return s;
	}
};

void testPrint(int n)
{
	Solution s;
	
	vector<string> v = s.readBinaryWatch(n);
	for (auto s : v)
		cout << s << endl;
}

int main(void)
{
	testPrint(1);

	return 0;
}