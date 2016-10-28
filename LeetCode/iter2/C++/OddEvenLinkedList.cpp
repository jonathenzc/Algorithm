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
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *oddHead = head;
		ListNode *oddNext = oddHead;
		ListNode *evenHead = head->next;
		ListNode *evenNext = evenHead;

		bool odd = true;
		head = evenHead->next;

		while (head != NULL)
		{
			if (odd)
			{
				oddNext->next = head;
				oddNext = oddNext->next;
			}
			else
			{
				evenNext->next = head;
				evenNext = evenNext->next;
			}

			odd = !odd;
			head = head->next;
		}

		if (evenNext != NULL)
			evenNext->next = NULL;

		oddNext->next = evenHead;

		return oddHead;
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
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	ListNode *l5 = new ListNode(5);
	ListNode *l6 = new ListNode(6);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;

	Solution ss;
	ListNode *root = ss.oddEvenList(l1);
	printList(root);

	return 0;
}