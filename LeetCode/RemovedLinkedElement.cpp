#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
	//如果链表头部就是该元素，那么将该头节点指向下一个节点
	while (head != NULL && head->val == val)
		head = head->next;
	
	if (head != NULL)
	{
		ListNode * lastIter = head;
		ListNode * iter = head;

		while (iter != NULL)
		{
			if (iter->val == val)
				lastIter->next = iter->next;
			else
				lastIter = iter;

			iter = iter->next;
		}
	}

	return head;
}

int main()
{
	ListNode * head = new ListNode(1);
	ListNode * node1 = new ListNode(1);
	ListNode * node2 = new ListNode(1);
	ListNode * node3 = new ListNode(1);
	ListNode * node4 = new ListNode(1);
	ListNode * node5 = new ListNode(1);
	ListNode * node6 = new ListNode(1);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	ListNode * target = removeElements(head,1);

	while (target != NULL)
	{
		cout << target->val << " ";
		target = target->next;
	}

	return 0;
}