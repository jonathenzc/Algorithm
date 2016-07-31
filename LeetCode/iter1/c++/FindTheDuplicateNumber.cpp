#include <iostream>
#include <vector>

using namespace std;

//ͨ�����ֵķ����𲽱ƽ��ظ���Ӧ���ڵķ�Χ
int findDuplicate(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	
	int n = nums.size()-1;
	int low = 1;
	int high = n;
	int half = (n+1)/2;
	int mid = (low + high) / 2;
	int count = 0;

	while (low < high)
	{
		count = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= mid) //ͳ��С����λ�������ĸ���
				count++;
		}

		if (count > mid) //��С�ظ������ڵ�������[low,mid]
			high = mid;
		else
			low = mid+1;
	}

	return low;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);

	cout << findDuplicate(v);

	return 0;
}