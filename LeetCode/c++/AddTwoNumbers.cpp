#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == NULL)
		return l2;
	
	if (l2 == NULL)
		return l1;

	int sum = l1->val + l2->val;
	int addDigit = 0;
	if (sum > 9)
	{
		addDigit = 1;
		sum -= 10;
	}

	ListNode *result = new ListNode(sum);
	ListNode *traverse = result;

	l1 = l1->next;
	l2 = l2->next;

	while (l1 != NULL && l2 != NULL)
	{
		sum = l1->val + l2->val+addDigit;
		if (sum > 9)
		{
			sum -= 10;
			addDigit = 1;
		}
		else
			addDigit = 0;

		ListNode *tmp = new ListNode(sum);
		traverse->next = tmp;
		traverse = traverse->next;

		l1 = l1->next;
		l2 = l2->next;
	}

	if (l1 == NULL && l2 == NULL) //l2还有数字
	{
		if (addDigit == 1) //看进位是否为1
		{
			ListNode *tmp = new ListNode(1);
			traverse->next = tmp;
		}
	}
	else if (l1 == NULL) //l2还有数字
	{
		while (l2 != NULL)
		{
			sum = l2->val + addDigit;
			if (sum > 9)
			{
				sum -= 10;
				addDigit = 1;
			}
			else
				addDigit = 0;

			ListNode *tmp = new ListNode(sum);
			traverse->next = tmp;
			traverse = traverse->next;

			l2 = l2->next;
		}

		if (addDigit == 1) //看进位是否为1
		{
			ListNode *tmp = new ListNode(1);
			traverse->next = tmp;
		}
	}
	else if(l2 == NULL) // l1还有数字
	{
		while (l1 != NULL)
		{
			sum = l1->val + addDigit;
			if (sum > 9)
			{
				sum -= 10;
				addDigit = 1;
			}
			else
				addDigit = 0;

			ListNode *tmp = new ListNode(sum);
			traverse->next = tmp;
			traverse = traverse->next;

			l1 = l1->next;
		}

		if (addDigit == 1) //看进位是否为1
		{
			ListNode *tmp = new ListNode(1);
			traverse->next = tmp;
		}
	}
	
	return result;
}

int main()
{
	ListNode* node1 = new ListNode(9);
	ListNode* node2 = new ListNode(9);
	ListNode* node3 = new ListNode(9);

	ListNode* node4 = new ListNode(9);
	ListNode* node5 = new ListNode(6);
	ListNode* node6 = new ListNode(1);

	//node1->next = node2;
	//node2->next = node3;

	//node4->next = node5;
	//node5->next = node6;


	ListNode* result = addTwoNumbers(node1,node4);

	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}

	cout << endl;

	return 0;
}
