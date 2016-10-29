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
	ListNode* partition(ListNode* head, int x) {
		ListNode *greatNode = new ListNode(1);
		ListNode *greatNext = greatNode;

		ListNode *lessNode = new ListNode(1);
		ListNode *lessNext = lessNode;

		while (head != NULL)
		{
			if (head->val < x) {
				lessNext->next = head;
				lessNext = lessNext->next;
			}
			else
			{
				greatNext->next = head;
				greatNext = greatNext->next;
			}

			head = head->next;
		}

		greatNext->next = NULL;
		lessNext->next = greatNode->next;

		return lessNode->next;
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
	ListNode *root = ss.partition(l1,3);
	printList(root);

	return 0;
}