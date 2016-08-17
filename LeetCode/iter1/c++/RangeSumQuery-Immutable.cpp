#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> &nums) {
		
		dp = new int[nums.size()+1];
		dp[0] = 0;

		for (int i = 1; i <= nums.size(); i++)
			dp[i] = dp[i - 1] + nums[i-1];
	}

	int sumRange(int i, int j) {
		return dp[j+1] - dp[i];
	}
private:
	int *dp;
};

int main()
{
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(-5);
	nums.push_back(2);
	nums.push_back(-1);

	NumArray numArray(nums);
	cout << numArray.sumRange(0,2)<<endl;
	cout << numArray.sumRange(2, 5) << endl;
	cout << numArray.sumRange(0, 5) << endl;

	return 0;
}