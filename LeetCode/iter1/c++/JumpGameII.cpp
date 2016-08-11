#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jump(vector<int>& nums) {
	int steps = 0, end = 0;
	
	for (int start = 0; start < nums.size()-1; )
	{
		steps++;

		int max = end+1; //从start最远可达的范围

		for (int step = start; step <= end; step++)
		{
			if (step + nums[step] >= nums.size() - 1)
				return steps;

			if (step + nums[step] > max)
				max = step + nums[step];
		}

		start = end + 1;
		end = max;
	}

	return steps;
}

int main()
{
	vector<int> v1;

	//v1.push_back(2);
	//v1.push_back(3);
	//v1.push_back(1);
	//v1.push_back(1);
	//v1.push_back(4);

	//v1.push_back(1);
	//v1.push_back(1);
	//v1.push_back(2);
	//v1.push_back(2);
	//v1.push_back(0);
	//v1.push_back(1);
	//v1.push_back(1);

	v1.push_back(5);
	v1.push_back(9);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(0);

	cout << jump(v1)<<endl;

	return 0;
}