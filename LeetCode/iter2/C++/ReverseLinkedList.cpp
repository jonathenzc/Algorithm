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
	bool isPalindrome(ListNode* head) {
		return false;
	}

	//迭代版本
	ListNode* reverseListIter(ListNode* head) {
		if (head == NULL)
			return head;

		ListNode *nextNode = head->next;
		head->next = NULL;
		ListNode *nextNextNode = nextNode;
		while (nextNode != NULL) {
			nextNextNode = nextNode->next;
			nextNode->next = head;

			head = nextNode;
			nextNode = nextNextNode;
		}

		return head;
	}

	//递归版本
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
			return head;

		return helper(head,NULL);
	}
private:
	ListNode* helper(ListNode *head, ListNode *preNode)
	{
		if (head == NULL)
			return preNode;

		ListNode *nextNode = head->next;
		head->next = preNode;
		preNode = head;

		return helper(nextNode,preNode);
	}
};

int main(void)
{
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(3);
	ListNode *l3 = new ListNode(4);
	ListNode *l4 = new ListNode(5);
	ListNode *l5 = new ListNode(6);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	Solution ss;


	ListNode *ret = ss.reverseList(l1);

	while (ret != NULL)
	{
		cout << ret->val << " ";
		ret = ret->next;
	}

	cout << endl;

	return 0;
}