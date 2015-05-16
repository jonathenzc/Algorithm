#include <iostream>

using namespace std;

//这题目的核心在于建立两个数组：一个用来存正常的堆栈信息，另一个是用来记录最小值得。
//这里还要用到一个想法就是当堆栈的第一个数弹出去之后，大于等于它的数就不会是最小值了。
//虽然是句废话，但可以帮助我们建立最小值的数组：在建立堆栈的时候，我们就不用去记录比第一个数大的数了。
int stack[72000];
//int stackSize = 0;
int stackTopIndex = 0;

int minStack[72000];
//int minStackSize = 0;
int minStackTopIndex = 0;

void push(int x) 
{
	stack[stackTopIndex++] = x;

	if (minStackTopIndex == 0 || x <= minStack[minStackTopIndex-1])//记录比栈第一个的元素要小的元素
		minStack[minStackTopIndex++] = x;
}

void pop() 
{
	if (stackTopIndex != 0)
	{
		stackTopIndex--;
		int popedElement = stack[stackTopIndex];

		if (popedElement <= minStack[minStackTopIndex-1])
			minStackTopIndex--;
	}
}

int top() 
{
	return stack[stackTopIndex-1];
}

int getMin() 
{
	return minStack[minStackTopIndex-1];
}

int main()
{
	push(-2);
	push(0);
	push(-1);

	cout<<getMin()<<" ";
	cout << top() << " ";
	pop();
	cout<<getMin()<<endl;

	return 0;
}