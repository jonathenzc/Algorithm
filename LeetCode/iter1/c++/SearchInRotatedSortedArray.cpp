#include <iostream>
#include <vector>

using namespace std;

int findMinIndex(vector<int>& nums)
{
	int left = 0, right = nums.size() - 1;

	while (left < right)
	{
		if (nums[left] < nums[right])
			return left;

		int mid = (left + right) / 2;
		if (nums[mid] > nums[right])
			left = mid + 1;
		else
			right = mid;
	}

	return left;
}

int binarySearch(vector<int> nums, int target,int start,int end)
{

	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (target == nums[mid])
			return mid;
		else if (target < nums[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}

	return -1;
}

int search(vector<int>& nums, int target) {
	int minIndex = findMinIndex(nums);

	if (target == nums[minIndex])
		return minIndex;

	int maxNum;
	if (minIndex == 0)
		maxNum = nums[nums.size() - 1];
	else
		maxNum = nums[minIndex - 1];

	if (target < nums[minIndex] || target > maxNum)
		return -1;

	//确定是从最小值的左边找，还是最小值的右边找
	if (target == nums[nums.size() - 1])
		return nums.size() - 1;
	else if (target < nums[nums.size() - 1])
	{
		return binarySearch(nums,target,minIndex,nums.size()-1);
	}
	else
	{
		if (minIndex != 0)
			return binarySearch(nums, target, 0, minIndex - 1);
		else
			return -1;
	}
}

void testPrint(vector<vector<char>>& board)
{
	for (auto row : board)
	{
		for (auto col : row)
			cout << col << " ";

		cout << endl;
	}

	cout << endl;
}

int main()
{
	vector<int> v1;

	//v1.push_back(4); //0
	//v1.push_back(5); //1
	//v1.push_back(6); //2
	//v1.push_back(7); //3
	//v1.push_back(0); //4
	//v1.push_back(1); //5
	//v1.push_back(2); //6

	//v1.push_back(2); //0
	//v1.push_back(4); //1
	//v1.push_back(5); //2
	//v1.push_back(6); //3
	//v1.push_back(7); //4
	//v1.push_back(0); //5
	//v1.push_back(1); //6

	//v1.push_back(1); //0
	//v1.push_back(2); //1
	//v1.push_back(4); //2
	//v1.push_back(5); //3
	//v1.push_back(6); //4
	//v1.push_back(7); //5
	//v1.push_back(0); //6

	//v1.push_back(0); //0
	//v1.push_back(1); //1
	//v1.push_back(2); //2
	//v1.push_back(4); //3
	//v1.push_back(5); //4
	//v1.push_back(6); //5
	//v1.push_back(7); //6

	//v1.push_back(7); //0
	//v1.push_back(0); //1
	//v1.push_back(1); //2
	//v1.push_back(2); //3
	//v1.push_back(4); //4
	//v1.push_back(5); //5
	//v1.push_back(6); //6

	//v1.push_back(6); //0
	//v1.push_back(7); //1
	//v1.push_back(0); //2
	//v1.push_back(1); //3
	//v1.push_back(2); //4
	//v1.push_back(4); //5
	//v1.push_back(5); //6

	v1.push_back(5); //0
	v1.push_back(6); //1
	v1.push_back(7); //2
	v1.push_back(0); //3
	v1.push_back(1); //4
	v1.push_back(2); //5
	v1.push_back(4); //6

	for (int i = -2; i < 10; i++)
		cout <<i<<" "<< search(v1,i)<<endl;



	return 0;
}