#include <iostream>
#include <vector>
#include <stack>

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
				leftArea = heights[topIndex]*(topIndex-st.top());

			int rightArea = heights[topIndex] * (i-topIndex-1);

			int square = leftArea + rightArea;
			if (max < square)
				max = square;
		}

		st.push(i);
	}

	return max;
}

//int largestRectangleArea(vector<int> &height) {
//	if (height.size() == 0) return 0;
//	stack<int> st;
//	int MAX = 0;
//	height.push_back(0);
//	int leftarea = 0, rightarea = 0;
//	for (int i = 0; i < height.size(); ++i) {
//		while (!st.empty() && height[st.top()] > height[i]) {
//			int tmp = st.top();
//			st.pop();
//			leftarea = (st.empty() ? tmp + 1 : tmp - st.top()) * height[tmp]; //以tmp为高度，tmp所在柱以及向左延伸出来的矩形面积
//			rightarea = (i - tmp - 1) * height[tmp]; //以tmp为高度，向右边延伸出来的矩形面积
//			if ((leftarea + rightarea) > MAX) MAX = (leftarea + rightarea);
//		}
//		st.push(i);
//	}
//	return MAX;
//}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(2);
	v.push_back(1);

	cout << largestRectangleArea(v)<<endl;

	vector<int> v1;
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(2);
	v1.push_back(3);

	cout << largestRectangleArea(v1)<<endl;

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(1);
	v2.push_back(2);

	cout << largestRectangleArea(v2) << endl;

	vector<int> v4;
	v4.push_back(3);
	v4.push_back(2);
	v4.push_back(5);

	cout << largestRectangleArea(v4) << endl;

	vector<int> v3;
	v3.push_back(4);
	v3.push_back(2);
	v3.push_back(0);
	v3.push_back(3);
	v3.push_back(2);
	v3.push_back(5);

	cout << largestRectangleArea(v3) << endl;

	return 0;
}