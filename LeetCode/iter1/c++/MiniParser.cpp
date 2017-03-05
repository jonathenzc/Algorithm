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

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class Solution {
public:
	NestedInteger deserialize(string s) {
		int pos = 0;
		if (s[0] == '[')
			return helper(s, pos);

		int num = 0;
		int sign = 1;
		if (s[pos] == '-')
		{
			sign = -1;
			pos++;
		}

		for (int i = pos; i < s.size(); i++)
			num = num * 10 + (s[i] - '0');

		num = sign*num;

		return NestedInteger(num);
	}
private:
	NestedInteger helper(string s, int &startIndex)
	{
		NestedInteger ni;

		if (s[startIndex] == '[') {
			while (s[startIndex] != ']') {

				startIndex++;
				if (s[startIndex] == ']') //处理[]
					break;

				ni.add(helper(s, startIndex));
			}

			startIndex++; //处理逗号
		}
		else
		{

			int sign = 1;
			if (s[startIndex] == '-') {
				sign = -1;
				startIndex++;
			}

			int num = 0;
			while (startIndex < s.size() && s[startIndex] >= '0' && s[startIndex] <= '9')
			{
				num = num * 10 + (s[startIndex] - '0');
				startIndex++;
			}
			
			num = sign*num;

			ni.setInteger(num);
		}

		return ni;
	}
};

int main(void)
{
	Solution ss;
	NestedInteger ninteger = ss.deserialize("[123,[456,[789]]]");

	cout << "fff";
	return 0;
}