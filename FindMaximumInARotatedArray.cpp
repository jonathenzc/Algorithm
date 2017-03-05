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
	int findMax(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;
		int maxCan = INT_MIN;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] > nums[start])
				start = mid + 1;
			else if (nums[mid] < nums[start])
				end = mid;
			else
				start++;

			maxCan = max(maxCan,nums[mid]);
		}

		return maxCan;
	}
};


void PrintV(vector<int> v)
{
	for (auto num : v)
		cout << num << " ";

	cout << endl;
}

void testPrint(int leftPart,int rightPart)
{
	vector<int> v;
	for (int i = leftPart - 1; i>=0; i--)
		v.push_back(leftPart+rightPart-i);

	for (int i = 1; i <= rightPart; i++)
		v.push_back(i);

	PrintV(v);

	Solution s;
	cout << "Max "<<s.findMax(v) << endl;
}


int main(void)
{
	int size = 8;
	for (int i = 0; i < size;i++)
		testPrint(i,size-i);

	//vector<int> v;
	//v.push_back(3);
	//v.push_back(3);
	//v.push_back(1);
	//v.push_back(3);

	//Solution s;
	//cout << s.findMin(v)<<endl;

	return 0;
}