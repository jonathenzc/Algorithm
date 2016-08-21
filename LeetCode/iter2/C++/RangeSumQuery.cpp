#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> &nums) {
		numV = nums;
		if (nums.size() != 0)
		{
			dp = new int[nums.size()];
			dp[0] = nums[0];
			for (int i = 1; i < nums.size(); i++)
				dp[i] = dp[i - 1] + nums[i];
		}
	}

	int sumRange(int i, int j) {
		if (numV.size() != 0)
			return dp[j] - dp[i] + numV[i];
		else
			return 0;
	}
private:
	int *dp;
	vector<int> numV;
};


int main()
{

	return 0;
}