#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoList(ListNode *first, ListNode *second)
{
	ListNode *resultNode = NULL;
	ListNode *traverseNode = NULL;
	if (first != NULL && second != NULL)
	{
		if (first->val > second->val)
		{
			resultNode = second;
			traverseNode = second;
			second = second->next;
		}
		else
		{
			resultNode = first;
			traverseNode = first;
			first = first->next;
		}

		while (first != NULL && second != NULL)
		{
			if (first->val > second->val)
			{
				traverseNode->next = second;
				traverseNode = second;
				second = second->next;
			}
			else
			{
				traverseNode->next = first;
				traverseNode = first;
				first = first->next;
			}
		}

		//处理剩下没有被归并的
		if (first == NULL)
			traverseNode->next = second;

		if (second == NULL)
			traverseNode->next = first;
	}
	else if (first == NULL)
		resultNode = second;
	else if (second == NULL)
		resultNode = first;

	return resultNode;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0)
		return NULL;
	else if (lists.size() == 1)
		return lists[0];

	for (int i = 0; i < lists.size() - 1; i++)
	{
		ListNode *mergedHead = mergeTwoList(lists[i], lists[i + 1]);
		lists[i + 1] = mergedHead;
	}

	return lists[lists.size()-1];
}

int main()
{
	ListNode* head = new ListNode(4);
	ListNode* node1 = new ListNode(19);
	ListNode* node2 = new ListNode(5);
	ListNode* node3 = new ListNode(14);
	ListNode* node4 = new ListNode(-3);
	ListNode* node5 = new ListNode(1);
	ListNode* node6 = new ListNode(5);
	ListNode* node7 = new ListNode(8);
	ListNode* node8 = new ListNode(11);
	ListNode* node9 = new ListNode(15);

	head->next = node1;
	node2->next = node3;
	node4->next = node5;
	node6->next = node7;
	node8->next = node9;

	vector<ListNode*> v;
	v.push_back(head);
	v.push_back(node2);
	v.push_back(node4);
	v.push_back(node6);
	v.push_back(node8);

	//ListNode* head = new ListNode(8);
	//ListNode* node1 = new ListNode(7);
	//ListNode* node2 = new ListNode(6);
	//ListNode* node3 = new ListNode(5);
	//ListNode* node4 = new ListNode(4);
	//ListNode* node5 = new ListNode(3);
	//ListNode* node6 = new ListNode(2);
	//ListNode* node7 = new ListNode(1);

	//head->next = node1;
	//node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	//node5->next = node6;
	//node6->next = node7;


	ListNode* result = mergeKLists(v);

	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}

	return 0;
}
