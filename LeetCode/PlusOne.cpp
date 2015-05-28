#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
	bool whetherPlusOne = false;

	digits[digits.size() - 1] += 1;

	if (digits[digits.size() - 1] >= 10)
	{
		whetherPlusOne = true;
		digits[digits.size() - 1] = 0;
	}

	if (whetherPlusOne)
	{
		for (int i = digits.size() - 2; i >= 0; i--)
		{
			digits[i] += 1;

			if (digits[i] >= 10)
			{
				whetherPlusOne = true;
				digits[i] = 0;
			}
			else
			{
				whetherPlusOne = false;
				break;
			}
		}

		//是否需要进1
		if (whetherPlusOne)
		{
			digits.push_back(0);//扩充一位
			for (int i = digits.size() - 1; i > 0; i--)
				digits[i] = digits[i - 1];

			digits[0] = 1;
		}
	}

	return digits;
}

int main()
{

	vector<int> v;
	v.push_back(9);
	v.push_back(9);

	vector<int> plusOneV = plusOne(v);
	
	for (int i = 0; i < plusOneV.size(); i++)
		cout << plusOneV[i];

	return 0;
}