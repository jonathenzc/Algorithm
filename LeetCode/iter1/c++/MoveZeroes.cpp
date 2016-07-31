#include <iostream>
#include <vector>

using namespace std;

//思路是统计某数前0的个数，将数往前移“0数”个位置
void moveZeroes(vector<int>& nums)
{
	int zeroCnt = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			zeroCnt++;
		else
			nums[i - zeroCnt] = nums[i];
	}
		
	for (int i =0; i < zeroCnt;i++)
		nums[nums.size()-zeroCnt+i] = 0;
}

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(3);
	v.push_back(12);

	moveZeroes(v);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}