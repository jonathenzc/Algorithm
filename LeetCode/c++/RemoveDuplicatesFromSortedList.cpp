#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
	if (head != NULL)
	{
		ListNode *headIter = head;
		ListNode *removeIter = head->next;

		while (headIter != NULL && removeIter != NULL)
		{
			if (removeIter->val != headIter->val)
			{
				headIter->next = removeIter;
				headIter = headIter->next;
			}

			removeIter = removeIter->next;
		}

		if (headIter != NULL)
			headIter->next = removeIter;
	}

	return head;
}

int main()
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(4);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	ListNode *node = deleteDuplicates(node1);
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}


	return 0;
}