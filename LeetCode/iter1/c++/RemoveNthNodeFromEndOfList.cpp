#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	int nodeSize = 0;
	ListNode *node = head;

	//记录链表的长度
	while (node != NULL)
	{
		nodeSize++;
		node = node->next;
	}

	//将链表从头数的第nodeSize-n个节点去掉
	if (nodeSize == 1)
		return NULL;
	else
	{
		int cnt = 0;
		ListNode *lastNode = head;
		node = head;

		while (cnt < nodeSize - n)
		{
			lastNode = node;
			node = node->next;
			cnt++;
		}

		if (lastNode == node)
			return lastNode->next;
		else
		{
			lastNode->next = node->next;

			return head;
		}
	}
}

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *temp = head;
	for (int i = 1; i < 2; i++)
	{
		temp->next = new ListNode(i);
		temp = temp->next;
	}

	temp = removeNthFromEnd(head,2);
	while (temp != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}

	if (temp == NULL)
		cout << "It's NULL.\n";

	return 0;
}