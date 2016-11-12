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
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *pre = new ListNode(0);
		pre->next = head;

		int cnt = 1;
		ListNode *traverse = head;
		ListNode *newHead = pre;

		while (traverse != NULL)
		{
			if (cnt == k)
			{
				traverse = traverse->next;

				ListNode *tmpHead = reverseList(head, traverse);
				pre->next = tmpHead;
				pre = head;
				head->next = traverse;
				head = head->next;

				cnt = 1;
			}
			else
			{
				traverse = traverse->next;
				cnt++;
			}
		}

		return newHead->next;
	}
private:
	ListNode *reverseList(ListNode *start, ListNode *end)
	{
		ListNode *nextNode = start->next;

		while (nextNode != end)
		{
			ListNode *tmp = nextNode->next;
			nextNode->next = start;

			start = nextNode;
			nextNode = tmp;
		}

		return start;
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
	ListNode *l7 = new ListNode(7);
	ListNode *l8 = new ListNode(8);
	ListNode *l9 = new ListNode(9);
	ListNode *l10 = new ListNode(10);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	l7->next = l8;
	l8->next = l9;
	l9->next = l10;
	
	Solution ss;
	ListNode *root = ss.reverseKGroup(l1,3);
	printList(root);

	return 0;
}