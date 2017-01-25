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
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> hashMap;
		for (int i = 0; i < nums1.size(); i++)
			hashMap[nums1[i]] = 1;

		vector<int> ret;

		for (int i = 0; i < nums2.size(); i++)
		{
			if (hashMap[nums2[i]] == 1)
			{
				ret.push_back(nums2[i]);
				hashMap[nums2[i]] = 0;
			}
		}

		return ret;
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
	
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(1);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(2);

	
	vector<int> ret = s.intersection(v1,v2);

	for (auto num : ret)
		cout << num << endl;

	return 0;
}