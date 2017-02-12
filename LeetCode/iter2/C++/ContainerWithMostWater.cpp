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
	int maxArea(vector<int>& height) {
		int area = 0;

		int start = 0;
		int end = height.size() - 1;

		while (start < end)
		{
			int minHeight = min(height[start],height[end]);
			area = max(area, minHeight*(end - start));

			if (height[start] < height[end])
				start++;
			else 
				end--;
		}

		return area;
	}
};

int main(void)
{
	vector<int> height;
	height.push_back(1);
	height.push_back(1);

	Solution s;
	cout << s.maxArea(height) << endl;

	return 0;
}