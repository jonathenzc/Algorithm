#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) 
{
	if (head == NULL || head->next == NULL)
		return false;

	ListNode *slowNode = head;
	ListNode *fastNode = head->next;

	while (slowNode != NULL && fastNode != NULL)
	{
		if (slowNode == fastNode)
			return true;

		slowNode = slowNode->next;
		if (fastNode->next != NULL)
			fastNode = fastNode->next->next;
		else
			break;
	}

	return false;
}

int main()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n5;

	if (hasCycle(n1))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}