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
	vector<int> plusOne(vector<int>& digits) {
		
		//反转vector
		reverse(digits.begin(),digits.end());

		int addDigit = 1;
		
		for (int i = 0; i < digits.size(); i++)
		{
			digits[i] += addDigit;

			if (digits[i] > 9)
			{
				digits[i] -= 10;
				addDigit = 1;
			}
			else
				addDigit = 0;
		}

		if (addDigit == 1)
			digits.push_back(1);

		reverse(digits.begin(),digits.end());

		return digits;
	}
};

int main(void)
{
	vector<int> v;
	//for (int i = 1; i < 10; i++)
	//	v.push_back(i);

	v.push_back(9);
	v.push_back(9);
	v.push_back(9);

	cout << "Before adding one\n";

	for (auto num : v)
		cout << num << " ";

	cout << "After adding one\n";

	Solution s;
	v = s.plusOne(v);

	for (auto num : v)
		cout << num << " ";

	return 0;
}