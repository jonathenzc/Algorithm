#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) 
{
	//��Ҫע�⣬��Ϊ��k�����˾���Ĵ�С��Ȼ���Խ��з�ת
	if (k > nums.size())
		k -= nums.size();

	int *temp = new int[k];
	for (int i = 0; i < k; i++)
		temp[i] = nums[nums.size() - k + i];

	for (int i = nums.size() - k - 1; i >= 0; i--)
		nums[i + k] = nums[i];

	for (int i = 0; i < k; i++)
		nums[i] = temp[i];
}

int main()
{
	vector<int> v;

	for (int i = 0; i < 2; i++)
		v.push_back(i);

	rotate(v, 3);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}