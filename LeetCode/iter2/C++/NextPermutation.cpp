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
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 1)
			return;

		int index = nums.size() - 1;
		int target = nums[index];
		index--;

		//找出需要交换的位置
		while (index >= 0 && nums[index] >= target)
		{
			target = nums[index];
			index--;
		}

		if (index == -1) //54321
			reArrangeOrder(nums, 0, nums.size() - 1);
		else
		{
			int targetIndex = index;
			index = nums.size() - 1;

			//找到比nums[targetIndex]大的数，交换他们
			while (index >= 0 && nums[index] <= nums[targetIndex])
				index--;
			
			int tmp = nums[index];
			nums[index] = nums[targetIndex];
			nums[targetIndex] = tmp;

			reArrangeOrder(nums,targetIndex+1,nums.size()-1);
		}
	}
private:
	void reArrangeOrder(vector<int> &nums, int start, int end)
	{
		while (start < end)
		{
			int tmp = nums[start];
			nums[start] = nums[end];
			nums[end] = tmp;

			start++;
			end--;
		}
	}
};

void testPrint(vector<int> v)
{
	for (int num : v)
		cout << num << " ";

	cout << endl;
}

int main(void)
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(3);
	v2.push_back(2);
	v2.push_back(1);

	vector<int> v3;
	v3.push_back(1);
	v3.push_back(1);
	v3.push_back(5);

	Solution s;
	s.nextPermutation(v1);
	s.nextPermutation(v2);
	s.nextPermutation(v3);

	testPrint(v1);
	testPrint(v2);
	testPrint(v3);

	return 0;
}