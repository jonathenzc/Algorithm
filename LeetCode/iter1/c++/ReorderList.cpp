#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *nextNode = head->next;
	ListNode *traverse = nextNode->next;

	nextNode->next = head;
	head->next = NULL;
	head = nextNode;

	while (traverse != NULL)
	{
		nextNode = traverse->next;
		traverse->next = head;
		head = traverse;

		traverse = nextNode;
	}

	return head;
}

ListNode *getMid(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;

	ListNode *result = head;

	while (slow != NULL && fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			fast = fast->next;
			if(fast == NULL)
			{
				result = slow->next;
				break;
			}
		}
		else
		{
			result = slow;
			break;
		}

		slow = slow->next;
	}

	return result;
}

void reorderList(ListNode* head) {
	//找出中间的节点
	ListNode *mid = getMid(head);

	//逆转后面的指针
	ListNode *reversedHead = reverseList(mid);

	//进行归并
	ListNode *headTraverse = head;
	ListNode *reversedTraverse = reversedHead;

	ListNode *tmp = NULL;
	while (headTraverse != NULL && headTraverse != mid)
	{
		tmp = headTraverse->next;
		headTraverse->next = reversedTraverse;

		headTraverse = tmp;

		if (headTraverse == mid)
			break;

		tmp = reversedTraverse->next;
		reversedTraverse->next = headTraverse;

		reversedTraverse = tmp;
	}
}

int main()
{
	ListNode* head = new ListNode(8);
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

	reorderList(head);

	ListNode* result = head;

	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}

	return 0;
}
