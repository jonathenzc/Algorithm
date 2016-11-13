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

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		stack<int> tmpSt;

		while (!st.empty())
		{
			tmpSt.push(st.top());
			st.pop();
		}

		tmpSt.push(x);

		while (!tmpSt.empty())
		{
			st.push(tmpSt.top());
			tmpSt.pop();
		}
	}

	// Removes the element from in front of queue.
	void pop(void) {
		st.pop();
	}

	// Get the front element.
	int peek(void) {
		return st.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return st.empty();
	}
private:
	stack<int> st;
};

int main(void)
{
	Queue q;
	for (int i = 0; i < 10;i++)
		q.push(i);

	while (!q.empty())
	{
		cout << q.peek() << " ";
		q.pop();
	}

	return 0;
}