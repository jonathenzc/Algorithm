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
			int mid = start + (end - start) / 2;
			if (nums[mid] > nums[end])
				start = mid+1;
			else if (nums[mid] < nums[end])
				end = mid;
			else
				end--;
		}

		return nums[start];
	}

	//第二种线性方法
	//int findMin(vector<int>& nums) {
	//	int preNum = nums[0];
	//	int target = nums[0];
	//	for (int i = 1; i < nums.size(); i++)
	//	{
	//		if (nums[i] < preNum)
	//		{
	//			target = nums[i];
	//			break;
	//		}
	//		else
	//			preNum = nums[i];
	//	}

	//	return target;
	//}
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

	//vector<int> v;
	//v.push_back(3);
	//v.push_back(3);
	//v.push_back(1);
	//v.push_back(3);

	//Solution s;
	//cout << s.findMin(v)<<endl;

	return 0;
}