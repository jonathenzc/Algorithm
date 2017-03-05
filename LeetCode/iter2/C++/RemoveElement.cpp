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
	int removeElement(vector<int>& nums, int val) {
		int left = 0, right = nums.size() - 1;
		int targetCnt = 0;

		while (left <= right)
		{
			//从nums找出val的下标
			while (left < nums.size() && nums[left] != val)
				left++;

			//从后找出不是val的下标
			while (right >= 0 && nums[right] == val)
				right--;

			if (left < right)
			{
				targetCnt++;

				//交换两者位置
				int tmp = nums[left];
				nums[left] = nums[right];
				nums[right] = tmp;

				left++;
				right--;
			}
		}

		return left;
	}
};

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(1);

	//vector<int> nums;
	//nums.push_back(3);
	//nums.push_back(2);
	//nums.push_back(2);
	//nums.push_back(3);

	Solution s;

	cout << s.removeElement(nums,5)<<endl;
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";

	return 0;
}