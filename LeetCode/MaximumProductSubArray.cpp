#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b,int c)
{
	if (a >= b && c<=a) //max a
		return a;
	else if (b >= c && a <= b) //max b
		return b;
	else if (c >= a && b <= c)//max c
		return c;
}

int min(int a, int b,int c)
{
	if (a <= b && c >= a) //min a
		return a;
	else if (b <= c && a >= b) //min b
		return b;
	else if (c <= a && b >= c)//min c
		return c;
}

int maxProduct(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;

	int curmax = nums[0];
	int curmin = nums[0];
	int maxPro = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		int temp = curmax;
		curmax = max(curmax*nums[i],nums[i],curmin*nums[i]);
		curmin = min(temp*nums[i], nums[i], curmin*nums[i]);

		if (curmax > maxPro)
			maxPro = curmax;
	}
	
	return maxPro;
}

//int maxProduct(vector<int>& nums) {
//	if (nums.size() == 0) return 0;
//	long long curmax = nums[0], curmin = nums[0], res = nums[0];
//	for (int i = 1; i<nums.size(); ++i){
//		long long premax = curmax;
//		curmax = max(curmax*nums[i], max(curmin*nums[i], (long long)nums[i]));
//		curmin = min(premax*nums[i], min(curmin*nums[i], (long long)nums[i]));
//		res = max(res, curmax);
//	}
//	return int(res);
//}


int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(-2);
	v.push_back(4);
	//v.push_back(-5); 
	//v.push_back(-2);

	cout << maxProduct(v);

	return 0;
}