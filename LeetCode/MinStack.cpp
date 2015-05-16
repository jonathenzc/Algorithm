#include <iostream>

using namespace std;

//����Ŀ�ĺ������ڽ����������飺һ�������������Ķ�ջ��Ϣ����һ����������¼��Сֵ�á�
//���ﻹҪ�õ�һ���뷨���ǵ���ջ�ĵ�һ��������ȥ֮�󣬴��ڵ����������Ͳ�������Сֵ�ˡ�
//��Ȼ�Ǿ�ϻ��������԰������ǽ�����Сֵ�����飺�ڽ�����ջ��ʱ�����ǾͲ���ȥ��¼�ȵ�һ����������ˡ�
int stack[72000];
//int stackSize = 0;
int stackTopIndex = 0;

int minStack[72000];
//int minStackSize = 0;
int minStackTopIndex = 0;

void push(int x) 
{
	stack[stackTopIndex++] = x;

	if (minStackTopIndex == 0 || x <= minStack[minStackTopIndex-1])//��¼��ջ��һ����Ԫ��ҪС��Ԫ��
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