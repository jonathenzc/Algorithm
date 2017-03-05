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
	int trap(vector<int>& height) {
		int amount = 0;

		int preHeight = 0;
		int i = 0;
		while (i < height.size())
		{
			if (indexV.empty() || height[i] <= height[indexV.back()]) 
				indexV.push_back(i++);
			else
			{
				int bottomIndex = indexV.back();
				indexV.pop_back();
				if (!indexV.empty())
					amount += (i-indexV.back()-1) * (min(height[i],height[indexV.back()])-height[bottomIndex]);
			}
		}

		return amount;
	}
private:
	vector<int> indexV;
};

int main(void)
{
	Solution s;

	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	
	cout << s.trap(v) << endl;

	return 0;
}