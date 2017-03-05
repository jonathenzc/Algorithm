#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 0)
			return head;

		int lenSize = 0;
		ListNode *tmp = head;
		while (tmp != NULL)
		{
			lenSize++;
			tmp = tmp->next;
		}

		k = k%lenSize;
		if (k == 0)
			return head;

		ListNode *fast = head;
		int cnt = 0;
		while (cnt < k)
		{
			fast = fast->next;
			cnt++;
		}
		
		ListNode *slow = head;
		while (fast->next != NULL) {
			fast = fast->next;
			slow = slow->next;
		}

		fast->next = head;
		head = slow->next;
		slow->next = NULL;

		return head;
	}
};

void printList(ListNode *l)
{
	while (l != NULL)
	{
		cout << l->val << " ";
		l = l->next;
	}

	cout << endl;
}

int main(void)
{
	ListNode *l1 = new ListNode(4);
	ListNode *l2 = new ListNode(5);
	ListNode *l3 = new ListNode(6);
	ListNode *l4 = new ListNode(7);
	ListNode *l5 = new ListNode(8);
	ListNode *l6 = new ListNode(9);
	ListNode *l7 = new ListNode(1);
	ListNode *l8 = new ListNode(2);



	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	l7->next = l8;

	Solution ss;
	ListNode *root = ss.rotateRight(l1,2);
	printList(root);

	return 0;
}