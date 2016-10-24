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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL) //排除0、1个节点的
			return head;

		ListNode *fakeHead = new ListNode(1);
		fakeHead->next = head;

		n = n - m;

		//先定位到第m个节点
		ListNode *preNode = fakeHead;
		ListNode *startNode = fakeHead;
		while (m > 0)
		{
			preNode = startNode;
			startNode = startNode->next;
			m--;
		}

		ListNode *tailNode = startNode->next;

		while (n > 0)
		{
			ListNode *tmp = tailNode->next;
			
			tailNode->next = startNode;
			startNode = tailNode;
			tailNode = tmp;

			n--;
		}

		preNode->next->next = tailNode;
		preNode->next = startNode;

		return fakeHead->next;
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

	for (int m = 1; m <= 6; m++)
	{
		for (int n = m; n <= 6; n++)
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
			ListNode *intersection = ss.reverseBetween(l1, m, n);
			printList(intersection);
		}
	}

	return 0;
}