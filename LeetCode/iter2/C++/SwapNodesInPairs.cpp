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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *nextNode = head->next;
		ListNode *current = nextNode->next;
		ListNode *preNode = head;

		nextNode->next = head;
		head->next = current;
		head = nextNode;

		

		while (current != NULL && current->next != NULL)
		{
			nextNode = current->next;
			current->next = nextNode->next;
			nextNode->next = current;
			preNode->next = nextNode;

			preNode = current;
			current = current->next;
		}

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
	ListNode *ret = ss.swapPairs(l1);
	printList(ret);

	return 0;
}