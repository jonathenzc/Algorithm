#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	/* solution 1
	* a-p a a   2*p
	* a-p a a a  3*p
	* a-p a a a a 4*p
	*/
	int minMoves1(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int moves = 0;
		for (int i = nums.size() - 1; i > 0; i--) {
			moves += (nums.size() - i)*(nums[i] - nums[i - 1]);
		}

		return moves;
	}

	/* solution 2
	* m: moves, n: nums.size(), a: final num
	* sum + m*(n-1) = a*n
	* a=min+m
	*/
	int minMoves(vector<int>& nums) {
		//sum+m(n-1) = (min+m)*n = nmin+mn
		//sum -nmin = m

		long long sum = 0, min = INT_MAX;
		for (int num : nums) {
			sum += num;
			min = num < min ? num : min;
		}

		return sum - nums.size()*min;
	}
};

void print(bool result) {
	result ? cout << "true\n" : cout << "false\n";
}

int main(void)
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(1);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(5);

	vector<int> v3;
	v3.push_back(2);
	v3.push_back(3);

	vector<int> v4;
	v4.push_back(2);

	vector<int> v5;

	vector<int> v6;
	v6.push_back(1);
	v6.push_back(INT_MAX);

	Solution s;
	cout << s.minMoves(v1) << endl;
	cout << s.minMoves(v2) << endl;
	cout << s.minMoves(v3) << endl;
	cout << s.minMoves(v4) << endl;
	cout << s.minMoves(v5) << endl;
	cout << s.minMoves(v6) << endl;

	return 0;
}