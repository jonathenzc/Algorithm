#include <iostream>

using namespace std;
	
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	if (head == NULL)
		return NULL;

	ListNode *slowNode = head;
	ListNode *fastNode = head->next;

	ListNode *resultNode = NULL;
	bool isCircle = true;

	while (slowNode != fastNode)
	{
		slowNode = slowNode->next;

		if (fastNode == NULL)
		{
			resultNode = NULL;
			isCircle = false;
			break;
		}

		fastNode = fastNode->next;

		if (fastNode == NULL)
		{
			resultNode = NULL;
			isCircle = false;
			break;
		}

		fastNode = fastNode->next;
	}

	if (isCircle)
	{
		//从头遍历，与fastNode相交的节点即位第一个相交节点
		slowNode = head;
		fastNode = fastNode->next;

		while (slowNode != fastNode)
		{
			slowNode = slowNode->next;
			fastNode = fastNode->next;
		}

		resultNode = slowNode;
	}


	return resultNode;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(4);
	ListNode* node4 = new ListNode(5);
	ListNode* node5 = new ListNode(6);
	ListNode* node6 = new ListNode(7);
	ListNode* node7 = new ListNode(8);
	
	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;

	node7->next = node2;

	ListNode *connectedNode = detectCycle(head);

	if (connectedNode == NULL)
		cout << "is not list";
	else
		cout << connectedNode->val;

	return 0;
}