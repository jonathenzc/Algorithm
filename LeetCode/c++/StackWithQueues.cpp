#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int stackSize = 0;

// Push element x onto stack.
void push(int x) {
	if (!q.empty())
	{
		//先用qHelper来存
		queue<int> qHelper;
		while (!q.empty())
		{
			qHelper.push(q.front());
			q.pop();
		}

		q.push(x);

		//再将qHelper中的内容重新压入q中
		while (!qHelper.empty())
		{
			q.push(qHelper.front());
			qHelper.pop();
		}
	}
	else
		q.push(x);

	stackSize++;
}

// Removes the element on top of the stack.
void pop() {
	q.pop();
	stackSize--;
}

// Get the top element.
int top() {
	return q.front();
}

// Return whether the stack is empty.
bool empty() {
	if (stackSize == 0)
		return true;
	else
		return false;
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
		cout << top()<<" ";
		pop();
	}

	return 0;
}