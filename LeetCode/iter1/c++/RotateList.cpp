#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
	if (k <= 0 || head == NULL)
		return head;

	//先获取链表的大小
	int size = 0;
	ListNode *traverse = head;
	ListNode *tail = NULL;
	while (traverse != NULL)
	{
		tail = traverse;
		traverse = traverse->next;
		size++;
	}

	int pivot_index = k % size;
	if (pivot_index == 0)
		return head;

	pivot_index = size - pivot_index;

	//获取第size-k+1个节点
	int cnt = 0;
	traverse = head;
	ListNode *pre = NULL;
	while (cnt < pivot_index)
	{
		pre = traverse;
		traverse = traverse->next;
		cnt++;
	}

	//旋转链表
	tail->next = head;
	head = traverse;
	pre->next = NULL;

	return head;
}

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	//ListNode* node3 = new ListNode(3);
	//ListNode* node4 = new ListNode(4);
	//ListNode* node5 = new ListNode(5);
	//ListNode* node6 = new ListNode(6);

	node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	//node5->next = node6;


	ListNode* result = rotateRight(node1,2);

	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}

	cout << endl;

	return 0;
}
