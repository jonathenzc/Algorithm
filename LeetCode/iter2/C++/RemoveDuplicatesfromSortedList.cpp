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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return NULL;

		ListNode *nextNode = head;
		ListNode *preHead = head;

		while (nextNode != NULL)
		{
			if (nextNode->val != preHead->val)
			{
				preHead->next = nextNode;
				preHead = nextNode;
			}

			nextNode = nextNode->next;
		}

		preHead->next = NULL;

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
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(1);
	ListNode *l3 = new ListNode(2);
	ListNode *l4 = new ListNode(2);
	ListNode *l5 = new ListNode(3);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	Solution ss;
	ListNode * ret = ss.deleteDuplicates(l1);
	printList(ret);
	

	return 0;
}