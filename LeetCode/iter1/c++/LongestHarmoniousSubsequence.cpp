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
#include <map>

using namespace std;

class Solution {
public:
	int findLHS(vector<int>& nums) {

		map<int, int> numMap;
		for (int i = 0; i < nums.size(); i++)
		{
			if (numMap.find(nums[i]) == numMap.end())
				numMap[nums[i]] = 1;
			else 
			{
				int cnt = numMap[nums[i]];
				numMap[nums[i]] = cnt + 1;
			}
		}

		int preNum;
		int preNumCnt = 0;
		int harmoniousLen = 0;
		map<int, int>::iterator iter = numMap.begin();
		for (iter; iter != numMap.end(); iter++)
		{
			if (preNumCnt == 0)
			{
				preNum = iter->first;
				preNumCnt = iter->second;
			}
			else
			{
				if (iter->first - preNum == 1)
				{
					harmoniousLen = max(harmoniousLen, preNumCnt + iter->second);
				}

				preNum = iter->first;
				preNumCnt = iter->second;
			}
		}

		return harmoniousLen;
	}
};

int main(void)
{
	vector<int> v;

	//测试集合1
	//for (int i = 0; i < 5; i++)
	//	v.push_back(5);

	//for (int i = 0; i < 6; i++)
	//	v.push_back(7);

	//测试集合2
	//v.push_back(1);
	//v.push_back(3);
	//v.push_back(2);
	//v.push_back(2);
	//v.push_back(5);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(7);

	//测试集合3
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(3);
	v.push_back(7);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);


	Solution s;
	cout << s.findLHS(v) << endl;

	return 0;
} 