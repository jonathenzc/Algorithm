#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
	if (head == NULL)
		return NULL;
	else
	{
		ListNode *node = head;
		ListNode *reversedNode = new ListNode(node->val);
		node = node->next;

		while (node != NULL)
		{
			ListNode *temp = new ListNode(node->val);
			temp->next = reversedNode;
			reversedNode = temp;

			node = node->next;
		}

		return reversedNode;
	}
}

int main()
{
	ListNode *head = new ListNode(7);
	ListNode *node = head;

	for (int i = 6; i>=0; i--)
	{
		ListNode *nextNode = new ListNode(i);
		node->next = nextNode;
		node = node->next;
	}

	node = reverseList(head);

	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}

	return 0;
}