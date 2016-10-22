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
	ListNode* removeElements(ListNode* head, int val) {
		//忽略头节点为val的一系列节点
		while (head != NULL && head->val == val)
			head = head->next;

		ListNode *preNode = head;
		ListNode *nextNode = head;

		while (nextNode != NULL)
		{
			if (nextNode->val == val)
			{
				preNode->next = nextNode->next;
			}
			else
				preNode = nextNode;

			nextNode = nextNode->next;
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
	ListNode *l2 = new ListNode(1);
	ListNode *l3 = new ListNode(2);
	ListNode *l4 = new ListNode(2);
	ListNode *l5 = new ListNode(3);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	Solution ss;
	ListNode * ret = ss.removeElements(l1,3);
	printList(ret);
	

	return 0;
}