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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int aLen = getListLen(headA);
		int bLen = getListLen(headB);

		int diff = abs(aLen-bLen);

		if (aLen > bLen)
		{
			while (diff > 0)
			{
				diff--;
				headA = headA->next;
			}
		}
		else
		{
			while (diff > 0)
			{
				diff--;
				headB = headB->next;
			}
		}

		while (headA != NULL && headB != NULL)
		{
			if (headA == headB)
				break;

			headA = headA->next;
			headB = headB->next;
		}

		return headA;
	}
private:
	int getListLen(ListNode *head)
	{
		int cnt = 0;
		while (head != NULL)
		{
			cnt++;
			head = head->next;
		}

		return cnt;
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

	ListNode *Bl1 = new ListNode(11);
	ListNode *Bl2 = new ListNode(12);
	ListNode *Bl3 = new ListNode(13);
	ListNode *Bl4 = new ListNode(14);
	ListNode *Bl5 = new ListNode(15);
	ListNode *Bl6 = new ListNode(16);

	Bl1->next = Bl2;
	Bl2->next = Bl3;
	Bl3->next = Bl4;
	Bl4->next = Bl5;
	Bl5->next = Bl6;
	Bl6->next = l3;

	Solution ss;
	ListNode *intersection = ss.getIntersectionNode(l1, Bl1);
	cout << intersection->val;

	return 0;
}