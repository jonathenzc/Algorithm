#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) 
{
	//�ҳ�val��nums�е�index
	vector<int> valIndexV;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == val)
			valIndexV.push_back(i);
	}

	//��������val,���������Ԫ���Ƶ�
	int backIndex = nums.size() - 1;
	for (int i = 0; i < valIndexV.size(); i++)
	{
		if (backIndex <= valIndexV[i])
			break;

		//�Ӻ�ʼ�ҳ�����val��Ԫ�أ������Ƶ���һ����Ҫ�Ƴ���λ��
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
