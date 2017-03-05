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
	void reorderList(ListNode* head) {
		if (head != NULL && head->next != NULL) //排除0,1个节点的链表
		{
			ListNode *slow = head;
			ListNode *fast = head;

			while (fast != NULL && fast->next != NULL)
			{
				slow = slow->next;
				fast = fast->next->next;
			}

			ListNode *head2 = slow;
			fast = head2->next;

			head2->next = NULL;
			slow->next = NULL;

			while (fast != NULL)
			{
				ListNode *tmp = fast->next;
				fast->next = head2;

				head2 = fast;
				fast = tmp;
			}

			//得到新的链表head和head2
			slow = head;
			bool flag = true; //true为head指向head2
			while (slow != head2)
			{
				if (flag) {
					ListNode *tmp = slow->next;
					slow->next = head2;
					slow = tmp;
					flag = false;
				}
				else
				{
					ListNode *tmp = head2->next;
					head2->next = slow;
					head2 = tmp;
					flag = true;
				}
			}
		}
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
	//l5->next = l6;

	Solution ss;
	printList(l1);
	ss.reorderList(l1);
	printList(l1);

	return 0;
}