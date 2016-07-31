#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	if (heights.size() == 0)
		return 0;

	stack<int> st; //记录柱状图的下标

	heights.push_back(0); //处理3 4 5 6 7这样的情况

	int max = 0;

	for (int i = 0; i < heights.size(); i++)
	{
		while (!st.empty() && heights[st.top()] > heights[i]) //弹栈直到栈顶元素比heights[i]小
		{
			int topIndex = st.top();
			st.pop();

			int leftArea = 0;
			if (st.empty()) //递增波峰图的最小下标,需要一直求到前面的宽度,即个数，下标+1
				leftArea = heights[topIndex] * (topIndex + 1);
			else
				leftArea = heights[topIndex] * (topIndex - st.top());

			int rightArea = heights[topIndex] * (i - topIndex - 1);

			int square = leftArea + rightArea;
			if (max < square)
				max = square;
		}

		st.push(i);
	}

	return max;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.size() == 0)
		return 0;

	//维护一个大小为matrix[0].size()的一维数组
	int size = matrix[0].size();
	vector<int> height;
	for (int i = 0; i < size; i++)
		height.push_back(0);

	int max = 0;

	for (int i = 0; i < matrix.size(); i++)
	{
		vector<char> tmpV = matrix[i];
		for (int j = 0; j < tmpV.size(); j++)
		{
			if (tmpV[j] == '1')
				height[j]++;
			else
				height[j] = 0;
		}

		int square = largestRectangleArea(height);

		if (max < square)
			max = square;
	}

	return max;
}

int main()
{
	vector<vector<char>> v;
	vector<char> tmpV1;
	tmpV1.push_back('0');
	tmpV1.push_back('0');
	tmpV1.push_back('0');
	tmpV1.push_back('1');
	tmpV1.push_back('1');

	vector<char> tmpV2;
	tmpV2.push_back('0');
	tmpV2.push_back('0');
	tmpV2.push_back('0');
	tmpV2.push_back('0');
	tmpV2.push_back('1');

	vector<char> tmpV3;
	tmpV3.push_back('1');
	tmpV3.push_back('1');
	tmpV3.push_back('1');
	tmpV3.push_back('0');
	tmpV3.push_back('0');


	v.push_back(tmpV1);
	v.push_back(tmpV1);
	v.push_back(tmpV2);
	v.push_back(tmpV3);
	v.push_back(tmpV3);

	cout << maximalRectangle(v) << endl;

	return 0;
}