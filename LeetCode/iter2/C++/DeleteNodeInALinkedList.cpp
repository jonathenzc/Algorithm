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
	void deleteNode(ListNode* node) {
		ListNode *preNode = node;
		while (node->next != NULL)
		{
			node->val = node->next->val;

			preNode = node;
			node = node->next;
		}

		preNode->next = NULL;
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
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(3);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(2);
	ListNode *l5 = new ListNode(1);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	Solution ss;
	ss.deleteNode(l1);
	printList(l1);
	

	return 0;
}