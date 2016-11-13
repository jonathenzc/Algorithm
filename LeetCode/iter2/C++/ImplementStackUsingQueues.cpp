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

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		queue<int> tmpQ;

		while (!q.empty())
		{
			tmpQ.push(q.front());
			q.pop();
		}

		q.push(x);

		while (!tmpQ.empty())
		{
			q.push(tmpQ.front());
			tmpQ.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		q.pop();
	}

	// Get the top element.
	int top() {
		return q.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}
private:
	queue<int> q;
};

int main(void)
{
	Stack st;
	for (int i = 0; i < 10;i++)
		st.push(i);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}