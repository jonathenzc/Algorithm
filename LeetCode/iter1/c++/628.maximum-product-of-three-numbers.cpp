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
	int maximumProduct(vector<int>& nums) {
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
		int min1 = INT_MAX, min2 = INT_MAX;

		for (int num : nums) {
			if (num > max1) {
				max3 = max2;
				max2 = max1;
				max1 = num;
			}
			else if (num > max2) {
				max3 = max2;
				max2 = num;
			}
			else if (num > max3) {
				max3 = num;
			}

			if (num < min1) {
				min2 = min1;
				min1 = num;
			}
			else if (num < min2) {
				min2 = num;
			}
		}
		/*cout << posNum1 << " " << posNum2 << " " << posNum3<<endl;
		cout << negNum1 << " " << negNum2 << endl;*/

		return max(min1 * min2 * max1, max1 * max2 * max3);
	}
};

int main()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(4);
	v1.push_back(1);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	vector<int> v3;
	v3.push_back(4);
	v3.push_back(3);
	v3.push_back(2);
	v3.push_back(1);

	vector<int> v4;
	v4.push_back(4);
	v4.push_back(3);
	v4.push_back(2);
	v4.push_back(1);
	v4.push_back(-1);
	v4.push_back(-5);
	v4.push_back(-10);
	v4.push_back(-4);
	v4.push_back(-6);
	v4.push_back(-4);
	v4.push_back(-20);

	vector<int> v5;
	v5.push_back(-1);
	v5.push_back(-2);
	v5.push_back(-3);

	vector<int> v6;
	v6.push_back(1);
	v6.push_back(2);
	v6.push_back(3);

	vector<int> v7;
	v7.push_back(-1000);
	v7.push_back(-1000);
	v7.push_back(1000);

	Solution s;
	cout << s.maximumProduct(v1) << endl;
	cout << s.maximumProduct(v2) << endl;
	cout << s.maximumProduct(v3) << endl;
	cout << s.maximumProduct(v4) << endl;
	cout << s.maximumProduct(v5) << endl;
	cout << s.maximumProduct(v6) << endl;
	cout << s.maximumProduct(v7) << endl;

	return 0;
}