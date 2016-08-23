#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	stack<int> s;
	int maxArea = 0;

	int i = 0;
	heights.push_back(0);

	while (i < heights.size())
	{
		if (s.empty() || heights[s.top()] <= heights[i])
			s.push(i++);
		else
		{
			int pivot = s.top();
			s.pop();

			int area = heights[pivot] * ((s.empty()?i:i-s.top()-1));

			if (area > maxArea)
				maxArea = area;
		}
	}
	
	return maxArea;
}

int main()
{
	vector<int> heights;
	heights.push_back(3);
	heights.push_back(2);
	//heights.push_back(5);
	//heights.push_back(6);
	//heights.push_back(2);
	//heights.push_back(3);

	cout << largestRectangleArea(heights);


	//vector<vector<char>> v;

	////vector<char> v1;
	////v1.push_back('1');
	////v1.push_back('0');
	////v1.push_back('1');
	////v1.push_back('0');
	////v1.push_back('0');

	////vector<char> v2;
	////v2.push_back('1');
	////v2.push_back('0');
	////v2.push_back('1');
	////v2.push_back('1');
	////v2.push_back('1');

	////vector<char> v3;
	////v3.push_back('1');
	////v3.push_back('1');
	////v3.push_back('1');
	////v3.push_back('1');
	////v3.push_back('1');

	////vector<char> v4;
	////v4.push_back('1');
	////v4.push_back('0');
	////v4.push_back('1');
	////v4.push_back('1');
	////v4.push_back('0');

	//vector<char> v1;
	//v1.push_back('0');
	//v1.push_back('0');
	//v1.push_back('0');
	//v1.push_back('1');

	//vector<char> v2;
	//v2.push_back('1');
	//v2.push_back('1');
	//v2.push_back('0');
	//v2.push_back('1');

	//vector<char> v3;
	//v3.push_back('1');
	//v3.push_back('1');
	//v3.push_back('1');
	//v3.push_back('1');

	//vector<char> v4;
	//v4.push_back('0');
	//v4.push_back('1');
	//v4.push_back('1');
	//v4.push_back('1');

	//vector<char> v5;
	//v5.push_back('0');
	//v5.push_back('1');
	//v5.push_back('1');
	//v5.push_back('1');

	//v.push_back(v1);
	//v.push_back(v2);
	//v.push_back(v3);
	//v.push_back(v4);
	//v.push_back(v5);

	//cout << maximalSquare(v);




	return 0;
}