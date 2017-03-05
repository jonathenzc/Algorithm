#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
	int maxArea = 0;
	stack<int> s;

	for (int i = 0; i < height.size();)
	{
		if (s.empty() || height[i] <= height[s.top()])
		{
			s.push(i);
			i++;
		}
		else
		{
			int bot_index = s.top();
			s.pop();
			if (!s.empty())
			{
				int area = ( min(height[s.top()], height[i]) - height[bot_index] )*(i - s.top() - 1);
				maxArea += area;
			}
		}
	}

	return maxArea;
}

int main()
{
	vector<int> v1;

	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(1);

	cout << trap(v1)<<endl;

	return 0;
}