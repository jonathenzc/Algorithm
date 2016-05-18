#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head,int size)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *nextNode = head->next;
	ListNode *traverse = nextNode->next;

	ListNode *tail = head;

	nextNode->next = head;
	head->next = NULL;
	head = nextNode;

	int cnt = 1;

	while (cnt<size)
	{
		nextNode = traverse->next;
		traverse->next = head;
		head = traverse;

		traverse = nextNode;

		cnt++;
	}

	tail->next = traverse;

	return head;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (m == n)
		return head;

	int cnt = 1;
	ListNode* resultNode = head;
	ListNode* pre = NULL;

	while (cnt<m)
	{
		pre = head;
		head = head->next;
		cnt++;
	}

	ListNode *reverseHead = reverseList(head,n-m);

	if (pre != NULL)
		pre->next = reverseHead;
	else
		resultNode = reverseHead;

	return resultNode;
}

int main()
{
	for (int i = 1; i <= 8; i++)
	{

		ListNode* head = new ListNode(8);
		ListNode* node1 = new ListNode(7);
		ListNode* node2 = new ListNode(6);
		ListNode* node3 = new ListNode(5);
		ListNode* node4 = new ListNode(4);
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

		ListNode* result = reverseBetween(head, i, 7);

		while (result != NULL)
		{
			cout << result->val << " ";
			result = result->next;
		}

		cout << endl;
	}

	return 0;
}
