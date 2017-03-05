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

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		if (v.empty())
		{
			v.push_back(0);
			minEle = x;
		}
		else
		{
			v.push_back(long(x - minEle));
			if (x < minEle)
				minEle = x;
		}
	}

	void pop() {
		if (!v.empty())
		{
			long topEle = v.back();
			v.pop_back();

			if (topEle < 0)
				minEle = minEle - topEle;
		}
	}

	int top() {
		long topGap = v.back();
		if (topGap > 0)
			return long(topGap + minEle);

		return minEle;
	}

	int getMin() {
		return minEle;
	}
private:
	long minEle;
	vector<long> v;
};

int main(void)
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout<<minStack.getMin()<<endl;         //-3
	minStack.pop();
	cout<<minStack.top()<<endl;            // 0
	cout<<minStack.getMin()<<endl;         //-2

	return 0;
}