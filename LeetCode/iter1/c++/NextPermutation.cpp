#include <iostream>
#include <vector>

using namespace std;

void swapValue(vector<int> &nums, int start, int end)
{
	int tmp = nums[start];
	nums[start] = nums[end];
	nums[end] = tmp;
}

void adjustOrder(vector<int> &nums, int start, int end)
{
	while (start < end)
	{
		swapValue(nums,start,end);

		start++;
		end--;
	}
}

void nextPermutation(vector<int>& nums) {
	if (nums.size() > 0)
	{
		int target = nums[nums.size()-1];
		int index = -1;
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] < target)
			{
				index = i;
				break;
			}
			else
				target = nums[i];
		}

		if (index == -1)
			adjustOrder(nums,0,nums.size()-1);
		else
		{
			//找到比index大的数的下标
			int startIndex = index;
			for (int i = nums.size() - 1; i >= index; i--)
			{
				if (nums[i] > nums[index])
				{
					startIndex = i;
					break;
				}
			}

			//交换index和
			swapValue(nums, index, startIndex);

			//调整顺序
			adjustOrder(nums, index + 1, nums.size() - 1);
		}
	}
}

void testPrint(vector<int> v)
{
	cout << "before next Per\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << "after next Per\n";

	nextPermutation(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << endl;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(4);
	v1.push_back(1);
	testPrint(v1);

	vector<int> v2;
	v2.push_back(3);
	v2.push_back(2);
	v2.push_back(1);

	testPrint(v2);

	vector<int> v3;
	v3.push_back(1);
	v3.push_back(1);
	v3.push_back(5);

	testPrint(v3);

	vector<int> v4;
	v4.push_back(1);
	v4.push_back(5);
	v4.push_back(1);

	testPrint(v4);

	vector<int> v5;
	v5.push_back(5);
	v5.push_back(1);
	v5.push_back(1);

	testPrint(v5);

	vector<int> v6;
	v6.push_back(1);
	v6.push_back(1);
	v6.push_back(1);

	testPrint(v6);

	vector<int> v7;
	v7.push_back(1);
	v7.push_back(1);

	testPrint(v7);

	vector<int> v8;
	v8.push_back(1);
	v8.push_back(2);

	testPrint(v8);

	vector<int> v9;
	v9.push_back(2);
	v9.push_back(1);

	testPrint(v9);

	vector<int> v10;
	v10.push_back(1);

	testPrint(v10);

	return 0;
}