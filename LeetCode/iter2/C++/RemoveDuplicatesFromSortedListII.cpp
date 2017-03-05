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
		return helper(head);
	}
private:
	ListNode *helper(ListNode *head)
	{
		if (head == NULL)
			return NULL;

		//ignore duplicate head
		ListNode *preNode = head;
		head = head->next;

		while (head != NULL && head->val == preNode->val)
		{
			while (head != NULL && head->val == preNode->val)
				head = head->next;

			preNode = head;
			if (head == NULL)
				break;
			head = head->next;
		}
		
		if(preNode != NULL)
			preNode->next = helper(head);

		return preNode;
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
	ListNode *l1 = new ListNode(3);
	ListNode *l2 = new ListNode(3);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(3);
	ListNode *l5 = new ListNode(3);
	ListNode *l6 = new ListNode(3);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;

	Solution ss;
	ListNode *root = ss.deleteDuplicates(l1);
	printList(root);

	return 0;
}