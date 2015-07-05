#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string int2Str(int n)
{
	stringstream ss;
	string s = "";
	ss << n;
	ss >> s;

	return s;
}

vector<string> summaryRanges(vector<int>& nums) 
{
	vector<string> v;

	if (nums.size() == 1)
	{
		string s = int2Str(nums[0]);
		v.push_back(s);
	}
	else if (nums.size()>1)
	{
		int start = nums[0];
		int end = start;
		string s = int2Str(start);

		for (int i = 1; i < nums.size(); i++)
		{
			if (end+1 != nums[i])
			{
				if (start != end)
					s += "->" + int2Str(end);

				v.push_back(s);

				//Ñ°ÕÒÏÂÒ»¸ö·¶Î§
				start = nums[i];
				end = start;
				s = int2Str(start);
			}
			else
				end = nums[i];

			if (i == nums.size() - 1)
			{
				if (start != end)
					s += "->" + int2Str(end);

				v.push_back(s);
			}
		}
	}

	return v;
}

int main()
{
	vector<int> v;
	v.push_back(-3);
	v.push_back(-1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	v.push_back(11);
	v.push_back(15);
	v.push_back(17);

	vector<string> range;
	range = summaryRanges(v);

	for (int i = 0; i < range.size(); i++)
		cout << range[i]<<endl;

	return 0;
}