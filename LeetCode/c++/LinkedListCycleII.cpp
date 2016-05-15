//#include <iostream>
//#include <math.h>
//
//using namespace std;
//	
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* findPartition(ListNode* head, ListNode* end)
//{
//	int target = head->val;
//	ListNode *changeNode = head;
//	ListNode *traverseNode = head;
//
//	while (traverseNode != end && traverseNode != NULL)
//	{
//		traverseNode = traverseNode->next;
//
//		if (traverseNode != NULL)
//		{
//			if (traverseNode->val < target)
//			{
//				changeNode = changeNode->next;
//				int tmp = changeNode->val;
//				changeNode->val = traverseNode->val;
//				traverseNode->val = tmp;			
//			}
//		}
//	}
//
//	int tmp = changeNode->val;
//	changeNode->val = head->val;
//	head->val = tmp;
//
//	return changeNode;
//}
//
//void sortHelper(ListNode* head,ListNode* end)
//{
//	if (head != NULL && head != end)
//	{
//		ListNode *mid = findPartition(head,end);
//		sortHelper(head,mid);
//		if(mid != NULL)
//			sortHelper(mid->next,end);
//	}
//}
//
//ListNode* sortList(ListNode* head) {
//	if (head == NULL)
//		return head;
//
//	sortHelper(head,NULL);
//
//	return head;
//}
//
//int main()
//{
//	ListNode* head = new ListNode(8);
//	ListNode* node1 = new ListNode(6);
//	ListNode* node2 = new ListNode(7);
//	ListNode* node3 = new ListNode(4);
//	ListNode* node4 = new ListNode(5);
//	ListNode* node5 = new ListNode(3);
//	ListNode* node6 = new ListNode(2);
//	ListNode* node7 = new ListNode(1);
//
//	head->next = node1;
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = node6;
//	node6->next = node7;
//
//	ListNode* result = sortList(head);
//
//	while (result != NULL)
//	{
//		cout << result->val << " ";
//		result = result->next;
//	}
//
//	return 0;
//}


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