#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) 
{
	//找出val在nums中的index
	vector<int> valIndexV;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == val)
			valIndexV.push_back(i);
	}

	//移走所有val,将容器后的元素移到
	int backIndex = nums.size() - 1;
	for (int i = 0; i < valIndexV.size(); i++)
	{
		if (backIndex <= valIndexV[i])
			break;

		//从后开始找出不是val的元素，将它移到第一个需要移除的位置
		while (nums[backIndex] == val)
			backIndex--;

		if (nums[backIndex] != val)
			nums[valIndexV[i]] = nums[backIndex];

		backIndex--;
	}

	return nums.size() - valIndexV.size();
}

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);

	cout << removeElement(v, 1)<< " ";

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";


	return 0;
}
