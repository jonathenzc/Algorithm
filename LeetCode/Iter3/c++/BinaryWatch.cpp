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
		vector<vector<int>> digitV(6,vector<int>());
		buildDigitV(digitV);
		print(digitV);

		int hourOneCnt = 0;

		while (hourOneCnt <= num)
		{
			if (hourOneCnt < 6 && num - hourOneCnt < 6)
			{
				string s = "";
				vector<int> hourV = digitV[hourOneCnt];

				vector<int> minuteV = digitV[num - hourOneCnt];

				for (int i = 0; i < hourV.size(); i++)
				{
					if (hourV[i] < 12)
					{
						s = str2int(hourV[i]) + ":";

						for (int j = 0; j < minuteV.size(); j++)
						{
							string combinedStr = s;

							if (minuteV[j] < 10)
								combinedStr += '0';

							combinedStr += str2int(minuteV[j]);

							retV.push_back(combinedStr);
						}
					}
				}
			}

			hourOneCnt++;
		}

		return retV;
	}
private:
	vector<string> retV;
	
	void print(vector<vector<int>> v)
	{
		for (auto tmpV : v)
		{
			for (int num : tmpV)
				cout << num << " ";

			cout << endl;
		}
	}

	string str2int(int num)
	{
		stringstream ss;
		ss << num;
		string s;
		ss >> s;

		return s;
	}


	void buildDigitV(vector<vector<int>> &v)
	{
		for (int i = 0; i < 60; i++)
		{
			int zeroCnt = countOnes(i);
			v[zeroCnt].push_back(i);
		}
	}

	int countOnes(int num)
	{
		int ret = 0;

		while (num > 0) 
		{
			ret += num & 1;
			num = num >> 1;
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<string> v = s.readBinaryWatch(2);
	for (string s : v)
		cout << s << endl;

	return 0;
}