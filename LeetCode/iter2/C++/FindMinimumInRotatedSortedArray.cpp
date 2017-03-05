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
	int findMin(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;

		while (start < end)
		{
			if (nums[start] < nums[end])
				break;

			int mid = (start + end) / 2;
			if (nums[mid] > nums[end])
				start = mid + 1;
			else
				end = mid;
		}

		return nums[start];
	}
};


void PrintV(vector<int> v)
{
	for (auto num : v)
		cout << num << " ";

	cout << endl;
}

void testPrint(int leftPart,int rightPart)
{
	vector<int> v;
	for (int i = leftPart - 1; i>=0; i--)
		v.push_back(leftPart+rightPart-i);

	for (int i = 1; i <= rightPart; i++)
		v.push_back(i);

	PrintV(v);

	Solution s;
	cout << "Min "<<s.findMin(v) << endl;
}


int main(void)
{
	int size = 7;
	for (int i = 0; i < size;i++)
		testPrint(i,size-i);

	return 0;
}