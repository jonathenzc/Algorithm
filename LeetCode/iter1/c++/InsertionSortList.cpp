#include <iostream>

using namespace std;
	
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
	if (head == NULL)
		return NULL;

	ListNode *start = head;
	ListNode *target = start->next;
	ListNode *beforeStart = NULL;
	ListNode *beforeTarget = head;

	while (target != NULL)
	{
		start = head;
		beforeStart = NULL;

		int targetVal = target->val;

		while (start != target && start->val <= targetVal)
		{
			beforeStart = start;
			start = start->next;
		}

		if (start != target)
		{
			beforeTarget->next = target->next;

			ListNode *tmp = new ListNode(targetVal);

			if (beforeStart != NULL)
			{
				beforeStart->next = tmp;
				tmp->next = start;
			}
			else
			{
				tmp->next = start;
				head = tmp;
			}
		}
		else
			beforeTarget = target;

		target = target->next;
	}

	return head;
}

int main()
{
	ListNode* head = new ListNode(4);
	ListNode* node1 = new ListNode(5);
	ListNode* node2 = new ListNode(8);
	ListNode* node3 = new ListNode(9);
	ListNode* node4 = new ListNode(6);
	ListNode* node5 = new ListNode(3);
	ListNode* node6 = new ListNode(2);
	ListNode* node7 = new ListNode(1);
	
	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;


	ListNode *connectedNode = insertionSortList(head);

	while (connectedNode != NULL)
	{
		cout << connectedNode->val << " ";

		connectedNode = connectedNode->next;
	}

	cout << endl;

	ListNode* ahead = new ListNode(1);
	ListNode* anode1 = new ListNode(2);
	ListNode* anode2 = new ListNode(3);
	ListNode* anode3 = new ListNode(4);
	ListNode* anode4 = new ListNode(5);
	ListNode* anode5 = new ListNode(6);
	ListNode* anode6 = new ListNode(7);
	ListNode* anode7 = new ListNode(8);

	ahead->next = anode1;
	anode1->next = anode2;
	anode2->next = anode3;
	anode3->next = anode4;
	anode4->next = anode5;
	anode5->next = anode6;
	anode6->next = anode7;


	ListNode *aconnectedNode = insertionSortList(ahead);

	while (aconnectedNode != NULL)
	{
		cout << aconnectedNode->val << " ";

		aconnectedNode = aconnectedNode->next;
	}

	cout << endl;

	return 0;
}