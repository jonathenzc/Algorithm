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
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;

		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
				break;
		}

		if (fast == NULL || fast->next == NULL)
			fast = NULL;
		else
		{
			while (fast != head)
			{
				head = head->next;
				fast = fast->next;
			}
		}
		
		return fast;
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
	l6->next = l3;

	Solution ss;
	ListNode *intersection = ss.detectCycle(l1);
	cout << intersection->val;

	return 0;
}