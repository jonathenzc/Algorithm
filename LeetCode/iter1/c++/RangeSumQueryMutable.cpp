#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> &nums) {
		v = nums;
		if (nums.size() > 0)
		{
			dp = new int[nums.size()];
			dp[0] = nums[0];
			for (int i = 1; i < nums.size(); i++)
				dp[i] = dp[i - 1] + nums[i];
		}
	}

	void update(int i, int val) {
		int diff = val - v[i];
		v[i] = val;
		for (int j = i; j < v.size(); j++)
			dp[j] += diff;
	}

	int sumRange(int i, int j) {
		return dp[j]-dp[i] +v[i];
	}
private:
	int *dp;
	vector<int> v;
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

	NumArray ma(v);
	cout << ma.sumRange(0, 2) << endl; //9
	ma.update(1,2);
	cout << ma.sumRange(0,2)<<endl; //8


	vector<int> v1;
	v1.push_back(-1);

	NumArray ma1(v1);
	cout << ma1.sumRange(0, 0) << endl; //-1
	ma1.update(0, 1);
	cout << ma1.sumRange(0, 0) << endl; //1

		
	return 0;
}