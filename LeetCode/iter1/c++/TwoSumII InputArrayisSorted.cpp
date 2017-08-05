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
	vector<int> twoSum(vector<int>& numbers, int target) {
		int start = 0, end = numbers.size() - 1;
		while (start < end)
		{
			int sum = numbers[start] + numbers[end];
			if (sum == target)
				break;
			else if (sum > target)
				end--;
			else
				start++;
		}

		return vector<int>{start+1,end+1};
	}
};

int main(void)
{
	Solution s;

	//vector<int> numbers;
	//numbers.push_back(2);
	//numbers.push_back(7);
	//numbers.push_back(11);
	//numbers.push_back(15);

	//vector<int> ret = s.twoSum(numbers, 17);
	//for (int index : ret)
	//{
	//	cout << index << " ";
	//}
	//cout << endl;

	vector<int> numbers2;
	numbers2.push_back(3);
	numbers2.push_back(24);
	numbers2.push_back(50);
	numbers2.push_back(79);
	numbers2.push_back(88);
	numbers2.push_back(150);
	numbers2.push_back(345);

	vector<int> ret2 = s.twoSum(numbers2, 200);
	for (int index : ret2) 
	{
		cout << index << " ";
	}
	cout << endl;


	return 0;
}