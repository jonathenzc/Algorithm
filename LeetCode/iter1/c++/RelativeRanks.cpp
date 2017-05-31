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
		vector<string> findRelativeRanks(vector<int>& nums) {
			vector<string> v;

			map<int, int> rankMap;
			for (int num : nums)
				rankMap[num] = 1;

			int rank = nums.size();
			for (map<int, int>::iterator iter = rankMap.begin(); iter != rankMap.end(); iter++)
				rankMap[iter->first] = rank--;
			
			for (int i = 0; i < nums.size(); i++)
			{
				if (rankMap[nums[i]] == 1)
					v.push_back("Gold Medal");
				else if (rankMap[nums[i]] == 2)
					v.push_back("Silver Medal");
				else if (rankMap[nums[i]] == 3)
					v.push_back("Bronze Medal");
				else
					v.push_back(int2str(rankMap[nums[i]]));
			}

			return v;
		}
	private:
		string int2str(int num)
		{
			stringstream ss;
			ss << num;
			string s;
			ss >> s;

			return s;
		}
	};

void testPrint(vector<int> v)
{
	Solution s;

	vector<string> retV = s.findRelativeRanks(v);
	for (int i = 0; i < retV.size(); i++)
		cout << retV[i] << " ";

	cout << endl;
}

int main(void)
{
	vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	testPrint(v);

	vector<int> v1;
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(4);

	testPrint(v1);


	vector<int> v2;
	v2.push_back(10);
	v2.push_back(3);
	v2.push_back(8);
	v2.push_back(9);
	v2.push_back(4);

	testPrint(v2);

	return 0;
}