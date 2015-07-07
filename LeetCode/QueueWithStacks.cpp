#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

// Push element x to the back of queue.
void push(int x) {
	if (!s.empty())
	{
		//先将栈里的元素压入到sHelper中
		stack<int> sHelper;
		while (!s.empty())
		{
			sHelper.push(s.top());
			s.pop();
		}

		s.push(x);

		//再将sHelper中的元素压回到栈中
		while (!sHelper.empty())
		{
			s.push(sHelper.top());
			sHelper.pop();
		}
	}
	else
		s.push(x);
}

// Removes the element from in front of queue.
void pop(void) {
	s.pop();
}

// Get the front element.
int peek(void) {
	return s.top();
}

// Return whether the queue is empty.
bool empty(void) {
	return s.empty();
}

int main()
{
	if (empty())
		cout << "Empty\n";

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);

	while (!empty())
	{
		cout << peek() << " ";
		pop();
	}

	return 0;
}