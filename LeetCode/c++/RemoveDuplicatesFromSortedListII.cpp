#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *ignoreDuplicate(ListNode *node)
{
	bool containsDuplicate = false;

	while (node != NULL && node->next != NULL)
	{
		if (node->val == node->next->val)
		{
			node = node->next;
			containsDuplicate = true;
		}
		else
		{
			if (containsDuplicate)
			{
				containsDuplicate = false;
				node = node->next;
			}

			break;
		}
	}

	if (containsDuplicate)
		node = node->next;

	return node;
}

ListNode* deleteDuplicates(ListNode* head) 
{
	if (head != NULL)
	{
		ListNode *headCopy = head;
		//没重复就返回当前指针，有重复就第一个不同的节点
		ListNode *headIter = ignoreDuplicate(head);

		while (headIter != NULL && headCopy->val != headIter->val)//开头有重复元素
		{
			headCopy = headIter;
			headIter = ignoreDuplicate(headIter);
		}

		//找出第一个单独元素，可以作为整个列表的头节点
		head = headIter;
		while (headIter != NULL && headIter->next!= NULL)
		{
			ListNode *headNext = headIter->next;
			ListNode *nextIter = ignoreDuplicate(headNext);

			headIter->next = nextIter;

			if (headNext!=NULL && nextIter != NULL && headNext->val == nextIter->val)
				headIter = headIter->next;
		}
	}
	
	return head;
}

int main()
{
	ListNode *root = new ListNode(1);
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(2);
	ListNode *node4 = new ListNode(7);
	ListNode *node5 = new ListNode(7);
	ListNode *node6 = new ListNode(7);

	root->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	ListNode *removeNode = deleteDuplicates(root);

	while (removeNode != NULL)
	{
		cout << removeNode->val << " ";
		removeNode = removeNode->next;
	}

	return 0;
}