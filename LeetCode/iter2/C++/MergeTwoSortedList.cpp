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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = NULL;
		ListNode *nextNode = NULL;

		if (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val) {
				head = new ListNode(l1->val);
				l1 = l1->next;
			}
			else {
				head = new ListNode(l2->val);
				l2 = l2->next;
			}

			nextNode = head;

			while (l1 != NULL && l2 != NULL)
			{
				ListNode *tmpNode = new ListNode(1);

				if (l1->val < l2->val) {
					tmpNode->val = l1->val;
					l1 = l1->next;
				}
				else {
					tmpNode->val = l2->val;
					l2 = l2->next;
				}

				nextNode->next = tmpNode;
				nextNode = nextNode->next;
			}

			if (l1 != NULL)
				nextNode->next = l1;
			else if (l2 != NULL)
				nextNode->next = l2;

		}
		else if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;
		else
			return NULL;

		return head;
	}
};

int main(void)
{
	ListNode *l11 = new ListNode(2);
	ListNode *l12 = new ListNode(4);
	ListNode *l13 = new ListNode(6);
	l11->next = l12;
	l12->next = l13;

	ListNode *l21 = new ListNode(1);
	ListNode *l22 = new ListNode(3);
	ListNode *l23 = new ListNode(5);
	l21->next = l22;
	l22->next = l23;

	Solution ss;

	ListNode *ret = ss.mergeTwoLists(l11,l21);

	while (ret != NULL)
	{
		cout << ret->val << " ";
		ret = ret->next;
	}

	return 0;
}