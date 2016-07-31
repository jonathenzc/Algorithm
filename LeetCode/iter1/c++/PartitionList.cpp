#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
	if (head == NULL)
		return NULL;
	
	ListNode *smallHead = NULL;
	ListNode *smallTraverse = NULL;

	ListNode *bigHead = NULL;
	ListNode *bigTraverse = NULL;

	ListNode *traverse = head;

	while (traverse != NULL)
	{
		if (traverse->val < x) //构建比它小的链表
		{
			if (smallHead == NULL)
			{
				smallHead = new ListNode(traverse->val);
				smallTraverse = smallHead;
			}
			else
			{
				ListNode *tmp = new ListNode(traverse->val);
				smallTraverse->next = tmp;
				smallTraverse = smallTraverse->next;
			}
		}
		else //构建比它大的链表
		{
			if (bigHead == NULL)
			{
				bigHead = new ListNode(traverse->val);
				bigTraverse = bigHead;
			}
			else
			{
				ListNode *tmp = new ListNode(traverse->val);
				bigTraverse->next = tmp;
				bigTraverse = bigTraverse->next;
			}
		}

		traverse = traverse->next;
	}

	if (smallHead == NULL) //x比链表中的值都小
		return bigHead;
	else
	{
		smallTraverse->next = bigHead;
		return smallHead;
	}
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* node1 = new ListNode(4);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(5);
	ListNode* node5 = new ListNode(2);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	ListNode *result = partition(head,3);

	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}


	return 0;
}