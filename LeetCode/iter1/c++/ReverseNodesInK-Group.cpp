#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head, int size, ListNode *&tailNode)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *nextNode = head->next;
	ListNode *traverse = nextNode->next;

	ListNode *tail = head;

	nextNode->next = head;
	head->next = NULL;
	head = nextNode;

	int cnt = 2;

	while (cnt<size)
	{
		nextNode = traverse->next;
		traverse->next = head;
		head = traverse;

		traverse = nextNode;

		cnt++;
	}

	tail->next = traverse;
	tailNode = tail;

	return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
	if (k <= 1 || head == NULL || head->next == NULL)
		return head;

	//先获取链表的大小
	int size = 0;
	ListNode *traverse = head;

	while (traverse != NULL)
	{
		traverse = traverse->next;
		size++;
	}

	int group = size / k;

	if (group == 0)
		return head;

	//逆反第一组
	ListNode *tail = NULL;
	head = reverseList(head,k,tail);

	int cnt = 1;
	ListNode *next = tail->next;
	ListNode *oldTail = tail;
	while (cnt < group)
	{
		oldTail = tail;
		oldTail->next = reverseList(next,k,tail);
		next = tail->next;
		cnt++;
	}

	return head;
}

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(6);
	ListNode* node7 = new ListNode(7);
	ListNode* node8 = new ListNode(8);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;


	ListNode* result = reverseKGroup(node1,9);

	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}

	cout << endl;

	return 0;
}
