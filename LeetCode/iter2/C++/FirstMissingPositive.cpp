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
	int firstMissingPositive(vector<int>& nums) {
		int vSize = nums.size();

		//将数组中的元素放入该值指向的下标
		int i = 0;
		while (i < nums.size())
		{
			while (nums[i] <= vSize && nums[i] > 0 && nums[i] != nums[nums[i]-1])
				swapValue(nums,i,nums[i]-1);

			i++;
		}

		int index = nums.size();
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1)
			{
				index = i;
				break;
			}
		}

		return index + 1;
	}
private:
	void swapValue(vector<int>& nums, int i, int j)
	{
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
};

int main(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(0);

	vector<int> v1;
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(-1);
	v1.push_back(1);

	vector<int> v2;
	v2.push_back(50);
	v2.push_back(51);
	v2.push_back(52);

	vector<int> v3;
	v3.push_back(50);
	v3.push_back(1);
	v3.push_back(0);

	Solution s;
	cout << s.firstMissingPositive(v) << endl;
	cout << s.firstMissingPositive(v1) << endl;
	cout << s.firstMissingPositive(v2) << endl;
	cout << s.firstMissingPositive(v3) << endl;
	return 0;
}