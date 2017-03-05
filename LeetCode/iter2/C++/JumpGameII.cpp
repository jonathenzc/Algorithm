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
	int jump(vector<int>& nums) {
		minJump = 0;

		int curDis=0;
		int i = 0;

		while (curDis < nums.size() - 1)
		{
			int preDis = curDis;

			while (i <= preDis)
			{
				curDis = max(curDis, nums[i]+i);
				i++;
			}

			minJump++;
		}

		return minJump;
	}
private:
	int minJump;
};

int main(void)
{
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(4);

	vector<int> v3;
	v3.push_back(2);
	v3.push_back(5);
	v3.push_back(0);
	v3.push_back(0);

	Solution s;
	cout << s.jump(v2) << endl
		<< s.jump(v3) << endl;

	return 0;
}